#include <node_api.h>
#include <iostream>

// 执行异步工作的函数
void execute_work(napi_env env, void* data) {
  napi_handle_scope scope;
  napi_open_handle_scope(env, &scope);

  // 解析工作数据
  napi_value value = *(reinterpret_cast<napi_value*>(data));
  int result;
  napi_get_value_int32(env, value, &result);

  // 执行计算密集型或阻塞操作
  result *= 2;

  // 返回结果
  napi_value result_value;
  napi_create_int32(env, result, &result_value);

  // 存储结果
  *(reinterpret_cast<napi_value*>(data)) = result_value;

  napi_close_handle_scope(env, scope);
}

// 当异步工作完成时调用的函数
void complete_work(napi_env env, napi_status status, void* data) {
  napi_handle_scope scope;
  napi_open_handle_scope(env, &scope);

  // 解析工作数据
  napi_deferred deferred = *(reinterpret_cast<napi_deferred*>(data));
  napi_value result_value = *(reinterpret_cast<napi_value*>(data) + 1);

  if (status != napi_ok) {
    // 如果操作失败，则拒绝Deferred对象并返回错误
    napi_reject_deferred(env, deferred, napi_create_error(env, "Error occurred"));
  } else {
    // 否则，解决Deferred对象并返回结果
    napi_resolve_deferred(env, deferred, result_value);
  }

  // 释放工作数据
  napi_delete_async_work(env, *(reinterpret_cast<napi_async_work*>(data)));
  delete[] reinterpret_cast<napi_value*>(data);

  napi_close_handle_scope(env, scope);
}

// 异步NAPI接口函数
napi_value my_async_function(napi_env env, napi_callback_info info) {
  size_t argc = 1;
  napi_value argv[1];

  // 解析参数
  napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

  // 创建Deferred对象
  napi_deferred deferred;
  napi_value promise;
  napi_create_promise(env, &deferred, &promise);

  // 创建异步工作对象并将其推入事件循环中
  napi_async_work work;
  napi_value value = argv[0];
  napi_create_async_work(env, nullptr, promise, execute_work, complete_work, new napi_value[2]{ deferred, value },
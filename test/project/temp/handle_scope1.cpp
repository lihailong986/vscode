#include <node_api.h>
#include <iostream>

napi_value my_async_function(napi_env env, napi_callback_info info) {
  // 解析参数
  size_t argc = 2;
  napi_value argv[2];
  napi_get_cb_info(env, info, &argc, argv, NULL, NULL);

  // 获取JavaScript回调函数
  napi_value callback = argv[1];

  // 创建异步操作数据结构
  AsyncData* asyncData = new AsyncData;
  asyncData->callback = napi_create_reference(env, callback, 1);

  // 调用异步操作
  uv_work_t* workReq = new uv_work_t;
  workReq->data = asyncData;
  uv_queue_work(uv_default_loop(), workReq, AsyncWorker, AsyncComplete);

  return NULL;
}

void AsyncWorker(uv_work_t* req) {
  AsyncData* asyncData = static_cast<AsyncData*>(req->data);

  // 创建一个handle scope
  napi_status status;
  napi_handle_scope scope;
  status = napi_open_handle_scope(asyncData->env, &scope);
  if (status != napi_ok) {
    // 处理错误
    return;
  }

  // 执行异步操作
  // ...

  // 创建JavaScript对象
  napi_value obj;
  status = napi_create_object(asyncData->env, &obj);
  if (status != napi_ok) {
    // 处理错误
    napi_close_handle_scope(asyncData->env, scope);
    return;
  }

  // 使用JavaScript对象
  // ...

  // 保存JavaScript对象的引用
  asyncData->result = napi_create_reference(asyncData->env, obj, 1);

  // 关闭handle scope
  napi_close_handle_scope(asyncData->env, scope);
}

void AsyncComplete(uv_work_t* req, int status) {
  AsyncData* asyncData = static_cast<AsyncData*>(req->data);

  // 创建一个handle scope
  napi_handle_scope scope;
  napi_open_handle_scope(asyncData->env, &scope);

  // 获取JavaScript回调函数
  napi_value callback = napi_get_reference_value(asyncData->env, asyncData->callback);

  // 创建JavaScript对象
  napi_value result = napi_get_reference_value(asyncData->env, asyncData->result);

  // 调用JavaScript回调函数
  napi_value argv[1] = { result };
  napi_value global;
  napi_get_global(asyncData->env, &global);
  napi_call_function(asyncData->env, global, callback, 1, argv, NULL);

  // 释放资源
  napi_delete_reference(asyncData->env, asyncData->callback);
  napi_delete_reference(asyncData->env, asyncData->result);
  delete asyncData;

  // 关闭
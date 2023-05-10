/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <cstring>
#include <string>
#include <memory>
#include <vector>
#include <node_api.h>
#include <any>
#include "tool_utility.h"
#include "khtime.h"

#define NUMBER_JS_2_C(napi_v, type, dest)        \
    if (typeid(type) == typeid(int32_t)) {       \
        dest = pxt->SwapJs2CInt32(napi_v);       \
    }                                            \
    else if (typeid(type) == typeid(uint32_t)) { \
        dest = pxt->SwapJs2CUint32(napi_v);      \
    }                                            \
    else if (typeid(type) == typeid(int64_t)) {  \
        dest = pxt->SwapJs2CInt64(napi_v);       \
    }                                            \
    else if (typeid(type) == typeid(double_t)) { \
        dest = pxt->SwapJs2CDouble(napi_v);      \
    }

#define NUMBER_JS_2_C_ENUM(napi_v, type, dest, enum_type)      \
    if (typeid(type) == typeid(int32_t))  {    \
        dest = static_cast<enum_type>(pxt->SwapJs2CInt32(napi_v));     \
    }                                           \
    else if (typeid(type) == typeid(uint32_t)) { \
        dest = static_cast<enum_type>(pxt->SwapJs2CUint32(napi_v));    \
    }                                          \
    else if (typeid(type) == typeid(int64_t)) { \
        dest = static_cast<enum_type>(pxt->SwapJs2CInt64(napi_v));     \
    }                                           \
    else if (typeid(type) == typeid(double_t)) { \
        dest = static_cast<enum_type>(pxt->SwapJs2CDouble(napi_v));    \
    }
    
#define BOOLEAN_JS_2_C(napi_v, type, dest) {    \
    dest = pxt->SwapC2JsBool(napi_v);          \
}

#define C_DELETE(p)  \
    if ((p)) {         \
        delete (p);    \
    }

__attribute__((unused)) static napi_value number_c_to_js(XNapiTool *pxt, const std::type_info &n, DataPtr num)
{
    if (n == typeid(int32_t))
        return pxt->SwapC2JsInt32(*(int32_t *)num);
    else if (n == typeid(uint32_t))
        return pxt->SwapC2JsUint32(*(uint32_t *)num);
    else if (n == typeid(int64_t))
        return pxt->SwapC2JsInt64(*(int64_t *)num);
    else if (n == typeid(double_t))
        return pxt->SwapC2JsDouble(*(double_t *)num);
    return nullptr;
}
#define NUMBER_C_2_JS(pxt, n) \
    number_c_to_js(pxt, typeid((n)), reinterpret_cast<DataPtr>(&(n)))

namespace khtime {
struct setNtpServerUrl_value_struct {
    std::string in0;
    uint32_t outErrCode = 0;
};

void setNtpServerUrl_execute(XNapiTool *pxt, DataPtr data)
{
    void *data_ptr = data;
    setNtpServerUrl_value_struct *vio = static_cast<setNtpServerUrl_value_struct *>(data_ptr);
    
    setNtpServerUrl(vio->in0, vio->outErrCode);
}

void setNtpServerUrl_complete(XNapiTool *pxt, DataPtr data)
{
    void *data_ptr = data;
    setNtpServerUrl_value_struct *vio = static_cast<setNtpServerUrl_value_struct *>(data_ptr);
    napi_value result = nullptr;
    result = pxt->UndefinedValue();
    napi_value errCodeResult = nullptr;
    napi_value napiErrCode = nullptr;
    napiErrCode = NUMBER_C_2_JS(pxt, vio->outErrCode);
    pxt->SetValueProperty(errCodeResult, "code", napiErrCode);
    {
        napi_value args[XNapiTool::TWO] = {errCodeResult, result};
        pxt->FinishAsync(XNapiTool::TWO, args);
    }
    
    delete vio;
}

napi_value setNtpServerUrl_middle(napi_env env, napi_callback_info info)
{
    XNapiTool *pxt = std::make_unique<XNapiTool>(env, info).release();
    if (pxt->IsFailed()) {
        napi_value err = pxt->GetError();
        delete pxt;
        return err;
    }
    
    struct setNtpServerUrl_value_struct *vio = new setNtpServerUrl_value_struct();
        pxt->SwapJs2CUtf8(pxt->GetArgv(XNapiTool::ZERO), vio->in0);

    napi_value result = pxt->StartAsync(setNtpServerUrl_execute, reinterpret_cast<DataPtr>(vio), setNtpServerUrl_complete,
    pxt->GetArgc() == XNapiTool::TWO? pxt->GetArgv(XNapiTool::ONE) : nullptr);
    if (pxt->IsFailed()) {
        result = pxt->GetError();
    }
    return result;
}
struct setNtpSwitch_value_struct {
    std::string in0;
    uint32_t outErrCode = 0;
};

void setNtpSwitch_execute(XNapiTool *pxt, DataPtr data)
{
    void *data_ptr = data;
    setNtpSwitch_value_struct *vio = static_cast<setNtpSwitch_value_struct *>(data_ptr);
    
    setNtpSwitch(vio->in0, vio->outErrCode);
}

void setNtpSwitch_complete(XNapiTool *pxt, DataPtr data)
{
    void *data_ptr = data;
    setNtpSwitch_value_struct *vio = static_cast<setNtpSwitch_value_struct *>(data_ptr);
    napi_value result = nullptr;
    result = pxt->UndefinedValue();
    napi_value errCodeResult = nullptr;
    napi_value napiErrCode = nullptr;
    napiErrCode = NUMBER_C_2_JS(pxt, vio->outErrCode);
    pxt->SetValueProperty(errCodeResult, "code", napiErrCode);
    {
        napi_value args[XNapiTool::TWO] = {errCodeResult, result};
        pxt->FinishAsync(XNapiTool::TWO, args);
    }
    
    delete vio;
}

napi_value setNtpSwitch_middle(napi_env env, napi_callback_info info)
{
    XNapiTool *pxt = std::make_unique<XNapiTool>(env, info).release();
    if (pxt->IsFailed()) {
        napi_value err = pxt->GetError();
        delete pxt;
        return err;
    }
    
    struct setNtpSwitch_value_struct *vio = new setNtpSwitch_value_struct();
        pxt->SwapJs2CUtf8(pxt->GetArgv(XNapiTool::ZERO), vio->in0);

    napi_value result = pxt->StartAsync(setNtpSwitch_execute, reinterpret_cast<DataPtr>(vio), setNtpSwitch_complete,
    pxt->GetArgc() == XNapiTool::TWO? pxt->GetArgv(XNapiTool::ONE) : nullptr);
    if (pxt->IsFailed()) {
        result = pxt->GetError();
    }
    return result;
}
struct getNtpSwitchState_value_struct {
    uint32_t outErrCode = 0;
    NUMBER_TYPE_1 out;
};

void getNtpSwitchState_execute(XNapiTool *pxt, DataPtr data)
{
    void *data_ptr = data;
    getNtpSwitchState_value_struct *vio = static_cast<getNtpSwitchState_value_struct *>(data_ptr);
    
    getNtpSwitchState(vio->outErrCode, vio->out);
}

void getNtpSwitchState_complete(XNapiTool *pxt, DataPtr data)
{
    void *data_ptr = data;
    getNtpSwitchState_value_struct *vio = static_cast<getNtpSwitchState_value_struct *>(data_ptr);
    napi_value result = nullptr;
    result = NUMBER_C_2_JS(pxt, vio->out);
    napi_value errCodeResult = nullptr;
    napi_value napiErrCode = nullptr;
    napiErrCode = NUMBER_C_2_JS(pxt, vio->outErrCode);
    pxt->SetValueProperty(errCodeResult, "code", napiErrCode);
    {
        napi_value args[XNapiTool::TWO] = {errCodeResult, result};
        pxt->FinishAsync(XNapiTool::TWO, args);
    }
    
    delete vio;
}

napi_value getNtpSwitchState_middle(napi_env env, napi_callback_info info)
{
    XNapiTool *pxt = std::make_unique<XNapiTool>(env, info).release();
    if (pxt->IsFailed()) {
        napi_value err = pxt->GetError();
        delete pxt;
        return err;
    }
    
    struct getNtpSwitchState_value_struct *vio = new getNtpSwitchState_value_struct();
    
    napi_value result = pxt->StartAsync(getNtpSwitchState_execute, reinterpret_cast<DataPtr>(vio), getNtpSwitchState_complete,
    pxt->GetArgc() == XNapiTool::ONE? pxt->GetArgv(XNapiTool::ZERO) : nullptr);
    if (pxt->IsFailed()) {
        result = pxt->GetError();
    }
    return result;
}}
static napi_value init(napi_env env, napi_value exports)
{
    std::shared_ptr<XNapiTool> pxt = std::make_shared<XNapiTool>(env, exports);
        pxt->DefineFunction("setNtpServerUrl", khtime::setNtpServerUrl_middle);
    pxt->DefineFunction("setNtpSwitch", khtime::setNtpSwitch_middle);
    pxt->DefineFunction("getNtpSwitchState", khtime::getNtpSwitchState_middle);

    return exports;
}

static napi_module g_khtime_Module = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = init,
    .nm_modname = "",
    .nm_priv = ((void *)0),
    .reserved = {(void *)0},
};

extern "C" __attribute__((constructor)) void Register_khtime_Module(void)
{
    napi_module_register(&g_khtime_Module);
}

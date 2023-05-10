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
#ifndef IMPL_KHTIME_H
#define IMPL_KHTIME_H

#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <map>
#include <any>

using NUMBER_TYPE_1 = uint32_t;
using NUMBER_TYPE_2 = uint32_t;


namespace khtime {
bool setNtpServerUrl(std::string& url, uint32_t& outErrCode);
bool setNtpSwitch(std::string& switchValue, uint32_t& outErrCode);
bool getNtpSwitchState(uint32_t& outErrCode, NUMBER_TYPE_1& out);
}
#endif // IMPL_KHTIME_H

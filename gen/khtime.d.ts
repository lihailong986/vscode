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

import { AsyncCallback, ErrorCallback } from './basic';

/**
 * Set Ntp.
 * @since 8
 * @syscap SystemCapability.Miscservices.Time
 * @devices phone, tablet, tv, wearable, car
 * @import khTime from '@ohos.khtime';
 */
declare namespace khtime {
    /**
    * set the URL of NTP server.
    * @since 8
    * @param the URL of NTP server.
    * @permission N/A
    */
    function setNtpServerUrl(url: string, callback: AsyncCallback<void>): void;
    function setNtpServerUrl(url: string): Promise<void>;

    /**
    * set the switch of NTP server.
    * @since 8
    * @param the switch status of NTP server is true or false.
    * @permission N/A
    */
    function setNtpSwitch(switchValue: string, callback: AsyncCallback<void>): void;
    function setNtpSwitch(switchValue: string): Promise<void>;

    /**
    * get the switch of NTP server.
    * @since 8
    * @return the switch value of NTP server is true or false.
    * @permission N/A
    */
    function getNtpSwitchState(callback: AsyncCallback<number>): void;
    function getNtpSwitchState(): Promise<number>;
}

export default khtime;

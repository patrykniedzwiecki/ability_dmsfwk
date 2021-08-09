/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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

#include "distributed_sched_proxy.h"
#include "dtbschedmgr_log.h"
#include "ipc_types.h"
#include "parcel_helper.h"
#include "string_ex.h"

using namespace std;
using namespace OHOS::AAFwk;

namespace OHOS {
namespace DistributedSchedule {
namespace {
const std::u16string DMS_PROXY_INTERFACE_TOKEN = u"ohos.distributedschedule.accessToken";
}
int32_t DistributedSchedProxy::StartRemoteAbility(const OHOS::AAFwk::Want& userWant,
    OHOS::AAFwk::Want& innerWant, int32_t requestCode)
{
    sptr<IRemoteObject> remote = Remote();
    if (remote == nullptr) {
        return ERR_NULL_OBJECT;
    }
    MessageParcel data;
    if(!data.WriteInterfaceToken(DMS_PROXY_INTERFACE_TOKEN)) {
        return ERR_FLATTEN_OBJECT;
    }
    PARCEL_WRITE_HELPER(data, Parcelable, &userWant);
    PARCEL_WRITE_HELPER(data, Parcelable, &innerWant);
    PARCEL_WRITE_HELPER(data, Int32, requestCode);
    MessageParcel reply;
    PARCEL_TRANSACT_SYNC_RET_INT(remote, START_REMOTE_ABILITY, data, reply);
}

int32_t DistributedSchedProxy::StartAbilityFromRemote(const OHOS::AAFwk::Want& userWant,
    OHOS::AAFwk::Want& innerWant, int32_t requestCode)
{
    sptr<IRemoteObject> remote = Remote();
    if (remote == nullptr) {
        return ERR_NULL_OBJECT;
    }
    MessageParcel data;
    if(!data.WriteInterfaceToken(DMS_PROXY_INTERFACE_TOKEN)) {
        return ERR_FLATTEN_OBJECT;
    }
    PARCEL_WRITE_HELPER(data, Parcelable, &userWant);
    PARCEL_WRITE_HELPER(data, Parcelable, &innerWant);
    PARCEL_WRITE_HELPER(data, Int32, requestCode);
    MessageParcel reply;
    PARCEL_TRANSACT_SYNC_RET_INT(remote, START_ABILITY_FROM_REMOTE, data, reply);
}
} // namespace DistributedSchedule
} // namespace OHOS

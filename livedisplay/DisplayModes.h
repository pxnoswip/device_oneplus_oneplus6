/*
 * Copyright (C) 2019 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef VENDOR_LINEAGE_LIVEDISPLAY_V2_0_DISPLAYMODES_H
#define VENDOR_LINEAGE_LIVEDISPLAY_V2_0_DISPLAYMODES_H

#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <vendor/lineage/livedisplay/2.0/IDisplayModes.h>
#include <map>

namespace vendor {
namespace lineage {
namespace livedisplay {
namespace V2_0 {
namespace implementation {

using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

class DisplayModes : public IDisplayModes {
  public:
    DisplayModes();

    static bool isSupported();

    // Methods from ::vendor::lineage::livedisplay::V2_0::IDisplayModes follow.
    Return<void> getDisplayModes(getDisplayModes_cb resultCb) override;
    Return<void> getCurrentDisplayMode(getCurrentDisplayMode_cb resultCb) override;
    Return<void> getDefaultDisplayMode(getDefaultDisplayMode_cb ResultCb) override;
    Return<bool> setDisplayMode(int32_t modeID, bool makeDefault) override;

  private:
    struct ModeInfo {
        const char* name;
        const char* value;
    };
    static const std::map<int32_t, ModeInfo> kModeMap;
    int32_t mDefaultModeId;
};

}  // namespace implementation
}  // namespace V2_0
}  // namespace livedisplay
}  // namespace lineage
}  // namespace vendor

#endif  // VENDOR_LINEAGE_LIVEDISPLAY_V2_0_DISPLAYMODES_H

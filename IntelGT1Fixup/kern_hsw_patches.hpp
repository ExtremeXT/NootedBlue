//  Copyright © 2023 ChefKiss Inc. Licensed under the Thou Shalt Not Profit License version 1.0. See LICENSE for
//  details.

#ifndef kern_hsw_patches_hpp
#define kern_hsw_patches_hpp
#include <Headers/kern_user.hpp>
#include <Headers/kern_util.hpp>
/**
 * `Haswell Kext and Bundle paths`
 */

static const char kHSWMTLDriverPath[] = "/System/Library/Extensions/AppleIntelHD5000GraphicsMTLDriver.bundle/Contents/"
                                        "MacOS/AppleIntelHD5000GraphicsMTLDriver";
static const char kHSWVADriverPath[] = "/System/Library/Extensions/AppleIntelHD5000GraphicsVADriver.bundle/Contents/"
                                       "MacOS/AppleIntelHD5000GraphicsVADriver";

/**
 * `Haswell Patch Set for macOS Sierra`
 *  https://www.insanelymac.com/forum/topic/337685-intel-hd-graphics-haswell-gt1-qeci-1012/
 *  and also confirmed to lineup with the HSWGT1Fixup binary
 */

/** NOTE: We'll only be supporting Haswell on macOS Sierra+, and even then we might drop Sierra support due to the fact
 * that Xcode 14.3+ allegedly breaks compilation with older `MACOSX_DEPLOYMENT_TARGET` values, for the rest of the iGPUs
 * we'll support macOS Mojave+ due to how complex these drivers are to patch, if an effective patching method does
 * become a pattern further Legacy OS support may be provided, this is not guaranteed however. */

static const uint8_t kHSWHWProbeSierra1Original[] = {0x83, 0xF8, 0x04, 0x74, 0x12, 0x83, 0xF8, 0x02, 0x75, 0x3D};
static const uint8_t kHSWHWProbeSierra1Patched[] = {0x83, 0xF8, 0x04, 0x90, 0x90, 0x83, 0xF8, 0x02, 0x90, 0x90};

static const uint8_t kHSWHWProbeSierra2Original[] = {0x3D, 0x86, 0x80, 0x26, 0x0D, 0x74, 0x20};
static const uint8_t kHSWHWProbeSierra2Patched[] = {0x3D, 0x86, 0x80, 0x26, 0x0D, 0xEB, 0x20};

static const uint8_t kHSWHWProbeSierra3Original[] = {0x75, 0x59, 0x41, 0xC7, 0x86, 0x0C, 0x10, 0x00, 0x00, 0x02, 0x00,
    0x00, 0x00, 0xB8, 0x02, 0x00, 0x00, 0x00};
static const uint8_t kHSWHWProbeSierra3Patched[] = {0x90, 0x90, 0x41, 0xC7, 0x86, 0x0C, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xB8, 0x00, 0x00, 0x00, 0x00};

static const uint8_t kHSWHWProbeSierra4Original[] = {0x41, 0xC7, 0x86, 0x0C, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0xB8, 0x01, 0x00, 0x00, 0x00};
static const uint8_t kHSWHWProbeSierra4Patched[] = {0x41, 0xC7, 0x86, 0x0C, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xB8, 0x00, 0x00, 0x00, 0x00};
/** MTLIGAccelDevice::initializeDevice:sharedRef */
static const uint8_t kHSWMTLinitializeDeviceSierra1Original[] = {0xB9, 0x00, 0x01, 0x00, 0x00, 0x3D, 0x85, 0x80, 0x22,
    0x0D};
static const uint8_t kHSWMTLinitializeDeviceSierra1Patched[] = {0xB9, 0x40, 0x00, 0x00, 0x00, 0x3D, 0x85, 0x80, 0x22,
    0x0D};

static const uint8_t kHSWMTLinitializeDeviceSierra2Original[] = {0x0F, 0x94, 0xC1, 0x0F, 0xB6, 0xC9, 0xC1, 0xE1, 0x07};
static const uint8_t kHSWMTLinitializeDeviceSierra2Patched[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90};

static const uint8_t kHSWVASierra1Original[] = {0xEB, 0x4A, 0x81, 0xF9, 0x86, 0x80, 0x12, 0x04};
static const uint8_t kHSWVASierra1Patched[] = {0x90, 0x90, 0x81, 0xF9, 0x86, 0x80, 0x12, 0x04};

static const uint8_t kHSWVASierra2Original[] = {0x75, 0x3A, 0xC7, 0x83, 0x54, 0x98, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0xC7, 0x83, 0x5C, 0x98, 0x00, 0x00, 0x18, 0x01, 0x00, 0x00};
static const uint8_t kHSWVASierra2Patched[] = {0x75, 0x3A, 0xC7, 0x83, 0x54, 0x98, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0xC7, 0x83, 0x5C, 0x98, 0x00, 0x00, 0x18, 0x01, 0x00, 0x00};

static const uint8_t kHSWVASierra3Original[] = {0xC7, 0x83, 0x54, 0x98, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xC7, 0x83,
    0x5C, 0x98, 0x00, 0x00, 0x8C, 0x00, 0x00, 0x00};
static const uint8_t kHSWVASierra3Patched[] = {0xC7, 0x83, 0x54, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC7, 0x83,
    0x5C, 0x98, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00};

static const uint8_t kHSWVASierra4Original[] = {0x75, 0x3A, 0xC7, 0x86, 0x60, 0x4D, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0xC7, 0x86, 0x68, 0x4D, 0x00, 0x00, 0x18, 0x01, 0x00, 0x00};
static const uint8_t kHSWVASierra4Patched[] = {0x90, 0x90, 0xC7, 0x86, 0x60, 0x4D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC7, 0x86, 0x68, 0x4D, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00};

static const uint8_t kHSWVASierra5Original[] = {0xC7, 0x86, 0x60, 0x4D, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xC7, 0x86,
    0x68, 0x4D, 0x00, 0x00, 0x8C, 0x00, 0x00};
static const uint8_t kHSWVASierra5Patched[] = {0xC7, 0x86, 0x60, 0x4D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC7, 0x86,
    0x68, 0x4D, 0x00, 0x00, 0x46, 0x00, 0x00};

/**
 * `Haswell Patch Set for High Sierra`
 *  Found within a HSWGT1Fixup binary through Ghidra.
 *  You can find a copy inside the Assets folder.
 *  Binary obtained from:
 * https://osxinfo.net/konu/intel-hd-graphics-haswell-gt1-icin-grafik-hizlandirma-yamasi-sierra-mojave.7785/
 */

static const uint8_t kHSWHWProbeHS1Original[] = {0x74, 0x15, 0x0F, 0xB7, 0xC0, 0x83, 0xF8, 0x02, 0x75, 0x3D};
static const uint8_t kHSWHWProbeHS1Patched[] = {0x90, 0x90, 0x0F, 0xB7, 0xC0, 0x83, 0xF8, 0x02, 0x90, 0x90};
/** patches 2 & 3 to be worked on*/
static const uint8_t kHSWHWProbeHS2Original[] = {0x7E, 0x24, 0x3D, 0x86, 0x80, 0x2E, 0x0A};
static const uint8_t kHSWHWProbeHS2Patched[] = {0xEB, 0x24, 0x3D, 0x86, 0x80, 0x2E, 0x0A};

static const uint8_t kHSWHWProbeHS3Original[] = {0x3D, 0x86, 0x80, 0x12, 0x04, 0x74, 0x19};
static const uint8_t kHSWHWProbeHS3Patched[] = {0x3D, 0x86, 0x80, 0x12, 0x04, 0xEB, 0x19};

static const uint8_t kHSWHWProbeHS4Original[] = {0x41, 0xC7, 0x86, 0xBC, 0x0F, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xB8,
    0x01, 0x00, 0x00, 0x00};
static const uint8_t kHSWHWProbeHS4Patched[] = {0x41, 0xC7, 0x86, 0xBC, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB8,
    0x00, 0x00, 0x00, 0x00};

static const uint8_t kHSWMTLinitializeDeviceHS1Original[] = {0x0F, 0x85, 0x1B, 0x01, 0x00, 0x00};
static const uint8_t kHSWMTLinitializeDeviceHS1Patched[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};

static const uint8_t kHSWMTLinitializeDeviceHS2Original[] = {0xB8, 0x00, 0x01, 0x00, 0x00, 0x0B, 0x85, 0xA8, 0xF0, 0xFF,
    0xFF};
static const uint8_t kHSWMTLinitializeDeviceHS2Patched[] = {0xB8, 0x40, 0x00, 0x00, 0x00, 0x0B, 0x85, 0xA8, 0xF0, 0xFF,
    0xFF};

static const uint8_t kHSWMTLinitializeDeviceHS3Original[] = {0xB8, 0x80, 0x00, 0x00, 0x00, 0x0B, 0x85, 0xA8, 0xF0, 0xFF,
    0xFF};
static const uint8_t kHSWMTLinitializeDeviceHS3Patched[] = {0xB8, 0x40, 0x00, 0x00, 0x00, 0x0B, 0x85, 0xA8, 0xF0, 0xFF,
    0xFF};

static const uint8_t kHSWVAHS1Original[] = {0x81, 0xF9, 0x86, 0x80, 0x22, 0x0D, 0x74, 0x12, 0xEB, 0x4A};
static const uint8_t kHSWVAHS1Patched[] = {0x81, 0xF9, 0x86, 0x80, 0x22, 0x0D, 0x74, 0x12, 0x90, 0x90};

static const uint8_t kHSWVAHS2Original[] = {0x75, 0x3A, 0xC7, 0x83, 0x54, 0x98, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0xC7, 0x83, 0x5C, 0x98, 0x00, 0x00, 0x18, 0x01, 0x00, 0x00};
static const uint8_t kHSWVAHS2Patched[] = {0x90, 0x90, 0xC7, 0x83, 0x54, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC7,
    0x83, 0x5C, 0x98, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00};

static const uint8_t kHSWVAHS3Original[] = {0xC7, 0x83, 0x54, 0x98, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xC7, 0x83,
    0x5C, 0x98, 0x00, 0x00, 0x8C, 0x00, 0x00, 0x00};
static const uint8_t kHSWVAHS3Patched[] = {0xC7, 0x83, 0x54, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC7, 0x83, 0x5C,
    0x98, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00};

static const uint8_t kHSWVAHS4Original[] = {0x75, 0x3A, 0xC7, 0x86, 0x60, 0x4D, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0xC7, 0x86, 0x68, 0x4D, 0x00, 0x00, 0x18, 0x01, 0x00};
static const uint8_t kHSWVAHS4Patched[] = {0x90, 0x90, 0xC7, 0x86, 0x60, 0x4d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC7,
    0x86, 0x68, 0x4D, 0x00, 0x00, 0x46, 0x00, 0x00};

static const uint8_t kHSWVAHS5Original[] = {0xC7, 0x86, 0x60, 0x4D, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xC7, 0x86,
    0x68, 0x4D, 0x00, 0x00, 0x8c, 0x00, 0x00, 0x00};
static const uint8_t kHSWVAHS5Patched[] = {0xC7, 0x86, 0x60, 0x4D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC7, 0x86, 0x68,
    0x4D, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00};

/**
 * `Haswell Patch Set for Mojave`
 *  Found within a HSWGT1Fixup binary through Ghidra.
 *  Reported to be working through to 10.14.3? untested for recent versions.
 *  You can find a copy in the Assets folder
 *  Binary obtained from:
 * https://osxinfo.net/konu/intel-hd-graphics-haswell-gt1-icin-grafik-hizlandirma-yamasi-sierra-mojave.7785/
 */
/** ? ends up being used in the final version of HSWGT1Fixup, which is weird, because this does absolutely nothing. */
static const uint8_t kHSWHWMojave1Original[] = {0x0F, 0xA2, 0xBE, 0x01, 0x00, 0x00, 0x00};
static const uint8_t kHSWHWMojave1Patched[] = {0x0F, 0xA2, 0xBE, 0x01, 0x00, 0x00, 0x00};

static const uint8_t kHSWHWMojave2Original[] = {0x74, 0x0D, 0x0F, 0xB7, 0xC0, 0x83, 0xF8, 0x04};
static const uint8_t kHSWHWMojave2Patched[] = {0xEB, 0x0D, 0x0F, 0xB7, 0xC0, 0x83, 0xF8, 0x04};

static const uint8_t kHSWHWMojave3Original[] = {0x75, 0x2F, 0xBE, 0x02, 0x00, 0x00, 0x00, 0xB8, 0x02, 0x00, 0x00, 0x00};
static const uint8_t kHSWHWMojave3Patched[] = {0x90, 0x90, 0xBE, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x00, 0x00, 0x00, 0x00};

static const uint8_t kHSWHWMojave4Original[] = {0xEB, 0x3C, 0xB8, 0x01, 0x00, 0x00, 0x00};
static const uint8_t kHSWHWMojave4Patched[] = {0xEB, 0x3C, 0xB8, 0x00, 0x00, 0x00, 0x00};

static const uint8_t kHSWVAMojave1Original[] = {0xEB, 0x4A, 0x81, 0xF9, 0x86, 0x80, 0x12, 0x04};
static const uint8_t kHSWVAMojave1Patched[] = {0x90, 0x90, 0x81, 0xF9, 0x86, 0x80, 0x12, 0x04};

static const uint8_t kHSWVAMojave2Original[] = {0x75, 0x3A, 0xC7, 0x83, 0x54, 0x98, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0xC7, 0x83, 0x5C, 0x98, 0x00, 0x00, 0x18, 0x18, 0x01, 0x00, 0x00};
static const uint8_t kHSWVAMojave2Patched[] = {0x75, 0x3A, 0xC7, 0x83, 0x54, 0x98, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0xC7, 0x83, 0x5C, 0x98, 0x00, 0x00, 0x18, 0x18, 0x01, 0x00, 0x00};

/**
 * `Haswell Patch Set for Catalina (EXPERIMENTAL)`
 *  These patches are definitely broken, don't trust them at all to work
 */

static const uint8_t kHSWProbeCatalina1Original[] = {0x66, 0x83, 0xF8, 0x02, 0x74, 0x0B, 0x66, 0x83, 0xF8, 0x04, 0x75,
    0x7F};
static const uint8_t kHSWProbeCatalina1Patched[] = {0x66, 0x83, 0xF8, 0x02, 0x90, 0x90, 0x66, 0x83, 0xF8, 0x02, 0x90,
    0x90};

static const uint8_t kHSWProbeCatalina2Original[] = {0x75, 0x59, 0x41, 0xC7, 0x86, 0x0C, 0x10, 0x00, 0x00, 0x02, 0x00,
    0x00, 0x00, 0xB8, 0x02, 0x00, 0x00, 0x00};
static const uint8_t kHSWProbeCatalina2Patched[] = {0x90, 0x90, 0x41, 0xC7, 0x86, 0x0C, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xB8, 0x00, 0x00, 0x00, 0x00};

/** Patch obsolete? Investigation required.*/
// static const uint8_t kHSWProbeCatalina3Original[] = {0x41, 0xC7, 0x86, 0xBC, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00,
// 0x00, 0xB8, 0x01, 0x00, 0x00, 0x00}; static const uint8_t kHSWProbeCatalina3Patched[] = {0x41, 0xC7, 0x86, 0xBC,
// 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE9, 0x29, 0xFF, 0xFF, 0xFF};

static const uint8_t kHSWProbeCatalina4Original[] = {0xB8, 0x01, 0x00, 0x00, 0x00, 0x81, 0xFE, 0x86, 0x80, 0x12, 0x04,
    0x74};
static const uint8_t kHSWProbeCatalina4Patched[] = {0xB8, 0x00, 0x00, 0x00, 0x00, 0x81, 0xFE, 0x86, 0x80, 0x12, 0x04,
    0x74};
/** Due to changes in the kext, Patch 4 had to be split up into two patches in order to avoid it being too long */

/** Based off of WhateverGreen code*/

enum : uint32_t {
    HSWMTL = 1,
    HSWVA = 2,
    HSWMTLSierra = 3,
    HSWVASierra = 4,
    HSWMTLHS = 5,
    HSWVAHS = 6,
    HSWMTLMojave = 7,
    HSWVAMojave = 8,
    HSWMTLCatalina = 9,
    HSWVACatalina = 10,
};

static UserPatcher::BinaryModPatch kHSWMTLSierra1 {CPU_TYPE_X86_64, 0, kHSWMTLinitializeDeviceSierra1Original,
    kHSWMTLinitializeDeviceSierra1Patched, arrsize(kHSWMTLinitializeDeviceSierra1Original), 0, 1,
    UserPatcher::FileSegment::SegmentTextText, HSWMTLSierra};

static UserPatcher::BinaryModPatch kHSWMTLSierra2 {CPU_TYPE_X86_64, 0, kHSWMTLinitializeDeviceSierra2Original,
    kHSWMTLinitializeDeviceSierra2Patched, arrsize(kHSWMTLinitializeDeviceSierra2Original), 0, 1,
    UserPatcher::FileSegment::SegmentTextText, HSWMTLSierra};

static UserPatcher::BinaryModPatch kHSWVASierra1 {CPU_TYPE_X86_64, 0, kHSWVASierra1Original, kHSWVASierra1Patched,
    arrsize(kHSWVASierra1Original), 0, 1, UserPatcher::FileSegment::SegmentTextText, HSWVASierra};

static UserPatcher::BinaryModPatch kHSWVASierra2 {CPU_TYPE_X86_64, 0, kHSWVASierra2Original, kHSWVASierra2Patched,
    arrsize(kHSWVASierra2Original), 0, 1, UserPatcher::FileSegment::SegmentTextText, HSWVASierra};

static UserPatcher::BinaryModPatch kHSWVASierra3 {CPU_TYPE_X86_64, 0, kHSWVASierra3Original, kHSWVASierra3Patched,
    arrsize(kHSWVASierra3Original), 0, 1, UserPatcher::FileSegment::SegmentTextText, HSWVASierra};

static UserPatcher::BinaryModPatch kHSWVASierra4 {CPU_TYPE_X86_64, 0, kHSWVASierra4Original, kHSWVASierra4Patched,
    arrsize(kHSWVASierra4Original), 0, 1, UserPatcher::FileSegment::SegmentTextText, HSWVASierra};

static UserPatcher::BinaryModPatch kHSWVASierra5 {CPU_TYPE_X86_64, 0, kHSWVASierra5Original, kHSWVASierra5Patched,
    arrsize(kHSWVASierra5Original), 0, 1, UserPatcher::FileSegment::SegmentTextText, HSWVASierra};

static UserPatcher::BinaryModPatch kHSWMTLHS1 {CPU_TYPE_X86_64, 0, kHSWMTLinitializeDeviceHS1Original,
    kHSWMTLinitializeDeviceHS1Patched, arrsize(kHSWMTLinitializeDeviceHS1Original), 0, 1,
    UserPatcher::FileSegment::SegmentTextText, HSWMTLHS};

static UserPatcher::BinaryModPatch kHSWMTLHS2 {CPU_TYPE_X86_64, 0, kHSWMTLinitializeDeviceHS2Original,
    kHSWMTLinitializeDeviceHS2Patched, arrsize(kHSWMTLinitializeDeviceHS2Original), 0, 1,
    UserPatcher::FileSegment::SegmentTextText, HSWMTLHS};

static UserPatcher::BinaryModPatch kHSWMTLHS3 {CPU_TYPE_X86_64, 0, kHSWMTLinitializeDeviceHS2Original,
    kHSWMTLinitializeDeviceHS2Patched, arrsize(kHSWMTLinitializeDeviceHS2Original), 0, 1,
    UserPatcher::FileSegment::SegmentTextText, HSWMTLHS};

static UserPatcher::BinaryModPatch kHSWVAHS1 {CPU_TYPE_X86_64, 0, kHSWVAHS1Original, kHSWVAHS1Patched,
    arrsize(kHSWVAHS1Original), 0, 1, UserPatcher::FileSegment::SegmentTextText, HSWVAHS};

static UserPatcher::BinaryModPatch kHSWVAHS2 {CPU_TYPE_X86_64, 0, kHSWVAHS2Original, kHSWVAHS2Patched,
    arrsize(kHSWVAHS2Original), 0, 1, UserPatcher::FileSegment::SegmentTextText, HSWVAHS};

static UserPatcher::BinaryModPatch kHSWVAHS3 {CPU_TYPE_X86_64, 0, kHSWVAHS3Original, kHSWVAHS3Patched,
    arrsize(kHSWVAHS3Original), 0, 1, UserPatcher::FileSegment::SegmentTextText, HSWVAHS};

static UserPatcher::BinaryModPatch kHSWVAHS4 {CPU_TYPE_X86_64, 0, kHSWVAHS4Original, kHSWVAHS4Patched,
    arrsize(kHSWVAHS4Original), 0, 1, UserPatcher::FileSegment::SegmentTextText, HSWVAHS};

static UserPatcher::BinaryModPatch kHSWVAHS5 {CPU_TYPE_X86_64, 0, kHSWVAHS5Original, kHSWVAHS5Patched,
    arrsize(kHSWVAHS5Original), 0, 1, UserPatcher::FileSegment::SegmentTextText, HSWVAHS};

static uint32_t kHSWMTLLength = sizeof("/System/Library/Extensions/AppleIntelHD5000GraphicsMTLDriver.bundle/Contents/"
                                       "MacOS/AppleIntelHD5000GraphicsMTLDriver") -
                                1;
static uint32_t kHSWVALength = sizeof("/System/Library/Extensions/AppleIntelHD5000GraphicsVADriver.bundle/Contents/"
                                      "MacOS/AppleIntelHD5000GraphicsVADriver") -
                               1;

static UserPatcher::ProcInfo kHSWMTLProcInfo {kHSWMTLDriverPath, kHSWMTLLength, HSWMTL};
static UserPatcher::ProcInfo kHSWVAProcInfo {kHSWVADriverPath, kHSWVALength, HSWVA};

/** HSWGT1Fixup managed to cram all the patches into a single pointer/whatever, for now we'll leave this as is */

static UserPatcher::BinaryModInfo kBinModInfoHSWMTLSierra1 {kHSWMTLDriverPath, &kHSWMTLSierra1, 1};
static UserPatcher::BinaryModInfo kBinModInfoHSWMTLSierra2 {kHSWMTLDriverPath, &kHSWMTLSierra2, 1};
static UserPatcher::BinaryModInfo kBinModInfoHSWVASierra1 {kHSWVADriverPath, &kHSWVASierra1, 1};
static UserPatcher::BinaryModInfo kBinModInfoHSWVASierra2 {kHSWVADriverPath, &kHSWVASierra2, 1};
static UserPatcher::BinaryModInfo kBinModInfoHSWVASierra3 {kHSWVADriverPath, &kHSWVASierra3, 1};
static UserPatcher::BinaryModInfo kBinModInfoHSWVASierra4 {kHSWVADriverPath, &kHSWVASierra4, 1};
static UserPatcher::BinaryModInfo kBinModInfoHSWVASierra5 {kHSWVADriverPath, &kHSWVASierra5, 1};

static UserPatcher::BinaryModInfo kBinModInfoHSWMTLHS1 {kHSWMTLDriverPath, &kHSWMTLHS1, 1};
static UserPatcher::BinaryModInfo kBinModInfoHSWMTLHS2 {kHSWMTLDriverPath, &kHSWMTLHS2, 1};
static UserPatcher::BinaryModInfo kBinModInfoHSWMTLHS3 {kHSWMTLDriverPath, &kHSWMTLHS3, 1};
static UserPatcher::BinaryModInfo kBinModInfoHSWVAHS1 {kHSWVADriverPath, &kHSWVAHS1, 1};
static UserPatcher::BinaryModInfo kBinModInfoHSWVAHS2 {kHSWVADriverPath, &kHSWVAHS2, 1};
static UserPatcher::BinaryModInfo kBinModInfoHSWVAHS3 {kHSWVADriverPath, &kHSWVAHS3, 1};
static UserPatcher::BinaryModInfo kBinModInfoHSWVAHS4 {kHSWVADriverPath, &kHSWVAHS4, 1};
static UserPatcher::BinaryModInfo kBinModInfoHSWVAHS5 {kHSWVADriverPath, &kHSWVAHS5, 1};

static_assert(arrsize(kHSWProbeCatalina1Original) == arrsize(kHSWProbeCatalina1Patched));
static_assert(arrsize(kHSWProbeCatalina2Original) == arrsize(kHSWProbeCatalina2Patched));
// static_assert(arrsize(kHSWProbeCatalina3Original) == arrsize(kHSWProbeCatalina3Patched));
static_assert(arrsize(kHSWProbeCatalina4Original) == arrsize(kHSWProbeCatalina4Patched));

#endif /* kern_hsw_patches_hpp */
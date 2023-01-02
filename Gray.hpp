#pragma once
#ifndef AE_UTILS_GRAY_HPP
#define AE_UTILS_GRAY_HPP

#include <AE_Effect.h>

namespace REC709 {
constexpr float kKR = 0.2126f;
constexpr float kKG = 0.7152f;
constexpr float kKB = 0.0722f;
constexpr PF_Pixel32 ToGray(const PF_Pixel32 &in) noexcept {
    float res = in.red * kKR + in.green * kKG + in.blue * kKB;
    return PF_Pixel32{in.alpha, res, res, res};
}
}  // namespace REC709

namespace REC2020 {
constexpr float kKR = 0.2627f;
constexpr float kKG = 0.678f;
constexpr float kKB = 0.0593f;
constexpr PF_Pixel32 ToGray(const PF_Pixel32 &in) noexcept {
    float res = in.red * kKR + in.green * kKG + in.blue * kKB;
    return PF_Pixel32{in.alpha, res, res, res};
}
}  // namespace REC2020

#endif
#pragma once
#ifndef AE_UTILS_GRAY_HPP
#define AE_UTILS_GRAY_HPP

#include <AE_Effect.h>

namespace Gray {

namespace Generic {
constexpr float KR = 0.298912f;
constexpr float KG = 0.586611f;
constexpr float KB = 0.114478f;
constexpr PF_Pixel32 ToGray(const PF_Pixel32 &in) noexcept {
    float res = in.red * KR + in.green * KG + in.blue * KB;
    return PF_Pixel32{in.alpha, res, res, res};
}
}  // namespace Generic

namespace REC709 {
constexpr float KR = 0.2126f;
constexpr float KG = 0.7152f;
constexpr float KB = 0.0722f;
constexpr PF_Pixel32 ToGray(const PF_Pixel32 &in) noexcept {
    float res = in.red * KR + in.green * KG + in.blue * KB;
    return PF_Pixel32{in.alpha, res, res, res};
}
}  // namespace REC709

namespace REC2020 {
constexpr float KR = 0.2627f;
constexpr float KG = 0.678f;
constexpr float KB = 0.0593f;
constexpr PF_Pixel32 ToGray(const PF_Pixel32 &in) noexcept {
    float res = in.red * KR + in.green * KG + in.blue * KB;
    return PF_Pixel32{in.alpha, res, res, res};
}
}  // namespace REC2020

}  // namespace Gray

#endif
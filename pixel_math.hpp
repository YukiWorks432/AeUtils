#pragma once
#ifndef AE_UTILS_PIXEL_MATH_HPP
#define AE_UTILS_PIXEL_MATH_HPP

#include <AE_Effect.h>

#include <algorithm>
#include <cmath>
#include <type_traits>

namespace pixel_math {

#define PIXEL_MATH_FUNC(func)                                     \
    inline PF_Pixel32 func(const PF_Pixel32 &x) noexcept {        \
        return PF_Pixel32{std::func(x.alpha), std::func(x.red),   \
                          std::func(x.green), std::func(x.blue)}; \
    }

#define PIXEL_MATH_FUNC2(func)                                              \
    inline PF_Pixel32 func(const PF_Pixel32 &x, const float n) noexcept {   \
        return PF_Pixel32{std::func(x.alpha, n), std::func(x.red, n),       \
                          std::func(x.green, n), std::func(x.blue, n)};     \
    }                                                                       \
    inline PF_Pixel32 func(const PF_Pixel32 &x, const double n) noexcept {  \
        return PF_Pixel32{                                                  \
            static_cast<float>(std::func(static_cast<double>(x.alpha), n)), \
            static_cast<float>(std::func(static_cast<double>(x.red), n)),   \
            static_cast<float>(std::func(static_cast<double>(x.green), n)), \
            static_cast<float>(std::func(static_cast<double>(x.blue), n))}; \
    }

#define PIXEL_MATH_FUNC3(func)                                        \
    template <typename T, std::enable_if_t<std::is_arithmetic_v<T>,   \
                                           std::nullptr_t> = nullptr> \
    inline PF_Pixel32 func(const PF_Pixel32 &x, const T a,            \
                           const T b) noexcept {                      \
        return PF_Pixel32{                                            \
            std::func(x.alpha, a, b),                                 \
            std::func(x.red, a, b),                                   \
            std::func(x.green, a, b),                                 \
            std::func(x.blue, a, b),                                  \
        };                                                            \
    }

PIXEL_MATH_FUNC(exp);
PIXEL_MATH_FUNC(exp2);
PIXEL_MATH_FUNC(expm1);
PIXEL_MATH_FUNC(log);
PIXEL_MATH_FUNC(log10);
PIXEL_MATH_FUNC(log1p);
PIXEL_MATH_FUNC(log2);
PIXEL_MATH_FUNC2(pow);
PIXEL_MATH_FUNC(sqrt);
PIXEL_MATH_FUNC(cbrt);
PIXEL_MATH_FUNC2(hypot);
PIXEL_MATH_FUNC(abs);
PIXEL_MATH_FUNC(fabs);
PIXEL_MATH_FUNC(erf);
PIXEL_MATH_FUNC(erfc);
PIXEL_MATH_FUNC(tgamma);
PIXEL_MATH_FUNC(lgamma);
PIXEL_MATH_FUNC(ceil);
PIXEL_MATH_FUNC(floor);
PIXEL_MATH_FUNC(trunc);
PIXEL_MATH_FUNC(round);
PIXEL_MATH_FUNC(nearbyint);
PIXEL_MATH_FUNC(rint);
PIXEL_MATH_FUNC2(fmod);
PIXEL_MATH_FUNC2(remainder);
PIXEL_MATH_FUNC2(fmax);
PIXEL_MATH_FUNC2(fmin);
PIXEL_MATH_FUNC2(fdim);
PIXEL_MATH_FUNC3(clamp);

inline float accumulate(const PF_Pixel32 &x) noexcept {
    return x.alpha + x.red + x.green + x.blue;
}

template <typename To, typename From>
inline To saturation_cast(const From val) noexcept {
    if constexpr (std::is_same_v<From, uint8_t>) {
        return static_cast<To>(std::clamp(val, (uint8_t)0, (uint8_t)255));
    }
    if constexpr (std::is_same_v<From, uint16_t>) {
        return static_cast<To>(
            std::clamp(val, (uint16_t)0, (uint16_t)SHRT_MAX));
    }
    if constexpr (std::is_same_v<From, float>) {
        return static_cast<To>(std::clamp(val, (float)0, (float)1));
    }
}

}  // namespace pixel_math

#endif
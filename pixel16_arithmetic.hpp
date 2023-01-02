#pragma once
#ifndef PIXEL16_ARITHMETIC_HPP
#define PIXEL16_ARITHMETIC_HPP

#include <AE_Effect.h>

#include <type_traits>

#if _MSVC_LANG < 202002L

template <typename T>
inline PF_Pixel16 operator+(const PF_Pixel16 &src, const T x) noexcept {
    static_assert(std::is_integral_v<T>);
    return PF_Pixel16{static_cast<A_u_short>(src.alpha + x),
                      static_cast<A_u_short>(src.red + x),
                      static_cast<A_u_short>(src.green + x),
                      static_cast<A_u_short>(src.blue + x)};
}
template <typename T>
inline PF_Pixel16 operator-(const PF_Pixel16 &src, const T x) noexcept {
    static_assert(std::is_integral_v<T>);
    return PF_Pixel16{static_cast<A_u_short>(src.alpha - x),
                      static_cast<A_u_short>(src.red - x),
                      static_cast<A_u_short>(src.green - x),
                      static_cast<A_u_short>(src.blue - x)};
}
template <typename T>
inline PF_Pixel16 operator*(const PF_Pixel16 &src, const T x) noexcept {
    static_assert(std::is_integral_v<T>);
    return PF_Pixel16{static_cast<A_u_short>(src.alpha * x),
                      static_cast<A_u_short>(src.red * x),
                      static_cast<A_u_short>(src.green * x),
                      static_cast<A_u_short>(src.blue * x)};
}
template <typename T>
inline PF_Pixel16 operator/(const PF_Pixel16 &src, const T x) noexcept {
    static_assert(std::is_integral_v<T>);
    return PF_Pixel16{static_cast<A_u_short>(src.alpha / x),
                      static_cast<A_u_short>(src.red / x),
                      static_cast<A_u_short>(src.green / x),
                      static_cast<A_u_short>(src.blue / x)};
}
template <typename T>
inline PF_Pixel16 operator+(const T x, const PF_Pixel16 &src) noexcept {
    static_assert(std::is_integral_v<T>);
    return PF_Pixel16{static_cast<A_u_short>(x + src.alpha),
                      static_cast<A_u_short>(x + src.red),
                      static_cast<A_u_short>(x + src.green),
                      static_cast<A_u_short>(x + src.blue)};
}
template <typename T>
inline PF_Pixel16 operator-(const T x, const PF_Pixel16 &src) noexcept {
    static_assert(std::is_integral_v<T>);
    return PF_Pixel16{static_cast<A_u_short>(x - src.alpha),
                      static_cast<A_u_short>(x - src.red),
                      static_cast<A_u_short>(x - src.green),
                      static_cast<A_u_short>(x - src.blue)};
}
template <typename T>
inline PF_Pixel16 operator*(const T x, const PF_Pixel16 &src) noexcept {
    static_assert(std::is_integral_v<T>);
    return PF_Pixel16{static_cast<A_u_short>(x * src.alpha),
                      static_cast<A_u_short>(x * src.red),
                      static_cast<A_u_short>(x * src.green),
                      static_cast<A_u_short>(x * src.blue)};
}
template <typename T>
inline PF_Pixel16 operator/(const T x, const PF_Pixel16 &src) noexcept {
    static_assert(std::is_integral_v<T>);
    return PF_Pixel16{static_cast<A_u_short>(x / src.alpha),
                      static_cast<A_u_short>(x / src.red),
                      static_cast<A_u_short>(x / src.green),
                      static_cast<A_u_short>(x / src.blue)};
}

template <typename T>
inline PF_Pixel32 operator+(const PF_Pixel16 &src, const T x) noexcept {
    static_assert(std::is_floating_point_v<T>);
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha + x),
                      static_cast<A_FpShort>(src.red + x),
                      static_cast<A_FpShort>(src.green + x),
                      static_cast<A_FpShort>(src.blue + x)};
}
template <typename T>
inline PF_Pixel32 operator-(const PF_Pixel16 &src, const T x) noexcept {
    static_assert(std::is_floating_point_v<T>);
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha - x),
                      static_cast<A_FpShort>(src.red - x),
                      static_cast<A_FpShort>(src.green - x),
                      static_cast<A_FpShort>(src.blue - x)};
}
template <typename T>
inline PF_Pixel32 operator*(const PF_Pixel16 &src, const T x) noexcept {
    static_assert(std::is_floating_point_v<T>);
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha * x),
                      static_cast<A_FpShort>(src.red * x),
                      static_cast<A_FpShort>(src.green * x),
                      static_cast<A_FpShort>(src.blue * x)};
}
template <typename T>
inline PF_Pixel32 operator/(const PF_Pixel16 &src, const T x) noexcept {
    static_assert(std::is_floating_point_v<T>);
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha / x),
                      static_cast<A_FpShort>(src.red / x),
                      static_cast<A_FpShort>(src.green / x),
                      static_cast<A_FpShort>(src.blue / x)};
}
template <typename T>
inline PF_Pixel32 operator+(const T x, const PF_Pixel16 &src) noexcept {
    static_assert(std::is_floating_point_v<T>);
    return PF_Pixel32{static_cast<A_FpShort>(x + src.alpha),
                      static_cast<A_FpShort>(x + src.red),
                      static_cast<A_FpShort>(x + src.green),
                      static_cast<A_FpShort>(x + src.blue)};
}
template <typename T>
inline PF_Pixel32 operator-(const T x, const PF_Pixel16 &src) noexcept {
    static_assert(std::is_floating_point_v<T>);
    return PF_Pixel32{static_cast<A_FpShort>(x - src.alpha),
                      static_cast<A_FpShort>(x - src.red),
                      static_cast<A_FpShort>(x - src.green),
                      static_cast<A_FpShort>(x - src.blue)};
}
template <typename T>
inline PF_Pixel32 operator*(const T x, const PF_Pixel16 &src) noexcept {
    static_assert(std::is_floating_point_v<T>);
    return PF_Pixel32{static_cast<A_FpShort>(x * src.alpha),
                      static_cast<A_FpShort>(x * src.red),
                      static_cast<A_FpShort>(x * src.green),
                      static_cast<A_FpShort>(x * src.blue)};
}
template <typename T>
inline PF_Pixel32 operator/(const T x, const PF_Pixel16 &src) noexcept {
    static_assert(std::is_floating_point_v<T>);
    return PF_Pixel32{static_cast<A_FpShort>(x / src.alpha),
                      static_cast<A_FpShort>(x / src.red),
                      static_cast<A_FpShort>(x / src.green),
                      static_cast<A_FpShort>(x / src.blue)};
}

#else

#include <concepts>

template <std::integral T>
inline PF_Pixel16 operator+(const PF_Pixel16 &src, const T x) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(src.alpha + x),
                      static_cast<A_u_short>(src.red + x),
                      static_cast<A_u_short>(src.green + x),
                      static_cast<A_u_short>(src.blue + x)};
}
template <std::integral T>
inline PF_Pixel16 operator-(const PF_Pixel16 &src, const T x) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(src.alpha - x),
                      static_cast<A_u_short>(src.red - x),
                      static_cast<A_u_short>(src.green - x),
                      static_cast<A_u_short>(src.blue - x)};
}
template <std::integral T>
inline PF_Pixel16 operator*(const PF_Pixel16 &src, const T x) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(src.alpha * x),
                      static_cast<A_u_short>(src.red * x),
                      static_cast<A_u_short>(src.green * x),
                      static_cast<A_u_short>(src.blue * x)};
}
template <std::integral T>
inline PF_Pixel16 operator/(const PF_Pixel16 &src, const T x) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(src.alpha / x),
                      static_cast<A_u_short>(src.red / x),
                      static_cast<A_u_short>(src.green / x),
                      static_cast<A_u_short>(src.blue / x)};
}
template <std::integral T>
inline PF_Pixel16 operator+(const T x, const PF_Pixel16 &src) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(x + src.alpha),
                      static_cast<A_u_short>(x + src.red),
                      static_cast<A_u_short>(x + src.green),
                      static_cast<A_u_short>(x + src.blue)};
}
template <std::integral T>
inline PF_Pixel16 operator-(const T x, const PF_Pixel16 &src) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(x - src.alpha),
                      static_cast<A_u_short>(x - src.red),
                      static_cast<A_u_short>(x - src.green),
                      static_cast<A_u_short>(x - src.blue)};
}
template <std::integral T>
inline PF_Pixel16 operator*(const T x, const PF_Pixel16 &src) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(x * src.alpha),
                      static_cast<A_u_short>(x * src.red),
                      static_cast<A_u_short>(x * src.green),
                      static_cast<A_u_short>(x * src.blue)};
}
template <std::integral T>
inline PF_Pixel16 operator/(const T x, const PF_Pixel16 &src) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(x / src.alpha),
                      static_cast<A_u_short>(x / src.red),
                      static_cast<A_u_short>(x / src.green),
                      static_cast<A_u_short>(x / src.blue)};
}

template <std::floating_point T>
inline PF_Pixel32 operator+(const PF_Pixel16 &src, const T x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha + x),
                      static_cast<A_FpShort>(src.red + x),
                      static_cast<A_FpShort>(src.green + x),
                      static_cast<A_FpShort>(src.blue + x)};
}
template <std::floating_point T>
inline PF_Pixel32 operator-(const PF_Pixel16 &src, const T x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha - x),
                      static_cast<A_FpShort>(src.red - x),
                      static_cast<A_FpShort>(src.green - x),
                      static_cast<A_FpShort>(src.blue - x)};
}
template <std::floating_point T>
inline PF_Pixel32 operator*(const PF_Pixel16 &src, const T x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha * x),
                      static_cast<A_FpShort>(src.red * x),
                      static_cast<A_FpShort>(src.green * x),
                      static_cast<A_FpShort>(src.blue * x)};
}
template <std::floating_point T>
inline PF_Pixel32 operator/(const PF_Pixel16 &src, const T x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha / x),
                      static_cast<A_FpShort>(src.red / x),
                      static_cast<A_FpShort>(src.green / x),
                      static_cast<A_FpShort>(src.blue / x)};
}
template <std::floating_point T>
inline PF_Pixel32 operator+(const T x, const PF_Pixel16 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x + src.alpha),
                      static_cast<A_FpShort>(x + src.red),
                      static_cast<A_FpShort>(x + src.green),
                      static_cast<A_FpShort>(x + src.blue)};
}
template <std::floating_point T>
inline PF_Pixel32 operator-(const T x, const PF_Pixel16 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x - src.alpha),
                      static_cast<A_FpShort>(x - src.red),
                      static_cast<A_FpShort>(x - src.green),
                      static_cast<A_FpShort>(x - src.blue)};
}
template <std::floating_point T>
inline PF_Pixel32 operator*(const T x, const PF_Pixel16 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x * src.alpha),
                      static_cast<A_FpShort>(x * src.red),
                      static_cast<A_FpShort>(x * src.green),
                      static_cast<A_FpShort>(x * src.blue)};
}
template <std::floating_point T>
inline PF_Pixel32 operator/(const T x, const PF_Pixel16 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x / src.alpha),
                      static_cast<A_FpShort>(x / src.red),
                      static_cast<A_FpShort>(x / src.green),
                      static_cast<A_FpShort>(x / src.blue)};
}

#endif

inline PF_Pixel16 operator+(const PF_Pixel16 &src,
                            const PF_Pixel8 &x) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(src.alpha + x.alpha),
                      static_cast<A_u_short>(src.red + x.red),
                      static_cast<A_u_short>(src.green + x.green),
                      static_cast<A_u_short>(src.blue + x.blue)};
}
inline PF_Pixel16 operator-(const PF_Pixel16 &src,
                            const PF_Pixel8 &x) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(src.alpha - x.alpha),
                      static_cast<A_u_short>(src.red - x.red),
                      static_cast<A_u_short>(src.green - x.green),
                      static_cast<A_u_short>(src.blue - x.blue)};
}
inline PF_Pixel16 operator*(const PF_Pixel16 &src,
                            const PF_Pixel8 &x) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(src.alpha * x.alpha),
                      static_cast<A_u_short>(src.red * x.red),
                      static_cast<A_u_short>(src.green * x.green),
                      static_cast<A_u_short>(src.blue * x.blue)};
}
inline PF_Pixel16 operator/(const PF_Pixel16 &src,
                            const PF_Pixel8 &x) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(src.alpha / x.alpha),
                      static_cast<A_u_short>(src.red / x.red),
                      static_cast<A_u_short>(src.green / x.green),
                      static_cast<A_u_short>(src.blue / x.blue)};
}
inline PF_Pixel16 operator+(const PF_Pixel8 &x,
                            const PF_Pixel16 &src) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(x.alpha + src.alpha),
                      static_cast<A_u_short>(x.red + src.red),
                      static_cast<A_u_short>(x.green + src.green),
                      static_cast<A_u_short>(x.blue + src.blue)};
}
inline PF_Pixel16 operator-(const PF_Pixel8 &x,
                            const PF_Pixel16 &src) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(x.alpha - src.alpha),
                      static_cast<A_u_short>(x.red - src.red),
                      static_cast<A_u_short>(x.green - src.green),
                      static_cast<A_u_short>(x.blue - src.blue)};
}
inline PF_Pixel16 operator*(const PF_Pixel8 &x,
                            const PF_Pixel16 &src) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(x.alpha * src.alpha),
                      static_cast<A_u_short>(x.red * src.red),
                      static_cast<A_u_short>(x.green * src.green),
                      static_cast<A_u_short>(x.blue * src.blue)};
}
inline PF_Pixel16 operator/(const PF_Pixel8 &x,
                            const PF_Pixel16 &src) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(x.alpha / src.alpha),
                      static_cast<A_u_short>(x.red / src.red),
                      static_cast<A_u_short>(x.green / src.green),
                      static_cast<A_u_short>(x.blue / src.blue)};
}

inline PF_Pixel16 operator+(const PF_Pixel16 &src,
                            const PF_Pixel16 &x) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(src.alpha + x.alpha),
                      static_cast<A_u_short>(src.red + x.red),
                      static_cast<A_u_short>(src.green + x.green),
                      static_cast<A_u_short>(src.blue + x.blue)};
}
inline PF_Pixel16 operator-(const PF_Pixel16 &src,
                            const PF_Pixel16 &x) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(src.alpha - x.alpha),
                      static_cast<A_u_short>(src.red - x.red),
                      static_cast<A_u_short>(src.green - x.green),
                      static_cast<A_u_short>(src.blue - x.blue)};
}
inline PF_Pixel16 operator*(const PF_Pixel16 &src,
                            const PF_Pixel16 &x) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(src.alpha * x.alpha),
                      static_cast<A_u_short>(src.red * x.red),
                      static_cast<A_u_short>(src.green * x.green),
                      static_cast<A_u_short>(src.blue * x.blue)};
}
inline PF_Pixel16 operator/(const PF_Pixel16 &src,
                            const PF_Pixel16 &x) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(src.alpha / x.alpha),
                      static_cast<A_u_short>(src.red / x.red),
                      static_cast<A_u_short>(src.green / x.green),
                      static_cast<A_u_short>(src.blue / x.blue)};
}

#endif  // PIXEL16_ARITHMETIC_HPP
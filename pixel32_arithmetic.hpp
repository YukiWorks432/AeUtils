#pragma once
#ifndef PIXEL32_ARITHMETIC_HPP
#define PIXEL32_ARITHMETIC_HPP

#include <AE_Effect.h>

#include <type_traits>

#if _MSVC_LANG < 202002L

template <typename T,
          std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> = nullptr>
inline PF_Pixel32 operator+(const PF_Pixel32 &src, const T x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha + x),
                      static_cast<A_FpShort>(src.red + x),
                      static_cast<A_FpShort>(src.green + x),
                      static_cast<A_FpShort>(src.blue + x)};
}
template <typename T,
          std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> = nullptr>
inline PF_Pixel32 operator-(const PF_Pixel32 &src, const T x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha - x),
                      static_cast<A_FpShort>(src.red - x),
                      static_cast<A_FpShort>(src.green - x),
                      static_cast<A_FpShort>(src.blue - x)};
}
template <typename T,
          std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> = nullptr>
inline PF_Pixel32 operator*(const PF_Pixel32 &src, const T x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha * x),
                      static_cast<A_FpShort>(src.red * x),
                      static_cast<A_FpShort>(src.green * x),
                      static_cast<A_FpShort>(src.blue * x)};
}
template <typename T,
          std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> = nullptr>
inline PF_Pixel32 operator/(const PF_Pixel32 &src, const T x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha / x),
                      static_cast<A_FpShort>(src.red / x),
                      static_cast<A_FpShort>(src.green / x),
                      static_cast<A_FpShort>(src.blue / x)};
}
template <typename T,
          std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> = nullptr>
inline PF_Pixel32 operator+(const T x, const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x + src.alpha),
                      static_cast<A_FpShort>(x + src.red),
                      static_cast<A_FpShort>(x + src.green),
                      static_cast<A_FpShort>(x + src.blue)};
}
template <typename T,
          std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> = nullptr>
inline PF_Pixel32 operator-(const T x, const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x - src.alpha),
                      static_cast<A_FpShort>(x - src.red),
                      static_cast<A_FpShort>(x - src.green),
                      static_cast<A_FpShort>(x - src.blue)};
}
template <typename T,
          std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> = nullptr>
inline PF_Pixel32 operator*(const T x, const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x * src.alpha),
                      static_cast<A_FpShort>(x * src.red),
                      static_cast<A_FpShort>(x * src.green),
                      static_cast<A_FpShort>(x * src.blue)};
}
template <typename T,
          std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> = nullptr>
inline PF_Pixel32 operator/(const T x, const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x / src.alpha),
                      static_cast<A_FpShort>(x / src.red),
                      static_cast<A_FpShort>(x / src.green),
                      static_cast<A_FpShort>(x / src.blue)};
}

#else

#include <concepts>

template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;

template <Number T>
inline PF_Pixel32 operator+(const PF_Pixel32 &src, const T x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha + x),
                      static_cast<A_FpShort>(src.red + x),
                      static_cast<A_FpShort>(src.green + x),
                      static_cast<A_FpShort>(src.blue + x)};
}
template <Number T>
inline PF_Pixel32 operator-(const PF_Pixel32 &src, const T x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha - x),
                      static_cast<A_FpShort>(src.red - x),
                      static_cast<A_FpShort>(src.green - x),
                      static_cast<A_FpShort>(src.blue - x)};
}
template <Number T>
inline PF_Pixel32 operator*(const PF_Pixel32 &src, const T x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha * x),
                      static_cast<A_FpShort>(src.red * x),
                      static_cast<A_FpShort>(src.green * x),
                      static_cast<A_FpShort>(src.blue * x)};
}
template <Number T>
inline PF_Pixel32 operator/(const PF_Pixel32 &src, const T x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha / x),
                      static_cast<A_FpShort>(src.red / x),
                      static_cast<A_FpShort>(src.green / x),
                      static_cast<A_FpShort>(src.blue / x)};
}
template <Number T>
inline PF_Pixel32 operator+(const T x, const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x + src.alpha),
                      static_cast<A_FpShort>(x + src.red),
                      static_cast<A_FpShort>(x + src.green),
                      static_cast<A_FpShort>(x + src.blue)};
}
template <Number T>
inline PF_Pixel32 operator-(const T x, const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x - src.alpha),
                      static_cast<A_FpShort>(x - src.red),
                      static_cast<A_FpShort>(x - src.green),
                      static_cast<A_FpShort>(x - src.blue)};
}
template <Number T>
inline PF_Pixel32 operator*(const T x, const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x * src.alpha),
                      static_cast<A_FpShort>(x * src.red),
                      static_cast<A_FpShort>(x * src.green),
                      static_cast<A_FpShort>(x * src.blue)};
}
template <Number T>
inline PF_Pixel32 operator/(const T x, const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x / src.alpha),
                      static_cast<A_FpShort>(x / src.red),
                      static_cast<A_FpShort>(x / src.green),
                      static_cast<A_FpShort>(x / src.blue)};
}

#endif

inline PF_Pixel32 operator+(const PF_Pixel32 &src,
                            const PF_Pixel8 &x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha + x.alpha),
                      static_cast<A_FpShort>(src.red + x.red),
                      static_cast<A_FpShort>(src.green + x.green),
                      static_cast<A_FpShort>(src.blue + x.blue)};
}
inline PF_Pixel32 operator-(const PF_Pixel32 &src,
                            const PF_Pixel8 &x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha - x.alpha),
                      static_cast<A_FpShort>(src.red - x.red),
                      static_cast<A_FpShort>(src.green - x.green),
                      static_cast<A_FpShort>(src.blue - x.blue)};
}
inline PF_Pixel32 operator*(const PF_Pixel32 &src,
                            const PF_Pixel8 &x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha * x.alpha),
                      static_cast<A_FpShort>(src.red * x.red),
                      static_cast<A_FpShort>(src.green * x.green),
                      static_cast<A_FpShort>(src.blue * x.blue)};
}
inline PF_Pixel32 operator/(const PF_Pixel32 &src,
                            const PF_Pixel8 &x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha / x.alpha),
                      static_cast<A_FpShort>(src.red / x.red),
                      static_cast<A_FpShort>(src.green / x.green),
                      static_cast<A_FpShort>(src.blue / x.blue)};
}
inline PF_Pixel32 operator+(const PF_Pixel8 &x,
                            const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x.alpha + src.alpha),
                      static_cast<A_FpShort>(x.red + src.red),
                      static_cast<A_FpShort>(x.green + src.green),
                      static_cast<A_FpShort>(x.blue + src.blue)};
}
inline PF_Pixel32 operator-(const PF_Pixel8 &x,
                            const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x.alpha - src.alpha),
                      static_cast<A_FpShort>(x.red - src.red),
                      static_cast<A_FpShort>(x.green - src.green),
                      static_cast<A_FpShort>(x.blue - src.blue)};
}
inline PF_Pixel32 operator*(const PF_Pixel8 &x,
                            const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x.alpha * src.alpha),
                      static_cast<A_FpShort>(x.red * src.red),
                      static_cast<A_FpShort>(x.green * src.green),
                      static_cast<A_FpShort>(x.blue * src.blue)};
}
inline PF_Pixel32 operator/(const PF_Pixel8 &x,
                            const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x.alpha / src.alpha),
                      static_cast<A_FpShort>(x.red / src.red),
                      static_cast<A_FpShort>(x.green / src.green),
                      static_cast<A_FpShort>(x.blue / src.blue)};
}

inline PF_Pixel32 operator+(const PF_Pixel32 &src,
                            const PF_Pixel16 &x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha + x.alpha),
                      static_cast<A_FpShort>(src.red + x.red),
                      static_cast<A_FpShort>(src.green + x.green),
                      static_cast<A_FpShort>(src.blue + x.blue)};
}
inline PF_Pixel32 operator-(const PF_Pixel32 &src,
                            const PF_Pixel16 &x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha - x.alpha),
                      static_cast<A_FpShort>(src.red - x.red),
                      static_cast<A_FpShort>(src.green - x.green),
                      static_cast<A_FpShort>(src.blue - x.blue)};
}
inline PF_Pixel32 operator*(const PF_Pixel32 &src,
                            const PF_Pixel16 &x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha * x.alpha),
                      static_cast<A_FpShort>(src.red * x.red),
                      static_cast<A_FpShort>(src.green * x.green),
                      static_cast<A_FpShort>(src.blue * x.blue)};
}
inline PF_Pixel32 operator/(const PF_Pixel32 &src,
                            const PF_Pixel16 &x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha / x.alpha),
                      static_cast<A_FpShort>(src.red / x.red),
                      static_cast<A_FpShort>(src.green / x.green),
                      static_cast<A_FpShort>(src.blue / x.blue)};
}
inline PF_Pixel32 operator+(const PF_Pixel16 &x,
                            const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x.alpha + src.alpha),
                      static_cast<A_FpShort>(x.red + src.red),
                      static_cast<A_FpShort>(x.green + src.green),
                      static_cast<A_FpShort>(x.blue + src.blue)};
}
inline PF_Pixel32 operator-(const PF_Pixel16 &x,
                            const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x.alpha - src.alpha),
                      static_cast<A_FpShort>(x.red - src.red),
                      static_cast<A_FpShort>(x.green - src.green),
                      static_cast<A_FpShort>(x.blue - src.blue)};
}
inline PF_Pixel32 operator*(const PF_Pixel16 &x,
                            const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x.alpha * src.alpha),
                      static_cast<A_FpShort>(x.red * src.red),
                      static_cast<A_FpShort>(x.green * src.green),
                      static_cast<A_FpShort>(x.blue * src.blue)};
}
inline PF_Pixel32 operator/(const PF_Pixel16 &x,
                            const PF_Pixel32 &src) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(x.alpha / src.alpha),
                      static_cast<A_FpShort>(x.red / src.red),
                      static_cast<A_FpShort>(x.green / src.green),
                      static_cast<A_FpShort>(x.blue / src.blue)};
}

inline PF_Pixel32 operator+(const PF_Pixel32 &src,
                            const PF_Pixel32 &x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha + x.alpha),
                      static_cast<A_FpShort>(src.red + x.red),
                      static_cast<A_FpShort>(src.green + x.green),
                      static_cast<A_FpShort>(src.blue + x.blue)};
}
inline PF_Pixel32 operator-(const PF_Pixel32 &src,
                            const PF_Pixel32 &x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha - x.alpha),
                      static_cast<A_FpShort>(src.red - x.red),
                      static_cast<A_FpShort>(src.green - x.green),
                      static_cast<A_FpShort>(src.blue - x.blue)};
}
inline PF_Pixel32 operator*(const PF_Pixel32 &src,
                            const PF_Pixel32 &x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha * x.alpha),
                      static_cast<A_FpShort>(src.red * x.red),
                      static_cast<A_FpShort>(src.green * x.green),
                      static_cast<A_FpShort>(src.blue * x.blue)};
}
inline PF_Pixel32 operator/(const PF_Pixel32 &src,
                            const PF_Pixel32 &x) noexcept {
    return PF_Pixel32{static_cast<A_FpShort>(src.alpha / x.alpha),
                      static_cast<A_FpShort>(src.red / x.red),
                      static_cast<A_FpShort>(src.green / x.green),
                      static_cast<A_FpShort>(src.blue / x.blue)};
}

inline PF_Pixel32 &operator+=(PF_Pixel32 &src, const PF_Pixel32 &x) noexcept {
    src.alpha += x.alpha;
    src.red += x.red;
    src.green += x.green;
    src.blue += x.blue;
    return src;
}
inline PF_Pixel32 &operator-=(PF_Pixel32 &src, const PF_Pixel32 &x) noexcept {
    src.alpha -= x.alpha;
    src.red -= x.red;
    src.green -= x.green;
    src.blue -= x.blue;
    return src;
}
inline PF_Pixel32 &operator*=(PF_Pixel32 &src, const PF_Pixel32 &x) noexcept {
    src.alpha *= x.alpha;
    src.red *= x.red;
    src.green *= x.green;
    src.blue *= x.blue;
    return src;
}
inline PF_Pixel32 &operator/=(PF_Pixel32 &src, const PF_Pixel32 &x) noexcept {
    src.alpha /= x.alpha;
    src.red /= x.red;
    src.green /= x.green;
    src.blue /= x.blue;
    return src;
}

#endif  // PIXEL32_ARITHMETIC_HPP
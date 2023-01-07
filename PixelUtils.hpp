#pragma once
#ifndef AE_UTILS_PIXEL_UTILS_HPP
#define AE_UTILS_PIXEL_UTILS_HPP

#include <AE_Effect.h>

#include "pixel16_arithmetic.hpp"
#include "pixel32_arithmetic.hpp"
#include "pixel8_arithmetic.hpp"

bool operator==(const PF_Pixel8 &left, const PF_Pixel8 &right) noexcept {
    return (left.alpha == right.alpha) && (left.red == right.red) &&
           (left.green == right.green) && (left.blue == right.blue);
}
bool operator==(const PF_Pixel16 &left, const PF_Pixel16 &right) noexcept {
    return (left.alpha == right.alpha) && (left.red == right.red) &&
           (left.green == right.green) && (left.blue == right.blue);
}
bool operator==(const PF_Pixel32 &left, const PF_Pixel32 &right) noexcept {
    return (left.alpha == right.alpha) && (left.red == right.red) &&
           (left.green == right.green) && (left.blue == right.blue);
}
bool operator!=(const PF_Pixel8 &left, const PF_Pixel8 &right) noexcept {
    return !((left.alpha == right.alpha) && (left.red == right.red) &&
             (left.green == right.green) && (left.blue == right.blue));
}
bool operator!=(const PF_Pixel16 &left, const PF_Pixel16 &right) noexcept {
    return !((left.alpha == right.alpha) && (left.red == right.red) &&
             (left.green == right.green) && (left.blue == right.blue));
}
bool operator!=(const PF_Pixel32 &left, const PF_Pixel32 &right) noexcept {
    return !((left.alpha == right.alpha) && (left.red == right.red) &&
             (left.green == right.green) && (left.blue == right.blue));
}

#include <iostream>

template <class _Elem, class _Traits, class _Alloc>
inline std::basic_ostream<_Elem, _Traits> &operator<<(
    std::basic_ostream<_Elem, _Traits> &_Ostr, const PF_Pixel8 &src) {
    _Ostr << "A: " << src.alpha << ", R: " << src.red << ", G: " << src.green
          << ", B: " << src.blue;
    return _Ostr;
}
template <class _Elem, class _Traits, class _Alloc>
inline std::basic_ostream<_Elem, _Traits> &operator<<(
    std::basic_ostream<_Elem, _Traits> &_Ostr, const PF_Pixel16 &src) {
    _Ostr << "A: " << src.alpha << ", R: " << src.red << ", G: " << src.green
          << ", B: " << src.blue;
    return _Ostr;
}
template <class _Elem, class _Traits, class _Alloc>
inline std::basic_ostream<_Elem, _Traits> &operator<<(
    std::basic_ostream<_Elem, _Traits> &_Ostr, const PF_Pixel32 &src) {
    _Ostr << "A: " << src.alpha << ", R: " << src.red << ", G: " << src.green
          << ", B: " << src.blue;
    return _Ostr;
}

#include <cmath>

inline bool IsFinite(const PF_Pixel32 &src) noexcept {
    return std::isfinite(src.alpha) & std::isfinite(src.red) &
           std::isfinite(src.green) & std::isfinite(src.blue);
}

#endif  // PIXEL_UTILS_HPP
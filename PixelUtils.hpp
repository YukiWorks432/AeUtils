#pragma once
#ifndef AE_UTILS_PIXEL_UTILS_HPP
#define AE_UTILS_PIXEL_UTILS_HPP

#include <AE_Effect.h>

#include "pixel16_arithmetic.hpp"
#include "pixel32_arithmetic.hpp"
#include "pixel8_arithmetic.hpp"

inline bool operator==(const PF_Pixel8 &left, const PF_Pixel8 &right) noexcept {
    return (left.alpha == right.alpha) && (left.red == right.red) &&
           (left.green == right.green) && (left.blue == right.blue);
}
inline bool operator==(const PF_Pixel16 &left,
                       const PF_Pixel16 &right) noexcept {
    return (left.alpha == right.alpha) && (left.red == right.red) &&
           (left.green == right.green) && (left.blue == right.blue);
}
inline bool operator==(const PF_Pixel32 &left,
                       const PF_Pixel32 &right) noexcept {
    return (left.alpha == right.alpha) && (left.red == right.red) &&
           (left.green == right.green) && (left.blue == right.blue);
}
inline bool operator!=(const PF_Pixel8 &left, const PF_Pixel8 &right) noexcept {
    return !((left.alpha == right.alpha) && (left.red == right.red) &&
             (left.green == right.green) && (left.blue == right.blue));
}
inline bool operator!=(const PF_Pixel16 &left,
                       const PF_Pixel16 &right) noexcept {
    return !((left.alpha == right.alpha) && (left.red == right.red) &&
             (left.green == right.green) && (left.blue == right.blue));
}
inline bool operator!=(const PF_Pixel32 &left,
                       const PF_Pixel32 &right) noexcept {
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

#include <cassert>
#include <cmath>

#include "Rect.hpp"

inline bool IsFinite(const PF_Pixel32 &src) noexcept {
    return std::isfinite<float>(src.alpha) && std::isfinite<float>(src.red) &&
           std::isfinite<float>(src.green) && std::isfinite<float>(src.blue);
}

template <class T, class U>
inline T PixelCast(const U &src) noexcept {
    std::string str = "SaturationCast Error.\n";
    str += "T " + typeid(T).name() + "\n";
    str += "U " + typeid(U).name();
    assert(!(str.c_str()));
    return T{};
}
template <>
inline PF_Pixel32 PixelCast(const PF_Pixel &src) noexcept {
    return src / 255.0f;
}
template <>
inline PF_Pixel32 PixelCast(const PF_Pixel16 &src) noexcept {
    return src / 32768.0f;
}
template <>
inline PF_Pixel32 PixelCast(const PF_Pixel32 &src) noexcept {
    return src;
}
template <>
inline PF_Pixel PixelCast(const PF_Pixel32 &src) noexcept {
    return PF_Pixel{static_cast<uint8_t>(src.alpha * 255.0f),
                    static_cast<uint8_t>(src.red * 255.0f),
                    static_cast<uint8_t>(src.green * 255.0f),
                    static_cast<uint8_t>(src.blue * 255.0f)};
}
template <>
inline PF_Pixel16 PixelCast(const PF_Pixel32 &src) noexcept {
    return PF_Pixel16{static_cast<A_u_short>(src.alpha * 32768.0f),
                      static_cast<A_u_short>(src.red * 32768.0f),
                      static_cast<A_u_short>(src.green * 32768.0f),
                      static_cast<A_u_short>(src.blue * 32768.0f)};
}

void PrePixelsCast(const PF_Pixel *src, PF_Pixel32 *out,
                   const RectData &rect) noexcept {
#pragma omp parallel for
    for (int y = 0; y < rect.out.height; ++y) {
        for (int x = 0; x < rect.out.width; ++x) {
            const int src_pos = y * rect.in.pitch + x;
            const int out_pos = y * rect.out.pitch + x;

            out[out_pos] = PixelCast<PF_Pixel32, PF_Pixel>(src[src_pos]);
        }
    }
}
void PrePixelsCast(const PF_Pixel16 *src, PF_Pixel32 *out,
                   const RectData &rect) noexcept {
#pragma omp parallel for
    for (int y = 0; y < rect.out.height; ++y) {
        for (int x = 0; x < rect.out.width; ++x) {
            const int src_pos = y * rect.in.pitch + x;
            const int out_pos = y * rect.out.pitch + x;

            out[out_pos] = PixelCast<PF_Pixel32, PF_Pixel16>(src[src_pos]);
        }
    }
}
void PrePixelsCast(const PF_Pixel32 *src, PF_Pixel32 *out,
                   const RectData &rect) noexcept {
#pragma omp parallel for
    for (int y = 0; y < rect.out.height; ++y) {
        for (int x = 0; x < rect.out.width; ++x) {
            const int src_pos = y * rect.in.pitch + x;
            const int out_pos = y * rect.out.pitch + x;

            out[out_pos] = src[src_pos];
        }
    }
}
void PostPixelsCast(const PF_Pixel32 *src, PF_Pixel *out,
                    const RectData &rect) noexcept {
#pragma omp parallel for
    for (int y = 0; y < rect.out.height; ++y) {
        for (int x = 0; x < rect.out.width; ++x) {
            const int pos = y * rect.out.pitch + x;

            out[pos] = PixelCast<PF_Pixel, PF_Pixel32>(src[pos]);
        }
    }
}
void PostPixelsCast(const PF_Pixel32 *src, PF_Pixel16 *out,
                    const RectData &rect) noexcept {
#pragma omp parallel for
    for (int y = 0; y < rect.out.height; ++y) {
        for (int x = 0; x < rect.out.width; ++x) {
            const int pos = y * rect.out.pitch + x;

            out[pos] = PixelCast<PF_Pixel16, PF_Pixel32>(src[pos]);
        }
    }
}
void PostPixelsCast(const PF_Pixel32 *src, PF_Pixel32 *out,
                    const RectData &rect) noexcept {
#pragma omp parallel for
    for (int y = 0; y < rect.out.height; ++y) {
        for (int x = 0; x < rect.out.width; ++x) {
            const int pos = y * rect.out.pitch + x;

            out[pos] = src[pos];
        }
    }
}

#endif  // PIXEL_UTILS_HPP
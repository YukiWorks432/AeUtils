#pragma once
#ifndef AE_UTILS_RECT_HPP
#define AE_UTILS_RECT_HPP

#include <utility>

struct RectType {
    int width = 0, height = 0, pitch = 0;
};

class RectData {
  public:
    RectType in;
    RectType out;

    RectData(const RectType &in_, const RectType &out_) noexcept
        : in(in_), out(out_) {}

    RectData(const RectData &) = default;
    RectData(RectData &&) = default;
    RectData() noexcept {
        in = RectType();
        out = RectType();
    }

    RectData &operator=(const RectData &) = default;
    RectData &operator=(RectData &&) = default;

    RectType Bigger() const noexcept {
        return RectType{std::max(in.width, out.width),
                        std::max(in.height, out.height),
                        std::max(in.pitch, out.pitch)};
    }
    RectType Smaller() const noexcept {
        return RectType{std::min(in.width, out.width),
                        std::min(in.height, out.height),
                        std::min(in.pitch, out.pitch)};
    }
};

#endif
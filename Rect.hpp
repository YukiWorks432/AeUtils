#pragma once
#ifndef AE_UTILS_RECT_HPP
#define AE_UTILS_RECT_HPP

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
    };
    RectData &operator=(const RectData &) = default;
    RectData &operator=(RectData &&) = default;

    RectType Bigger() const noexcept {
        return RectType{in.width > out.width ? in.width : out.width,
                        in.height > out.height ? in.height : out.height,
                        in.pitch > out.pitch ? in.pitch : out.pitch};
    }
};

#endif
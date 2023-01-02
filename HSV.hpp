#pragma once
#ifndef AE_UTILS_HSV_HPP
#define AE_UTILS_HSV_HPP

#include <AE_Effect.h>

#include <initializer_list>

class HSV {
  public:
    // 0 ~ 1
    float h, s, v;

    HSV(const PF_Pixel32 &in) noexcept {
        float min, max, delta;

        min = in.red < in.green ? in.red : in.green;
        min = min < in.blue ? min : in.blue;

        max = in.red > in.green ? in.red : in.green;
        max = max > in.blue ? max : in.blue;

        delta = max - min;
        if (delta == 0) {
            h = 0;
            s = 0;
            v = max;
            return;
        }
        if (in.red == max) {
            h = (in.green - in.blue) / delta;
            if (h < 0) h += 6;
        } else if (in.green == max) {
            h = 2 + (in.blue - in.red) / delta;
        } else {
            h = 4 + (in.red - in.green) / delta;
        }
        h /= 6;
        if (h > 1) {
            h -= 1;
        }

        s = delta;
        if (max != 0) {
            s /= max;
        }

        v = max;
    }
    HSV(const std::initializer_list<int> &src) noexcept {
        h = *src.begin();
        s = *(src.begin() + 1);
        v = *(src.begin() + 2);
    }
    HSV(const HSV &) = default;
    HSV(HSV &&) = default;
    HSV() noexcept {
        h = 0.0;
        s = 0.0;
        v = 0.0;
    }
    PF_Pixel32 ToRGB() const noexcept {
        float hh, p, q, t, ff;
        long i;
        PF_Pixel32 out;
        out.alpha = 1.0;

        if (this->s <= 0.0) {  // < is bogus, just shuts up warnings
            out.red = this->v;
            out.green = this->v;
            out.blue = this->v;
            return out;
        }
        hh = this->h;
        if (hh >= 360.0) hh = 0.0;
        hh /= 60.0;
        i = (long)hh;
        ff = hh - i;
        p = this->v * (1.0 - this->s);
        q = this->v * (1.0 - (this->s * ff));
        t = this->v * (1.0 - (this->s * (1.0 - ff)));

        switch (i) {
            case 0:
                out.red = this->v;
                out.green = t;
                out.blue = p;
                break;
            case 1:
                out.red = q;
                out.green = this->v;
                out.blue = p;
                break;
            case 2:
                out.red = p;
                out.green = this->v;
                out.blue = t;
                break;

            case 3:
                out.red = p;
                out.green = q;
                out.blue = this->v;
                break;
            case 4:
                out.red = t;
                out.green = p;
                out.blue = this->v;
                break;
            case 5:
            default:
                out.red = this->v;
                out.green = p;
                out.blue = q;
                break;
        }
        return out;
    }

    HSV &operator=(const HSV &) = default;
    HSV &operator=(HSV &&) = default;
};

#endif
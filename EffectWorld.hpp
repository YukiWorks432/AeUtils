#pragma once
#ifndef AE_UTILS_EFFECT_WORLD_HPP
#define AE_UTILS_EFFECT_WORLD_HPP

#include <AEFX_SuiteHelper.h>
#include <AE_Effect.h>
#include <AE_EffectCBSuites.h>
#include <AE_Macros.h>

#include <cassert>
#include <memory>

#include "Rect.hpp"

template <typename pixel_type>
class EffectWorld {
  public:
    EffectWorld() = delete;
    EffectWorld(const EffectWorld&) = delete;
    EffectWorld(EffectWorld&&) = default;

    EffectWorld(PF_InData* in_data, PF_OutData* out_data) noexcept
        : in_data_(in_data), out_data_(out_data) {}
    ~EffectWorld() noexcept { dispose(); }

    PF_Err alloc(const RectType& new_rect, const bool clear = false) noexcept {
        PF_Err err = PF_Err_NONE;

#ifdef _DEBUG
        assert(disposed && "EffectWorld Error! This world is allocated.");
#endif

        auto world_suite = AEFX_SuiteScoper<PF_WorldSuite2>(
            in_data_, kPFWorldSuite, kPFWorldSuiteVersion2, out_data_);
        auto pixel_suite = AEFX_SuiteScoper<PF_PixelDataSuite2>(
            in_data_, kPFPixelDataSuite, kPFPixelDataSuiteVersion2, out_data_);

        if constexpr (std::is_same_v<pixel_type, PF_Pixel8>) {
            pixel_format = PF_PixelFormat_ARGB32;
        } else if constexpr (std::is_same_v<pixel_type, PF_Pixel16>) {
            pixel_format = PF_PixelFormat_ARGB64;
        } else if constexpr (std::is_same_v<pixel_type, PF_Pixel32>) {
            pixel_format = PF_PixelFormat_ARGB128;
        }

        err = world_suite->PF_NewWorld(in_data_->effect_ref, new_rect.pitch,
                                       new_rect.height, clear, pixel_format,
                                       &src_world_);

        if (err != PF_Err_NONE) {
            return err;
        }

        rect_.width = src_world_.width;
        rect_.height = src_world_.height;
        rect_.pitch = src_world_.rowbytes / sizeof(pixel_type);

        if constexpr (std::is_same_v<pixel_type, PF_Pixel8>) {
            pixel_suite->get_pixel_data8(&src_world_, nullptr, &ptr_);
        } else if constexpr (std::is_same_v<pixel_type, PF_Pixel16>) {
            pixel_suite->get_pixel_data16(&src_world_, nullptr, &ptr_);
        } else if constexpr (std::is_same_v<pixel_type, PF_Pixel32>) {
            pixel_suite->get_pixel_data_float(&src_world_, nullptr, &ptr_);
        } else {
            static_assert([] { return false; }(), "EffectWorld is error");
        }

        disposed = false;

        return PF_Err_NONE;
    }

    PF_Err dispose() noexcept {
        PF_Err err = PF_Err_NONE;

        auto world_suite = AEFX_SuiteScoper<PF_WorldSuite2>(
            in_data_, kPFWorldSuite, kPFWorldSuiteVersion2, out_data_);

        if (disposed == false) {
            err =
                world_suite->PF_DisposeWorld(in_data_->effect_ref, &src_world_);
            disposed = true;
        };

        rect_ = {};

        return err;
    }

    void reinterpret_rect(const RectType& new_rect) noexcept {
        if (rect.pitch * rect.height == new_rect.pitch * new_rect.height) {
            rect_ = new_rect;
        }
    }

    pixel_type* get() noexcept { return ptr_; }
    pixel_type* const& ptr = ptr_;

    const RectType& rect = rect_;
    const int& width = rect.width;
    const int& height = rect.height;
    const int& pitch = rect.pitch;

  private:
    RectType rect_;
    PF_InData* in_data_;
    PF_OutData* out_data_;
    PF_EffectWorld src_world_;
    PF_PixelFormat pixel_format;
    bool disposed;
    pixel_type* ptr_;
};

template <typename pixel_type>
class InputWorld {
  public:
    InputWorld() = delete;
    InputWorld(const InputWorld&) = default;
    InputWorld(InputWorld&&) = default;

    InputWorld(PF_InData* in_data, PF_OutData* out_data,
               PF_EffectWorld* src) noexcept
        : in_data_(in_data), out_data_(out_data), src_world_(src) {
        auto world_suite = AEFX_SuiteScoper<PF_WorldSuite2>(
            in_data, kPFWorldSuite, kPFWorldSuiteVersion2, out_data);
        world_suite->PF_GetPixelFormat(src, &pixel_format);
        auto pixel_suite = AEFX_SuiteScoper<PF_PixelDataSuite2>(
            in_data_, kPFPixelDataSuite, kPFPixelDataSuiteVersion2, out_data_);

        rect_.width = src->width;
        rect_.height = src->height;
        rect_.pitch = src->rowbytes / sizeof(pixel_type);

        if constexpr (std::is_same_v<pixel_type, PF_Pixel8>) {
            pixel_suite->get_pixel_data8(src_world_, nullptr, &ptr_);
        } else if constexpr (std::is_same_v<pixel_type, PF_Pixel16>) {
            pixel_suite->get_pixel_data16(src_world_, nullptr, &ptr_);
        } else if constexpr (std::is_same_v<pixel_type, PF_Pixel32>) {
            pixel_suite->get_pixel_data_float(src_world_, nullptr, &ptr_);
        }

        switch (pixel_format) {
            case PF_PixelFormat_ARGB32:
                assert((std::is_same_v<pixel_type, PF_Pixel8>));
                break;
            case PF_PixelFormat_ARGB64:
                assert((std::is_same_v<pixel_type, PF_Pixel16>));
                break;
            case PF_PixelFormat_ARGB128:
                assert((std::is_same_v<pixel_type, PF_Pixel32>));
                break;
            default:
                assert(false);
                break;
        }
    }

    pixel_type* get() noexcept { return ptr_; }

    pixel_type* const& ptr = ptr_;

    const RectType& rect = rect_;
    const int& width = rect.width;
    const int& height = rect.height;
    const int& pitch = rect.pitch;

  private:
    RectType rect_;
    PF_InData* in_data_;
    PF_OutData* out_data_;
    PF_EffectWorld* src_world_;
    PF_PixelFormat pixel_format;
    pixel_type* ptr_;
};

template <typename T>
using OutputWorld = InputWorld<T>;

#endif
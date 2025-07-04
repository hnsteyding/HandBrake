/* hwaccel.h
 *
 * Copyright (c) 2003-2025 HandBrake Team
 * This file is part of the HandBrake source code.
 * Homepage: <http://handbrake.fr/>.
 * It may be used under the terms of the GNU General Public License v2.
 * For full terms see the file COPYING file or visit http://www.gnu.org/licenses/gpl-2.0.html
 */

#ifndef HANDBRAKE_HWACCEL_COMMON_H
#define HANDBRAKE_HWACCEL_COMMON_H

#include "handbrake/hbffmpeg.h"

enum AVPixelFormat hw_hwaccel_get_hw_format(AVCodecContext *ctx, const enum AVPixelFormat *pix_fmts);
enum AVHWDeviceType hw_hwaccel_get_hw_device_type(AVBufferRef *hw_device_ctx);

const AVCodec * hb_hwaccel_find_decoder_by_name(enum AVCodecID codec_id, enum AVHWDeviceType type);

int hb_hwaccel_hw_ctx_init(int codec_id, int hw_decode, int device_index, void **hw_device_ctx);
void hb_hwaccel_hw_ctx_close(void **hw_device_ctx);

int hb_hwaccel_hwframes_ctx_init(AVCodecContext *ctx,
                                 enum AVPixelFormat hw_pix_fmt,
                                 enum AVPixelFormat sw_pix_fmt);

AVBufferRef *hb_hwaccel_init_hw_frames_ctx(AVBufferRef *hw_device_ctx,
                                       enum AVPixelFormat sw_fmt,
                                       enum AVPixelFormat hw_fmt,
                                       int width,
                                       int height,
                                       int initial_pool_size);
int hb_hwaccel_hwframe_init(hb_job_t *job, struct AVFrame **frame);
hb_buffer_t * hb_hwaccel_copy_video_buffer_to_hw_video_buffer(hb_job_t *job, hb_buffer_t **buf);

const char * hb_hwaccel_get_name(int hw_decode);
int hb_hwaccel_available(int codec_id, const char *device_name);
int hb_hwaccel_decode_is_enabled(hb_job_t *job);
int hb_hwaccel_is_full_hardware_pipeline_enabled(hb_job_t *job);

#endif // HANDBRAKE_HWACCEL_COMMON_H

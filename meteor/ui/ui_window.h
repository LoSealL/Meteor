/****************************************
 * Copyright (c) 2019 Wenyi Tang
 * Author: Wenyi Tang
 * E-mail: wenyitang@outlook.com
 * Description:
 ****************************************/
#ifndef METEOR_UI_UI_WINDOW_H_
#define METEOR_UI_UI_WINDOW_H_
#include <set>
#include <string>
#include <vector>
#include "imgui/imgui.h"
#include "ll_graphic/engine/engine.h"

namespace mt {
namespace ui {
constexpr char *kSupportedFormats[] = {
    "Decoder", "RGBA", "ARGB", "YUV", "Y", "NV12", "NV21", "YV12", "YV21",
};
// Same order as `kSupportedFormats`
enum { RGBA = 1, ARGB, YUV, Y, NV12, NV21, YV12, YV21 };

constexpr float kStatusBarHeight = 50;
constexpr float kTitleBarHeight = 88;

inline bool CheckFps(float fps) {
  int counts = static_cast<int>(roundf(60.f / fps));
  static int cnt_last = 0;
  cnt_last++;
  if (cnt_last >= counts) {
    cnt_last = 0;
    return true;
  }
  return false;
}

struct TitleBarInfo {
  bool image_view;
  bool image_compare;
  bool exp;
  bool player;
  ImVec2 pos;
  ImVec2 size;
};

struct TitleBarArgs {
  std::string name;
  uint32_t window_flag;
};

TitleBarInfo TitleBar(const TitleBarArgs &args);

struct ImageViewerInfo {
  ImVec2 pos;
  ImVec2 size;
  bool toggle_open;
  bool toggle_run;
  bool toggle_prev;
  bool toggle_next;
  bool toggle_jump;
  bool toggle_refresh;
  bool toggle_format_change;
  bool toggle_reset;
  std::string path;
  int format_id;
  int image_size[2];
  float image_pos_uv[4];
  int frame_num;
  float scale;
  float fps;
  ImVec2 image_cursor;
};

struct ImageViewerArgs {
  bool enable;
  uint32_t window_flag;
  ImVec2 parent_pos;
  ImVec2 parent_size;
  int image_size[2];
  int max_frame;
  ImTextureID tex_id;
  ImVec4 cursor_color;
};

ImageViewerInfo ImageViewer(const ImageViewerArgs &args);

void ImageViewerBehave(ll::engine::Env *e, ll::engine::core::Renderer *r,
                       const ImageViewerInfo &info, ImageViewerArgs *args);

struct ImageCompareInfo {
  ImVec2 pos;
  ImVec2 size;
  bool toggle_remove;
  bool toggle_run;
  bool toggle_prev;
  bool toggle_next;
  bool toggle_jump;
  bool toggle_refresh;
  bool toggle_format_change;
  bool toggle_reset;
  bool toggle_save;
  std::vector<std::string> paths;
  std::vector<std::string> saved_paths;
  int path_id;
  int format_id;
  int image_size[2];
  float image_pos_uv[4];
  int frame_num;
  float scale;
  float fps;
  int image_index;
  std::string image_name;
  ImVec2 image_cursor;
  ImVec4 bound_box;
  int bound_index;
  ImVec4 real_box;
};

struct ImageCompareArgs {
  bool enable;
  uint32_t window_flag;
  ImVec2 parent_pos;
  ImVec2 parent_size;
  int image_size[2];
  int max_frame;
  std::vector<ImTextureID> tex_ids;
  ImVec4 cursor_color;
  double global_psnr;
  double local_psnr;
};

ImageCompareInfo ImageCompare(const ImageCompareArgs &args);

void ImageCompareBehave(ll::engine::Env *e, ll::engine::core::Renderer *r,
                        const ImageCompareInfo &info, ImageCompareArgs *args);

struct StatusBarInfo {
  ImVec2 pos;
  ImVec2 size;
};

struct StatusBarArgs {
  uint32_t window_flag;
  ImVec2 parent_pos;
  ImVec2 parent_size;
  std::string image_name;
  ImVec2 cursor_coord;
  ImVec4 cursor_color;
  float scale;
  float local_psnr;
  ImVec2 local_rect;
  float global_psnr;
};

StatusBarInfo StatusBar(const StatusBarArgs &args);

struct ExpInfo {
  ImVec2 pos;
  ImVec2 size;
  char url[512];
  bool toggle_open;
  bool toggle_run;
  bool toggle_prev;
  bool toggle_next;
  bool toggle_jump;
  bool toggle_refresh;
  bool toggle_format_change;
  bool toggle_reset;
  bool toggle_connect;
  bool toggle_compare;
  std::string path;
  int format_id;
  int image_size[2];
  float image_pos_uv[4];
  int frame_num;
  float scale;
  ImVec2 image_cursor;
  ImVec2 select_offset;
  ImVec2 select_region;
};

struct ExpArgs {
  bool enable;
  uint32_t window_flag;
  ImVec2 parent_pos;
  ImVec2 parent_size;
  int image_size[2];
  int max_frame;
  ImTextureID tex_id;
  ImTextureID sub_tex_id[4];
  int subimage_size[8];
  ImVec4 cursor_color;
  bool connected;
};

ExpInfo ExpPanel(const ExpArgs &args);

void ExpActualBehave(ll::engine::Env *e, ll::engine::core::Renderer *r,
                     const ExpInfo &info, ExpArgs *args);

struct PlayerInfo {
  ImVec2 pos;
  ImVec2 size;
  bool toggle_reload;
  bool toggle_play;
  bool toggle_revert;
  int cam_id;
  int type_id;
  std::string name;
  float scale;
  ImVec2 image_cursor;
  ImVec4 cursor_color;
  int image_size[2];
  float image_pos_uv[4];
};

struct PlayerArgs {
  bool enable;
  bool playing;
  uint32_t window_flag;
  ImVec2 parent_pos;
  ImVec2 parent_size;
  std::vector<std::string> cams;
  std::vector<std::string> cam_types;
  uint32_t image_size[2];
  ImTextureID tex_id;
};

PlayerInfo PlayerPannel(const PlayerArgs &args);

void PlayerActualBehave(ll::engine::Env *e, ll::engine::core::Renderer *r,
                        const PlayerInfo &info, PlayerArgs *args);
}  // namespace ui
}  // namespace mt

extern std::string OnButtonOpenFile(std::string pth);

extern std::string OnButtonSaveFile(std::string);

extern std::vector<std::string> OnButtonOpenFile();
#endif  // METEOR_UI_UI_WINDOW_H_

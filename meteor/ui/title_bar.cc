#include "meteor/ui/ui_window.h"

TitleBarInfo TitleBar(const TitleBarArgs &args) {
  static TitleBarInfo ret_info{ true };
  ImGui::Begin(args.name.c_str(), nullptr,
               static_cast<ImGuiWindowFlags>(args.window_flag));
  const ImVec2 &kDispSize = ImGui::GetIO().DisplaySize;
  ret_info.pos = ImVec2{ kDispSize.x * 0.05f, kDispSize.y * 0.01f };
  ret_info.size = ImVec2{ kDispSize.x * 0.9f, 88 };
  ImGui::SetWindowPos(ret_info.pos, ImGuiCond_Always);
  ImGui::SetWindowSize(ret_info.size, ImGuiCond_Always);
  ImGui::TextColored(ImVec4{ 1,1,1,1 }, "Function Panel");
  ImGui::BeginChild("Unknown", ImVec2{ 0, 0 }, true);
  if (ImGui::Button("View Image")) {
    ret_info.image_view = true;
    ret_info.image_compare = false;
  }
  ImGui::SameLine();
  if (ImGui::Button("Compare")) {
    ret_info.image_compare = true;
    ret_info.image_view = false;
  }
  ImGui::EndChild();
  ImGui::End();
  return ret_info;
}
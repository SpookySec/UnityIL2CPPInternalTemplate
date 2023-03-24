#pragma once
#include "hook.hpp"
#include "../ext/imgui/imgui.h"

namespace Globals
{
    // Possible global vars here
    inline Hooks::HooksManager HookManager;
    // inline UnityEngine_Camera_o MainCamera{ NULL };

    namespace Gui
    {
        inline ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_AlwaysAutoResize |
            ImGuiWindowFlags_NoCollapse;
    }
}
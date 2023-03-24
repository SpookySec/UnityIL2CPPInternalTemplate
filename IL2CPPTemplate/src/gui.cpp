#include "../hdr/gui.hpp"

void InitMenu()
{
    // LIB SPECIFIC CODE
}

void Menu(bool render)
{
    ImGui::Begin("Cheat Menu", &render, Globals::Gui::windowFlags);
    // YOUR MENU HERE
    ImGui::ShowDemoWindow();
    if (Config::bButtons)                                  //CHECKS FOR CONFIG IF AUTOMATIC CREATION OF BUTTONS IS ENABLED
        for (Hooks::Hook* hook : Globals::HookManager.gHooks)  //CREATE A BUTTON FOR EACH HOOK
            createButton(
                hook,
                hook->name,
                hook->enabled
            );

    ImGui::End();
}

void createButton(Hooks::Hook* hook, std::string name, bool enabled)
{
    if (ImGui::Checkbox(name.c_str(), &enabled))
        hook->enabled ? hook->Disable() : hook->Enable();
}
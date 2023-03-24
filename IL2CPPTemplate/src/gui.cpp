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

    ImGui::End();
}
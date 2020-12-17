#include "LoseScreen.h"


using namespace godot;

void LoseScreen::_register_methods() {
    register_method("_init", &LoseScreen::_init);
    register_method("_on_RestartGame_pressed", &LoseScreen::_on_RestartGame_pressed);
    register_method("_on_ExitGame_pressed", &LoseScreen::_on_ExitGame_pressed);
    register_method("_process", &LoseScreen::_process);
}

LoseScreen::LoseScreen()
{
}

LoseScreen::~LoseScreen()
{
}

void LoseScreen::_init()
{
    input = Input::get_singleton();
}

void LoseScreen::_process() {
    if (input->is_action_pressed("ui_accept")) {
        _on_RestartGame_pressed(0);
    }
    if (input->is_action_pressed("ui_cancel")) {
        _on_ExitGame_pressed(0);
    }
}

void LoseScreen::_on_RestartGame_pressed(Variant)
{
    SceneManager* sceneManager = sceneManager->GetInstance();
    sceneManager->SwapScene("Lose.tscn", "Game.tscn", this);
    GameLoop::SetMetaState(MetaState::Gameplay);
}

void LoseScreen::_on_ExitGame_pressed(Variant)
{
    get_tree()->quit();
}

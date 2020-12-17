#include "LoseScreen.h"


using namespace godot;

void LoseScreen::_register_methods() {
    register_method("_init", &LoseScreen::_init);
    register_method("_on_RestartGame_pressed", &LoseScreen::_on_RestartGame_pressed);
    register_method("_on_ExitGame_pressed", &LoseScreen::_on_ExitGame_pressed);
}

LoseScreen::LoseScreen()
{
}

LoseScreen::~LoseScreen()
{
}

void LoseScreen::_init()
{
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

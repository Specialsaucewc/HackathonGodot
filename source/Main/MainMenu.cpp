#include "MainMenu.h"


using namespace godot;

void MainMenu::_register_methods() {
    register_method("_init", &MainMenu::_init);
    register_method("_ready", &MainMenu::_ready);
    register_method("_process", &MainMenu::_process);
    register_method("_on_LoadGame_pressed", &MainMenu::_on_LoadGame_pressed);
}

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::_ready()
{
}

void MainMenu::_init()
{
    input = Input::get_singleton();
}

void MainMenu::_process(float delta)
{
    if (input->is_action_pressed("ui_accept")) {
        _on_LoadGame_pressed(0);
    }
}

void MainMenu::_on_LoadGame_pressed(Variant)
{
    SceneManager* sceneManager = sceneManager->GetInstance();
    //sceneManager->LoadScene("Example.tscn", this);
    sceneManager->SwapScene("MainMenu.tscn", "Game.tscn", this);
    GameLoop::SetMetaState(MetaState::Gameplay);
}

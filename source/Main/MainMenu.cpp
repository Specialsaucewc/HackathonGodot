#include "MainMenu.h"
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>

#include "SceneManager.h"

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
}

void MainMenu::_process(float delta)
{
}

void MainMenu::_on_LoadGame_pressed(Variant)
{
    SceneManager* sceneManager = sceneManager->GetInstance();
    //sceneManager->LoadScene("Example.tscn", this);
    sceneManager->SwapScene("MainMenu.tscn", "Game.tscn", this);
}

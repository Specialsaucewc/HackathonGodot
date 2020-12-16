#include "GameLoop.h"
#include <ResourceLoader.hpp>

using namespace godot;

void GameLoop::_register_methods() {
    register_method("_ready", &GameLoop::_ready);
    register_method("_init", &GameLoop::_init);
    register_method("_process", &GameLoop::_process);
}

GameLoop::GameLoop()
{
    sceneManager = sceneManager->GetInstance();
}

GameLoop::~GameLoop()
{
}

void GameLoop::_ready()
{
    sceneManager->LoadScene("MainMenu.tscn", this);
}

void GameLoop::_init()
{   
}

void GameLoop::_process(float delta)
{
    // Main game loop here
}
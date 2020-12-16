#include "GameLoop.h"

using namespace godot;
MetaState* GameLoop::metaState = NULL;
bool GameLoop::stateChanged = false;

void GameLoop::_register_methods() {
    register_method("_ready", &GameLoop::_ready);
    register_method("_init", &GameLoop::_init);
    register_method("_process", &GameLoop::_process);

    register_property("hex_spawn_time", &GameLoop::hexSpawnTime, 5.0f);
}

GameLoop::GameLoop()
{
    sceneManager = sceneManager->GetInstance();
    //sceneManager->SetRootNode(this);
}

GameLoop::~GameLoop()
{
}

void GameLoop::_ready()
{
    sceneManager->LoadScene("MainMenu.tscn", this);
    SetMetaState(MetaState::MainMenu);
}

void GameLoop::_init()
{   
}

void GameLoop::_process(float delta)
{
    // Main game loop here
    if (debugMode)
    {
        if (stateChanged)
        {
            godot::String currentMetaState;
            switch (*GetMetaState())
            {
            case MetaState::MainMenu:
                currentMetaState = "MainMenu";
                break;
            case MetaState::Gameplay:
                currentMetaState = "Gameplay";
                break;
            default:
                currentMetaState = "N/A";
                break;
            }

            Godot::print("Game Sate: " + currentMetaState);
            stateChanged = false;
        }
    }

    switch (*GetMetaState())
    {
    case MetaState::Gameplay:
        // Gameplay stuff here
        secondsSinceLastSpawn += delta;
        if (secondsSinceLastSpawn > hexSpawnTime)
        {
            secondsSinceLastSpawn = fmod(secondsSinceLastSpawn, hexSpawnTime);
            sceneManager->LoadScene("Hex.tscn", this);

            if (debugMode)
            {
                Godot::print("Hex Added");
            }
        }
        break;
    }
}
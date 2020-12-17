#include "GameTimer.h"

using namespace godot;

GameTimer::GameTimer() 
{

}

GameTimer::~GameTimer() 
{

}

void GameTimer::_register_methods() 
{
    register_method("_init", &GameTimer::_init);
    register_method("_process", &GameTimer::_process);
}

void GameTimer::_init() 
{
}

void GameTimer::_process() 
{
    float gametime = *GameLoop::GetGameTime();
    char buffer[64];
    int ret = snprintf(buffer, sizeof buffer, "%.*f",2, gametime);

    set_text(buffer);
}
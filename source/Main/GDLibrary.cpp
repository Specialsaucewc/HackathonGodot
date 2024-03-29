#include "GameLoop.h"
#include "MainMenu.h"
#include "Player.h"
#include "Hex.h"
#include "LoseScreen.h"
#include "GameTimer.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle) {
    godot::Godot::nativescript_init(handle);

    godot::register_class<godot::GameLoop>();
    godot::register_class<godot::MainMenu>();
    godot::register_class<godot::Player>();
    godot::register_class<godot::Hex>();
    godot::register_class<godot::LoseScreen>();
    godot::register_class<godot::GameTimer>();
}
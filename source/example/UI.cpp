#include "UI.h"
#include <ResourceLoader.hpp>

using namespace godot;

void UI::_register_methods() {
    register_method("_ready", &UI::_ready);
    register_method("_process", &UI::_process);
    register_method("_on_LoadGame_pressed", &UI::_on_LoadGame_pressed);
}

UI::UI()
{
}

UI::~UI()
{
}

void UI::_ready()
{
    ResourceLoader* loader = ResourceLoader::get_singleton();
    mainGame = loader->load("res://scenes/Example.tscn");
}

void UI::_init()
{
}

void UI::_process(float delta)
{
}

void UI::_on_LoadGame_pressed(Variant)
{
    SceneTree* tree = get_tree();
    //tree->change_scene_to(mainGame);
    Node* testNode = get_node("Test");
    Node* sceneToLoad = mainGame->instance();
    testNode->add_child(sceneToLoad);
}

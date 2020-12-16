#include <ResourceLoader.hpp>
#include "SceneManager.h"

using namespace godot;

void SceneManager::_register_methods()
{
    register_method("_init", &SceneManager::_init);
    register_method("_process", &SceneManager::_process);
    register_method("_on_LoadGame_pressed", &SceneManager::LoadScene);
}

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::_init()
{
}

void SceneManager::_process()
{
}

void SceneManager::LoadScene(const godot::String sceneToLoad, Node* callingNode)
{
    ResourceLoader* loader = ResourceLoader::get_singleton();
    _currentScene = loader->load("res://scenes/" + sceneToLoad);
    
    Node* scene = _currentScene->instance();
    Node* testRoot = callingNode->get_tree()->get_current_scene()->get_node("SceneRootNode");
    
    testRoot->add_child(scene);
}
#include <ResourceLoader.hpp>
#include "SceneManager.h"
#include <iostream>
#include <fstream>

using namespace godot;

SceneManager* SceneManager::instance = NULL;

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
    Node* sceneRoot = GetRootSceneNode(callingNode);

    sceneRoot->add_child(scene);
}

void SceneManager::UnloadScene(const godot::String sceneToUnload, Node* callingNode)
{
    Node* sceneRoot = GetRootSceneNode(callingNode);
}

void SceneManager::SwapScene(const godot::String sceneToUnload, const godot::String sceneToLoad, Node* callingNode)
{
    Node* sceneRoot = GetRootSceneNode(callingNode);
}

Node* SceneManager::GetRootSceneNode(Node* callingNode)
{
    Node* sceneRoot = callingNode->get_tree()->get_current_scene()->get_node("SceneRootNode");
    return sceneRoot;
}
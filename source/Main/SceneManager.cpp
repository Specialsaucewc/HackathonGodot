#include "SceneManager.h"
#include <iostream>
#include <fstream>

using namespace godot;

SceneManager* SceneManager::instance = NULL;
//Node* SceneManager::sceneRootNode = NULL;
//bool SceneManager::sceneRootNodeSet = false;

void SceneManager::_init(Node* callingNode)
{
}

void SceneManager::_process()
{
}

void SceneManager::LoadScene(const godot::String sceneToLoad, Node* callingNode)
{
    Ref<PackedScene> _currentScene = loader->load("res://scenes/" + sceneToLoad);

    Node* scene = _currentScene->instance();
    activeScenes.insert(std::make_pair(sceneToLoad, scene));
    Node* sceneRoot = GetRootSceneNode(callingNode);

    sceneRoot->add_child(scene);
}

void SceneManager::UnloadScene(const godot::String sceneToUnload, Node* callingNode)
{
    Node* sceneRoot = GetRootSceneNode(callingNode);

    std::map<godot::String, Node*>::iterator sceneMap = activeScenes.find(sceneToUnload);
    if (sceneMap != activeScenes.end())
    {
        Node* unloadingScene = sceneMap->second;
        unloadingScene->queue_free();
        activeScenes.erase(sceneMap);
    }
}

void SceneManager::SwapScene(const godot::String sceneToUnload, const godot::String sceneToLoad, Node* callingNode)
{
    UnloadScene(sceneToUnload, callingNode);
    LoadScene(sceneToLoad, callingNode);
}

Node* SceneManager::GetRootSceneNode(Node* callingNode)
{
    Node* sceneRoot = callingNode->get_tree()->get_current_scene()->get_node("SceneRootNode");
    return sceneRoot;
}
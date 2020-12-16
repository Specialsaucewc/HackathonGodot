#pragma once
#include <Godot.hpp>
#include <SceneTree.hpp>
#include <PackedScene.hpp>
#include <Node.hpp>

namespace godot {

    class SceneManager
    {

    private:
        static SceneManager* instance;
        SceneManager() {};
        ~SceneManager() {};

        Node* rootSceneNode = nullptr;
        Ref<PackedScene> _currentScene;
        Node* _currentSceneNode;

        Node* GetRootSceneNode(Node* callingNode);

    public:       
        static SceneManager* GetInstance() {
            if (!instance)
                instance = new SceneManager;
            return instance;
        }

        void _init();
        void _process();
        void LoadScene(const godot::String sceneToLoad, Node* callingNode);
        void UnloadScene(const godot::String sceneToUnload, Node* rootNode);
        void SwapScene(const godot::String sceneToUnload, const godot::String sceneToLoad, Node* callingNode);
    };
}
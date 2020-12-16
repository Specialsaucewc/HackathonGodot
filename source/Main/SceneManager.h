#pragma once
#include <Godot.hpp>
#include <SceneTree.hpp>
#include <PackedScene.hpp>
#include <Node.hpp>

namespace godot {

    class SceneManager : public Node
    {
        GODOT_CLASS(SceneManager, Node)

    private:
        Node* rootSceneNode = nullptr;
        Ref<PackedScene> _currentScene;

    public:
        static void _register_methods();

        SceneManager();
        ~SceneManager();

        void _init();
        void _process();
        void LoadScene(const godot::String sceneToLoad, Node* rootNode);
    };
}
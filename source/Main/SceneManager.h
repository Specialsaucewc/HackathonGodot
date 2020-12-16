#pragma once
#include <Godot.hpp>
#include <SceneTree.hpp>
#include <PackedScene.hpp>
#include <Node.hpp>
#include <map>
#include <ResourceLoader.hpp>

namespace godot {

    class SceneManager
    {

    private:
        static SceneManager* instance;
        //static Node* sceneRootNode;
        //static bool sceneRootNodeSet;

        SceneManager() {
            loader = ResourceLoader::get_singleton();
        };
        ~SceneManager() {};

        ResourceLoader* loader = nullptr;
        Node* rootSceneNode = nullptr;
        Node* _currentSceneNode;

        std::map<godot::String, Node*> activeScenes;

        Node* GetRootSceneNode(Node* callingNode);

    public:       
        static SceneManager* GetInstance() {
            if (!instance)
                instance = new SceneManager;
            return instance;
        }

        /*static Node* GetRootNode()
        {
            if (sceneRootNode)
            {
                return sceneRootNode;
            }
        }*/

        /*static void SetRootNode(Node* callingNode)
        {
            if (!sceneRootNodeSet)
            {
                sceneRootNode = callingNode->get_tree()->get_current_scene()->get_node("SceneRootNode");
                sceneRootNodeSet = true;
            }
        }*/

        void _init(Node* callingNode);
        void _process();
        void LoadScene(const godot::String sceneToLoad, Node* callingNode);
        void UnloadScene(const godot::String sceneToUnload, Node* callingNode);
        void SwapScene(const godot::String sceneToUnload, const godot::String sceneToLoad, Node* callingNode);
    };
}
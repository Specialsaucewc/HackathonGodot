#pragma once
#include <Godot.hpp>
#include <Node.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include "SceneManager.h"

namespace godot {
    
	class GameLoop : public Node {
		GODOT_CLASS(GameLoop, Node)
            
		private:
			Ref<PackedScene> mainGame;
			Node* mainGameNode = nullptr;
			SceneManager* sceneManager;

        public:
		static void _register_methods();
        
		GameLoop();
		~GameLoop();
        
		void _ready();
		void _init();
		void _process(float delta);
	};
}
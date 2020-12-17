#pragma once
#include <Godot.hpp>
#include <Node.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <ResourceLoader.hpp>
#include <Input.hpp>

#include "SceneManager.h"

namespace godot {

	enum class MetaState {
		Null,
		MainMenu,
		HowToMenu,
		Gameplay,
		Paused,
		GameLost,
		GameWon
	};
    
	class GameLoop : public Node {
		GODOT_CLASS(GameLoop, Node)
            
		private:
			static MetaState* metaState;
			Node* mainGameNode = nullptr;
			SceneManager* sceneManager;

			// Hex spawn
			float secondsSinceLastSpawn = 0.0f;
			float hexSpawnTime = 5.0f;

			// Debug
			bool debugMode = true;
			static bool stateChanged;
			Input* input;

        public:
		static void _register_methods();

		static MetaState* GetMetaState() {
			if (!metaState)
			{
				metaState = new MetaState;
				SetMetaState(MetaState::MainMenu);
			}
			return metaState;
		};

		static void SetMetaState(MetaState newState)
		{
			if (!metaState)
			{
				metaState = new MetaState;
			}
			*metaState = newState;
			stateChanged = true;
		};
        
		GameLoop();
		~GameLoop();
        
		void _ready();
		void _init();
		void _process(float delta);
	};
}
#pragma once
#include <Godot.hpp>
#include <Node.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
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

			Ref<PackedScene> mainGame;
			Node* mainGameNode = nullptr;
			SceneManager* sceneManager;

			// Debug
			bool debugMode = true;
			static bool stateChanged;

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
#pragma once
#include <Godot.hpp>
#include <Control.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <Variant.hpp>
#include <ResourceLoader.hpp>

#include "SceneManager.h"
#include "GameLoop.h"

namespace godot {
    
	class MainMenu : public Control {
		GODOT_CLASS(MainMenu, Control)
            
        private:
			Input* input;
        
        public:
		static void _register_methods();
        
		MainMenu();
		~MainMenu();
        
		void _ready();
		void _init();
		void _process(float delta);
		void _on_LoadGame_pressed(Variant body);
	};
}
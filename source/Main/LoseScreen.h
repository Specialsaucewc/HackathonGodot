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

	class LoseScreen : public Control {
		GODOT_CLASS(LoseScreen, Control)

	private:
		Input* input;

	public:
		static void _register_methods();

		LoseScreen();
		~LoseScreen();

		void _init();
		void _on_RestartGame_pressed(Variant body);
		void _on_ExitGame_pressed(Variant body);
		void _process();
	};
}
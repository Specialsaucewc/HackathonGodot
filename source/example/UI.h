#pragma once
#include <Godot.hpp>
#include <Control.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <Variant.hpp>
#include <Tree.hpp>

namespace godot {

	class UI : public Control {
		GODOT_CLASS(UI, Control)

	private:
		Ref<PackedScene> mainGame;

	public:
		static void _register_methods();

		UI();
		~UI();

		void _ready();
		void _init();
		void _process(float delta);
		void _on_LoadGame_pressed(Variant body);
	};
}
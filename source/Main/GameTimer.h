#pragma once
#include <Godot.hpp>
#include <Label.hpp>

#include "GameLoop.h"

namespace godot {
	class GameTimer : public Label {
		GODOT_CLASS(GameTimer, Label)

	private:
	public:
		static void _register_methods();
		GameTimer();
		~GameTimer();

		void _init();
		void _process();
	};
}
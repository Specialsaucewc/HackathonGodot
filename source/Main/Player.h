#pragma once
#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <Input.hpp>

namespace godot {

    class Player : public KinematicBody2D {
        GODOT_CLASS(Player, KinematicBody2D)

    private:
        float rotation;
        float moveSpeed;
        Input* input;
        void apply_rotation(float rot);
        float get_input();

    public:
        static void _register_methods();

        Player();
        ~Player();

        void _init(); // our initializer called by Godot

        void _physics_process(float delta);
    };

}
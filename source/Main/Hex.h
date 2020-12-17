#pragma once
#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include "SceneManager.h"
#include "GameLoop.h"

namespace godot {

    class Hex : public KinematicBody2D {
        GODOT_CLASS(Hex, KinematicBody2D)

    private:
        float rotation;
        float moveSpeed = 4.;
        float maxRotationSpeed = 4.;
        float rotationSpeed = 4.;
        Vector2 scale = Vector2(6.,6.);
        void apply_scale(float scaleChange);
        void apply_rotation(float rot);
        SceneManager* sceneManager;

    public:
        static void _register_methods();

        Hex();
        ~Hex();

        void _init(); // our initializer called by Godot

        void _process();
        void _physics_process(float delta);
        void _on_Area2D_body_entered(Variant);
    };

}
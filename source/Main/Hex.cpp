#include "Hex.h"

using namespace godot;

void Hex::_register_methods() {
    register_method("_physics_process", &Hex::_physics_process);
    register_method("_init", &Hex::_init);
    register_method("_on_Area2D_body_entered", &Hex::_on_Area2D_body_entered);

    register_property("move_speed", &Hex::moveSpeed, 4.f);
    register_property("starting_scale", &Hex::scale, Vector2(6., 6.));
}

Hex::Hex() {
}

Hex::~Hex() {
    // add your cleanup here
}

void Hex::_init() {
    // initialize any variables here
    rotation = get_rotation();
    scale = get_scale();
}

void Hex::_physics_process(float delta) {

    float newScale = (delta * moveSpeed);
    apply_scale(newScale);
}

void Hex::apply_scale(float scaleChange) {
    scale = Vector2(scale.x - scaleChange, scale.y - scaleChange);
    set_scale(scale);

    if (scale.x < .3) {
        queue_free();
    }
}

void _on_Area2D_body_entered(Variant) {
    Godot::print("Hello?");
}
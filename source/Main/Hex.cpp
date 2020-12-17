#include "Hex.h"

using namespace godot;

void Hex::_register_methods() {
    register_method("_physics_process", &Hex::_physics_process);
    register_method("_init", &Hex::_init);
    register_method("_process", &Hex::_process);
    register_method("_on_Area2D_body_entered", &Hex::_on_Area2D_body_entered);

    register_property("move_speed", &Hex::moveSpeed, 4.f);
    register_property("rotation_speed", &Hex::maxRotationSpeed, 4.f);
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
    sceneManager = sceneManager->GetInstance();
    float a = 5;
    rotationSpeed = float(rand()) / float((RAND_MAX)) * maxRotationSpeed;
    float rotationDir = rand() - (RAND_MAX / 2);
    rotationSpeed *= (rotationDir > 0) - (rotationDir < 0);
}

void Hex::_process()
{
    if (*GameLoop::GetMetaState() == MetaState::GameLost)
    {
        queue_free();
    }
}

void Hex::_physics_process(float delta) {
    float newScale = (delta * moveSpeed);
    apply_scale(newScale);

    float newRotation = (delta * rotationSpeed);
    apply_rotation(newRotation);
}

void Hex::apply_scale(float scaleChange) {
    scale = Vector2(scale.x - scaleChange, scale.y - scaleChange);
    set_scale(scale);

    if (scale.x < .35) {
        queue_free();
    }
}

void Hex::apply_rotation(float rot) {
    rotation = fmod(rotation + rot, 360);
    set_rotation(rotation);
}

void Hex::_on_Area2D_body_entered(Variant) {
    sceneManager->SwapScene("Game.tscn", "Lose.tscn", this);
    GameLoop::SetMetaState(MetaState::GameLost);
    queue_free();
}
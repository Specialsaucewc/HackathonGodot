#include "Player.h"

using namespace godot;

void Player::_register_methods() {
    register_method("_physics_process", &Player::_physics_process);
    register_method("_init", &Player::_init);
}

Player::Player() {
}

Player::~Player() {
    // add your cleanup here
}

void Player::_init() {
    // initialize any variables here
    rotation = get_rotation();
}

void Player::_physics_process(float delta) {
    float axis = get_input();

    float new_rotation = rotation + 1;
    apply_rotation(new_rotation);
}

float Player::get_input() {
    float axis = 0;
    if (Input.IsActionPressed("player_left")) {
        return axis -= 1;
    }
    if (Input.IsActionPressed("player_right")) {
        return axis += 1;
    }
    return axis;
}


void Player::apply_rotation(float rot) {
    rotation = fmod(rotation + rot, 360);

    set_rotation(rotation);
}
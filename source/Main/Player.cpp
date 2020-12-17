#include "Player.h"

using namespace godot;

void Player::_register_methods() {
    register_method("_physics_process", &Player::_physics_process);
    register_method("_init", &Player::_init);
    register_property("move_speed", &Player::moveSpeed, 10.f);
}

Player::Player() {
}

Player::~Player() {
    // add your cleanup here
}

void Player::_init() {
    // initialize any variables here
    rotation = get_rotation();
    input = Input::get_singleton();
}

void Player::_physics_process(float delta) {
    float axis = get_input();

    float new_rotation = (axis*delta*moveSpeed);
    apply_rotation(new_rotation);

    //Godot::print(this->get_transform());
    /*if (test_move(this->get_transform(), get_facing_vector(), false)) {
        Godot::print("Game Over");
    }*/
    //Ref<KinematicCollision2D> collision = move_and_collide(this->get_facing_vector(), true, true, true);
    
    
}

float Player::get_input() {
    float axis = 0;
    if (input->is_action_pressed("player_left")) {
        return axis -= 1;
    }
    if (input->is_action_pressed("player_right")) {
        return axis += 1;
    }
    return axis;
}


Vector2 Player::get_facing_vector() {
    return Vector2(-sinf(rotation), cos(rotation));
}

void Player::apply_rotation(float rot) {
    rotation = fmod(rotation + rot, 360);

    set_rotation(rotation);
}
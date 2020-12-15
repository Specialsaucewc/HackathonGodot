#include "GDExample.h"

using namespace godot;

void GDExample::_register_methods() {
    register_method("_process", &GDExample::_process);
}

GDExample::GDExample() {
}

GDExample::~GDExample() {
    // add your cleanup here
}

void GDExample::_init() {
    // initialize any variables here
    time_passed = 0.0;
    color.r = 1.0f;
    color.b = 1.0f;
    color.g = 1.0f;
}

void GDExample::_process(float delta) {
    time_passed += delta;
    
    Vector2 new_position = Vector2(10.0 + (100.0 * sin(time_passed * 2.0)), 10.0 + (100.0 * cos(time_passed * 1.5)));
    color.r = .5 + .5 * sin(time_passed);
    color.b = .5 + .5 * sin(time_passed + 2);
    color.g = .5 + .5 * sin(time_passed + 4);

    set_modulate(color);
    set_position(new_position);
}
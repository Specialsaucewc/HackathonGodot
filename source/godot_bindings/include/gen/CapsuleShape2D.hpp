#ifndef GODOT_CPP_CAPSULESHAPE2D_HPP
#define GODOT_CPP_CAPSULESHAPE2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Shape2D.hpp"
namespace godot {


class CapsuleShape2D : public Shape2D {
	struct ___method_bindings {
		godot_method_bind *mb_get_height;
		godot_method_bind *mb_get_radius;
		godot_method_bind *mb_set_height;
		godot_method_bind *mb_set_radius;
	};
	static ___method_bindings ___mb;
	static void *_detail_class_tag;

public:
	static void ___init_method_bindings();
	inline static size_t ___get_id() { return (size_t)_detail_class_tag; }

	static inline const char *___get_class_name() { return (const char *) "CapsuleShape2D"; }
	static inline const char *___get_godot_class_name() { return (const char *) "CapsuleShape2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (o) ? (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o) : nullptr; }

	// enums

	// constants


	static CapsuleShape2D *_new();

	// methods
	real_t get_height() const;
	real_t get_radius() const;
	void set_height(const real_t height);
	void set_radius(const real_t radius);

};

}

#endif
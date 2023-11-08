#include "ac_round_clipping_container.h"

#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

using namespace godot;

void ACRoundClippingContainer::_bind_methods(){}

ACRoundClippingContainer::ACRoundClippingContainer(){
	set_clip_children_mode(CLIP_CHILDREN_ONLY);
}

ACRoundClippingContainer::~ACRoundClippingContainer(){}

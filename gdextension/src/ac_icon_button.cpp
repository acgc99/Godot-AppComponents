#include "ac_icon_button.h"

#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

using namespace godot;

void ACIconButton::_bind_methods(){}

ACIconButton::ACIconButton(){
	set_flat(true);
	set_icon_alignment(HORIZONTAL_ALIGNMENT_CENTER);
	set_expand_icon(true);
}

ACIconButton::~ACIconButton(){}

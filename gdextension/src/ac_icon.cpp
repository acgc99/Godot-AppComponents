#include "ac_icon.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;


ACIcon::ACIcon(){
    set_expand_mode(EXPAND_IGNORE_SIZE);
    set_stretch_mode(STRETCH_KEEP_ASPECT_CENTERED);
}


ACIcon::~ACIcon(){}


void ACIcon::_bind_methods(){}

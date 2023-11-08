#include "ac_page_container.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;


ACPageContainer::ACPageContainer(){
    add_theme_constant_override("separation", 0);
}


ACPageContainer::~ACPageContainer(){}


void ACPageContainer::_bind_methods(){}

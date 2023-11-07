#include "ac_page.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;


ACPage::ACPage(){
    add_theme_constant_override("separation", 0);
}


ACPage::~ACPage(){}


void ACPage::_bind_methods(){}

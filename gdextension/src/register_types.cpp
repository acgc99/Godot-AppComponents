#include "register_types.h"

#include "ac_animated_control.h"
#include "ac_http_image.h"
#include "ac_icon.h"
#include "ac_icon_button.h"
#include "ac_page_container.h"
#include "ac_round_clipping_container.h"

#include "gdextension_interface.h"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/defs.hpp"
#include "godot_cpp/godot.hpp"

using namespace godot;

void initialize_ac(ModuleInitializationLevel p_level){
    if(p_level != MODULE_INITIALIZATION_LEVEL_SCENE){
        return;
    }
    ClassDB::register_class<ACAnimatedControl>();
    ClassDB::register_class<ACHTTPImage>();
    ClassDB::register_class<ACIcon>();
    ClassDB::register_class<ACIconButton>();
    ClassDB::register_class<ACPageContainer>();
    ClassDB::register_class<ACRoundClippingContainer>();
}

void uninitialize_ac(ModuleInitializationLevel p_level){
    if(p_level != MODULE_INITIALIZATION_LEVEL_SCENE){
        return;
    }
}

extern "C"{
    GDExtensionBool GDE_EXPORT ac_init(
        GDExtensionInterfaceGetProcAddress p_get_proc_address,
        const GDExtensionClassLibraryPtr p_library,
        GDExtensionInitialization *r_initialization){
            godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
            init_obj.register_initializer(initialize_ac);
            init_obj.register_terminator(uninitialize_ac);
            init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
            return init_obj.init();
        }
}

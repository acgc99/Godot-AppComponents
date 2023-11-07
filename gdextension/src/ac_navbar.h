#ifndef AC_NAVBAR_H
#define AC_NAVBAR_H

#include <godot_cpp/classes/panel_container.hpp>

namespace godot{

    class ACNavBar: public PanelContainer{
        GDCLASS(ACNavBar, PanelContainer)

        public:
            ACNavBar();
            ~ACNavBar();
        private:
        protected:
            static void _bind_methods();

    };
}

#endif AC_NAVBAR_H

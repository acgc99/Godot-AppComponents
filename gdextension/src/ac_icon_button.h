#ifndef AC_ICON_BUTTON_H
#define AC_ICON_BUTTON_H

#include <godot_cpp/classes/button.hpp>

namespace godot{

    class ACIconButton: public Button{
        GDCLASS(ACIconButton, Button)

        public:
            ACIconButton();
            ~ACIconButton();
        private:
        protected:
            static void _bind_methods();

    };
}

#endif AC_ICON_BUTTON_H

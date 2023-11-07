#ifndef AC_PAGE_H
#define AC_PAGE_H

#include <godot_cpp/classes/v_box_container.hpp>

namespace godot{

    class ACPage: public VBoxContainer{
        GDCLASS(ACPage, VBoxContainer)

        public:
            ACPage();
            ~ACPage();
        private:
        protected:
            static void _bind_methods();

    };
}

#endif AC_PAGE_H

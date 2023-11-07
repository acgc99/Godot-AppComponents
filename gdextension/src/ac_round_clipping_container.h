#ifndef AC_ROUND_CLIPPING_CONTAINER_H
#define AC_NAVBAC_ROUND_CLIPPING_CONTAINER_HAR_H

#include <godot_cpp/classes/panel_container.hpp>

namespace godot{

    class ACRoundClippingContainer: public PanelContainer{
        GDCLASS(ACRoundClippingContainer, PanelContainer)

        public:
            ACRoundClippingContainer();
            ~ACRoundClippingContainer();
        private:
        protected:
            static void _bind_methods();

    };
}

#endif AC_ROUND_CLIPPING_CONTAINER_H

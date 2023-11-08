#ifndef AC_ROUND_CLIPPING_CONTAINER_H
#define AC_ROUND_CLIPPING_CONTAINER_H

#include "godot_cpp/classes/panel_container.hpp"

namespace godot{

	class ACRoundClippingContainer: public PanelContainer{
		GDCLASS(ACRoundClippingContainer, PanelContainer)

		protected:
			static void _bind_methods();

		public:
			ACRoundClippingContainer();
			~ACRoundClippingContainer();
	};
}

#endif AC_ROUND_CLIPPING_CONTAINER_H

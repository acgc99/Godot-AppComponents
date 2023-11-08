#ifndef AC_PAGE_CONTAINER_H
#define AC_PAGE_CONTAINER_H

#include "godot_cpp/classes/v_box_container.hpp"

namespace godot{

	class ACPageContainer: public VBoxContainer{
		GDCLASS(ACPageContainer, VBoxContainer)

		protected:
			static void _bind_methods();

		public:
			ACPageContainer();
			~ACPageContainer();
	};
}

#endif AC_PAGE_CONTAINER_H

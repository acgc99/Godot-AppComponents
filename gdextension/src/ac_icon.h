#ifndef AC_ICON_H
#define AC_ICON_H

#include "godot_cpp/classes/texture_rect.hpp"

namespace godot{

	class ACIcon: public TextureRect{
		GDCLASS(ACIcon, TextureRect)

		protected:
			static void _bind_methods();

		public:
			ACIcon();
			~ACIcon();
	};
}

#endif AC_ICON_H

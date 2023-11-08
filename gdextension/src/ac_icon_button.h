#ifndef AC_ICON_BUTTON_H
#define AC_ICON_BUTTON_H

#include "godot_cpp/classes/button.hpp"

namespace godot{

	class ACIconButton: public Button{
		GDCLASS(ACIconButton, Button)

		private:

		protected:
			static void _bind_methods();

		public:
			ACIconButton();
			~ACIconButton();
	};
}

#endif AC_ICON_BUTTON_H

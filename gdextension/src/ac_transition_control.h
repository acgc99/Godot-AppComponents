#ifndef AC_TRANSITION_CONTROL_H
#define AC_TRANSITION_CONTROL_H

#include "godot_cpp/classes/control.hpp"
#include "godot_cpp/classes/property_tweener.hpp"
#include "godot_cpp/classes/tween.hpp"

namespace godot{

	class ACTransitionControl: public Control{
		GDCLASS(ACTransitionControl, Control)

		public:
			enum Animation {
				ANIMATION_VANISH,
				ANIMATION_TRANSLATE_LEFT,
				ANIMATION_TRANSLATE_LEFT_UP,
				ANIMATION_TRANSLATE_UP,
				ANIMATION_TRANSLATE_RIGHT_UP,
				ANIMATION_TRANSLATE_RIGHT,
				ANIMATION_TRANSLATE_RIGHT_DOWN,
				ANIMATION_TRANSLATE_DOWN,
				ANIMATION_TRANSLATE_LEFT_DOWN,
				ANIMATION_SHRINK_LEFT,
				ANIMATION_SHRINK_LEFT_UP,
				ANIMATION_SHRINK_UP,
				ANIMATION_SHRINK_RIGHT_UP,
				ANIMATION_SHRINK_RIGHT,
				ANIMATION_SHRINK_RIGHT_DOWN,
				ANIMATION_SHRINK_DOWN,
				ANIMATION_SHRINK_LEFT_DOWN,
				ANIMATION_SHRINK_CENTER,
				ANIMATION_EXPAND_LEFT,
				ANIMATION_EXPAND_LEFT_UP,
				ANIMATION_EXPAND_UP,
				ANIMATION_EXPAND_RIGHT_UP,
				ANIMATION_EXPAND_RIGHT,
				ANIMATION_EXPAND_RIGHT_DOWN,
				ANIMATION_EXPAND_DOWN,
				ANIMATION_EXPAND_LEFT_DOWN,
				ANIMATION_EXPAND_CENTER
			};

		private:
			double duration = 1.0;
			ACTransitionControl::Animation animation = ANIMATION_VANISH;
			Tween::EaseType ease = Tween::EASE_IN_OUT;
			Tween::TransitionType transition = Tween::TRANS_LINEAR;
			double initial_alpha = 1.0;
			Vector2 initial_position = Vector2(0, 0);
			Vector2 initial_scale = Vector2(1, 1);

			Ref<Tween> _tween;

			void _reset_properties();
			void _create_tween();
			void _on_tween_finished();

			void _transit_vanish();
			void _transit_translate_left();
			void _transit_translate_left_up();
			void _transit_translate_up();
			void _transit_translate_right_up();
			void _transit_translate_right();
			void _transit_translate_right_down();
			void _transit_translate_down();
			void _transit_translate_left_down();
			void _transit_shrink_left();
			void _transit_shrink_left_up();
			void _transit_shrink_up();
			void _transit_shrink_right_up();
			void _transit_shrink_right();
			void _transit_shrink_right_down();
			void _transit_shrink_down();
			void _transit_shrink_left_down();
			void _transit_shrink_center();
			void _transit_expand_left();
			void _transit_expand_left_up();
			void _transit_expand_up();
			void _transit_expand_right_up();
			void _transit_expand_right();
			void _transit_expand_right_down();
			void _transit_expand_down();
			void _transit_expand_left_down();
			void _transit_expand_center();

		protected:
			static void _bind_methods();

		public:
			void set_duration(const double p_duration);
			double get_duration() const;

			void set_animation(const ACTransitionControl::Animation p_animation);
			ACTransitionControl::Animation get_animation() const;

			void set_transition(const Tween::TransitionType p_transition);
			Tween::TransitionType get_transition() const;

			void set_ease(const Tween::EaseType p_ease);
			Tween::EaseType get_ease() const;

			void set_initial_alpha(const double p_initial_alpha);
			double get_initial_alpha() const;

			void set_initial_position(const Vector2 p_initial_position);
			Vector2 get_initial_position() const;

			void set_initial_scale(const Vector2 p_initial_scale);
			Vector2 get_initial_scale() const;

			void transite();

			ACTransitionControl();
			~ACTransitionControl();
	};
}

VARIANT_ENUM_CAST(ACTransitionControl::Animation);

#endif AC_TRANSITION_CONTROL_H

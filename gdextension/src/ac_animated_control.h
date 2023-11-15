#ifndef AC_ANIMATED_CONTROL_H
#define AC_ANIMATED_CONTROL_H

#include "godot_cpp/classes/control.hpp"
#include "godot_cpp/classes/property_tweener.hpp"
#include "godot_cpp/classes/tween.hpp"

namespace godot{

	class ACAnimatedControl: public Control{
		GDCLASS(ACAnimatedControl, Control)

		public:
			enum Animation {
				ANIMATION_APPEAR,
				ANIMATION_DISAPPEAR,
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
				ANIMATION_EXPAND_CENTER,
				ANIMATION_CUSTOM
			};

		private:
			double duration = 1.0;
			ACAnimatedControl::Animation animation = ANIMATION_APPEAR;
			Tween::EaseType ease = Tween::EASE_IN_OUT;
			Tween::TransitionType transition = Tween::TRANS_LINEAR;
			double initial_modulate_a = 1.0;
			Vector2 initial_position = Vector2(0, 0);
			Vector2 initial_scale = Vector2(1, 1);
			double final_modulate_a = 1.0;
			Vector2 final_position = Vector2(0, 0);
			Vector2 final_scale = Vector2(1, 1);

			Ref<Tween> _tween;

			void _create_tween();
			void _on_tween_finished();

			void _animation_appear();
			void _animation_disappear();
			void _animation_translate_left();
			void _animation_translate_left_up();
			void _animation_translate_up();
			void _animation_translate_right_up();
			void _animation_translate_right();
			void _animation_translate_right_down();
			void _animation_translate_down();
			void _animation_translate_left_down();
			void _animation_shrink_left();
			void _animation_shrink_left_up();
			void _animation_shrink_up();
			void _animation_shrink_right_up();
			void _animation_shrink_right();
			void _animation_shrink_right_down();
			void _animation_shrink_down();
			void _animation_shrink_left_down();
			void _animation_shrink_center();
			void _animation_expand_left();
			void _animation_expand_left_up();
			void _animation_expand_up();
			void _animation_expand_right_up();
			void _animation_expand_right();
			void _animation_expand_right_down();
			void _animation_expand_down();
			void _animation_expand_left_down();
			void _animation_expand_center();
			void _animation_custom();

		protected:
			static void _bind_methods();

		public:
			void set_duration(const double p_duration);
			double get_duration() const;

			void set_animation(const ACAnimatedControl::Animation p_animation);
			ACAnimatedControl::Animation get_animation() const;

			void set_transition(const Tween::TransitionType p_transition);
			Tween::TransitionType get_transition() const;

			void set_ease(const Tween::EaseType p_ease);
			Tween::EaseType get_ease() const;

			void set_initial_modulate_a(const double p_initial_modulate_a);
			double get_initial_modulate_a() const;

			void set_initial_position(const Vector2 p_initial_position);
			Vector2 get_initial_position() const;

			void set_initial_scale(const Vector2 p_initial_scale);
			Vector2 get_initial_scale() const;

			void set_final_modulate_a(const double p_final_modulate_a);
			double get_final_modulate_a() const;

			void set_final_position(const Vector2 p_final_position);
			Vector2 get_final_position() const;

			void set_final_scale(const Vector2 p_final_scale);
			Vector2 get_final_scale() const;

			bool is_running() const;
			void animate();
			void resume_animation();
			void pause_animation();
			void kill_animation();

			ACAnimatedControl();
			~ACAnimatedControl();
	};
}

VARIANT_ENUM_CAST(ACAnimatedControl::Animation);

#endif AC_ANIMATED_CONTROL_H

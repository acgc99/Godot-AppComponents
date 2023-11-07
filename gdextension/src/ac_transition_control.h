#ifndef AC_TRANSITION_CONTROL_H
#define AC_TRANSITION_CONTROL_H

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/tween.hpp>
#include <godot_cpp/classes/property_tweener.hpp>

namespace godot{

    class ACTransitionControl: public Control{
        GDCLASS(ACTransitionControl, Control)

        public:
            ACTransitionControl();
            ~ACTransitionControl();
            void transite();
            double duration = 1.0;
            double get_duration() const;
            void set_duration(const double duration);
            enum Animation {ANIMATION_VANISH, ANIMATION_TRANSLATE_LEFT, ANIMATION_TRANSLATE_LEFT_UP, ANIMATION_TRANSLATE_UP, ANIMATION_TRANSLATE_RIGHT_UP, ANIMATION_TRANSLATE_RIGHT, ANIMATION_TRANSLATE_RIGHT_DOWN, ANIMATION_TRANSLATE_DOWN, ANIMATION_TRANSLATE_LEFT_DOWN, ANIMATION_SHRINK_LEFT, ANIMATION_SHRINK_LEFT_UP, ANIMATION_SHRINK_UP, ANIMATION_SHRINK_RIGHT_UP, ANIMATION_SHRINK_RIGHT, ANIMATION_SHRINK_RIGHT_DOWN, ANIMATION_SHRINK_DOWN, ANIMATION_SHRINK_LEFT_DOWN, ANIMATION_SHRINK_CENTER};
            ACTransitionControl::Animation animation = ANIMATION_VANISH;
            ACTransitionControl::Animation get_animation() const;
            void set_animation(const ACTransitionControl::Animation animation);
            Tween::EaseType ease = Tween::EASE_IN_OUT;
            Tween::EaseType get_ease() const;
            void set_ease(const Tween::EaseType ease);
            Tween::TransitionType transition = Tween::TRANS_LINEAR;
            Tween::TransitionType get_transition() const;
            void set_transition(const Tween::TransitionType transition);
            double initial_alpha = 1.0;
            double get_initial_alpha() const;
            void set_initial_alpha(const double initial_alpha);
            Vector2 initial_position = Vector2(0, 0);
            Vector2 get_initial_position() const;
            void set_initial_position(const Vector2 initial_position);
            Vector2 initial_scale = Vector2(1, 1);
            Vector2 get_initial_scale() const;
            void set_initial_scale(const Vector2 initial_scale);
        private:
            Ref<Tween> tween;
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
            void _create_tween();
            void _reset_properties();
            void _on_tween_finished();
        protected:
            static void _bind_methods();

    };
}

VARIANT_ENUM_CAST(ACTransitionControl::Animation);

#endif AC_TRANSITION_CONTROL_H

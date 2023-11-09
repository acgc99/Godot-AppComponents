#include "ac_transition_control.h"

#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

using namespace godot;

void ACTransitionControl::set_duration(const double p_duration){
	duration = p_duration;
}

double ACTransitionControl::get_duration() const {
	return duration;
}

void ACTransitionControl::set_animation(const ACTransitionControl::Animation p_animation){
	animation = p_animation;
}

ACTransitionControl::Animation ACTransitionControl::get_animation() const {
	return animation;
}

void ACTransitionControl::set_ease(const Tween::EaseType p_ease){
	ease = p_ease;
}

Tween::EaseType ACTransitionControl::get_ease() const {
	return ease;
}

void ACTransitionControl::set_transition(const Tween::TransitionType p_transition){
	transition = p_transition;
}

Tween::TransitionType ACTransitionControl::get_transition() const {
	return transition;
}

void ACTransitionControl::animate(){
	if(_tween != NULL && _tween->is_running()){
		_tween->kill();
	}
	if(animation == ANIMATION_VANISH){
		_animation_vanish();
	}
	else if(animation == ANIMATION_TRANSLATE_LEFT){
		_animation_translate_left();
	}
	else if(animation == ANIMATION_TRANSLATE_LEFT_UP){
		_animation_translate_left_up();
	}
	else if(animation == ANIMATION_TRANSLATE_UP){
		_animation_translate_up();
	}
	else if(animation == ANIMATION_TRANSLATE_RIGHT_UP){
		_animation_translate_right_up();
	}
	else if(animation == ANIMATION_TRANSLATE_RIGHT){
		_animation_translate_right();
	}
	else if(animation == ANIMATION_TRANSLATE_RIGHT_DOWN){
		_animation_translate_right_down();
	}
	else if(animation == ANIMATION_TRANSLATE_DOWN){
		_animation_translate_down();
	}
	else if(animation == ANIMATION_TRANSLATE_LEFT_DOWN){
		_animation_translate_left_down();
	}
	else if(animation == ANIMATION_SHRINK_LEFT){
		_animation_shrink_left();
	}
	else if(animation == ANIMATION_SHRINK_LEFT_UP){
		_animation_shrink_left_up();
	}
	else if(animation == ANIMATION_SHRINK_UP){
		_animation_shrink_up();
	}
	else if(animation == ANIMATION_SHRINK_RIGHT_UP){
		_animation_shrink_right_up();
	}
	else if(animation == ANIMATION_SHRINK_RIGHT){
		_animation_shrink_right();
	}
	else if(animation == ANIMATION_SHRINK_RIGHT_DOWN){
		_animation_shrink_right_down();
	}
	else if(animation == ANIMATION_SHRINK_DOWN){
		_animation_shrink_down();
	}
	else if(animation == ANIMATION_SHRINK_LEFT_DOWN){
		_animation_shrink_left_down();
	}
	else if(animation == ANIMATION_SHRINK_CENTER){
		_animation_shrink_center();
	}
	else if(animation == ANIMATION_EXPAND_LEFT){
		_animation_expand_left();
	}
	else if(animation == ANIMATION_EXPAND_LEFT_UP){
		_animation_expand_left_up();
	}
	else if(animation == ANIMATION_EXPAND_UP){
		_animation_expand_up();
	}
	else if(animation == ANIMATION_EXPAND_RIGHT_UP){
		_animation_expand_right_up();
	}
	else if(animation == ANIMATION_EXPAND_RIGHT){
		_animation_expand_right();
	}
	else if(animation == ANIMATION_EXPAND_RIGHT_DOWN){
		_animation_expand_right_down();
	}
	else if(animation == ANIMATION_EXPAND_DOWN){
		_animation_expand_down();
	}
	else if(animation == ANIMATION_EXPAND_LEFT_DOWN){
		_animation_expand_left_down();
	}
	else if(animation == ANIMATION_EXPAND_CENTER){
		_animation_expand_center();
	}
}

void ACTransitionControl::_create_tween(){
	_tween = create_tween();
	_tween->connect("finished", Callable(this, "_on_tween_finished"));
}

void ACTransitionControl::_on_tween_finished(){
	emit_signal("finished");
}

void ACTransitionControl::_animation_vanish(){
	_create_tween();
	_tween->tween_property(this, "modulate:a", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_translate_left(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_position().x - get_size().x, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_translate_left_up(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_position().x - get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y - get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_translate_up(){
	_create_tween();
	_tween->tween_property(this, "position:y", get_position().y - get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_translate_right_up(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_position().x + get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y - get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_translate_right(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_position().x + get_size().x, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_translate_right_down(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_position().x + get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y + get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_translate_down(){
	_create_tween();
	_tween->tween_property(this, "position:y", get_position().y + get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_translate_left_down(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_position().x - get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y + get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_shrink_left(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_shrink_left_up(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_shrink_up(){
	_create_tween();
	_tween->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_shrink_right_up(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x + get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_shrink_right(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x + get_size().x, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_shrink_right_down(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x + get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y + get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_shrink_down(){
	_create_tween();
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y + get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_shrink_left_down(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y + get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_shrink_center(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x + get_size().x/2.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y + get_size().y/2.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_expand_left(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 1.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_expand_left_up(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 1.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_expand_up(){
	_create_tween();
	_tween->tween_property(this, "scale:y", 1.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_expand_right_up(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x - get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 1.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_expand_right(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x - get_size().x, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_expand_right_down(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x - get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y - get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_expand_down(){
	_create_tween();
	_tween->parallel()->tween_property(this, "scale:y", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y - get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_expand_left_down(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y - get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_animation_expand_center(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x - get_size().x/2.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y - get_size().y/2.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_bind_methods(){
	ClassDB::bind_method(D_METHOD("set_duration", "duration"), &ACTransitionControl::set_duration);
	ClassDB::bind_method(D_METHOD("get_duration"), &ACTransitionControl::get_duration);
	ClassDB::bind_method(D_METHOD("set_animation", "animation"), &ACTransitionControl::set_animation);
	ClassDB::bind_method(D_METHOD("get_animation"), &ACTransitionControl::get_animation);
	ClassDB::bind_method(D_METHOD("set_ease", "ease"), &ACTransitionControl::set_ease);
	ClassDB::bind_method(D_METHOD("get_ease"), &ACTransitionControl::get_ease);
	ClassDB::bind_method(D_METHOD("set_transition", "transition"), &ACTransitionControl::set_transition);
	ClassDB::bind_method(D_METHOD("get_transition"), &ACTransitionControl::get_transition);

	ClassDB::bind_method(D_METHOD("animate"), &ACTransitionControl::animate);
	ClassDB::bind_method(D_METHOD("_on_tween_finished"), &ACTransitionControl::_on_tween_finished);

	ClassDB::add_property("ACTransitionControl", PropertyInfo(Variant::FLOAT, "duration", PROPERTY_HINT_RANGE, "0.0,2.0,0.5,or_greater"), "set_duration", "get_duration");
	ClassDB::add_property("ACTransitionControl", PropertyInfo(Variant::INT, "animation", PROPERTY_HINT_ENUM, "Vanish,Translate Left,Translate Left Up,Translate Up,Translate Right Up,Translate Right,Translate Right Down,Translate Down,Translate Left Down,Shrink Left,Shrink Left Up,Shrink Up,Shrink Right Up,Shrink Right,Shrink Right Down,Shrink Down,Shrink Left Down,Shrink Center, Expand Left,Expand Left Up,Expand Up,Expand Right Up,Expand Right,Expand Right Down,Expand Down,Expand Left Down,Expand Center"), "set_animation", "get_animation");
	ClassDB::add_property("ACTransitionControl", PropertyInfo(Variant::INT, "ease", PROPERTY_HINT_ENUM, "In,Out,In Out,Out In"), "set_ease", "get_ease");
	ClassDB::add_property("ACTransitionControl", PropertyInfo(Variant::INT, "transition", PROPERTY_HINT_ENUM, "Linear,Sine,Quint,Quart,Quad,Expo,Elastic,Cubic,Circ,Bounce,Back,Spring"), "set_transition", "get_transition");

	BIND_ENUM_CONSTANT(ANIMATION_VANISH);
	BIND_ENUM_CONSTANT(ANIMATION_TRANSLATE_LEFT);
	BIND_ENUM_CONSTANT(ANIMATION_TRANSLATE_LEFT_UP);
	BIND_ENUM_CONSTANT(ANIMATION_TRANSLATE_UP);
	BIND_ENUM_CONSTANT(ANIMATION_TRANSLATE_RIGHT_UP);
	BIND_ENUM_CONSTANT(ANIMATION_TRANSLATE_RIGHT);
	BIND_ENUM_CONSTANT(ANIMATION_TRANSLATE_RIGHT_DOWN);
	BIND_ENUM_CONSTANT(ANIMATION_TRANSLATE_DOWN);
	BIND_ENUM_CONSTANT(ANIMATION_TRANSLATE_LEFT_DOWN);
	BIND_ENUM_CONSTANT(ANIMATION_SHRINK_LEFT);
	BIND_ENUM_CONSTANT(ANIMATION_SHRINK_LEFT_UP);
	BIND_ENUM_CONSTANT(ANIMATION_SHRINK_UP);
	BIND_ENUM_CONSTANT(ANIMATION_SHRINK_RIGHT_UP);
	BIND_ENUM_CONSTANT(ANIMATION_SHRINK_RIGHT);
	BIND_ENUM_CONSTANT(ANIMATION_SHRINK_RIGHT_DOWN);
	BIND_ENUM_CONSTANT(ANIMATION_SHRINK_DOWN);
	BIND_ENUM_CONSTANT(ANIMATION_SHRINK_LEFT_DOWN);
	BIND_ENUM_CONSTANT(ANIMATION_SHRINK_CENTER);
	BIND_ENUM_CONSTANT(ANIMATION_EXPAND_LEFT);
	BIND_ENUM_CONSTANT(ANIMATION_EXPAND_LEFT_UP);
	BIND_ENUM_CONSTANT(ANIMATION_EXPAND_UP);
	BIND_ENUM_CONSTANT(ANIMATION_EXPAND_RIGHT_UP);
	BIND_ENUM_CONSTANT(ANIMATION_EXPAND_RIGHT);
	BIND_ENUM_CONSTANT(ANIMATION_EXPAND_RIGHT_DOWN);
	BIND_ENUM_CONSTANT(ANIMATION_EXPAND_DOWN);
	BIND_ENUM_CONSTANT(ANIMATION_EXPAND_LEFT_DOWN);
	BIND_ENUM_CONSTANT(ANIMATION_EXPAND_CENTER);

	ADD_SIGNAL(MethodInfo("finished"));
}

ACTransitionControl::ACTransitionControl(){}

ACTransitionControl::~ACTransitionControl(){}

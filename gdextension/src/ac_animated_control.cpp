#include "ac_animated_control.h"

#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

using namespace godot;

void ACAnimatedControl::set_duration(const double p_duration){
	duration = p_duration;
}

double ACAnimatedControl::get_duration() const {
	return duration;
}

void ACAnimatedControl::set_animation(const ACAnimatedControl::Animation p_animation){
	animation = p_animation;
}

ACAnimatedControl::Animation ACAnimatedControl::get_animation() const {
	return animation;
}

void ACAnimatedControl::set_ease(const Tween::EaseType p_ease){
	ease = p_ease;
}

Tween::EaseType ACAnimatedControl::get_ease() const {
	return ease;
}

void ACAnimatedControl::set_transition(const Tween::TransitionType p_transition){
	transition = p_transition;
}

Tween::TransitionType ACAnimatedControl::get_transition() const {
	return transition;
}

void ACAnimatedControl::_create_tween(){
	_tween = create_tween();
	_tween->connect("finished", Callable(this, "_on_tween_finished"));
	_is_running = true;
}

void ACAnimatedControl::_on_tween_finished(){
	emit_signal("finished");
	_is_running = false;
}

void ACAnimatedControl::_animation_appear(){
	_create_tween();
	_tween->tween_property(this, "modulate:a", 1.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_disappear(){
	_create_tween();
	_tween->tween_property(this, "modulate:a", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_translate_left(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_position().x - get_size().x, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_translate_left_up(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_position().x - get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y - get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_translate_up(){
	_create_tween();
	_tween->tween_property(this, "position:y", get_position().y - get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_translate_right_up(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_position().x + get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y - get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_translate_right(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_position().x + get_size().x, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_translate_right_down(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_position().x + get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y + get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_translate_down(){
	_create_tween();
	_tween->tween_property(this, "position:y", get_position().y + get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_translate_left_down(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_position().x - get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y + get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_shrink_left(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_shrink_left_up(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_shrink_up(){
	_create_tween();
	_tween->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_shrink_right_up(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x + get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_shrink_right(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x + get_size().x, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_shrink_right_down(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x + get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y + get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_shrink_down(){
	_create_tween();
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y + get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_shrink_left_down(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y + get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_shrink_center(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x + get_size().x/2.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y + get_size().y/2.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_expand_left(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 1.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_expand_left_up(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 1.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_expand_up(){
	_create_tween();
	_tween->tween_property(this, "scale:y", 1.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_expand_right_up(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x - get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 1.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_expand_right(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x - get_size().x, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_expand_right_down(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x - get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y - get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_expand_down(){
	_create_tween();
	_tween->parallel()->tween_property(this, "scale:y", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y - get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_expand_left_down(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y - get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACAnimatedControl::_animation_expand_center(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_position().x - get_size().x/2.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 1.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_position().y - get_size().y/2.0, duration)->set_ease(ease)->set_trans(transition);
}

bool ACAnimatedControl::is_running() const {
	return _is_running;
}

void ACAnimatedControl::animate(){
	if(_tween != NULL && _tween->is_running()){
		_tween->kill();
	}
	if(animation == ANIMATION_APPEAR){
		_animation_appear();
	}
	else if(animation == ANIMATION_DISAPPEAR){
		_animation_disappear();
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

void ACAnimatedControl::_bind_methods(){
	ClassDB::bind_method(D_METHOD("set_duration", "duration"), &ACAnimatedControl::set_duration);
	ClassDB::bind_method(D_METHOD("get_duration"), &ACAnimatedControl::get_duration);
	ClassDB::bind_method(D_METHOD("set_animation", "animation"), &ACAnimatedControl::set_animation);
	ClassDB::bind_method(D_METHOD("get_animation"), &ACAnimatedControl::get_animation);
	ClassDB::bind_method(D_METHOD("set_ease", "ease"), &ACAnimatedControl::set_ease);
	ClassDB::bind_method(D_METHOD("get_ease"), &ACAnimatedControl::get_ease);
	ClassDB::bind_method(D_METHOD("set_transition", "transition"), &ACAnimatedControl::set_transition);
	ClassDB::bind_method(D_METHOD("get_transition"), &ACAnimatedControl::get_transition);

	ClassDB::bind_method(D_METHOD("is_running"), &ACAnimatedControl::is_running);
	ClassDB::bind_method(D_METHOD("animate"), &ACAnimatedControl::animate);
	ClassDB::bind_method(D_METHOD("_on_tween_finished"), &ACAnimatedControl::_on_tween_finished);

	ClassDB::add_property("ACAnimatedControl", PropertyInfo(Variant::FLOAT, "duration", PROPERTY_HINT_RANGE, "0.0,2.0,0.5,or_greater"), "set_duration", "get_duration");
	ClassDB::add_property("ACAnimatedControl", PropertyInfo(Variant::INT, "animation", PROPERTY_HINT_ENUM, "Appear,Disappear,Translate Left,Translate Left Up,Translate Up,Translate Right Up,Translate Right,Translate Right Down,Translate Down,Translate Left Down,Shrink Left,Shrink Left Up,Shrink Up,Shrink Right Up,Shrink Right,Shrink Right Down,Shrink Down,Shrink Left Down,Shrink Center, Expand Left,Expand Left Up,Expand Up,Expand Right Up,Expand Right,Expand Right Down,Expand Down,Expand Left Down,Expand Center"), "set_animation", "get_animation");
	ClassDB::add_property("ACAnimatedControl", PropertyInfo(Variant::INT, "ease", PROPERTY_HINT_ENUM, "In,Out,In Out,Out In"), "set_ease", "get_ease");
	ClassDB::add_property("ACAnimatedControl", PropertyInfo(Variant::INT, "transition", PROPERTY_HINT_ENUM, "Linear,Sine,Quint,Quart,Quad,Expo,Elastic,Cubic,Circ,Bounce,Back,Spring"), "set_transition", "get_transition");

	BIND_ENUM_CONSTANT(ANIMATION_APPEAR);
	BIND_ENUM_CONSTANT(ANIMATION_DISAPPEAR);
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

ACAnimatedControl::ACAnimatedControl(){}

ACAnimatedControl::~ACAnimatedControl(){}

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

void ACTransitionControl::set_initial_alpha(const double p_initial_alpha){
	initial_alpha = p_initial_alpha;
}

double ACTransitionControl::get_initial_alpha() const {
	return initial_alpha;
}

void ACTransitionControl::set_initial_position(const Vector2 p_initial_position){
	initial_position = p_initial_position;
}

Vector2 ACTransitionControl::get_initial_position() const {
	return initial_position;
}

void ACTransitionControl::set_initial_scale(const Vector2 p_initial_scale){
	initial_scale = p_initial_scale;
}

Vector2 ACTransitionControl::get_initial_scale() const {
	return initial_scale;
}

void ACTransitionControl::transite(){
	if(_tween != NULL && _tween->is_running()){
		_tween->kill();
	}
	if(animation == ANIMATION_VANISH){
		_transit_vanish();
	}
	else if(animation == ANIMATION_TRANSLATE_LEFT){
		_transit_translate_left();
	}
	else if(animation == ANIMATION_TRANSLATE_LEFT_UP){
		_transit_translate_left_up();
	}
	else if(animation == ANIMATION_TRANSLATE_UP){
		_transit_translate_up();
	}
	else if(animation == ANIMATION_TRANSLATE_RIGHT_UP){
		_transit_translate_right_up();
	}
	else if(animation == ANIMATION_TRANSLATE_RIGHT){
		_transit_translate_right();
	}
	else if(animation == ANIMATION_TRANSLATE_RIGHT_DOWN){
		_transit_translate_right_down();
	}
	else if(animation == ANIMATION_TRANSLATE_DOWN){
		_transit_translate_down();
	}
	else if(animation == ANIMATION_TRANSLATE_LEFT_DOWN){
		_transit_translate_left_down();
	}
	else if(animation == ANIMATION_SHRINK_LEFT){
		_transit_shrink_left();
	}
	else if(animation == ANIMATION_SHRINK_LEFT_UP){
		_transit_shrink_left_up();
	}
	else if(animation == ANIMATION_SHRINK_UP){
		_transit_shrink_up();
	}
	else if(animation == ANIMATION_SHRINK_RIGHT_UP){
		_transit_shrink_right_up();
	}
	else if(animation == ANIMATION_SHRINK_RIGHT){
		_transit_shrink_right();
	}
	else if(animation == ANIMATION_SHRINK_RIGHT_DOWN){
		_transit_shrink_right_down();
	}
	else if(animation == ANIMATION_SHRINK_DOWN){
		_transit_shrink_down();
	}
	else if(animation == ANIMATION_SHRINK_LEFT_DOWN){
		_transit_shrink_left_down();
	}
	else if(animation == ANIMATION_SHRINK_CENTER){
		_transit_shrink_center();
	}
}

void ACTransitionControl::_reset_properties(){
	Color mod = get_modulate();
	set_modulate(Color(mod.r, mod.g, mod.b, initial_alpha));
	set_position(initial_position);
	set_scale(initial_scale);
}

void ACTransitionControl::_create_tween(){
	_reset_properties();
	_tween = create_tween();
	_tween->connect("finished", Callable(this, "_on_tween_finished"));
}

void ACTransitionControl::_on_tween_finished(){
	emit_signal("finished");
}

void ACTransitionControl::_transit_vanish(){
	_create_tween();
	_tween->tween_property(this, "modulate:a", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_translate_left(){
	_create_tween();
	_tween->tween_property(this, "position:x", -get_size().x, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_translate_left_up(){
	_create_tween();
	_tween->tween_property(this, "position:x", -get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", -get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_translate_up(){
	_create_tween();
	_tween->tween_property(this, "position:y", -get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_translate_right_up(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", -get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_translate_right(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_size().x, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_translate_right_down(){
	_create_tween();
	_tween->tween_property(this, "position:x", get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_translate_down(){
	_create_tween();
	_tween->tween_property(this, "position:y", get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_translate_left_down(){
	_create_tween();
	_tween->tween_property(this, "position:x", -get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_shrink_left(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_shrink_left_up(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_shrink_up(){
	_create_tween();
	_tween->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_shrink_right_up(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_shrink_right(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_size().x, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_shrink_right_down(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_size().x, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_shrink_down(){
	_create_tween();
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_shrink_left_down(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_size().y, duration)->set_ease(ease)->set_trans(transition);
}

void ACTransitionControl::_transit_shrink_center(){
	_create_tween();
	_tween->tween_property(this, "scale:x", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:x", get_size().x/2.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "scale:y", 0.0, duration)->set_ease(ease)->set_trans(transition);
	_tween->parallel()->tween_property(this, "position:y", get_size().y/2.0, duration)->set_ease(ease)->set_trans(transition);
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
	ClassDB::bind_method(D_METHOD("set_initial_alpha", "initial_alpha"), &ACTransitionControl::set_initial_alpha);
	ClassDB::bind_method(D_METHOD("get_initial_alpha"), &ACTransitionControl::get_initial_alpha);
	ClassDB::bind_method(D_METHOD("set_initial_position", "initial_position"), &ACTransitionControl::set_initial_position);
	ClassDB::bind_method(D_METHOD("get_initial_position"), &ACTransitionControl::get_initial_position);
	ClassDB::bind_method(D_METHOD("set_initial_scale", "initial_scale"), &ACTransitionControl::set_initial_scale);
	ClassDB::bind_method(D_METHOD("get_initial_scale"), &ACTransitionControl::get_initial_scale);

	ClassDB::bind_method(D_METHOD("transite"), &ACTransitionControl::transite);
	ClassDB::bind_method(D_METHOD("_on_tween_finished"), &ACTransitionControl::_on_tween_finished);

	ClassDB::add_property("ACTransitionControl", PropertyInfo(Variant::FLOAT, "duration", PROPERTY_HINT_RANGE, "0.0,2.0,0.5,or_greater"), "set_duration", "get_duration");
	ClassDB::add_property("ACTransitionControl", PropertyInfo(Variant::INT, "animation", PROPERTY_HINT_ENUM, "Vanish,Translate Left,Translate Left Up,Translate Up,Translate Right Up,Translate Right,Translate Right Down,Translate Down,Translate Left Down,Shrink Left,Shrink Left Up,Shrink Up,Shrink Right Up,Shrink Right,Shrink Right Down,Shrink Down,Shrink Left Down,Shrink Center"), "set_animation", "get_animation");
	ClassDB::add_property("ACTransitionControl", PropertyInfo(Variant::INT, "ease", PROPERTY_HINT_ENUM, "In,Out,In Out,Out In"), "set_ease", "get_ease");
	ClassDB::add_property("ACTransitionControl", PropertyInfo(Variant::INT, "transition", PROPERTY_HINT_ENUM, "Linear,Sine,Quint,Quart,Quad,Expo,Elastic,Cubic,Circ,Bounce,Back,Spring"), "set_transition", "get_transition");
	ADD_SUBGROUP("Initial", "initial");
	ClassDB::add_property("ACTransitionControl", PropertyInfo(Variant::FLOAT, "initial_alpha", PROPERTY_HINT_RANGE, "0.0,1.0,0.05"), "set_initial_alpha", "get_initial_alpha");
	ClassDB::add_property("ACTransitionControl", PropertyInfo(Variant::VECTOR2, "initial_position", PROPERTY_HINT_NONE, "suffix:px"), "set_initial_position", "get_initial_position");
	ClassDB::add_property("ACTransitionControl", PropertyInfo(Variant::VECTOR2, "initial_scale", PROPERTY_HINT_NONE, "suffix:px"), "set_initial_scale", "get_initial_scale");

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

	ADD_SIGNAL(MethodInfo("finished"));
}

ACTransitionControl::ACTransitionControl(){}

ACTransitionControl::~ACTransitionControl(){}

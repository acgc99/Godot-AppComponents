@icon("res://editor/icons/list-box.svg")
extends ACTransitionControl

## TODO: improvement: when outside screen, do not draw

var is_open: bool = false


func open():
	is_open = true
	animation = ACTransitionControl.ANIMATION_TRANSLATE_RIGHT
	initial_position.x = -size.x
	transite()


func close() -> void:
	is_open = false
	animation = ACTransitionControl.ANIMATION_TRANSLATE_LEFT
	initial_position.x = position.x
	transite()


func _on_button_pressed() -> void:
	close()

@icon("res://editor/icons/message.svg")
extends ACTransitionControl


var is_open: bool = false


func open():
	is_open = true
	animation = ACTransitionControl.ANIMATION_EXPAND_CENTER
	initial_position += size/2.0
	initial_scale = Vector2.ZERO
	animate()


func close() -> void:
	is_open = false
	animation = ACTransitionControl.ANIMATION_SHRINK_CENTER
	initial_position = position
	initial_scale = Vector2.ONE
	animate()


func _on_button_pressed() -> void:
	close()

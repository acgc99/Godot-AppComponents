@icon("res://editor/icons/list-box.svg")
extends ACTransitionControl


var is_open: bool = false


func open():
	is_open = true
	animation = ACTransitionControl.ANIMATION_TRANSLATE_RIGHT
	animate()


func close() -> void:
	is_open = false
	animation = ACTransitionControl.ANIMATION_TRANSLATE_LEFT
	animate()


func _on_button_pressed() -> void:
	close()

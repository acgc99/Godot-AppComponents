@icon("res://editor/icons/message.svg")
extends ACAnimatedControl


var is_open: bool = false


func open() -> void:
	animation = ACAnimatedControl.ANIMATION_EXPAND_CENTER
	animate()


func close() -> void:
	animation = ACAnimatedControl.ANIMATION_SHRINK_CENTER
	animate()


func _on_finished() -> void:
	is_open = not is_open


func _on_button_pressed() -> void:
	close()


@icon("res://editor/icons/table-of-contents.svg")
extends ACAnimatedControl


var is_open: bool = false


func open() -> void:
	if not is_running():
		animation = ACAnimatedControl.ANIMATION_TRANSLATE_RIGHT
		animate()


func close() -> void:
	if not is_running():
		animation = ACAnimatedControl.ANIMATION_TRANSLATE_LEFT
		animate()


func _on_finished() -> void:
	is_open = not is_open


func _on_button_pressed() -> void:
	close()

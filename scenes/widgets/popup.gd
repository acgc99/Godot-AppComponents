@icon("res://editor/icons/message.svg")
extends ACAnimatedControl


@onready var button: Button = $Button


var is_open: bool = false


func open() -> void:
	if not is_running():
		_input_activation()
		animation = ACAnimatedControl.ANIMATION_EXPAND_CENTER
		animate()


func close() -> void:
	if not is_running():
		_input_deactivation()
		animation = ACAnimatedControl.ANIMATION_SHRINK_CENTER
		animate()


func _input_activation() -> void:
	button.mouse_filter = Control.MOUSE_FILTER_STOP

func _input_deactivation() -> void:
	button.mouse_filter = Control.MOUSE_FILTER_IGNORE

func _on_finished() -> void:
	is_open = not is_open


func _on_button_pressed() -> void:
	close()


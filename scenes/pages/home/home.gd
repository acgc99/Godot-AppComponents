extends Control


@onready var popup: ACAnimatedControl = $Popup


func _ready() -> void:
	popup._input_deactivation()
	popup.position = size/2.0
	popup.scale = Vector2.ZERO


func _on_nav_bar_pressed_left() -> void:
	get_parent().open_drawer()


func _on_nav_bar_pressed_right() -> void:
	popup.open()

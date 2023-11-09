extends Control


@onready var popup: Control = $Popup


func _on_nav_bar_pressed_left() -> void:
	get_parent().open_drawer()


func _on_nav_bar_pressed_right() -> void:
	popup.open()

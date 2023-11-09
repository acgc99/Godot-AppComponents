extends Control


func _on_nav_bar_pressed_left() -> void:
	get_parent().open_drawer()

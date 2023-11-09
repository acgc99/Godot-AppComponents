@icon("res://editor/icons/navigation-variant.svg")
extends PanelContainer

signal pressed_left


func _on_ac_icon_button_left_pressed() -> void:
	pressed_left.emit()

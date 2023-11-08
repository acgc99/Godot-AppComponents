@icon("res://editor/icons/navigation-variant.svg")
extends PanelContainer

signal pressed_left
signal pressed_right


func _on_ac_icon_button_left_pressed() -> void:
	pressed_left.emit()


func _on_ac_icon_button_right_pressed() -> void:
	pressed_right.emit()

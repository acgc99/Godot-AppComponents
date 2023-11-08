extends Control


@onready var transition = $Transition


func _ready() -> void:
	transition.transite()


func _on_nav_bar_pressed_left() -> void:
	print("Pressed left")


func _on_nav_bar_pressed_right() -> void:
	print("Pressed right")


func _on_transition_finished() -> void:
	print("Transition finished")

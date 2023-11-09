@icon("res://editor/icons/message.svg")
extends ACTransitionControl


var is_open: bool = false


func _ready() -> void:
	# FIXME #19:
	# To set initial conditions correctly.
	# You cannot do this on the Editor in the page scene (I do not know why),
	# you get bad results.
	position = get_parent_area_size()/2.0
	scale = Vector2.ZERO


func open():
	is_open = true
	animation = ACTransitionControl.ANIMATION_EXPAND_CENTER
	animate()


func close() -> void:
	is_open = false
	animation = ACTransitionControl.ANIMATION_SHRINK_CENTER
	animate()


func _on_button_pressed() -> void:
	close()

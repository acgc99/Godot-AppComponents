extends Control


func _ready() -> void:
	$ACTransitionControl.transite()


func _on_ac_transition_control_finished() -> void:
	print("Transition finished")
	$ACTransitionControl.transite()

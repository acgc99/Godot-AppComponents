extends Control


@onready var drawer: ACAnimatedControl = $NavDrawer


func _ready() -> void:
	drawer.position = Vector2(-size.x, 0)


func open_drawer() -> void:
	drawer.open()


func close_drawer() -> void:
	drawer.close()

extends Control


@onready var drawer: Control = $NavDrawer


func open_drawer() -> void:
	drawer.open()


func close_drawer() -> void:
	drawer.close()

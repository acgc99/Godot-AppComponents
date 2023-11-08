# App Components

This add-on is a collection of nodes for GUI design. They are intended to be the building blocks for you app, not the final widgets.

With these components you design widgets as independent scenes, that are then attached to the pages/screens of your app (see [Project Showcase](#projectshowcase).

| About      | Current Release                     |
|------------|-------------------------------------|
| Version    | 1.0.0 **(under development)**       |
| Date       | yyyy/mm/dd                          |
| Godot      | Godot 4.2.0                         |
| License    | [MIT License](./LICENSE.md)     |
| Author     | [acgc99](https://github.com/acgc99) |

## List of components:
- [ACHTTPImage](#achttpimage)
- [ACPageContainer](#acpagecontainer)
- [ACIconButton](#aciconbutton)
- [ACIcon](#acicon)
- [ACRoundClippingContainer](#acroundclippingcontainer)
- [ACTransitionControl](#actransitioncontrol)

Note: only attributes designed to be modified are listed.

### `ACHTTPImage` <a name="achttpimage"></a>

It works similar to `TextureRect`, but it requires an URL pointing to some image on the Internet and the specification of image extension.

Image is requested when `url` or `extension` changes, so if you change the image manually (`texture`), it will not be reset, you have to enter the `url` or `extension` again.

Note that large images might require long loading and saving times.

| `String`    | `url`       | `""` |
|-------------|-------------|------|
| `Extension` | `extension` | `0`  |


- `String url = ""`. Image URL.
- `Extension extension = 0`. Image extension. `Image` supported types: `.bmp`, `.jpg`, `.png`, `.tga` and `.webp`.

### `ACPageContainer` <a name="acpagecontainer"></a>

It is a `VBoxContainer` with no separation between its elements.

### `ACIconButton` <a name="aciconbutton"></a>

It is a `Button` with the attributes designed to contain only an icon.

### `ACIcon` <a name="acicon"></a>

A `TextureRect` designed to hold an icon. That is `expand_mode = EXPAND_IGNORE_SIZE` and `stretch_mode = STRETCH_KEEP_ASPECT_CENTERED`.

### `ACRoundClippingContainer` <a name="acroundclippingcontainer"></a>

A `PanelContainer` with `clip_children_mode = CLIP_CHILDREN_ONLY` to clip its children to its shape.

To make this node work properly, you have to assign a `Theme` and fill a `PanelContainer` type with a `panel` not null. If `panel` has rounded corners and this node has a `TextureRect`/`ColorRect` child that occupies all node, its corners will be rounded.

If your children look semitransparent, it is because of the theme.

### `ACTransitionControl` <a name="actransitioncontrol"></a>

A `Control` node with a `Tween` for animations designed for transition between pages, pop-ups or many other things.

Notes:
- You might need to set `mouse_filter = MOUSE_FILTER_IGNORE` so that elements below can receive mouse input. This might also apply to this node children. It will depend on your needs.

Methods:
- `transite`. Start animation.

Signals:
- `finished`. Emitted when `Tween` animation finishes.

Attributes:
- `float duarion = 1.0`. Animation duration in seconds.
- `Animation animation = ANIMATION_VANISH`. Possible animations: vanish (node is made invisible), transition left/left-up/up/right-up/right/right-down/down/left-down/ (node is moved on that direction the same quantity as its width/height) and shrink left/left-up/up/right-up/right/right-down/down/left-down/center (node is scaled up to zero).
- `Tween.EaseType ease = EASE_IN_OUT`.
- `Tween.TransitionType transition = Tween.TRANS_LINEAR`.
- `float initial_alpha = 1.0`. The animation starts with this `modulate.a`.
- `Vector2 initial_position = Vector2(0, 0)`. The animation starts with this `position`.
- `Vector2 initial_scale = Vector2(1, 1)`. The animation starts with this `scale`.

![tweening_cheatsheet](https://raw.githubusercontent.com/godotengine/godot-docs/master/img/tween_cheatsheet.webp) 

## Contributing <a name="contributing"></a>

## Project Showcase <a name="projectshowcase"></a>

The project showcase is in the GitHub repository. It is a showcase of what you can do with this add-on.

Notice that for the `Background` and `Contents` scenes, the size is not the full window size, the `NavBar` height is subtracted. This is not mandatory, but recommended, since these are the dimensions when integrated on `ACPageContainer`.
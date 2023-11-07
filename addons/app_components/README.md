# App Components

This add-on is a collection of nodes for GUI design. They are intended to be the building blocks for you app, not the final widgets.

| About      | Current Release                     |
|------------|-------------------------------------|
| Version    | 1.0.0 **(under development)**       |
| Date       | yyyy/mm/dd                          |
| Godot      | Godot 4.2.0                         |
| License    | [MIT License](./LICENSE.md)     |
| Author     | [acgc99](https://github.com/acgc99) |

## List of components:
- [ACHTTPImage](#achttpimage)
- [ACPage](#acpage)
- [ACIconButton](#aciconbutton)
- [ACIcon](#acicon)
- [ACNavBar](#acnavbar)

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

### `ACPage` <a name="acpage"></a>

It is a `VBoxContainer` with no separation between its elements.

### `ACIconButton` <a name="aciconbutton"></a>

It is a `Button` with the attributes designed to contain only an icon.

### `ACIcon` <a name="acicon"></a>

A `TextureRect` designed to hold an icon. That is `expand_mode = EXPAND_IGNORE_SIZE` and `stretch_mode = STRETCH_KEEP_ASPECT_CENTERED`.

### `ACNavBar` <a name="acnavbar"></a>

A `PanelContainer` with a different icon on the Edit to distinguish it from other nodes.

## Contributing
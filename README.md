# App Components

This add-on is a collection of nodes for GUI design. They are intended to be the building blocks for you app and with them you can build the final widgets as scenes.

With these components you design widgets as independent scenes, that are then attached to the pages/screens of your app. At the [Project Showcase](#projectshowcase) you will find a navigation drawer and pop-up example.

Do not forget to check [Contributing](#contributing) if you are interested on this add-on.

Lastly, this add-on has been tested on Windows 11 64-bits, I compiled it for other OS, but I could not test them. Feel free to open an issue is something is wrong.

| About      | Current Release                     |
|------------|-------------------------------------|
| Version    | 1.0.0 **(under development)**       |
| Date       | yyyy/mm/dd                          |
| Godot      | Godot 4.2.0                         |
| License    | [MIT License](./LICENSE.md)     |
| Author     | [acgc99](https://github.com/acgc99) |

This add-on was born on 6th November 2023.

## List of components:
- [ACAnimatedControl](#acanimatedcontrol)
- [ACHTTPImage](#achttpimage)
- [ACIcon](#acicon)
- [ACIconButton](#aciconbutton)
- [ACPageContainer](#acpagecontainer)
- [ACRoundClippingContainer](#acroundclippingcontainer)

### `ACAnimatedControl` <a name="acanimatedcontrol"></a>

A `Control` node with a `Tween` for animations designed for transition between pages, pop-ups or many other things.

Notes:
- You might need to set `mouse_filter = MOUSE_FILTER_IGNORE` so that elements below can receive mouse input. This might also apply to this node children. It will depend on your needs and scene tree structure. See `mouse_filter` [docs](https://docs.godotengine.org/en/stable/classes/class_control.html#enum-control-mousefilter)) and [Project Showcase](#projectshowcase).
- You might need to set a specific set of anchors for the animations that modify size and position to work properly, or specify initial conditions at some `_ready` function. See [Project Showcase](#projectshowcase).
- This node uses a `Tween` for animations. When you call `animate`, it checks first if the current `Tween` has ended (if any) and if not, it kills current `Tween` and process the new `transite` call. See `Tween` [docs](https://docs.godotengine.org/en/stable/classes/class_tween.html).
- Animations modify `position`, `scale` and `modulate.a`. If you want to reset those attributes, do it via code or playing the opposite animation.
- If you want to make sure that one animation does not start while another is being played (for example a pop-up that is dismissed when it is being shown), use `is_running()` method. This method is important for animations that modify `position` and `scale` because they are based of current `position` and `size`, therefore for example, if you are using `Animation.ANIMATION_TRANSLATE_LEFT` and you call this animation again without waiting the first to end, the final position will be the initial position minus `size.x` minus the quantity of `size.x` that the node had time to move on the first animation. However, you might not want to use this method for animations like `Animation.ANIMATE_APPEAR` and `Animation.ANIMATE_DISAPPEAR`.

#### Methods:
- `void animate()`. Starts animation.
- `bool is_running()`. Returns `true` is the animation is running, else `false`.

#### Signals:
- `finished()`. Emitted when `Tween` animation finishes.

#### Attributes:
- `float duarion = 1.0`. Animation duration in seconds.
- `Animation animation = ANIMATION_APPEAR`. Possible animations: appear/disappear, transition left/left-up/up/right-up/right/right-down/down/left-down/ (node is moved on that direction the same quantity as its width/height), shrink left/left-up/up/right-up/right/right-down/down/left-down/center (node is scaled up to zero shrinking to that corner) and expand left/left-up/up/right-up/right/right-down/down/left-down/center (node is scaled up to 1 growing from that corner).
- `Tween.EaseType ease = EASE_IN_OUT`.
- `Tween.TransitionType transition = Tween.TRANS_LINEAR`.

![tweening_cheatsheet](https://raw.githubusercontent.com/godotengine/godot-docs/master/img/tween_cheatsheet.webp) 

### `ACHTTPImage` <a name="achttpimage"></a>

It works similar to `TextureRect`, but it requires an URL pointing to some image on the Internet and the specification of image extension.

Notes:
- Image is requested on `_ready`. If you override this function, you can use the method `make_request`.
- Large images might require long loading/saving times.

#### Methods
- `void make_request()`. Makes the HTTP request and loads the image.

#### Signals:
- `request_finished()`. Emitted when the HTTP request finishes and image is loaded.

#### Attributes
- `String url = ""`. Image URL.
- `Extension extension = 0`. Image extension. `Image` supported types: `.bmp`, `.jpg`, `.png`, `.tga` and `.webp`.

### `ACIcon` <a name="acicon"></a>

A `TextureRect` designed to hold an icon. That is `expand_mode = EXPAND_IGNORE_SIZE` and `stretch_mode = STRETCH_KEEP_ASPECT_CENTERED`.

### `ACIconButton` <a name="aciconbutton"></a>

It is a `Button` with the attributes designed to contain only an icon.

### `ACPageContainer` <a name="acpagecontainer"></a>

It is a `VBoxContainer` with no separation between its elements.

### `ACRoundClippingContainer` <a name="acroundclippingcontainer"></a>

A `PanelContainer` with `clip_children_mode = CLIP_CHILDREN_ONLY` to clip its children to its shape.

Notes:
- To make this node work properly, you have to assign a `Theme` and fill a `PanelContainer` type with a `panel` not null. If `panel` has rounded corners and this node has a `TextureRect`/`ColorRect` child that occupies all node, its corners will be rounded.
- If your children look semitransparent, it is because of the theme.

## Contributing <a name="contributing"></a>

Anyone is welcomed to open a issue requesting a new component, improving already existing ones or reporting bugs.

### Code style:

- Follow [Godot style guidelines](https://docs.godotengine.org/en/stable/contributing/development/code_style_guidelines.html) (read until the end).
- In `.h`:
  - Public enums.
  - Private. Attributes.
  - Protected. `_bind_methods` and `_notification`.
  - Public. Setters and getters. Setter parameter is called `p_<attribute>`, for each attribute.
- In `.cpp`:
  - Setters and getters
  - Public methods
  - Private methods
  - `_bind_methods`. Follow same order when binding at `_bind_methods`, then enums and signals at end.
  - Constructor and destructor.
- One empty line between functions.
- Empty lines must not contain tabs or whitespaces.

### GitHub

- Preferably, one commit per issue.
- Commit messages must have this structure:
```
closes #XX, closes #YY; <description of issue XX>, <description of issue YY>
```

### Compiling

Before stable release, the add-on has to be compiled. These are the "recipes" I used:
```
scons platform=windows arch=x86_64 target=template_debug
scons platform=windows arch=x86_64 target=template_release
scons platform=windows arch=x86_32 target=template_debug
scons platform=windows arch=x86_32 target=template_release

scons platform=android arch=x86_64 target=template_debug
scons platform=android arch=x86_64 target=template_release
scons platform=android arch=arm64 target=template_debug
scons platform=android arch=arm64 target=template_release

scons platform=macos target=template_debug osxcross_sdk="darwin23"
scons platform=macos target=template_release osxcross_sdk="darwin23"

scons platform=linux arch=x86_64 target=template_debug
scons platform=linux arch=x86_64 target=template_release
```

This [tutorial](https://www.youtube.com/watch?v=qhGp8YbzJtU) might be helpful is you face compiling.

## Project Showcase <a name="projectshowcase"></a>

The project showcase is in the GitHub repository. It is a showcase of what you can do with this add-on.

Notice that:
- For the `Background` and `Contents` scenes, the size is not the full window size, the `NavBar` height is subtracted. This is not mandatory, but recommended, since these are the dimensions when integrated on `ACPageContainer`.
- `Popup` has to modify `mouse_filter` dynamically to work properly.
- `Popup` configuration for animation: [#19](https://github.com/acgc99/Godot-AppComponents/issues/19).
- `NavDrawer` configuration for animation: [#18](https://github.com/acgc99/Godot-AppComponents/issues/18).
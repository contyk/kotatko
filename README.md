# kotatko, a fluffy window manager

kotatko is a tiling window manager for X, based on [dwm][1].

Originally forked from dwm 6.1, the goal was to preserve Xft support, in case
it ever goes away again, and integrate community patches the author generally
uses, as well as drop support for things he does not, such as Xinerama or
non-Linux systems.  While kotatko attempts to integrate upstream dwm changes,
it continues to diverge from the original project and dwm community patches
most likely won't apply cleanly, if at all.

The name derives from *koťátko*, meaning *kitty* in Czech.

![Screenshot of the default kotatko interface](/screenshot.png?raw=true)

## Differences from dwm

* Includes the [gaps patch][2], modified.
* Includes the [rmaster patch][3], modified.
* Includes the [swallow patch][4], modified.
* Includes the [columns patch][5], modified.
* Includes the [urgent border patch][6], modified.
* Includes the [movestack patch][7], modified.
* Includes the [center patch][8], modified.
* Includes the [attachtop patch][9], modified.
* Includes the [centeredwindowname patch][10], modified.
* Adjustable bar padding.
* No tag client indicators.
* Other minor visual changes.
* Code style changes.
* The build process uses aggressive flags and LTO by default.
* No Xinerama or non-Linux system support.
* No hardcoded [dmenu][50] support.
* Ignores Xft errors, avoiding potential crashes when drawing the bar.

## Configuration

kotatko uses the common `config.h` configuration approach.  The defaults are
provided in `config.def.h` and consist of:

* The standard meta key is `Mod4`, aka the "Windows" key.
* The default font is `Source Code Pro`.
* The master factor is `0.70`.
* The master is on the right.
* The master uses columns.
* The number of master windows is `1`.
* The bar padding factor is set to `1.5`.
* Five tags preconfigured.
* Thick window borders and large gaps.
* [gruvbox][100] theme, the [base16 variant][101].
* The urgent indicator is yellow.
* The default terminal is [xterm][102]
* The default launcher command relies on [zsh][103] and [fzf][104].
* The default screenshot command relies on [maim][105] and [xclip][106].
* The default mixer command invokes [pamix][107].
* The default terminal swallows windows.
* [Ibus][108] windows float.
* [xev][109] windows don't swallow other windows.

## Plans

The codebase is still evolving.  The current plans include:

* Potentially integrating the [pertag patch][110].
* Revising the codebase, especially the integrated patches.
* Major code cleanup, style unification and restructuring.
* Rewriting the manual page.

## Authors & License

kotatko is distributed under the MIT/X Consortium license.  See the `LICENSE`
file for details.

Developed and managed by Petr Šabata, aka contyk.

The list of the original dwm authors, as well as patches contributors, is
provided in the `LICENSE` file.  If you've contributed to dwm, any of the
patches, or kotatko itself, and your name is missing, let me know.

[1]: https://dwm.suckless.org/
[2]: https://dwm.suckless.org/patches/gaps/
[3]: https://dwm.suckless.org/patches/rmaster/
[4]: https://dwm.suckless.org/patches/swallow/
[5]: https://dwm.suckless.org/patches/columns/
[6]: https://dwm.suckless.org/patches/urgentborder/
[7]: https://dwm.suckless.org/patches/movestack/
[8]: https://dwm.suckless.org/patches/center/
[9]: https://dwm.suckless.org/patches/attachtop/
[10]: https://dwm.suckless.org/patches/centeredwindowname/
[50]: https://tools.suckless.org/dmenu/
[100]: https://github.com/morhetz/gruvbox/
[101]: https://github.com/dawikur/base16-gruvbox-scheme
[102]: https://invisible-island.net/xterm/
[103]: https://www.zsh.org/
[104]: https://github.com/junegunn/fzf/
[105]: https://github.com/naelstrof/maim
[106]: https://github.com/astrand/xclip
[107]: https://github.com/patroclos/PAmix
[108]: https://github.com/ibus/ibus
[109]: https://xorg.freedesktop.org/wiki/
[110]: https://dwm.suckless.org/patches/pertag/

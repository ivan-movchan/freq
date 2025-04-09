![freq](logo.png#gh-light-mode-only)
![freq](logo-dark.png#gh-dark-mode-only)

[English](README.md) / [Русский](README-RU.md)

**freq** is a simple and minimalistic frequency analysis utility.

### Installation

Pre-compiled binaries for Windows and GNU/Linux systems are available
for download in ["Releases"](https://github.com/ivan-movchan/freq/releases).

For building from sources install any C compiler (GCC, Clang, etc.)
and GNU make, then edit `Makefile` if need and run `make`.
It is recommended to build in *NIX environment like MSYS2,
Windows Subsystem for Linux (WSL) or real *NIX system.

You can run `make install` to install freq and `make uninstall` to uninstall it.
(Actual for *NIX systems, root privileges are required.)

### Usage

```bash
$ freq [-pv] [< input_file]
```

* `-p` — additionally show percentage frequency values.
* `-v` — display program version and exit.
* `< input_file` - process data from `input_file`.

### Configuration

The configuration is done by editing `config.h` file and recompiling the program
from sources.

### Authors

freq is written by [Ivan Movchan](https://github.com/ivan-movchan).

The coincidence with
[freq utility from Plan 9 project](https://p9f.org/magic/man2html/1/freq)
is a pure accident, no more.

### Contributing

Want to make the project it better?

* Feel free to fork the repository, improve the program and make a pull request
  to accept your code to the project. Read the source code
  for better understanding coding style
  (max. 80 symbols per line, 4 spaces indent, etc.).

* Do not hesitate to report bugs/crashes and suggest new ideas
  using ["Issues"](https://github.com/ivan-movchan/freq/issues)
  or by contacting the developer.

**IMPORTANT:** Before reporting a bug/crash make sure you are using the latest
program version — your problem may have been already fixed in latest version.
When reporting a bug/crash, also tell the operating system version
(i. e. *Windows 7 x64*) and error messages the program displays.

### History

See [CHANGELOG.md](CHANGELOG.md) for version history.

### License

freq is free software released under the terms of MIT License.
See [LICENSE](LICENSE) file for further details.

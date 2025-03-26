![freq](logo.png#gh-light-mode-only)
![freq](logo-dark.png#gh-dark-mode-only)

[English](README.md) / [Русский](README-RU.md)

**freq** is a tiny console utility that performs frequency analysis of `stdin` (console input stream) data byte by byte.

### Installation

#### Dependencies

* `gcc`, `clang` or any other C compiler;
* `make`.

Edit `Makefile` to match your local setup (compilers, libraries, etc.) if need.

#### Build instructions

```bash
$ make
$ sudo make install
```

### Usage

To perform frequency analysis of `stdin` data:

```bash
$ freq [< input_file [> output_file]]
```

* `< input_file` - transfer data from `input_file` to `stdin` (console input stream);
* `> output_file` - transfer data from `stdout` (console output stream) to `output_file`.

To display program version and exit:

```
$ freq -v
```

### Configuration

The default maximum char value (and also the count of chars being analyzed by freq) is set to `UCHAR_MAX` and is defined by `MAX_CHAR` constant. You can change the value by editing the source code and recompiling the program or by defining `MAX_CHAR` with your own value in compiler flags (i. e. `-DMAX_CHAR=YOUR_VALUE`).

### Authors

freq is written by [Ivan Movchan](https://github.com/ivan-movchan).

### License

See [LICENSE](LICENSE) for copyright and licensing details.

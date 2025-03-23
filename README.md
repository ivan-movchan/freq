![freq](logo.png)

[English](README.md) / [Русский](README-RU.md)

A tiny utility that performs frequency analysis on `stdin` (console input stream) data byte by byte.

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

To perform frequency analysis on `stdin` data:

```bash
$ freq [< input_file [> output_file]]`
```

* `< input_file` - read data from `input_file` file and write into console (`stdin`);
* `> output_file` - write data from `stdout` (console output stream) to `output_file` file.

To display program version and exit:

```
$ freq -v
```

### Configuration

The default max. char value (and also the count of chars being analyzed by freq) is set to `UCHAR_MAX` and is defined in `MAX_CHAR` constant. You can change the constant by editing the source code and recompiling the program or by defining `MAX_CHAR` in compiler flags (i. e. `-DMAX_CHAR=YOUR_VALUE`).

### Authors

freq is written by [Ivan Movchan](https://github.com/ivan-movchan).

### License

See [LICENSE](LICENSE) for copyright and licensing details.

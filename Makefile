#
# Copyright (c) 2025 Ivan Movchan <ivan.movchan.07@gmail.com>
#
# This file is a part of freq.
#
# freq is free software released under the terms of MIT License.
# See LICENSE file for further details.
#

CC=gcc
CCFLAGS=-O2
MAKE=make

SOURCE=freq.c
TARGET=freq

PREFIX=/usr

all: $(TARGET)

$(TARGET): $(SOURCE)
	cp -u config.def.h config.h
	$(CC) $(CCFLAGS) -o $(TARGET) $(SOURCE)

install: $(TARGET)
	cp $(TARGET) $(PREFIX)/local/bin/$(TARGET)
	chmod +x $(PREFIX)/local/bin/$(TARGET)

uninstall: install
	rm -f $(PREFIX)/local/bin/$(TARGET)

clean: $(TARGET)
	rm -f $(TARGET)

i686-linux:
	$(MAKE) CC=i686-linux-gnu-gcc TARGET=freq-i686

x86_64-linux:
	$(MAKE) CC=x86_64-linux-gnu-gcc TARGET=freq-x86_64

win32:
	$(MAKE) CC=i686-w64-mingw32-gcc TARGET=freq-win32.exe

win64:
	$(MAKE) CC=x86_64-w64-mingw32-gcc TARGET=freq-win64.exe

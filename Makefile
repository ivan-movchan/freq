# See LICENSE file for copyright and licensing details.

CC=gcc
CCFLAGS=-O2

SOURCE=freq.c
TARGET=freq

PREFIX=/usr

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CCFLAGS) -o $(TARGET) $(SOURCE)

install: $(TARGET)
	cp $(TARGET) $(PREFIX)/local/bin/$(TARGET)
	chmod +x $(PREFIX)/local/bin/$(TARGET)

uninstall: install
	rm -f $(PREFIX)/local/bin/$(TARGET)

clean: $(TARGET)
	rm -f $(TARGET)

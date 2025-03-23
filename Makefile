CC=gcc
CCFLAGS=-O2

SOURCE=freq.c
TARGET=freq

PREFIX=/usr

all: freq

freq: $(SOURCE)
	$(CC) $(CCFLAGS) -o $(TARGET) $(SOURCE)

install: freq
	cp $(TARGET) $(PREFIX)/local/bin/$(TARGET)
	chmod +x $(PREFIX)/local/bin/$(TARGET)

uninstall: install
	rm -f $(PREFIX)/local/bin/$(TARGET)

TARGET := bin/pa1.out
SRC := src/main.cpp

CFLAGS := -Wall -Wextra -O3 -lm

all: $(TARGET)
$(TARGET): $(SRC) | $(BIN_DIR)
	gcc $(CFLAGS) -o $@ $<

clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean
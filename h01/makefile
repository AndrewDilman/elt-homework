CC = gcc
CFLAGS = -Wall -Wextra
SRC_DIR = src
BIN_DIR = bin
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
BIN_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(BIN_DIR)/%)

all: $(BIN_FILES)

$(BIN_DIR)/%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BIN_DIR)/*

distclean: clean
	rm -rf $(BIN_DIR)

.PHONY: all clean distclean

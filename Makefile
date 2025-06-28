STRUCT ?= list
CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -O2 -g -Iinclude

SRC_DIR = src/$(STRUCT)
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

BIN_DIR = bin
TARGET = $(BIN_DIR)/$(STRUCT)

# Default build target
$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $@

# Ensure bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean up build artifacts
clean:
	rm -rf $(OBJ) $(TARGET) $(BIN_DIR)

.PHONY: clean

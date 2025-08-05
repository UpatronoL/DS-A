STRUCT ?= list
SANITIZE ?= 1

CC = gcc
SANITIZER_FLAGS = -fsanitize=address -fno-omit-frame-pointer
ifeq ($(SANITIZE),0)
    SANITIZER_FLAGS =
endif

CFLAGS = -Wall -Wextra -O2 -g $(SANITIZER_FLAGS) -Iinclude

SRC_DIR = src/$(STRUCT)
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

BIN_DIR = bin
TARGET = $(BIN_DIR)/$(STRUCT)

TEST_DIR = tests
TEST_SRC = $(TEST_DIR)/$(STRUCT)_test.c
TEST_BIN = $(BIN_DIR)/$(STRUCT)_test

all: $(TARGET)

$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $@

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC) $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(TEST_SRC) $(OBJ) -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	find src -name '*.o' -delete
	rm -rf $(BIN_DIR)

.PHONY: all test clean


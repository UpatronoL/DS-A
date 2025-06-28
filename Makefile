CC   = gcc              # switch to clang if you prefer
CFLAGS = -std=c17 -Wall -Wextra -O2 -g
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = algods

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
.PHONY: clean


CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11 -Iinclude -g
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
TARGET = $(BIN_DIR)/program

all: $(BIN_DIR)/program

$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(INC_DIR):
	mkdir -p $(INC_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: clean
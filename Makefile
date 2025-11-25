CFLAGS = -Wall -Wextra -Werror -std=c11 -O2
CC = gcc
TARGET = a
BUILD_DIR = bin
SOURCE_DIR = src

all:$(TARGET)

SRC := $(shell find $(SOURCE_DIR) -name '*.c')
OBJ := $(addprefix $(BUILD_DIR)/, $(notdir $(SRC:.c=.o)))

$(OBJ) : | $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)




$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

vpath %.c $(shell find $(SOURCE_DIR) -type d)

$(BUILD_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean print
clean:
	rm -f $(OBJ) $(TARGET)

print:
	@echo $(SRC)
	@echo $(OBJ)

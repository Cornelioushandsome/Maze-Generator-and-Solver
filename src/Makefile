CC = gcc
TARGET = a
CFLAGS = -Wall -Wextra -I.

SRC = main.c mazeSetup/maze.c genAlgorithms/recursiveBacktracking.c
OBJ = $(SRC:%.c=objectFiles/%.o)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compile each .c into objectFiles folder, creating subfolders as needed
objectFiles/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf objectFiles $(TARGET)

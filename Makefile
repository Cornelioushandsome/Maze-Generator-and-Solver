SRC = main.c ./setup/mazeSetup.c ./generation/plainGeneration.c ./utils/mazeUtils.c
TARGET = a
CFLAGS = -Wall -Wextra
CC = gcc

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC)  $(SRC) -o $(TARGET) $(CFLAGS)

clean:
	rm -f $(TARGET)
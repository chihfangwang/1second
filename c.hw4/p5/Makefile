
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = a.out
SRCS = gomoku.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

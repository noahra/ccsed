CC = clang
CFLAGS = -Wall -Wextra
TARGET = sed
SRCS = sed.c command.c
OBJS = $(SRCS:.c=.o)

.PHONY: all run clean

all: run clean

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET) s/\"//g test.txt

clean:
	rm -f $(TARGET) $(OBJS)

CC = clang
CFLAGS = -Wall -Wextra
TARGET = sed

.PHONY: all run clean

all: run clean

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

run: $(TARGET)
	./$(TARGET) s/\"//g test.txt

clean:
	rm -f $(TARGET)

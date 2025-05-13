CC=gcc
CFLAGS=-Iinclude

SRC=src/main.c src/student.c src/address.c src/ui.c src/auth.c src/file_ops.c src/mouse.c
OBJ=$(SRC:.c=.o)
TARGET=student_mgmt

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET) 
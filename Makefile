CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c board/board.c
BIN = bin/enchessment

all: $(BIN)

$(BIN): $(SRC)
	@mkdir -p $(dir $(BIN))
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)

run: all
	@$(BIN)

clean:
	rm -rf bin

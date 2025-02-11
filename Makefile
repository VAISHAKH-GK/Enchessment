CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c board/board.c
BIN = bin/vchess

all: $(BIN)

$(BIN): $(SRC)
	@mkdir -p $(dir $(BIN))
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)

run: all
	@$(BIN)

clean:
	rm -rf bin

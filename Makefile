CC = gcc
CFLAGS = -Iinclude
SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.c)
BIN = bin/enchessment

all: $(BIN)

$(BIN):
	@mkdir -p $(dir $(BIN))
	$(CC) $(CFLAGS) -o $(BIN) $(SRCS)

run: all
	@$(BIN)

clean:
	rm -rf bin

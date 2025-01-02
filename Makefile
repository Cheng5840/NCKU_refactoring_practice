CC = gcc
CFLAGS = -std=gnu17 -Wall -Wextra 
SRC = game_logic.c
TEST_SRC = test/test_handle_player.c
OUTPUT = test_handle_player

all: $(OUTPUT)

$(OUTPUT): $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(TEST_SRC) $(SRC)


# 運行測試程序
test: $(OUTPUT)
	./$(OUTPUT)


clean:
	rm -f $(OUTPUT)

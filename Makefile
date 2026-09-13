CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -std=c11
INCLUDES = -Iinclude

SRC = src/list.c \
      src/task.c \
      src/cli.c \
      src/main.c

TEST_SRC = src/list.c \
           src/task.c \
           tests/test_list.c \
           tests/test_task.c

TARGET = cflow
TEST_TARGET = test_cflow


all: $(TARGET)


$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(TARGET)


$(TEST_TARGET): $(TEST_SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_SRC) -o $(TEST_TARGET)


test: $(TEST_TARGET)
	./$(TEST_TARGET)


debug:
	$(CC) $(CFLAGS) -g -fsanitize=address,undefined \
	$(INCLUDES) $(SRC) -o $(TARGET)


clean:
	rm -f $(TARGET) $(TEST_TARGET)


.PHONY: all test debug clean
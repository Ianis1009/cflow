CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -std=c11

INCLUDES = -Iinclude

SRC = src/list.c
MAIN = src/main.c
TEST = tests/test_list.c

TARGET = cflow
TEST_TARGET = test_list


all: $(TARGET)


$(TARGET): $(SRC) $(MAIN)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) $(MAIN) -o $(TARGET)


$(TEST_TARGET): $(SRC) $(TEST)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) $(TEST) -o $(TEST_TARGET)


test: $(TEST_TARGET)
	./$(TEST_TARGET)


clean:
	rm -f $(TARGET) $(TEST_TARGET)


debug:
	$(CC) $(CFLAGS) -g -fsanitize=address,undefined \
	$(INCLUDES) $(SRC) $(MAIN) -o $(TARGET)


.PHONY: all test clean debug
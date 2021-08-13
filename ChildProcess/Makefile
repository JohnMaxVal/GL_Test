EXE_NAME = logger

CC = g++
COMPILER_FLAGS = -std=c++11 -g -pthread

SRC_PATH = ./src/*.cpp
INCLUDE_PATH = -I./include

LOG_DELAY = 1000

build:
	$(CC) \
	$(COMPILER_FLAGS) \
	$(INCLUDE_PATH) \
	$(SRC_PATH) main.cpp \
	-o $(EXE_NAME)

run:
	./$(EXE_NAME) $(LOG_DELAY)

clean:
	rm $(EXE_NAME)

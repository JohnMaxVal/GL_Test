EXE_NAME = starter

CC = g++
COMPILER_FLAGS = -std=c++11 -g -pthread

SRC_PATH = ./src/*.cpp
INCLUDE_PATH = -I./include

TIME_DELAY = 1000

build:
	$(CC) \
	$(COMPILER_FLAGS) \
	$(INCLUDE_PATH) \
	$(SRC_PATH) main.cpp \
	-o $(EXE_NAME)

run:
	./$(EXE_NAME) $(TIME_DELAY)

term_child:
	pkill -f logger

kill_parent:
	pkill -f $(EXE_NAME)

clean:
	rm $(EXE_NAME)

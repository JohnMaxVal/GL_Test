EXE_NAME = logger

CC = g++
COMPILER_FLAGS = -std=c++11 -g -pthread

SRC_PATH = ./src/*.cpp
INCLUDE_PATH = -I./include

DBG_FOLDER = ./Debug
RLS_FOLDER = ./Release

INPUT_ARGS = 1000

build:
	$(CC) \
	$(COMPILER_FLAGS) \
	$(INCLUDE_PATH) \
	$(SRC_PATH) main.cpp \
	-o $(DGB_FOLDER)\$(EXE_NAME)

run:
	./$(EXE_NAME) $(INPUT_ARGS)

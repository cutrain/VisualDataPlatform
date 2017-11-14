CC := g++
SRC := src
LIB := lib
CFLAGS := -O3 -std=c++11
LIBS := 
FLAGS := -I./include


all:
	$(CC) -shared -fPIC $(CFLAGS) $(FLAGS) $(LIBS) -o $(LIB)/api.so main.cc
	@echo "\033[32;1mfinished\033[0m"

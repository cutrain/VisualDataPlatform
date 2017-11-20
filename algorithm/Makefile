CC := g++
SRC := src
LIB := lib
CFLAGS := -O2 -std=c++11
LIBS := -lboost_system -lboost_filesystem
FLAGS := -I./include
WARNS := -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused


all:
	@$(CC) -shared -fPIC $(CFLAGS) $(FLAGS) -o $(LIB)/api.so $(LIBS) main.cc && echo "\033[32;1mfinished\033[0m" || echo "\033[031;1mfailed\033[0m"

warn:
	@$(CC) -shared -fPIC $(CFLAGS) $(LIBS) $(FLAGS) $(WARNS) -o $(LIB)/api.so main.cc && echo "\033[32;1mfinished\033[0m" || echo "\033[031;1mfailed\033[0m"

CC := g++
SRC := src
LIB := lib
CFLAGS := -std=c++11
RELEASE := -O3
DEBUG := -D DEBUG
LIBS := -lboost_system -lboost_filesystem
STATIC_LIBS := -Wl,-Bstatic -lboost_system -Wl,--as-needed
FLAGS := -I./include
WARNS := -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused


all:
	@$(CC) -shared -fPIC $(CFLAGS) $(RELEASE) $(FLAGS) -o $(LIB)/api.so main.cc $(LIBS) && echo "\033[32;1mfinished\033[0m" || echo "\033[031;1mfailed\033[0m"

debug:
	@$(CC) -shared -fPIC $(CFLAGS) $(DEBUG) $(FLAGS) -o $(LIB)/api.so main.cc $(LIBS) && echo "\033[32;1mfinished\033[0m" || echo "\033[031;1mfailed\033[0m"

warn:
	@$(CC) -shared -fPIC $(CFLAGS) $(DEBUG) $(FLAGS) $(WARNS) -o $(LIB)/api.so main.cc $(LIBS) && echo "\033[32;1mfinished\033[0m" || echo "\033[031;1mfailed\033[0m"

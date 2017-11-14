CC := g++
SRC := src
LIB := lib
CFLAGS := -O3 -std=c++11
LIBS:= -ljson
FLAGS := -I ./jsoncpp-src-0.5.0/include -L ./jsoncpp-src-0.5.0/libs


all: $(LIB)/api.so
	@echo "\033[32;1mfinished\033[0m"

$(LIB)/api.so: $(SRC)/main.cc
	$(CC) -shared -fPIC $(CFLAGS) $(FLAGS) $(LIBS) -o $@ $^

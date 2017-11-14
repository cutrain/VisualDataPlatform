SRC := src
LIB := lib
CFLAGS := -O3
LIBS := -l./jsoncpp-src-0.5.0/libs/*/*.so
FLAGS := -I./jsoncpp-src-0.5.0/include/json

all: $(LIB)/misc.so
	@echo "\033[32;1mfinished\033[0m"

$(LIB)/%.so: $(SRC)/%.cc
	$(CC) -shared -fPIC $(CFLAGS) $(LIBS) $(FLAGS) -o $@ $^

SRC := src
LIB := lib
CFLAGS := -O3

all: $(LIB)/misc.so
	@echo "\033[32;1mfinished\033[0m"

$(LIB)/%.so: $(SRC)/%.cc
	$(CC) -shared -fPIC $(CFLAGS) -o $@ $^

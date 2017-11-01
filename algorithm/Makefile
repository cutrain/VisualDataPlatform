SRC := src
LIB := lib

all: $(LIB)/misc.so
	@echo "\033[32;1mfinished\033[0m"

$(LIB)/%.so: $(SRC)/%.cc
	$(CC) -shared -fPIC -o $@ $^

#include "src/core.cc"
#include "src/api.cc"
#include "src/input.cc"

#include "dist/jsoncpp.cpp"
GraphManager graphManager;
NodePtrMap typeMap = {
	{"input", new InputNode},
};
Data DataNull;

#include "dist/jsoncpp.cpp"
#include "src/core.cc"
#include "src/api.cc"
#include "src/input.cc"
GraphManager graphManager;
NodePtrMap typeMap = {
	{"input", new InputNode},
};
Data DataNull;

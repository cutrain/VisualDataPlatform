#include "core.cc"
#include "api.cc"
#include "input.cc"
GraphManager graphManager;
NodePtrMap typeMap = {
	{"input", new InputNode},
};
Data DataNull;

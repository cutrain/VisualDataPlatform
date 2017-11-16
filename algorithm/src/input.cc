#include "input.h"
#include <boost/algorithm/string.hpp>

InputNode::~InputNode() {
}

InputNode* InputNode::Create(const string& name) {
	name_ = name;
	InputNode* ret = new InputNode;
	return ret;
}

int InputNode::Set(const string& param) {
	// TODO: use json to decode
	if (param.substr(0,5) != "path:")
		return PARAM_NOT_SPECIFY;
	path_ = param.substr(5);
	return 0;
}

int InputNode::Run(const DataPtrMap& input) {
	if (path_ == "")
		return PARAM_NOT_SPECIFY;
	// TODO: read from the path
	return 0;
}


#ifndef INPUT_H_
#define INPUT_H_

#include "core.h"
#include <boost/filesystem.hpp>


class InputNode : public NodeBase {
protected:
	boost::filesystem::path path_;
public:
	InputNode() {type_ = "InputNode";}
	~InputNode();
	InputNode* Create(const string& name);
	int Set(const string& param);
	int Run(const DataPtrMap& input);
};


#endif // INPUT_H_

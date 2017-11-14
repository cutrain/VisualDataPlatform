#ifndef INPUT_H_
#define INPUT_H_

#include "core.h"

#ifdef __cplusplus
extern "C" {
#endif

class InputNode : public NodeBase {
protected:
	string path_;
public:
	InputNode() {type_ = "InputNode";}
	~InputNode();
	InputNode* Create(const string& name);
	int Set(const string& param);
	int Run(const DataPtrMap& input);
};


#ifdef __cplusplus
}
#endif
#endif // INPUT_H_

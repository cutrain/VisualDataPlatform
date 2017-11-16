#include "input.h"
#include <boost/algorithm/string.hpp>

#include <json/json.h>
#include <boost/filesystem.hpp>

namespace bf=boost::filesystem;

InputNode::~InputNode() {
}

InputNode* InputNode::Create(const string& name) {
	name_ = name;
	InputNode* ret = new InputNode;
	return ret;
}

int InputNode::Set(const string& param) {
	Json::Value json(param);
	// decode path
	Json::Value attr;
	if (!(attr = json.get("path", "")).empty())
	{
		string path = json.get("path", "").asString();
		bf::path p(path);
		if (p.empty())
			return PATH_NOT_SPECIFY;
		path_ = p;
	}
	// clear data
	for (auto iter = out_value_.begin(); iter != out_value_.end(); ++iter)
		delete iter->second;
	out_value_.clear();
	out_value_["output"] = new Data;
	// decode column type
	int column = json.get("column", "0").asInt();
	out_value_["output"]->dim.push_back(0);
	out_value_["output"]->dim.push_back(column);
	Json::Value value_type = json.get("column_type", "");
	for (int i = 0;i < column;++ i)
	{
		string str = value_type.get(i, "string").asString();
		out_value_["output"]->column_type.push_back(str);
	}
	// decode filetype
	string filetype = json.get("filetype", "csv").asString();
	out_value_["output"]->data_type = filetype;
	// decode name
	// TODO : CHECK if the comparison is right
	if (json.get("specify_name", "0").asString().compare("1") == 0)
	{
		out_value_["output"]->name.clear();
		Json::Value name = json.get("name", "");
		int name_num = name.size();
		for (int i = 0;i < name_num; ++i)
		{
			string str = name[i].asString();
			out_value_["output"]->name.push_back(str);
		}
	}
	return 0;
}

int InputNode::Run(const DataPtrMap& input) {
	if (path_.empty())
		return PATH_NOT_SPECIFY;
	
	return 0;
}


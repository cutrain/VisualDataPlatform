#include "input.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

#include <json/json.h>

#define MAXBUFFER 256

namespace bf=boost::filesystem;

InputNode::~InputNode() {
}

InputNode* InputNode::Create(const string& name) {
	name_ = name;
	InputNode* ret = new InputNode;
	return ret;
}

int InputNode::Set(const string& param) {
	print("in InputNode.Set Enter\n");
	Json::Reader reader;
	Json::Value json;
	reader.parse(param, json);
	Json::Value null;
	// decode path
	print("in InputNode.Set decode path\n");
	Json::Value attr;
	if (!(attr = json.get("path", null)).empty())
	{
		string path = json.get("path", null).asString();
		bf::path p(path);
		if (p.empty())
			return PATH_NOT_SPECIFY;
		path_ = p;
	}
	// clear data
	print("in InputNode.Set decode data\n");
	for (auto iter = out_value_.begin(); iter != out_value_.end(); ++iter)
		delete iter->second;
	out_value_.clear();
	out_value_["output"] = new Data;
	// decode column type
	print("in InputNode.Set decode column type\n");
	int column = json.get("column", Json::Value(0)).asInt();
	out_value_["output"]->dim.push_back(0);
	out_value_["output"]->dim.push_back(column);
	Json::Value value_type = json.get("column_type", null);
	for (int i = 0;i < column;++ i)
	{
		string str = value_type.get(i, Json::Value("string")).asString();
		out_value_["output"]->column_type.push_back(str);
	}
	// decode filetype
	string filetype = json.get("filetype", Json::Value("csv")).asString();
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
	print("InputNode::Run Enter\n");
	if (path_.empty())
		return PATH_NOT_SPECIFY;
	std::ifstream ifs;
	ifs.open(path_.c_str(), std::ifstream::in);
	print("InputNode::Run 1\n");

	string str;
	std::vector<string> substr;
	while (getline(ifs, str))
	{
		// TODO: use csv parser (known bug : string with ',' char will be split)
		print("InputNode::Run loop start\n");
		sprint(str);
		substr.clear();
		boost::split(substr, str, boost::is_any_of(",")); 
		for (int i = 0;i < static_cast<int>(substr.size()); ++ i)
		{
			sprint(substr[i]);
			Data*& tmp_data = out_value_["output"];
			print("1\n");
			std::vector<string>& tmp_vs = tmp_data->column_type;
			print("2\n");
			if (tmp_vs[i].compare("string") == 0)
				out_value_["output"]->value[i].push(substr[i]);
			else
				out_value_["output"]->value[i].push(std::stod(substr[i]));
		}
		print("InputNode::Run loop end\n");
	}
	print("InputNode::Run Leave\n");
	return 0;
}


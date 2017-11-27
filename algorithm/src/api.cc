#include "api.h"

#include <cstring>
#include <string>

#include <json/json.h>


const char* make_json(const char* func_name, int status_code, Json::Value&& json = Json::Value()) {
	json["status"] = status_code;
	json["function_name"] = func_name;
	string str = json.toStyledString();
	int len = str.length();
	static char* s;
	delete[] s;
	s = new char(1 + len);
	memcpy(s, str.c_str(), len);
	return s;
}


const char* Create(char* name, char* type, char* param) {
	string sname = string(name);
	string stype = string(type);
	string sparam = string(param);
	int ret = graphManager.Create(sname, stype, sparam);
	return make_json("create", ret);
}

const char* Delete(char* name) {
	// TODO: delete related edge
	string sname = string(name);
	int ret = graphManager.Delete(sname);
	return make_json("delete", ret);
}

const char* Connect(char* out_node, char* out_port, char* in_node, char* in_port) {
	string sout_node = string(out_node);
	string sout_port = string(out_port);
	string sin_node = string(in_node);
	string sin_port = string(in_port);
	int ret = graphManager.Connect(sout_node, sout_port, sin_node, sin_port);
	return make_json("connect", ret);
}

const char* Disconnect(char* out_node, char* out_port, char* in_node, char* in_port) {
	string sout_node = string(out_node);
	string sout_port = string(out_port);
	string sin_node = string(in_node);
	string sin_port = string(in_port);
	int ret = graphManager.Disconnect(sout_node, sout_port, sin_node, sin_port);
	return make_json("disconnect", ret);
}

const char* GetValue(char* name, char* out_port, int start_row, int end_row) {
	print("API::GetValue Enter\n");
	string sname = string(name);
	string sout_port = string(out_port);
	if (graphManager.CheckName(sname) == NAME_NOT_FOUND)
		return make_json("getvalue", NAME_NOT_FOUND);
	if (start_row < -1 || end_row < -1)
		return make_json("getvalue", RANGE_EXCCED);
	print("API::GetValue 1\n");

	NodePtr node = graphManager.GetNode(sname);
	print("API::GetValue 2\n");
	DataPtr value = node->GetValue(sout_port);
	print("API::GetValue 3\n");
	// TODO:return value with json
	if (start_row >= value->dim[0] || end_row >= value->dim[0])
		return make_json("getvalue", RANGE_EXCCED);
	if (start_row == -1)
	{
		start_row = 0;
		end_row = value->dim[0];
	}
	if (end_row == -1)
		end_row = value->dim[0];

	int step = 1;
	for (int i = 1;i < static_cast<int>(value->dim.size()); ++ i)
		step *= value->dim[i];
	Json::Value json;
	json["type"] = value->data_type;
	for (int i = 0;i < static_cast<int>(value->dim.size()); ++ i)
		json["dim"][i] = value->dim[i];
	for (int i = start_row; i < end_row; ++ i)
	{
		int base = i * step;
		for (int j = 0;j < step; ++ j)
			json["value"].append(boost::apply_visitor(ElemVisitor(), value->value[base+j]));
	}
	print("API::GetValue Leave\n");

	return make_json("getvalue", OK, std::move(json));
}

const char* Run(char* name) {
	print("api::Run Enter\n");
	string sname = string(name);
	if (graphManager.CheckName(sname) == NAME_NOT_FOUND)
		return make_json("run", NAME_NOT_FOUND);
	print("api::Run 1\n");
	DataPtrMap datas = graphManager.GetInput(sname);
	print("api::Run 2\n");
	NodePtr node = graphManager.GetNode(sname);
	print("api::Run 3\n");
	int ret = node->Run(datas);
	print("api::Run Leave\n");
	return make_json("run", ret);
}

const char* RunTo(char* name) {
	// TODO
	return make_json("runto", NOT_DEFINED);
}

const char* RunAll() {
	// TODO
	return make_json("runall", NOT_DEFINED);
}


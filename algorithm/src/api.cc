#include "api.h"

#include <cstring>
#include <string>
#include <json/json.h>

char retstr[100];
char* print_message(int message_code, char* append_message=(char*)"") {
	// TODO: map code to message & use recycle memory
	sprintf(retstr, "%d / %s", message_code, append_message);
	return retstr;
}

char* Create(char* name, char* type, char* param) {
	string sname = string(name);
	string stype = string(type);
	string sparam = string(param);
	int ret = graphManager.Create(sname, stype, sparam);
	return print_message(ret, (char*)"create");
}

char* Delete(char* name) {
	// TODO: delete related edge
	string sname = string(name);
	int ret = graphManager.Delete(sname);
	return print_message(ret, (char*)"delete");
}

char* Connect(char* out_node, char* out_port, char* in_node, char* in_port) {
	string sout_node = string(out_node);
	string sout_port = string(out_port);
	string sin_node = string(in_node);
	string sin_port = string(in_port);
	int ret = graphManager.Connect(sout_node, sout_port, sin_node, sin_port);
	return print_message(ret, (char*)"connect");
}

char* Disconnect(char* out_node, char* out_port, char* in_node, char* in_port) {
	string sout_node = string(out_node);
	string sout_port = string(out_port);
	string sin_node = string(in_node);
	string sin_port = string(in_port);
	int ret = graphManager.Disconnect(sout_node, sout_port, sin_node, sin_port);
	return print_message(ret, (char*)"disconnect");
}

char* GetValue(char* name, char* out_port, int start_row, int end_row) {
	string sname = string(name);
	string sout_port = string(out_port);
	if (graphManager.CheckName(sname) == NAME_NOT_FOUND)
		return print_message(NAME_NOT_FOUND, (char*)"getvalue");
	if (start_row < -1 || end_row < -1)
		return print_message(RANGE_EXCCED, (char*)"getvalue");

	NodePtr node = graphManager.GetNode(sname);
	DataPtr value = node->GetValue(sout_port);
	// TODO:return value with json
	if (start_row >= value->dim[0] || end_row >= value->dim[0])
		return print_message(RANGE_EXCCED, (char*)"getvalue");
	if (start_row == -1)
	{
		start_row = 0;
		end_row = value->dim[0];
	}
	if (end_row == -1)
		end_row = value->dim[0];
	
	int step = 1;
	for (int i = 1;i < (int)value->dim.size(); ++ i)
		step *= value->dim[i];
	Json::Value json;
	json["type"] = value->type;
	for (int i = 0;i < (int)value->dim.size(); ++ i)
		json["dim"][i] = value->dim[i];
	for (int i = start_row; i < end_row; ++ i)
	{
		int base = i * step;
		for (int j = 0;j < step; ++ j)
			json["value"].append(boost::apply_visitor(ElemVisitor(), value->value[base+j]));
	}
	return (char*)json.toStyledString().c_str();
}

char* Run(char* name) {
	string sname = string(name);
	if (graphManager.CheckName(sname) == NAME_NOT_FOUND)
		return print_message(NAME_NOT_FOUND, (char*)"run");
	DataPtrMap datas = graphManager.GetInput(sname);
	NodePtr node = graphManager.GetNode(sname);
	int ret = node->Run(datas);
	return print_message(ret, (char*)"run");
}

char* RunTo(char* name) {
	// TODO
	return (char*)"ERROR occurred without define";
}

char* RunAll() {
	// TODO
	return (char*)"ERROR occurred without define";
}


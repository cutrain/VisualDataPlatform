#include "api.h"

#include <cstring>
#include <string>
#ifdef __cplusplus
extern "C" {
#endif

// TODO : return message with json

char* print_message(int message_code, char* append_message=(char*)"") {
	// TODO: map code to message & use recycle memory
	char* str = new char(10);
	sprintf(str, "%d / %s", message_code, append_message);
	return str;
}

char* Create(char* name, char* type, char* param) {
	string sname = string(name);
	string stype = string(type);
	string sparam = string(param);
	int ret = graphManager.Create(sname, stype, sparam);
	return print_message(ret, (char*)"create");
}

char* Delete(char* name) {
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
	NodePtr node = graphManager.GetNode(sname);
	DataPtr value = node->GetValue(sout_port);
	// TODO:return value with json
	return print_message(0, (char*)"getvalue");
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
	return (char*)"ERROR occurred without define";
}

char* RunAll() {
	return (char*)"ERROR occurred without define";
}

#ifdef __cplusplus
}
#endif

#ifndef API_H_
#define API_H_
#include "core.h"

#ifdef __cplusplus
extern "C" {
#endif


// create a node, find 'type' & 'param format' in the Manual
char* Create(char* name, char* type, char* param);


char* Delete(char* name);


// connect two nodes's ports with directed edge
// look like this :  out_node(out_port) -> in_node(in_port)
// common use port : "output" "input"(for some special type of node, it may be different)
// read Manual for detail
char* Connect(char* out_node, char* out_port, char* in_node, char* in_port);


// cancel the exist edge
char* Disconnect(char* out_node, char* out_port, char* in_node, char* in_port);


// get the value in the node's port, get start_row to end_row's values
// return all value if start_row = -1
// return start_row to the bottom if end_row = -1
// row index start from 0
// return json : {'dim':[],'value':[]}
char* GetValue(char* name, char* out_port, int start_row, int end_row);


// run the specific node
char* Run(char* name);


// THIS API DOES NOT COMPLETE
char* RunTo(char* name);


// THIS API DOES NOT COMPLETE
char* RunAll();


#ifdef __cplusplus
}
#endif
#endif // API_H_

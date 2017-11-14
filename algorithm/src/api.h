#ifndef API_H_
#define API_H_
#include "core.h"

#ifdef __cplusplus
extern "C" {
#endif


char* Create(char* name, char* type, char* param);
char* Delete(char* name);
char* Connect(char* out_node, char* out_port, char* in_node, char* in_port);
char* Disconnect(char* out_node, char* out_port, char* in_node, char* in_port);
char* GetValue(char* name, char* out_port, int start_row, int end_row);
char* Run(char* name);
char* RunTo(char* name);
char* RunAll();

#ifdef __cplusplus
}
#endif
#endif // API_H_

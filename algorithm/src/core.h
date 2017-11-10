#ifndef COMPUTE_NODE_H_
#define COMPUTE_NODE_H_

#include <set>
#include <vector>
#include <boost/shared_ptr.hpp>
#ifdef __cplusplus
extern "C" {
#endif

struct Data {
	char* type;
	std::vector<int> dim;
	std::vector<double> value_double;
	std::vector<int> value_int;
};


class NodeBase{
private:
	char* name_;
	char* type_;
	std::set<boost::shared_ptr<Data> > value_;
public:
	NodeBase(char* name, char* type, char* param);
	~NodeBase();
	virtual int Run();
	virtual boost::shared_ptr<Data> GetValue(int row_start, int row_end);
	virtual int Reset(); //
	virtual int Clean();
};

char* Create(char* name, char* type, char* param);
char* Delete(char* name);
char* Connect(char* out_node, char* out_port, char* in_node, char* in_port);
char* Disconnect(char* out_node, char* out_port, char* in_node, char* in_port);
char* GetValue(char* name, int row_start, int row_end);

#ifdef __cplusplus
}
#endif
#endif // COMPUTE_NODE_H_

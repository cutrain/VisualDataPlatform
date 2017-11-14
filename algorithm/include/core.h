#ifndef CORE_H_
#define CORE_H_

#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/variant.hpp>

#ifdef __cplusplus
extern "C" {
#endif

// TODO: define ERROE TYPE
#define OK 0
#define NAME_EXIST 1
#define TYPE_EXIST 2
#define EDGE_EXIST 3
#define NAME_NOT_FOUND 4
#define TYPE_NOT_FOUND 5
#define EDGE_NOT_FOUND 6
#define PARAM_NOT_SPECIFY 7
#define RANGE_EXCCED 8

using std::string;
typedef std::pair<string, string> PairString;
typedef boost::variant<int, double> Element;

struct ElemVisitor : public boost::static_visitor<string> {
public:
	string operator()(int i) const { return std::to_string(i);}
	string operator()(double d) const { return std::to_string(d);}
};

// TODO: optimize data structure
struct Data {
	string type;
	std::vector<int> dim;
	std::vector<Element> value;
};
typedef Data* DataPtr;
typedef std::map<string, DataPtr> DataPtrMap;


class NodeBase {
protected:
	string type_;
	string name_;
	DataPtrMap out_value_;
public:
	NodeBase() {type_ = "NodeBase";}
	virtual ~NodeBase()=0;
	virtual NodeBase* Create(const string& name)=0;
	virtual int Set(const string& param)=0;
	virtual int Run(const DataPtrMap& input)=0;
	DataPtr GetValue(const string& port);
	string GetType();
};
typedef NodeBase* NodePtr;
typedef std::map<string, NodePtr> NodePtrMap;


typedef std::pair<PairString, PairString> GraphEdge;
typedef std::set<GraphEdge> EdgeSet;
class GraphManager {
private:
	// TODO: clear the use of shared_ptr<NodeBase>
	NodePtrMap nodes_;
	// In PairString, the first string represent node name, the second string represent node port
	EdgeSet edges_;
public:
	int CheckName(const string& name);
	int CheckType(const string& type);
	int Create(const string& name, const string& type, const string& param);
	int Delete(const string& name);
	int Connect(const string& out_node, const string& out_port, const string& in_node, const string& in_port);
	int Disconnect(const string& out_node, const string& out_port, const string& in_node, const string& in_port);
	// GetNode will not check the name, please use after confirm
	NodePtr GetNode(const string& name);
	// GetInput will not check the name, please use after confirm
	DataPtrMap GetInput(const string& name);
};
extern GraphManager graphManager;
extern NodePtrMap typeMap;
extern Data DataNull;




// start initialize


// initialize all type with the specify meaning
// include: typeMap
void init();


#ifdef __cplusplus
}
#endif
#endif // CORE_H_

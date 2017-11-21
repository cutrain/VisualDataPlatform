#include "core.h"

#include <cstdlib>
#include <cstdarg>


// NodeBase
DataPtr NodeBase::GetValue(const string& port) {
	DataPtrMap::iterator iter = out_value_.find(port);
	if (iter == out_value_.end())
		return &DataNull;
	return iter->second;
}

NodeBase::~NodeBase() {
	// TODO: destroy the value with shared_ptr
	// TODO: check memory
	for (DataPtrMap::iterator iter = out_value_.begin(); iter != out_value_.end(); ++ iter)
	{
		delete iter->second;
	}
}

string NodeBase::GetType() const {
	return type_;
}


// GraphManager
inline int GraphManager::CheckName(const string& name) const {
	return (nodes_.find(name) != nodes_.end()) ? (NAME_EXIST) : (NAME_NOT_FOUND);
}

inline int GraphManager::CheckType(const string& type) const {
	return (typeMap.find(type) != typeMap.end()) ? (TYPE_EXIST) : (TYPE_NOT_FOUND);
}

int GraphManager::Create(const string& name, const string& type, const string& param) {
	print("in graphManager.Creeate Enter\n");
	if (NAME_EXIST == CheckName(name))
		return NAME_EXIST;
	if (TYPE_NOT_FOUND == CheckType(type))
		return TYPE_NOT_FOUND;
	print("in graphManager.Creeate 1\n");
	NodePtr node = typeMap[type]->Create(name);
	print("in graphManager.Creeate 2\n");
	node->Set(param);
	print("in graphManager.Creeate 3\n");
	nodes_[name] = node;
	print("in graphManager.Creeate Leave\n");
	return 0;
}

int GraphManager::Delete(const string& name) {
	if (NAME_NOT_FOUND == CheckName(name))
		return NAME_NOT_FOUND;
	nodes_.erase(name);
	return 0;
}

int GraphManager::Connect
(const string& out_node, const string& out_port, const string& in_node, const string& in_port) {
	// confirm node
	if (NAME_NOT_FOUND == CheckName(out_node))
		return NAME_NOT_FOUND;
	if (NAME_NOT_FOUND == CheckName(in_node))
		return NAME_NOT_FOUND;

	PairString out(out_node, out_port);
	PairString in(in_node, in_port);
	GraphEdge edge(out, in);

	// modify graph
	std::pair<EdgeSet::iterator, bool> ret = edges_.insert(edge);
	if (ret.second == false)
		return EDGE_EXIST;
	return 0;
}

int GraphManager::Disconnect
(const string& out_node, const string& out_port, const string& in_node, const string& in_port) {
	// confirm node
	if (NAME_NOT_FOUND == CheckName(out_node))
		return NAME_NOT_FOUND;
	if (NAME_NOT_FOUND == CheckName(in_node))
		return NAME_NOT_FOUND;

	PairString out(out_node, out_port);
	PairString in(in_node, in_port);
	GraphEdge edge(out, in);
	// modify graph

	if (edges_.count(edge) == 0)
		return EDGE_NOT_FOUND;
	edges_.erase(edge);
	return 0;
}

NodePtr GraphManager::GetNode(const string& name) const {
	return nodes_.at(name);
}

DataPtrMap GraphManager::GetInput(const string& name) const  {
	// TODO: check whether 'ret' will be destroy after return
	DataPtrMap ret;
	for (EdgeSet::iterator iter = edges_.begin(); iter != edges_.end(); ++iter)
	{
		const GraphEdge& edge = *iter;
		const PairString& out = edge.first;
		const PairString& in = edge.second;
		if (in.first == name)
		{
			NodePtr nodeptr = GetNode(out.first);
			ret[in.second] = nodeptr->GetValue(out.second);
		}
	}
	return ret;
}


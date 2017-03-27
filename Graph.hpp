#ifndef _GRAPH_
#define _GRAPH_

#include <vector>

#include "Node.hpp"

class Graph {
	int nNodes, nEdges;
	std::vector<Node> nodes;
	std::vector <std::pair<int, int >> edges;
	Node finish;

public:
	void setnNodes(int n) {	nNodes = n;	}
	void setnEdges(int n) {	nEdges = n;	}

	void readNodes(std::ifstream& file);
	void readEdges(std::ifstream& file);
	void setIndegreeAndOutdegree();
	void setFinish();
	void setESEF_for_starters();
	void setLSLF_for_enders();
	void setESFF_for_graph();
	void setLSLF_for_graph();
	void displayNodes();
};


#endif //_GRAPH_

// CPM.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

#include "Graph.hpp"


void calcTotalETime(int nNodes, std::vector<Node> nodes) {
	for (Node e : nodes) {

	}
}

int main()
{
	Graph graph;
	int nNodes, nEdges;
	FILE *ofile;

	std::string fileName;

	/*std::cout << "Enter filename\n";
	std::cin >> fileName;*/

	std::ifstream file("dataSort80.txt");

	file >> nNodes >> nEdges;

	graph.setnNodes(nNodes);
	graph.setnEdges(nEdges);

	graph.readNodes(file);
	graph.readEdges(file);
	graph.setIndegreeAndOutdegree();
	graph.setESEF_for_starters();

	graph.setESFF_for_graph();
	graph.setFinish();
	graph.setLSLF_for_enders();
	graph.setLSLF_for_graph();
	graph.displayNodes();


	std::cin >> fileName;

    return 0;
}

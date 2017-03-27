#include <queue>
#include <fstream>
#include <iostream>
#include <functional>

#include "Graph.hpp"


void Graph::readNodes(std::ifstream& file) {
  int nodeTime;
  for (int i = 0; i < nNodes; i++) {
    file >> nodeTime;
    Node node(nodeTime);
    //if (!i) { node.setES(0); node.setEF(nodeTime); }
    nodes.push_back(node);
  }
}

void Graph::readEdges(std::ifstream& file) {
  std::pair<int, int> nPair;
  int a, b;
  for (int i = 0; i < nEdges; i++) {
    file >> a >> b;
    edges.push_back(std::make_pair(a, b));
  }
}

void Graph::setIndegreeAndOutdegree() {
  for (int i = 0; i < nNodes; i++) {
    for (std::pair<int, int> e : edges) {
      if (e.second == i+1) {
        nodes.at(i).increaseIndegree();
      }
      else if (e.first == i + 1) {
        nodes.at(i).increaseOutdegree();
      }
    }
  }
}

void Graph::setFinish() {
  for (Node e : nodes) {
    if (e.getOutdegree() == 0) {
      finish.setES(std::max(finish.getES(), e.getEF()));
      finish.setEF(finish.getES());
      finish.setLS(finish.getES());
      finish.setLF(finish.getES());
    }
  }
}

void Graph::setESEF_for_starters() {
  for (std::vector<Node>::iterator it = nodes.begin(); it != nodes.end(); it++) {
    if ((*it).getIndegree() == 0) {
      int a = (*it).getProcTime();
      (*it).setEF(a);
      //std::cout << e.getProcTime() << "asasda";
      //std::cout << (*it).getEF() << "asdadad";
    }
  }
}

void Graph::setLSLF_for_enders() {
  for (std::vector<Node>::iterator it = nodes.begin(); it != nodes.end(); it++) {
    if ((*it).getOutdegree() == 0) {
      (*it).setLSLFBasedOnSuccessor(&finish);
    }
  }
}

void Graph::setESFF_for_graph() {
  for (std::pair<int, int> e : edges) {
    nodes.at(e.second-1).setESEFBasedOnPredecessor(&nodes.at(e.first-1));
  }
}

/*void Graph::setLSLF_for_graph() {
  for (std::vector<std::pair<int, int>>::iterator it = edges.end()-1; it >= edges.begin(); it--) {
    nodes.at((*it).first - 1).setLSLFBasedOnSuccessor(&nodes.at((*it).first - 1));
  }
}*/

void Graph::setLSLF_for_graph() {
  for (int i = edges.size() - 1; i >= 0; i--) {
    nodes.at(edges.at(i).first - 1).setLSLFBasedOnSuccessor(&nodes.at(edges.at(i).second - 1));
  }
}

void Graph::displayNodes() {
  for (Node e : nodes) {
    std::cout << e.getES() << " " << e.getEF() <<" "<< e.getLS() <<" "<< e.getLF() << std::endl;
  }
  std::cout << finish.getES();
}

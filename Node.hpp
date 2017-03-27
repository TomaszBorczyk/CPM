#ifndef _NODE_
#define _NODE_

//std::pair<int, int> takePair
class Node {

private:
	int procTime;
	int earlyStart;
	int earlyFinish;
	int lateStart;
	int lateFinish;
	int indegree;
	int outdegree;

public:
	Node() {}

	Node(int procTime) {
		this->procTime = procTime;
		indegree = 0;
		outdegree = 0;
		earlyStart = 0;
		lateFinish = 9999;
		lateStart = 9999;
	}

	void increaseIndegree() {indegree++;}
	void increaseOutdegree() { outdegree++; }

	void setES(int es) {this->earlyStart = es;	}
	void setEF(int ef) {this->earlyFinish = ef; }
	void setLS(int ls) {lateStart = ls;	}
	void setLF(int lf) {lateFinish = lf;}

	int getES() {return earlyStart;}
	int getEF() {return earlyFinish;}
	int getLS() {return lateStart;}
	int getLF() {return lateFinish;}
	int getIndegree() {return indegree;}
	int getOutdegree() { return outdegree; }
	int getProcTime() {return procTime;}

	void setESEFBasedOnPredecessor(Node* node) {
		this->setES(std::max(this->getES(), node->getEF()));
		this->setEF(this->getES() + this->getProcTime());

	}

	void setLSLFBasedOnSuccessor(Node* node) {
		this->setLF(std::min(this->getLF(), node->getLS()));
		this->setLS(this->getLF() - this->getProcTime());

	}
};

#endif //_NODE_

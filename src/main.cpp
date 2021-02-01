#include "GateNode.hpp"
#include "QASMparser.h"
#include "util.cpp"
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char** argv) {
	char * qasmFileName = NULL;
	char * couplingMapFileName = NULL;
	int latency1 = 1;
	int latency2 = 1;
	int latencySwp = 1;
	
	//Parse command-line arguments:
	for(int iter = 1; iter < argc; iter++) {
		if(!strcmp(argv[iter], "-latency")) {
			latency1 = atoi(argv[++iter]);
			latency2 = atoi(argv[++iter]);
			latencySwp = atoi(argv[++iter]);
		} else if(!qasmFileName) {
			qasmFileName = argv[iter];
		} else if(!couplingMapFileName) {
			couplingMapFileName = argv[iter];
		} else {
			assert(false);
		}
	}
	
	//Build dependency graph for the quantum circuit's gates; put dependency graph's roots into a set
	set<GateNode*> firstGates;
	set<GateNode*> finishGates;
	int numLogicalQubits = -1;
	int numGates = -1;
	queue<GateNode*> myq;
	buildDependencyGraph(qasmFileName, firstGates, numLogicalQubits, numGates);
    cout<<"execute successfully"<<endl;
	for(auto x : firstGates) {
		cout<<x->name<<"gate with control qubit " << x->control << "target qubit "<<x->target<<"control child"<<x->controlChild<<"target child"<<x->targetChild<<endl;
		if(x->controlChild == NULL) {
			cout<<"nullpointer"<<endl;
		}else{
			cout<<x->controlChild->name<<endl;
		}
		if(x->targetChild == NULL) {
			cout<<"nullpointer"<<endl;
		}else{
			cout<<x->targetChild->name<<endl;
		}
		myq.push(x);
	}
	int cycle = 0;
    while(!myq.empty()){	
		cout<<"cycle number is : "<<cycle<<endl;
		for(int i = 0; i < myq.size();i++) {
			GateNode* x = myq.front();
			cout<<x->name<<"gate with control qubit " << x->control << "target qubit "<<x->target<<endl;
			finishGates.insert(x);
			if(x->controlChild != NULL) {
				GateNode* CC = x->controlChild;
				if(CC->targetParent == NULL || (CC->targetParent != NULL && finishGates.find(CC) != finishGates.end() )){
					myq.push(CC);
				}
			}
			if(x->targetChild != NULL) {
				GateNode* CC = x->targetChild;
				if(CC->controlParent == NULL || (CC->controlParent != NULL && finishGates.find(CC) != finishGates.end() )){
					myq.push(CC);
				}
			}
			myq.pop();

		}
		if(cycle > 100) {
			cout<<"error"<<endl;
			break;
		}
		cycle++;
	}

	//Parse the coupling map; put edges into a set
	int numPhysicalQubits = 0;
	set<pair<int, int> > couplings;
	buildCouplingMap(couplingMapFileName, couplings, numPhysicalQubits);
	assert(numPhysicalQubits >= numLogicalQubits);
	
	
	//student code goes here?
	
	
	//Exit the program:
	return 0;
}
#include "GateNode.hpp"
#include "QASMparser.h"
#include "util.cpp"
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
bool checkCnotCoupling(set<pair<int,int>> couplings,GateNode* g){
	if(g->control == -1) return true;
	pair<int,int> p1(g->control,g->target);
	pair<int,int> p2(g->target, g->control);
	if(couplings.find(p1) != couplings.end() || couplings.find(p2) != couplings.end()) {
		return true;
	}
	return false;
}
int costfunction(vector<GateNode*> s,  map<string,double> cp) {
	int size = s.size();
	int crosstalk = 0;
	for(int i = 0; i < size; i++) {
		for(int j = i+1; j < size; j++) {
			GateNode* one = s[i];
			GateNode* two = s[j];
			string temp;
			temp = to_string(one->control) + ','+to_string(one->target)+"->"+to_string(two->control)+','+to_string(two->target);
			if(cp.find(temp) != cp.end()) {
				crosstalk++;
			}
		}	
	}
	int point;
	point = crosstalk - size; 
	return point;

}
void Combi(GateNode* a[], int reqLen, int s, int currLen, bool check[], int l,map<string,double> crosstalkcrop)
{
   if(currLen > reqLen)
   return;
   else if (currLen == reqLen) {
      cout<<"\t";
	  vector<GateNode*> tv;
      for (int i = 0; i < l; i++) {
         if (check[i] == true) {
            cout<<a[i]->name<<"("<<a[i]->control<<","<<a[i]->target<<"); ";
			tv.push_back(a[i]);
		 }
      }
      cout<<"cost value is"<<costfunction(tv,crosstalkcrop);
      cout<<"\n";
      return;
   }
   if (s == l) {
      return;
   }
   check[s] = true;
   Combi(a, reqLen, s + 1, currLen + 1, check, l,crosstalkcrop);
   check[s] = false;
   Combi(a, reqLen, s + 1, currLen, check, l,crosstalkcrop);
}

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
	queue<GateNode*> myq,cnotq;
	buildDependencyGraph(qasmFileName, firstGates, numLogicalQubits, numGates);
    cout<<"execute successfully"<<endl;
	map<string,double> crosstalkprop;
	string temp  = "5,6->8,9";
	string temp2 = "8,9->11,10";//add all combinations latter or give a good choice;
	crosstalkprop[temp] = 0.2;
	crosstalkprop[temp2] = 0.1;
	for(auto x : firstGates) {
		cout<<x->name<<"gate with control qubit " << x->control << "target qubit "<<x->target<<endl;
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
		cnotq.push(x);
	}
	
	//Parse the coupling map; put edges into a set
	int numPhysicalQubits = 0;
	set<pair<int, int> > couplings;
	buildCouplingMap(couplingMapFileName, couplings, numPhysicalQubits);
	for(auto x : couplings) {
		cout<<"("<<x.first<<" --- "<<x.second<<" ), ";
	}
	cout<<endl;
	cout<<" ******  DAG cycles information *****"<<endl;
	//to check if our cnot is already mapping to the coupling graph
	int cycle = 0;
    while(!myq.empty()){	
		//cout<<"cycle number is : "<<cycle<<endl;
		int size = myq.size();
		cout<<"cycle number is : "<<cycle << "with cnots number: "<<size <<endl;
		for(int i = 0; i < size;i++) {
			GateNode* x = myq.front();
			cout<<x->name<<"(" << x->control << " , "<<x->target<<")"<<endl;
			
			finishGates.insert(x);
			if(x->controlChild != NULL) {
				cout<<"controlchild"<<endl;
				GateNode* CC = x->controlChild;
				if(CC->controlParent == x){
					if((CC->targetParent == NULL )|| (CC->targetParent != NULL && finishGates.find(CC) != finishGates.end() )){
					myq.push(CC);
					}
				}else{
					if((CC->controlParent == NULL )|| (CC->controlParent != NULL && finishGates.find(CC) != finishGates.end() )){
					myq.push(CC);
					}
				}
				
			}
			if(x->targetChild != NULL) {
				cout<<"targetchild"<<endl;
				GateNode* TC = x->targetChild;
				if(TC->targetParent == x){
					if((TC->controlParent == NULL) || (TC->controlParent != NULL && finishGates.find(TC) != finishGates.end() )){
					myq.push(TC);
					}
				}else {
					if((TC->targetParent == NULL) || (TC->targetParent != NULL && finishGates.find(TC) != finishGates.end() )){
					myq.push(TC);
					}
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

	pair<int, int> p1(1,13);
	if(couplings.find(p1) != couplings.end()) {
		cout<<"we find it"<<endl;
	}else{
		cout<<"we can not find the cnot on the map"<<endl;
	}
	assert(numPhysicalQubits >= numLogicalQubits);
	
	cycle = 0;

	cout<<" ***  crosstalk cnots cycles ***"<<endl;
	 while(!cnotq.empty()){	
		//cout<<"cycle number is : "<<cycle<<endl;
		int size = cnotq.size();
		cout<<"cycle number is : "<<cycle << ", with cnots number: "<<size <<endl;
		
		for(int i = 0; i < size;i++) {
			GateNode* x = cnotq.front();
			cout<<x->name<<"(" << x->control << " , "<<x->target<<")";
			if(checkCnotCoupling(couplings,x)){
				cout<<"cnot mapping satisfied"<<endl;
			}else{
				cout<<"no coupling mapping"<<endl;
			}
			finishGates.insert(x);
			if(x->controlChild != NULL) {
				//cout<<"controlchild"<<endl;
				GateNode* CC = x->controlChild;
				if(CC->controlParent == x){
					if((CC->targetParent == NULL )|| (CC->targetParent != NULL && finishGates.find(CC) != finishGates.end() )){
					cnotq.push(CC);
					}
				}else{
					if((CC->controlParent == NULL )|| (CC->controlParent != NULL && finishGates.find(CC) != finishGates.end() )){
					cnotq.push(CC);
					}
				}
				
			}
			if(x->targetChild != NULL) {
				//cout<<"targetchild"<<endl;
				GateNode* TC = x->targetChild;
				if(TC->targetParent == x){
					if((TC->controlParent == NULL) || (TC->controlParent != NULL && finishGates.find(TC) != finishGates.end() )){
					cnotq.push(TC);
					}
				}else {
					if((TC->targetParent == NULL) || (TC->targetParent != NULL && finishGates.find(TC) != finishGates.end() )){
					cnotq.push(TC);
					}
				}
				
			}
			cnotq.pop();

		}
		if(cycle > 100) {
			cout<<"error"<<endl;
			break;
		}
		cycle++;
	}
	//student code goes here?
	// cout<<" ***  crosstalk cnots cycles ***"<<endl;
	//  while(!cnotq.empty()){	
	// 	cout<<"cycle number is : "<<cycle<<endl;
	// 	int size = cnotq.size();
	// 	for(int i = 0; i < size;i++) {
	// 		GateNode* x = cnotq.front();
	// 		cout<<x->name<<"gate with control qubit " << x->control << "target qubit "<<x->target;
	// 		if(checkCnotCoupling(couplings,x)){
	// 			cout<<"cnot mapping satisfied"<<endl;
	// 		}else{
	// 			cout<<"no coupling mapping"<<endl;
	// 		}
	// 		finishGates.insert(x);
	// 		if(x->controlChild != NULL) {
	// 			GateNode* CC = x->controlChild;
	// 			if(CC->targetParent == NULL || (CC->targetParent != NULL && finishGates.find(CC) != finishGates.end() )){
	// 				cnotq.push(CC);
	// 			}
	// 		}
	// 		if(x->targetChild != NULL) {
	// 			GateNode* CC = x->targetChild;
	// 			if(CC->controlParent == NULL || (CC->controlParent != NULL && finishGates.find(CC) != finishGates.end() )){
	// 				cnotq.push(CC);
	// 			}
	// 		}
	// 		cnotq.pop();

	// 	}
	// 	if(cycle > 100) {
	// 		cout<<"error"<<endl;
	// 		break;
	// 	}
	// 	cycle++;
	// }
	
	//Exit the program:
	
// 	int n = 3;
// 	char a[3]={'a','b','c'};
// 	bool check[3];
// 	for(int i = 1; i <= n; i++) {
//       cout<<"\nThe all possible combination of length "<<i<<" for the given array set:\n";
//       Combi(a, i, 0, 0, check, n);
//    }
   int cursize = 0;
for(auto x : firstGates) {
		if(x->control == -1) continue;
		cout<<x->name<<"gate with control qubit " << x->control << "target qubit "<<x->target<<endl;
		cursize++;
	}
	GateNode* testa[cursize];
	cursize = 0;
	for(auto x : firstGates) {
		if(x->control == -1) continue;
		//cout<<x->name<<"gate with control qubit " << x->control << "target qubit "<<x->target<<endl;
		testa[cursize] = x;
		cursize++;
	}
	bool check[cursize];
	for(int i = 0 ; i < cursize;i++) {
		check[i] =false;
	}
	
	for(int i = 1; i <= cursize; i++) {
     	cout<<"\nThe all possible combination of length "<<i<<" for the given array set:\n";
    	Combi(testa, i, 0, 0, check, cursize,crosstalkprop);
   	}

	// map<string,double> crosstalkprop;
	// string temp  = "5,6->8,9";
	// string temp2 = "8,9->11,10";//add all combinations latter or give a good choice;
	// crosstalkprop[temp] = 0.2;
	// crosstalkprop[temp2] = 0.1;
	// string tempf;
	// tempf = tempf + to_string(8) + ',' + to_string(9)+"->"+"11"+','+"10";
	// cout<<tempf;
	// if(crosstalkprop.find(tempf) != crosstalkprop.end()) {
	// 	cout<<"find!!"<<endl;
	// }
	return 0;
}
#include "GateNode.hpp"
#include "QASMparser.h"
#include "util.cpp"
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
//#define zerocrosstalk
using namespace std;
bool checkCnotCoupling(set<pair<int,int>> couplings,GateNode* g, int *logical){
//	if(g->control == -1) return true;
	pair<int,int> p1(logical[g->control],logical[g->target]);
	pair<int,int> p2(logical[g->target], logical[g->control]);
	if(couplings.find(p1) != couplings.end() || couplings.find(p2) != couplings.end()) {
		return true;
	}
	return false;
}
int swapcost(set<pair<int,int>> swaps,set<pair<int,int>> couplings,vector<GateNode*> cx,int *logical,int **dis,map<string,double> cp,vector<GateNode*> minchoice,int *reverse,vector<GateNode*> rp,int n){
	//swap can cost crosstalk with swap, but it can also cost crosstalk with cnots
	int res = 0;
	// for(auto x:rs) {
	// 	int temp = logical[x->control];
	// 	logical[x->control] = logical[x->target];
	// 	logical[x->target] = temp; 
	// }
	// for(auto n:cx){
	// 	cout<<"name is"<<n->name<<" with control"<<logical[n->control]<<"target is"<<logical[n->target]<<" has lifetime" <<n->lifetime<<endl;
	// }

	// cout<<"logicaltophysical map"<<endl;
	// //int cur = 0;
	// for(int i =0;i < 15;i++) {
	// 	cout<<i<<"->"<<logical[i]<<" ;";
	// }
	// cout<<"logicaltophysical reversemap"<<endl;
	// //int cur = 0;
	// for(int i =0;i < 15;i++) {
	// 	cout<<i<<"->"<<logical[i]<<" ;";
	// }
	// cout<<endl;
	int log[n];
	for(int i=0;i<n;i++) {
		log[i] = logical[i];
	}
	for(auto x:cx) {
		int point = dis[logical[x->control]][logical[x->target]];
		res -= point;
		//tance from "<<logical[x->control]<<"to"<<logical[x->target]<<" : "<<point<<ensadfsfl;
	}
	for(auto x:swaps) {//swap 1,2
		int first = reverse[x.first];//13
		int second = reverse[x.second];

		int temp = log[first]; // 9
		log[first] = log[second]; // 
		log[second] = temp;		 
	}
	// for(auto n:cx){
	// 	cout<<"name is"<<n->name<<" with control"<<logical[n->control]<<"target is"<<logical[n->target]<<" has lifetime" <<n->lifetime<<endl;

	// }
	// for(int i =0;i < 15;i++) {
	// 	cout<<i<<"->"<<logical[i]<<" ;";
	// }
	for(auto x:cx) {
		int point = dis[log[x->control]][log[x->target]];
		res += point; 
		//cout<<"the distance from "<<logical[x->control]<<"to"<<logical[x->target]<<" : "<<point<<endl;
	 
	}
	// for(auto x:swaps) {//swap 1,2
	// 	int first = reverse[x.first];//13
	// 	int second = reverse[x.second];

	// 	int temp = logical[first]; // 9
	// 	logical[first] = logical[second]; // 
	// 	logical[second] = temp;		 
	// }
	// for(auto x:rs) {
	// 	int temp = logical[x->control];
	// 	logical[x->control] = logical[x->target];
	// 	logical[x->target] = temp; 
	// }
	int crosstalk = 0;
	#ifdef zerocrosstalk
		for(auto x:swaps) {
			for(auto y:minchoice){
				int f1 = x.first;
				int f2 = x.second;
				int f3 = y->control;
				int f4 = y->target;
			//	string temp = to_string(f1) + ','+to_string(f2);
				if(f1<f3) {
					string temp = to_string(f1) + ','+to_string(f2)+"->"+to_string(f3)+','+to_string(f4);
			
					for(map<string,double>::iterator iter=cp.begin();iter != cp.end();iter++) {
						string s1 = iter->first;
						if(s1.find(temp)!=string::npos){
							crosstalk=crosstalk+100;
						}
					}
				}else{
					string temp = to_string(f3) + ','+to_string(f4)+"->"+to_string(f1)+','+to_string(f2);
			
					for(map<string,double>::iterator iter=cp.begin();iter != cp.end();iter++) {
						string s1 = iter->first;
						if(s1.find(temp)!=string::npos){
							crosstalk=crosstalk+100;
						}
					}
				}
				
			}
			for(auto y:rp){
				int f1 = x.first;
				int f2 = x.second;
				int f3 = y->control;
				int f4 = y->target;
			//	string temp = to_string(f1) + ','+to_string(f2);
				if(f1<f3) {
					string temp = to_string(f1) + ','+to_string(f2)+"->"+to_string(f3)+','+to_string(f4);
			
					for(map<string,double>::iterator iter=cp.begin();iter != cp.end();iter++) {
						string s1 = iter->first;
						if(s1.find(temp)!=string::npos){
							crosstalk=crosstalk+100;
						}
					}
				}else{
					string temp = to_string(f3) + ','+to_string(f4)+"->"+to_string(f1)+','+to_string(f2);
			
					for(map<string,double>::iterator iter=cp.begin();iter != cp.end();iter++) {
						string s1 = iter->first;
						if(s1.find(temp)!=string::npos){
							crosstalk=crosstalk+100;
						}
					}
				}
			}

		}
		for(auto x:swaps) {
			for(auto y:swaps){
				int f1 = x.first;
				int f2 = x.second;
				int f3 = y.first;
				int f4 = y.second;
			//	string temp = to_string(f1) + ','+to_string(f2);
				if(f1<f3) {
					string temp = to_string(f1) + ','+to_string(f2)+"->"+to_string(f3)+','+to_string(f4);
			
					for(map<string,double>::iterator iter=cp.begin();iter != cp.end();iter++) {
						string s1 = iter->first;
						if(s1.find(temp)!=string::npos){
							crosstalk=crosstalk+100;
						}
					}
				}else{
					string temp = to_string(f3) + ','+to_string(f4)+"->"+to_string(f1)+','+to_string(f2);
			
					for(map<string,double>::iterator iter=cp.begin();iter != cp.end();iter++) {
						string s1 = iter->first;
						if(s1.find(temp)!=string::npos){
							crosstalk=crosstalk+100;
						}
					}
				}
			}
		}
		
	#endif
	return res+crosstalk;

}
// bool crossfind(set<pair<int,int>> couplings,vector<GateNode*> s){

// 	int size = s.size();
// 	//int crosstalk = 0;
// 	for(int i = 0; i < size; i++) {
// 		pair<int,int> p1(s[i]->control,s[i]->target);
// 		pair<int,int> p2(s[i]->target, s[i]->control);
// 		if(couplings.find(p1) != couplings.end() || couplings.find(p2) != couplings.end()) {
// 			return true;
// 		}
// 	}
// 	return false;
// }
int costfunction(vector<GateNode*> s,  map<string,double> cp,bool &flag) {
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
	if(crosstalk > 0) {
		flag = true;
	}
	int point;
	point = crosstalk - size; 
	return point;

}
void Combi(GateNode* a[], int reqLen, int s, int currLen, bool check[], int l,map<string,double> crosstalkcrop,int &min,vector<GateNode*> &minchoice)
{
   if(currLen > reqLen)
   return;
   else if (currLen == reqLen) {
      cout<<"\t";
	  bool flag = false;
	  vector<GateNode*> tv;
      for (int i = 0; i < l; i++) {
         if (check[i] == true) {
            cout<<a[i]->name<<"("<<a[i]->control<<","<<a[i]->target<<"); ";
			tv.push_back(a[i]);
		 }
      }
	  	int res = costfunction(tv,crosstalkcrop,flag);
    	cout<<"cost value is"<<res;
		if(flag != true) {
			if(res < min) {
				min = res;
				minchoice.clear();
				for(auto x:tv) {
					minchoice.push_back(x);
				}
				cout<<"update"<<endl;
			}
		}
		cout<<"\n";
      return;
   }
   if (s == l) {
      return;
   }
   check[s] = true;
   Combi(a, reqLen, s + 1, currLen + 1, check, l,crosstalkcrop,min,minchoice);
   check[s] = false;
   Combi(a, reqLen, s + 1, currLen, check, l,crosstalkcrop,min,minchoice);
}
void SwapCombi(vector<pair<int,int>> a, int reqLen, int s, int currLen, bool check[], int l,int &min,vector<pair<int,int>> &minchoice,set<set<pair<int,int>>> &allsc)
{
   if(currLen > reqLen)
   return;
   else if (currLen == reqLen) {
      //cout<<"\t";

      bool flag = false;
      //vector<pair<int,int>> tv;
      set<int> duplicate;
	  duplicate.clear();
	  set<pair<int,int>> temp;
	  temp.clear();
      for (int i = 0; i < l; i++) {
         if (check[i] == true && (duplicate.find(a[i].first)==duplicate.end())&& (duplicate.find(a[i].second)==duplicate.end())) {
            flag = true;
           // cout<<"swap"<<"("<<a[i].first<<","<<a[i].second<<"), ";

			duplicate.insert(a[i].first);
            duplicate.insert(a[i].second);
            //tv.push_back(a[i]);
			pair<int,int> tempair(a[i].first,a[i].second);
			temp.insert(tempair);
         }
		// cout<<";";
      }
	  
		if(flag == true) {
		// 	cout<<"\n";
			allsc.insert(temp);
		 }
        
      return;
   }
   if (s == l) {
      return;
   }
   check[s] = true;
   SwapCombi(a, reqLen, s + 1, currLen + 1, check, l,min,minchoice,allsc);
   check[s] = false;
   SwapCombi(a, reqLen, s + 1, currLen, check, l,min,minchoice,allsc);
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
	queue<GateNode*> myq,cnotq,testq;
	vector<vector<GateNode*>> schedulelayer;
	buildDependencyGraph(qasmFileName, firstGates, numLogicalQubits, numGates);
    cout<<"execute successfully"<<endl;
	map<string,double> crosstalkprop;
	string temp  = "0,1->2,3";
	//string temp2 = "29,39";//add all combinations latter or give a good choice;
	//string temp3 = "8,9->10,11";
	//string temp4 = "10,11->8,9";
	//string temp5 = "3,4->10,11";

	crosstalkprop[temp] = 0.2;
	//crosstalkprop[temp2] = 0.1;
	//crosstalkprop[temp3] = 0.1;
	//crosstalkprop[temp4] = 0.2;
	//crosstalkprop[temp5] = 0.1;
	cout<<"print first gate"<<endl;
	for(auto x : firstGates) {
		cout<<x->name<<"gate with control qubit " << x->control << "target qubit "<<x->target<<endl;
		if(x->controlChild == NULL) {
			cout<<"nullpointer"<<endl;
		}else{
			cout<<x->controlChild->name;
		}
		if(x->targetChild == NULL) {
			cout<<"nullpointer"<<endl;
		}else{
			cout<<x->targetChild->name;
		}
		myq.push(x);
		cnotq.push(x);
		testq.push(x);
	}
	cout<<"done print first gate"<<endl;
	//Parse the coupling map; put edges into a set
	int numPhysicalQubits = 0;
	set<pair<int, int> > couplings;
	buildCouplingMap(couplingMapFileName, couplings, numPhysicalQubits);
	for(auto x : couplings) {
		cout<<"("<<x.first<<" --- "<<x.second<<" ), ";
	}
	cout<<endl;
	//const int phynum = numPhysicalQubits;

	int **distance = new int*[numPhysicalQubits];
	for(int i = 0 ; i < numPhysicalQubits;i++) {
		distance[i] = new int[numPhysicalQubits];
	}
	for(int i = 0 ; i < numPhysicalQubits;i++) {
		for(int j = 0; j < numPhysicalQubits;j++) {
			if(i==j) {
				distance[i][j] = 0;
			}else{
				distance[i][j] = -1;
			}
		}
	}
	
	for(auto x : couplings) {
			distance[x.first][x.second]=1;
			distance[x.second][x.first]=1;
	}
	
	
		for(int i = 0 ; i < numPhysicalQubits;i++) {
			for(int j = i+1; j < numPhysicalQubits;j++) {
				if(distance[i][j] > 0){
					for(int k = j+1;k < numPhysicalQubits;k++) {
						if(distance[j][k] > 0 && distance[i][k] == -1) {
							distance[i][k] = distance[j][k]+distance[i][j];
						}
					}
				}
			}
		}
		
	for(int i = 0 ; i < numPhysicalQubits;i++) {
			for(int j = i+1; j < numPhysicalQubits;j++) {
				if(distance[i][j] > 0){
					for(int k = 0;k < numPhysicalQubits;k++) {
						if(distance[j][k] > 0 && distance[i][k] == -1) {
							distance[i][k] = distance[j][k]+distance[i][j];
						}
					}
				}
			}
		}
    for(int i = 0 ; i < numPhysicalQubits;i++) {
			for(int j = 0; j < i;j++) {
				distance[i][j] = distance[j][i];
			}
		}
		
	
	for(int i = 0 ; i < numPhysicalQubits;i++) {
		cout<<endl;
		for(int j = 0; j < numPhysicalQubits;j++) {
			cout<<distance[i][j]<<" ";
		}
	}



	cout<<" ******  DAG cycles information *****"<<endl;
	//to check if our cnot is already mapping to the coupling graph
	int cycle = 0;
    // while(!myq.empty()){	
	// 	//cout<<"cycle number is : "<<cycle<<endl;
	// 	int size = myq.size();
	// 	cout<<"cycle number is : "<<cycle << "with cnots number: "<<size <<endl;
	// 	for(int i = 0; i < size;i++) {
	// 		GateNode* x = myq.front();
	// 		cout<<x->name<<"(" << x->control << " , "<<x->target<<")"<<endl;
	// 		finishGates.insert(x);
	// 		if(x->controlChild != NULL) {
	// 			cout<<"controlchild"<<endl;
	// 			GateNode* CC = x->controlChild;
	// 			if(CC->controlParent == x){
	// 				if((CC->targetParent == NULL )|| (CC->targetParent != NULL && finishGates.find(CC->targetParent) != finishGates.end() )){
	// 				//cout<<"find1"<<endl;
	// 				if(CC->seen){
	// 					myq.push(CC);
	// 					CC->seen = false;
	// 				}
					
	// 				}
	// 			}else{
	// 				if((CC->controlParent == NULL )|| (CC->controlParent != NULL && finishGates.find(CC->controlParent) != finishGates.end() )){
	// 					if(CC->seen){
	// 						myq.push(CC);
	// 						CC->seen = false;
	// 					}
	// 				//cout<<"find2"<<endl;
	// 				}
	// 			}
				
	// 		}
	// 		if(x->targetChild != NULL) {
	// 			cout<<"targetchild"<<endl;
	// 			GateNode* TC = x->targetChild;
	// 			if(TC->targetParent == x){
	// 				if((TC->controlParent == NULL) || (TC->controlParent != NULL && finishGates.find(TC->controlParent) != finishGates.end() )){
	// 			//	myq.push(TC);
	// 				if(TC->seen){
	// 					myq.push(TC);
	// 					TC->seen = false;
	// 				}
	// 		//		cout<<"find3"<<endl;
	// 				}
	// 			}else {
	// 				if((TC->targetParent == NULL) || (TC->targetParent != NULL && finishGates.find(TC->targetParent) != finishGates.end() )){
	// 				if(TC->seen){
	// 					myq.push(TC);
	// 					TC->seen = false;
	// 				}
	// 		//		cout<<"find4"<<endl;
	// 				}
	// 			}
				
	// 		}
	// 		myq.pop();

	// 	}
	// 	if(cycle > 100) {
	// 		cout<<"error"<<endl;
	// 		break;
	// 	}
	// 	cycle++;
	// }
	//return 0;
	pair<int, int> p1(1,13);
	if(couplings.find(p1) != couplings.end()) {
		cout<<"we find it"<<endl;
	}else{
		cout<<"we can not find the cnot on the map"<<endl;
	}
	int *logicaltophysical = new int[numPhysicalQubits];
	for(int i = 0 ; i < numPhysicalQubits;i++) {
		logicaltophysical[i] = i;

	} 

	assert(numPhysicalQubits >= numLogicalQubits);
	cout<<"number of quibts are:"<<numPhysicalQubits<<endl;
	cycle = 0;
    finishGates.clear();
	vector<GateNode*> executionlayer;
	executionlayer.clear();
	cout<<" ***  crosstalk cnots cycles ***"<<endl;
	
	 while(!cnotq.empty()){	
		 cout<<"********** round"<<cycle<<" *********"<<endl;
		//cout<<"cycle number is : "<<cycle<<endl;
		int size = cnotq.size();
		cout<<"cycle number is : "<<cycle << ", with cnots number: "<<size <<endl;
		vector<GateNode*> v;
		vector<GateNode*> nv;
		vector<GateNode*> s;
		vector<GateNode*> remainswap;
		//executionlayer.clear();

		for(int i = 0; i < size; i++) {
			GateNode* y = cnotq.front();
			if(y->control != -1){
				if(checkCnotCoupling(couplings,y,logicaltophysical)){
					v.push_back(y);
				}else{
					nv.push_back(y);
				}
				
			}else{
				s.push_back(y);
			}
			//v.push_back(y);
			cnotq.pop();
			cnotq.push(y);
		}
		
		cout<<"*******"<<endl;		
		cout<<"single gates are:"<<endl;
		for(auto x : s) {
			cout<<x->name<<"(" << x->control << " , "<<x->target<<")"<<endl;
			x->lifetime = 1;
			executionlayer.push_back(x);
		}

		cout<<"*******"<<endl;		
		cout<<"all cnots meet couplings are:"<<endl;

		for(auto x : v) {
			cout<<x->name<<"(" << x->control << " , "<<x->target<<")"<<endl;	}
		//GateNode* testa[cursize];

		int cursize = v.size();
		GateNode* testa[cursize];
		
		for(int i = 0; i < cursize; i++) {
			testa[i]=v[i];
		}
		bool check[cursize];
		for(auto x : check) {
			x=false;
		}
		vector<GateNode*> minchoice;
		int tempmin = 100;
		for(int i = cursize; i >= 1; i--) {
     		cout<<"\nThe all possible combination of length "<<i<<" for the given array set:\n";
			
			Combi(testa, i, 0, 0, check, cursize,crosstalkprop,tempmin,minchoice);

   		}
		for(auto x : minchoice) {
			cout<<x->name<<"(" << x->control << " , "<< x->target << ")" << endl;
			x->lifetime = 1;
			executionlayer.push_back(x);
		}
		cout<<"*******"<<endl;
		cout<<"all cnots need swaps are:"<<endl;
		for(auto x : nv) {
			//cout<<"*******"<<endl;
			cout<<x->name<<"(" << x->control << " , "<<x->target<<")"<<"the logical mapping will be"<<x->name<<"(" << logicaltophysical[x->control] << " , "<< logicaltophysical[x->target]<<") "<<endl;
	;
		}
		
		cout<<"*******"<<endl;
		cout<<"the queue size is: "<<size<<endl;
		bool unusedqubits[numPhysicalQubits];
		for(int i = 0 ; i < numPhysicalQubits ; i++) {
			unusedqubits[i] = true;
		}
		for(auto x : s) {
			cout<<x->target<<endl;
			unusedqubits[logicaltophysical[x->target]] = false;
		}
		for(auto x: minchoice) {
			
			cout<<x->target<<endl;
			cout<<x->control<<endl;
			unusedqubits[logicaltophysical[x->control]] = false;
			unusedqubits[logicaltophysical[x->target]] = false;
		}
		for(auto x: executionlayer) {
			if(x->name.compare("swap")==0) {
			unusedqubits[x->control] = false;
			unusedqubits[x->target] = false;
			}
		}
		cout<<"the rest qubits can be used are:"<<endl;
		vector<int> unused;
		for(int i = 0 ; i < numPhysicalQubits ; i++) {
			if(unusedqubits[i]) {
				cout<< i <<" ";
				unused.push_back(i);
			}
		}
		cout<<endl;
		vector<pair<int,int>> allswaps;
		cout<<"the all possible swaps are:"<<endl;
		set<int> swapmap;
		
		cout<<"our current execution layer contains"<<endl;
		for(auto n:executionlayer) {
			cout<<"name is"<<n->name<<" with control"<<n->control<<"target is"<<n->target<<" has lifetime" <<n->lifetime<<endl;
			if(n->name.compare("swap")==0) {
				remainswap.push_back(n);
			}
	
		}

		cout<<"our ongoing swaps are "<<endl;
		for(auto n:remainswap) {
			cout<<"name is"<<n->name<<" with control"<<n->control<<"target is"<<n->target<<" has lifetime" <<n->lifetime<<endl;
			
		}
		int *logicaltophysical2 = new int[numPhysicalQubits];
		int *reverse = new int[numPhysicalQubits];
		for(int i = 0 ; i < numPhysicalQubits;i++) {
				logicaltophysical2[i]=logicaltophysical[i];
				//cout<<i<<"->"<<logicaltophysical[i]<<" , ";
		} 

		for(int i = 0 ; i < numPhysicalQubits;i++) {
				reverse[logicaltophysical[i]]=i;
				//cout<<i<<"->"<<logicaltophysical[i]<<" , ";
		} 
		for(auto x:remainswap) {
			int first = reverse[x->control];//13
			int second = reverse[x->target];
			int temp = logicaltophysical2[first];
			logicaltophysical2[first] = logicaltophysical2[second];
			logicaltophysical2[second] = temp; 
		}
		cout<<"considering remain swaps"<<endl;
			for(int i = 0 ; i < numPhysicalQubits;i++) {
				cout<<i<<"->"<<logicaltophysical2[i]<<" , ";
			} 
			cout<<endl;
		for(auto x:nv) {
			swapmap.insert(logicaltophysical2[x->control]);
			swapmap.insert(logicaltophysical2[x->target]);
		}
		cout<<"the swap map constains"<<endl;
		for(auto x:swapmap) {
			cout<<x<<",";
		}
		cout<<endl;
		cout<<"after consider ongoing swaps now the swaps are"<<endl;
	for(auto x : nv) {
			//cout<<"*******"<<endl;
			cout<<x->name<<"(" << x->control << " , "<<x->target<<")"<<"the logical mapping will be"<<x->name<<"(" << logicaltophysical2[x->control] << " , "<< logicaltophysical2[x->target]<<") "<<endl;
	;
		}
		for(int i = 0; i < unused.size();i++) {
			for(int j = i+1; j < unused.size(); j++) {
				pair<int,int> p(unused[i],unused[j]);
				if(couplings.find(p)!=couplings.end()&&(swapmap.find(unused[i])!=swapmap.end() || swapmap.find(unused[j])!=swapmap.end())) {
					allswaps.push_back(p);
				}
			}
		}
		cout<<"all possible swaps"<<endl;
		for(auto x:allswaps) {
			
			cout<<"swap("<<x.first<<","<<x.second<<")"<<";  ";
		}
		cout<<endl;
		vector<pair<int,int>> swapminchoice;
		set<set<pair<int,int>>> allsc;
		set<pair<int,int>> finalswap;

		int swapcurpoint=0;
	//if(cycle < 1) {
 			int swapsize = allswaps.size();
        	for(auto x : check) {
        		x=false;
         	}
         	for(int i = 1; i <= swapsize; i++) {
          		//cout<<"\nThe all possible combination of length "<<i<<" for the given array set:\n";
             
          		SwapCombi(allswaps, i, 0, 0, check, swapsize,tempmin,swapminchoice,allsc);

   	    	}
			cout<<"after checking duplicates the swaps combinations are"<<endl;
			int swapnumcombi =0;
			for(auto x: allsc) {
				for(auto y:x) {
					cout<<"swap ("<<y.first<<","<<y.second<<");";
				}
				cout<<endl;
				swapnumcombi++;
			}
			cout<<"there are totoal: "<< swapnumcombi<<endl;
			for(auto x:allsc) {
				set<pair<int,int>> curtemp = x;
				int respoint = swapcost(x,couplings,nv,logicaltophysical2,distance,crosstalkprop,minchoice,reverse,remainswap,numPhysicalQubits);
				for(auto y:x) {
					cout<<"swap ("<<y.first<<","<<y.second<<");";
				}
				cout<<"the swap cost point is:"<<respoint;
				if(respoint < swapcurpoint) {
					swapcurpoint = respoint;
					finalswap.clear();
					for(auto y:x) {
						//cout<<"swap ("<<y.first<<","<<y.second<<");";
						pair<int,int> p1;
						p1.first=y.first;
						p1.second=y.second;
						finalswap.insert(p1);
					}
					

				}
				cout<<endl;
			}
			//TODO: save swap to current queue, life time is 3 cycles; then change the logical to mapping; then cx2,4 can be done.
			cout<<"our choice of swaps are:"<<endl;
			for(auto y:finalswap) {
					cout<<"swap ("<<y.first<<","<<y.second<<");";
					//int temp = logicaltophysical[y.first];
					//logicaltophysical[y.first] = logicaltophysical[y.second];
					//logicaltophysical[y.second] = temp;				
			}
			cout<<endl;
			// for(int i = 0 ; i < numPhysicalQubits;i++) {
			// 	cout<<i<<"->"<<logicaltophysical[i]<<" , ";
			// }
			//cout<<endl;

	//	}
		for(auto y:finalswap) {
			GateNode *temp = new GateNode("swap",y.first,y.second,3);
			cout<<"adding swap"<<y.first<<","<<y.second<<endl;
			executionlayer.push_back(temp);
		}
		schedulelayer.push_back(executionlayer);
	
		cout<<"being execute without crosstalk schedule"<<endl;
		
		vector<GateNode*> pushbacktoqueue;
		for(int i = 0; i < size;i++) {
			
			GateNode* x = cnotq.front();
			if((find(executionlayer.begin(),executionlayer.end(),x) == executionlayer.end()) ){
				pushbacktoqueue.push_back(x);
				cnotq.pop();
				continue;
			 }
			cout<<x->name<<"(" << x->control << " , "<<x->target<<")"<<endl;
			// if(checkCnotCoupling(couplings,x)){
			// 	cout<<"cnot mapping satisfied"<<endl;
			// }else{
			// 	cout<<"no coupling mapping"<<endl;
			// }
			finishGates.insert(x);
			if(x->controlChild != NULL) {
				//cout<<"controlchild"<<endl;
				GateNode* CC = x->controlChild;
				if(CC->controlParent == x){
					if((CC->targetParent == NULL )|| (CC->targetParent != NULL && finishGates.find(CC->targetParent) != finishGates.end() )){
						if(CC->seen){
							cnotq.push(CC);
							CC->seen = false;
						}
					//cout<<"find1"<<endl;
					}
				}else{
					if((CC->controlParent == NULL )|| (CC->controlParent != NULL && finishGates.find(CC->controlParent) != finishGates.end() )){
						if(CC->seen){
							cnotq.push(CC);
							CC->seen = false;
						}
					//cout<<"find2"<<endl;
					}
				}
				
			}
			if(x->targetChild != NULL) {
				//cout<<"targetchild"<<endl;
				GateNode* TC = x->targetChild;
				if(TC->targetParent == x){
					if((TC->controlParent == NULL) || (TC->controlParent != NULL && finishGates.find(TC->controlParent) != finishGates.end() )){
						if(TC->seen){
							cnotq.push(TC);
							TC->seen = false;
						}
				//	cout<<"find3"<<endl;
					}
				}else {
					if((TC->targetParent == NULL) || (TC->targetParent != NULL && finishGates.find(TC->targetParent) != finishGates.end() )){
						if(TC->seen){
							cnotq.push(TC);
							TC->seen = false;
						}
				//	cout<<"find4"<<endl;
					}
				}
				
			}
			cnotq.pop();

		}
		for(auto x:pushbacktoqueue) {
			cnotq.push(x);
		}
		if(cycle > 160000){
			cout<<"error"<<endl;
			break;
		}
		vector<GateNode*> temp;
		temp.clear();
		for(auto x:executionlayer) {
			if(x->lifetime == 1) {
				if(x->name == "swap"){
				
					int first = reverse[x->control];//13
					int second = reverse[x->target];

					int temp = logicaltophysical[first]; // 9
					logicaltophysical[first] = logicaltophysical[second]; // 
					logicaltophysical[second] = temp;		 
	
					
				}
			}else {
				x->lifetime--;
				temp.push_back(x);
			}
		}
		for(int i = 0 ; i < numPhysicalQubits;i++) {
				cout<<i<<"->"<<logicaltophysical[i]<<" , ";
			} 
			cout<<endl;
		executionlayer.clear();
		for(auto x:temp) {
			executionlayer.push_back(x);
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
//    int cursize = 0;
// for(auto x : firstGates) {
// 		if(x->control == -1) continue;
// 		cout<<x->name<<"gate with control qubit " << x->control << "target qubit "<<x->target<<endl;
// 		cursize++;
// 	}
	// GateNode* testa[cursize];
	// cursize = 0;
	// for(auto x : firstGates) {
	// 	if(x->control == -1) continue;
	// 	//cout<<x->name<<"gate with control qubit " << x->control << "target qubit "<<x->target<<endl;
	// 	testa[cursize] = x;
	// 	cursize++;
	// }
	// bool check[cursize];
	// for(int i = 0 ; i < cursize;i++) {
	// 	check[i] =false;
	// }
	
	// for(int i = 1; i <= cursize; i++) {
    //  	cout<<"\nThe all possible combination of length "<<i<<" for the given array set:\n";
    // 	Combi(testa, i, 0, 0, check, cursize,crosstalkprop);
   	// }

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
	int curl = 0;
	int ccount=0;
	int gatecount = 0;
	int xsize = schedulelayer.size();
	set<GateNode*> save;
	bool errordetect = false;
	for(int i = 0; i < xsize;i++) {
		vector<GateNode*> x = schedulelayer[i];
		bool f = false;
		bool controlcheck = false;
		bool targetcheck = false;
		//cout<<"layer "<<curl<<endl;
		for(GateNode* y:x) {
			//cout<<y->name<<"gate " <<"(" <<y->control<<" , "<<y->target<<" );";
			if(y->controlParent != NULL) {
			//	cout<<"the control parent gate is"<<y->controlParent->name<<"gate " <<"(" <<y->controlParent->control<<" , "<<y->controlParent->target<<" );"<<endl;
				if(save.find(y->controlParent) != save.end()) {
					controlcheck = true;
				}
			}else{
			//	cout<<"no control parent"<<endl;
				controlcheck = true;
			}
			if(y->targetParent != NULL) {
			//	cout<<"the target parent gate is"<<y->targetParent->name<<"gate " <<"(" <<y->targetParent->control<<" , "<<y->targetParent->target<<" );"<<endl;
				if(save.find(y->targetParent) != save.end()) {
					targetcheck = true;
				}
			}else{
			//	cout<<"no target parent"<<endl;
				targetcheck = true;
			}

			if(y->name.compare("swap") != 0) {
				gatecount++;
			}
			if(targetcheck == false || controlcheck == false) {
				perror("dependency error");
				errordetect = true;
			}else{
				save.insert(y);
			}
			y->seen =true;
			
			//	cout<<"reset to default"<<y->name<<"gate " <<"(" <<y->control<<" , "<<y->target<<" );";
			
			int s = min(y->control,y->target);
			int t = max(y->control,y->target);
			if((s==0&& t==1) ||(s==2&& t==3)) {
				if(f){
					ccount++;
				}else{
					f=true;
				}
			}
		}

		//cout<<endl;
		curl++;
	}
	int testcount = 0;
	while(!testq.empty()){ 
		int size = testq.size();
		for(int i = 0; i < size; i++) {
			GateNode* x = testq.front();
			//cout<<x->name<<"gate " <<"(" <<x->control<<" , "<<x->target<<" );";
			testcount++;
			if(x->controlChild != NULL) {
				//cout<<"controlchild"<<endl;
				GateNode* CC = x->controlChild;
				if(CC->controlParent == x){
					if((CC->targetParent == NULL )|| (CC->targetParent != NULL && finishGates.find(CC->targetParent) != finishGates.end() )){
						if(CC->seen){
							testq.push(CC);
							CC->seen = false;
						}
					//cout<<"find1"<<endl;
					}
				}else{
					if((CC->controlParent == NULL )|| (CC->controlParent != NULL && finishGates.find(CC->controlParent) != finishGates.end() )){
						if(CC->seen){
							testq.push(CC);
							CC->seen = false;
						}
					//cout<<"find2"<<endl;
					}
				}
				
			}
			if(x->targetChild != NULL) {
				//cout<<"targetchild"<<endl;
				GateNode* TC = x->targetChild;
				if(TC->targetParent == x){
					if((TC->controlParent == NULL) || (TC->controlParent != NULL && finishGates.find(TC->controlParent) != finishGates.end() )){
						if(TC->seen){
							testq.push(TC);
							TC->seen = false;
						}
				//	cout<<"find3"<<endl;
					}
				}else {
					if((TC->targetParent == NULL) || (TC->targetParent != NULL && finishGates.find(TC->targetParent) != finishGates.end() )){
						if(TC->seen){
							testq.push(TC);
							TC->seen = false;
						}
				//	cout<<"find4"<<endl;
					}
				}
				
			}
			

		



			//v.push_back(y);
			testq.pop();
			//testq.push(y);
		}

	}	

	cout<<"there are total "<< gatecount <<" gates" <<endl; 
	cout<<"compare with  total "<< testcount <<" gates" <<endl; 
	cout<<"crosstalk number is"<<ccount<<endl;
	GateNode *n = new GateNode("swap",0,1,3);
	cout<<"try the new gatenode" <<endl;
	cout<<"name is"<<n->name<<" with control"<<n->control<<"target is"<<n->target<<" has lifetime" <<n->lifetime<<endl;
	if(errordetect) {
		cout<<"depedency error detect"<<endl;
	}else{
		cout<<"no depedency error"<<endl;
	}
	return 0;
}
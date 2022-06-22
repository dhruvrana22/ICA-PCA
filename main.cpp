#include <iostream>
#include <string>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

#include "pca.h"
#include "ica.h"
#include "utils.h"
using namespace std;
using namespace wisdom;
int main(){
	int nrSamples=20000,nrComp=16;
	vector<vector<double>> Data(nrSamples,vector<double>(nrComp));
	readData("eegData.csv",Data,nrSamples,nrComp);
	//cout<<"gg"<<endl;
	wisdom::PCA obj1;
	obj1.m1(Data);
	wisdom::ICA obj2;
	//cout<<"gg"<<endl;
	obj2.m2(Data);
	return 0;
}

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
	vector<vector<double>> result;
	readData("eegData.csv",Data,nrSamples,nrComp);
	wisdom::PCA obj1;
	result=obj1.m1(Data);
	saveData1("Result1.csv",result);
	wisdom::ICA obj2;
	result=obj2.m2(Data);
	saveData1("Result2.csv",result);
	return 0;
}

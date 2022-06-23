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
	wisdom::PCA obj1;
	vector<vector<double>> result1(obj1.nrSamples,vector<double>(2));
	obj1.m1(Data,result1);
	saveData1("Result1.csv",result1);
	wisdom::ICA obj2;
	vector<vector<double>> result2(obj2.nrSamples, vector<double>(obj2.nrIC));
	obj2.m2(Data,result2);
	saveData1("Result2.csv",result2);
	return 0;
}

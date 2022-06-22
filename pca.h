#ifndef PCA_H
#define PCA_H
#include <iostream>
#include <vector>
#include "qbMatrix.h"
using namespace std;
namespace wisdom{
	class PCA{
		public:
		int nrSamples=20000;
		int nrComp=16;
		void m1(vector<vector<double>> Data);
	};
	void vectods(vector<vector<double>> &Data,vector<double> &testData);
	void dstovec(qbMatrix2<double> &newX,vector<vector<double>> &result);
}
#endif

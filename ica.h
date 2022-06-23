#ifndef ICA_H
#define ICA_H
#include <iostream>
#include <vector>
#include <itpp/itsignal.h>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
using namespace itpp;
namespace wisdom{
	class ICA{
		public:
		int nrSamples = 19000; 
		int nrIC = 4;
		void m2(vector<vector<double>> Data,vector<vector<double>> &res);
	};
	void vectods(vector<vector<double>> &Data,mat X);
	void dstovec(mat b,vector<vector<double>> &res);
}
#endif

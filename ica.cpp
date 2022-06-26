#include <vector>
#include <itpp/itsignal.h>
#include <cstdio>
#include "ica.h"
#include "utils.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace itpp;
using namespace std;

namespace wisdom{
	//Independent Component Ananlysis using Itpp library
	//Data-data read from csv file
	//res-Result of ICA
	void ICA::m2(vector<vector<double>> Data,vector<vector<double>> &res){
		float tmp = 0.0;
		mat X = zeros(nrIC,nrSamples);
		//Convert 2D vector "Data" to mat "X"
		vectods(Data,X);
		Fast_ICA my_fastica(X);
		my_fastica.set_nrof_independent_components(nrIC);
		bool result = my_fastica.separate();
		if (result){
			my_fastica.get_mixing_matrix();
			my_fastica.get_separating_matrix();
			mat b=my_fastica.get_independent_components();
			//Convert mat "b" to 2D vector "res" i.e. Result
			dstovec(b,res);
		}
		else{
			cout << "ICA:Algorithm failed" << endl;
		}
	}
	//Convert 2D vector to mat
	void vectods(vector<vector<double>> &Data,mat &X){
		int c=X.rows();
		int r=X.cols();
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
	 	      		X(j,i) = Data[i][j];
	 	      	}
		}
	}
	
	//Convert mat to 2D vector
	void dstovec(mat b,vector<vector<double>> &res){
		int r=res.size();
		int c=res[0].size();
		for (int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				res[i][j]=b(j,i);
		}
	}
}

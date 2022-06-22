#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <random>
#include <fstream>
#include "utils.h"
using namespace std;

void readData(string name,vector<vector<double>> &Data,int rows,int cols){
	string rowData,number;
	stringstream rowDataStream;
	int numRows = 0;
	int numCols = 0;
	ifstream inputFile(name);
	if (inputFile.is_open()){		
		while (!inputFile.eof()){
			getline(inputFile, rowData);
			rowDataStream.clear();
			rowDataStream.str(rowData);
			numCols = 0;
			while (rowDataStream.good()){
				getline(rowDataStream,number, ',');
				if (!number.empty()) {
					double v=stod(number);
					Data[numRows][numCols]=v;
				}
				numCols += 1;
				if(numCols==cols)
					break;
			}
			numRows += 1;
			if(numRows==rows)
				break;
		}
		inputFile.close();
	}
}

void saveData1(string name,vector<vector<double>> &result){
	ofstream outputFile(name);
	int r=result.size();
	int c=result[0].size();
	if(outputFile.is_open()){
		for (int i=0;i<r;i++){
			for(int j=0;j<(c-1);j++)
				outputFile << result[i][j] <<",";
			outputFile << result[i][c-1] << endl;
		}
		outputFile.close();
	}
}

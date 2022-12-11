#include "GradDescent.h"
#include "MATRIXINVERSE.h"
#include <iostream>
using namespace std;
int main()
{  
	GradDecent gradSolve;
	vector<vector<double> > Sample = { {1,11},{2,13 }, { 3, 15 }, { 4, 17 } , {5,19},{6,21} };
    int time = 0;
	double j = 0;
	/*while(time < 100){
		vector<double> temp;
		temp.push_back(j);
		temp.push_back(2*j+9);
	  	Sample.push_back(temp);
		j = j + 0.1;
		time++;
		temp.clear();
	}*/
	
    gradSolve.sampleData = Sample;
    vector<double> re = gradSolve.calculateGradDescent();
	for(int i = 0;i < re.size();i++){
			cout<<re[i]<<endl;
	}
	


	MATRIXINVERSE matrixinverse;
	//matrixinverse.m_r = 2;
	//cout<<matrixinverse.calculateMATRIXInverse()<<endl;

}

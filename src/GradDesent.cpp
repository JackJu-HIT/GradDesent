/**
 * @file GradDescent.cpp
 * @author juchunyu
 * @brief 
 * @version 0.1
 * @date 2022-11-27
 * @copyright Copyright (c) 2022
 * 
 */
#include "GradDescent.h"
#include <iostream>
#include <cmath>

using namespace std;

double iterations    = 2000000;  
double tolerance     = 0.00001;
double Y             = 0.0001;
int  J_iterations    = 0;
long double W             = 0;
long double W1            = 0;
long double W2            = 0;
long double B             = 0;

long double W_temp;
long double W1_temp;
long double W2_temp;
long double B_temp;
long double J_last = 0;;
long double J_current;
long double W_result;
long double W1_result;
long double W2_result;
long double B_result;

//求解梯度下降
vector<double> GradDecent::calculateGradDescent()
{
    vector<vector<double> > a = this->sampleData;
    cout<<a[0][0]<<" "<<a[0][1]<<endl;
    cout<<a.size()<<endl;
    cout<<a[0].size()<<endl;
    cout<<"已经进入梯度下降代码！"<<endl;
    /*
      Y = 2 X +9,
      (1,11) (2,13) (3,15) (4,17)
    */  
    //double a[SIZE][2]    = {1,11,2,13,3,15,4,17,5,19,6,21};
    /*
    *F = W*X+B
    *J = (W*Xi+B-yi)^2/2*n
    */
   cout<<"输入数据"<<endl;
   for(int i = 0;i < a.size();i++){
     for(int j = 0;j<2;j++){
       cout<<a[i][j]<<" ";
     }
     cout<<endl;
   }
    J_last = 0;
    for(int k = 0;k < a.size();k++){
        J_last += (B + W * a[k][0]+ W1 * a[k][0] * a[k][0] + W2 * a[k][0] * a[k][0] * a[k][0] - a[k][1]) * (B + W * a[k][0]+ W1 * a[k][0] * a[k][0] + W2 * a[k][0] * a[k][0] * a[k][0] - a[k][1]);
    }
    J_last = J_last/(2*a.size());
     
    for(int i = 0;i < iterations;i++){
       long double DJDW = 0;
       for(int k = 0;k < a.size();k++){
           DJDW += (B + W * a[k][0] + W1 * a[k][0] * a[k][0] + W2 * a[k][0] * a[k][0] * a[k][0]- a[k][1]) * a[k][0];
       }
       DJDW = DJDW/a.size();
       //cout<<"DIDW"<<DJDW<<endl;
       long double DJDW1 = 0;
       for(int k = 0;k < a.size();k++){
           DJDW1 += (B + W * a[k][0] + W1 * a[k][0] * a[k][0] + W2 * a[k][0] * a[k][0]* a[k][0] - a[k][1]) * a[k][0] * a[k][0];
       }
       DJDW1 = DJDW1/a.size();
       //cout<<"DIDW1"<<DJDW1<<endl;
       long double DJDW2 = 0;
       for(int k = 0;k < a.size();k++){
           DJDW2 += (B + W * a[k][0] + W1 *  a[k][0] * a[k][0] + W2 *  a[k][0] * a[k][0]* a[k][0] - a[k][1]) * a[k][0] * a[k][0]* a[k][0];
       }
       DJDW2 = DJDW2/a.size();
       //cout<<"DIDW2"<<DJDW2<<endl;

       long double DJDB = 0;
       for(int k = 0;k < a.size();k++){
           DJDB += B + W * a[k][0] + W1 * a[k][0] * a[k][0] + W2 * a[k][0] * a[k][0]* a[k][0] - a[k][1];
       }
       DJDB = DJDB/a.size();

       //cout<<"DJDB"<<DJDB<<endl;
       W_temp  = W  - Y  * DJDW;
       W1_temp = W1 - Y * DJDW1;
       W2_temp = W2 - Y * DJDW2;
       B_temp  = B  - Y * DJDB;

       W   = W_temp;
       W1  = W1_temp;
       W2  = W2_temp;
       B   = B_temp;
      /*cout<<"W"<<W<<endl;
       cout<<"W1:"<<W1<<endl;
       cout<<"W2:"<<W2<<endl;
       cout<<"B"<<B<<endl;
       */
       J_current = 0;
       for(int k = 0;k < a.size();k++){
          J_current += (B + W * a[k][0] + W1 * a[k][0] * a[k][0] + W2 * a[k][0] * a[k][0]* a[k][0] - a[k][1]) * (B+ W * a[k][0] + W1 * a[k][0] * a[k][0] + W2 * a[k][0] * a[k][0]* a[k][0] - a[k][1]);
       }
       J_current = J_current/(2*a.size());

       cout<<"J_current"<<J_current<<"J_Last"<<J_last<<endl;
       if(abs(J_current - J_last) < tolerance){
            W_result     = W;
            W1_result    = W1;
            W2_result    = W2;
            B_result     = B;
            J_iterations = i;
            break;
       }
       /*
       cout<<"W_result:"<<W_result<<endl;
       cout<<"W1_result:"<<W1_result<<endl;
       cout<<"W2_result:"<<W2_result<<endl;
       cout<<"B_result:"<<B_result<<endl;
       cout<<"J_iterations:"<<J_iterations<<endl;
       */
       cout<<"当前训练次数:"<<J_iterations<<endl;
       cout<<"当前迭代误差："<<abs(J_current - J_last)<<endl;
       J_last = J_current;
    }
    cout<<"W_result:"<<W_result<<endl;
    cout<<"W1_result:"<<W1_result<<endl;
    cout<<"W2_result:"<<W2_result<<endl;
    cout<<"B_result:"<<B_result<<endl;
    cout<<"J_iterations:"<<J_iterations<<endl;
  
    return {W_result,W1_result,W2_result,B_result ,J_iterations};
}
#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <numbers>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <numeric> 
using namespace std;

class Data
{
	vector <int> NumData;
	vector <int> Frequency;
	vector<std::pair<int, int>> intervals;
	vector <float> X;
	vector <float> Fx;
	vector<float> logx;
	vector<float> Flogx;
	vector<float> F_div_x;
	float sumF_div_x=0.0f;
public:
	float CalculateHM();
	void GetData();
	void showdata();
	vector<std::pair<int, int>> Findinterval();
	void showclassInterval();
	vector <int> getFrequency();
	void showTable();
	void Calculate_X_Fx_logx_flogX();
	float CalculateAM();
	float CalculateGm();
	



























};


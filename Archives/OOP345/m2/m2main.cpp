//PY import numpy as np
#include <algorithm>   // transform
#include <cmath>       // exp
#include <cstdlib>     // srand, rand
#include <iomanip>     // setprecision for 8 decimal places
#include <iostream>    // cout
#include <numeric>     // inner_product
#include <vector>      // VECTORS: vector<T>, and MATRICES: vector<vector<T>>
#include <stdlib.h>    // abs

using namespace std;

auto  sigmoid = [](double x) { return 1. / (1. + exp(-x)); }; // activation function
auto  sigmoid_d = [](double x) { return 1. * (1. - x); };      // derivative of activation function

vector<vector<double>> X = { { 0,0,1 },{ 0,1,1 },{ 1,0,1 },{ 1,1,1 } }; // inputs
vector<double> y = { {0},       {1},       {1},       {0} }; // outputs for each input

void matMult(vector<double>& Y, vector<vector<double>>& M, vector<double>& X) { // Y = M * X
	for (size_t i = 0; i < M.size(); i++)
		Y[i] = inner_product(M[i].begin(), M[i].end(), X.begin(), double(0));
};
int main() 
{
	srand(1); // seed generator

	vector<double> syn0(X[0].size());
	for (auto& e : syn0)
		e = 2. * rand() / double(RAND_MAX) - 1.;
	vector<double> syn1(X[0].size());
	for (auto& d : syn1)
		d = 2. * rand() / double(RAND_MAX) - 1.;



	vector<vector<double>> l0 = X;
	vector<double> l1(y.size());
	vector<double> l1_error(y.size());
	vector<double> l1_delta(y.size());
	vector<double> l2(y.size());
	vector<double> l2_error(y.size());
	vector<double> l2_delta(y.size());

	for (int i = 0; i < 60000; i++)
	{
		matMult(l1, l0, syn0);
		for (auto& element : l1) 
			element = sigmoid(element);
		matMult(l2, l0, syn1);
		for (auto& element2 : l2)
			element2 = sigmoid(element2);

		transform(y.begin(), y.end(), l1.begin(), l2_error.begin(), [](double y, double l1) { return y - l1; });

		if ((i % 10000) == 0)
		{
			double total = 0;
			for (int i = 0; i < l2_error.size(); i++)
			{
				total += abs(l2_error[i]);
			}
			cout << "Error: " << total / double(l2_error.size()) << endl;
		}
		//l2_delta = l2_error*nonlin(l2,deriv=True)
		transform(l2_error.begin(), l2_error.end(), l2.begin(), l2_delta.begin(), [](double e, double l2) { return e * sigmoid_d(l2); });
		
		//l1_error = l2_delta.dot(syn1.T)
		for (unsigned int i = 0; i < l1_error.size(); i++)
		{
			l1_error[i] = inner_product(l2_delta.begin(), l2_delta.end(), syn1.begin(), double(0));
		}

		//l1_delta = l1_error * nonlin(l1,deriv=True)
		transform(l1_error.begin(), l1_error.end(), l1.begin(), l1_delta.begin(), [](double e, double l1) { return e * sigmoid_d(l1); });

		
	}
}



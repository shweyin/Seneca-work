// m2b.cpp: Convert the object-orientated version of the nine line neural net from python to C++
// https://medium.com/technology-invention-and-more/how-to-build-a-simple-neural-network-in-9-lines-of-python-code-cc8f23647ca1

// g++ -O -ggdb -Ofast -Wall   m2b.cpp   -o m2b

// Embed the python code in the C++ code as a C++ comment to document what the C++ code is doing

// Why not grep the embedded python code, strip off the C++ comment, and run it?
//   grep //PY m2b.cpp | sed 's;.*//PY ;;' | grep -v ';;' | time python 
// or if you prefer,
//   grep //PY m2b.cpp | sed 's;.*//PY ;;' | grep -v ';;' > m2b.py ; time python m2b.py


/////////////////////////////////////////////////////////
// Python and C++ do not produce the same answers.     //
//   close, but not equal                              //
//                                                     //
// VECTOR l1 after 10000 iterations:                   //
//   py:  0.00966449 0.00786506 0.99358898 0.99211957  //
//   C++: 0.00014907 0.00010229 0.99303409 0.98988006  //
//      (Small numbers are close to 0)                 //
//      (Large numbers are close to 1)                 //
//                                                     //
// The C++ code is at least 100+ times faster          //
//   2 ms vs 350 ms                                    //
//      time ./m2b --> 2 ms                            //
//      time python m2b.py --> 356 ms                  // 
//                                                     //
// If you are hired by a company with python NN code   //
// they may ask you, as the C++ expert, to convert     //
// their python code to C++.                           //
//                                                     //
// Python people point out speed isn't everything.     //
//   Airplanes are faster than cars.                   //
//   Why don't you drive an airplane to work?          //
/////////////////////////////////////////////////////////

//PY import numpy as np
#include <algorithm>   // transform
#include <cmath>       // exp
#include <cstdlib>     // srand, rand
#include <iomanip>     // setprecision for 8 decimal places
#include <iostream>    // cout
#include <numeric>     // inner_product
#include <vector>      // VECTORS: vector<T>, and MATRICES: vector<vector<T>>
using namespace std;

typedef double      T;
typedef vector<T>   VEC;
typedef vector<VEC> MAT;   // row major (C-like, neither FORTRAN-like, neither OpenGL-like)

void vecPrint(VEC& V) {
	for (auto col : V)
		cout << setprecision(8) << col << " ";
	cout << "\n";
}
void matPrint(MAT& M) {
	for (auto row : M)
		vecPrint(row);
}
void matTranspose(MAT& Y, MAT& X) {
	size_t rows = X.size();    //  number of rows    for matrix X
	size_t cols = X[0].size(); //  number of columns for matrix X
	Y.resize(cols);             // set number of rows for Y
	for (auto&e : Y)             // set number of cols for each row of Y
		e.resize(rows);
	for (size_t r = 0; r < rows; r++)   // copy data
		for (size_t c = 0; c < cols; c++)
			Y[c][r] = X[r][c];
}

void matMult(VEC& Y, MAT& M, VEC& X) { // Y = M * X
	for (size_t i = 0; i < M.size(); i++)
		Y[i] = inner_product(M[i].begin(), M[i].end(), X.begin(), T(0));
};

int main()
{
	//PY # sigmoid function
	//PY def nonlin(x,deriv=False):
	//PY   if(deriv==True):
	//PY     return x*(1-x)
	//PY   return 1/(1+np.exp(-x))

	//PY # replace nonlin with sigmoid, sigmoid_d
	//PY def sigmoid(x):
	//PY   return 1/(1+np.exp(-x))
	//PY def sigmoid_d(x):
	//PY     return x*(1-x)
	auto  sigmoid = [](T x) { return 1. / (1. + exp(-x)); }; // activation function
	auto  sigmoid_d = [](T x) { return 1. * (1. - x); };      // derivative of activation function


															  //PY # input dataset
															  //PY X = np.array([  [0,0,1], [0,1,1], [1,0,1], [1,1,1] ])
															  //PY # output dataset           
															  //PY y = np.array([[0,0,1,1]]).T
	MAT X = { { 0,0,1 },{ 0,1,1 },{ 1,0,1 },{ 1,1,1 } }; // inputs
	VEC y = { 0,       0,       1,       1 }; // outputs for each input


											  //PY # seed random numbers to make calculation
											  //PY # deterministic (just a good practice)
											  //PY np.random.seed(1)
											  //PY # initialize weights randomly with mean 0
											  //PY syn0 = 2*np.random.random((3,1)) - 1
	srand(1);
	VEC  syn0(X[0].size());
	for (auto& e : syn0) e = 2. * rand() / T(RAND_MAX) - 1.;

	auto L0 = X;           // loop invarient, moved out of loop  NOTE L0 is X.  L0 is never changed
	MAT  L0T;              // loop invarient, moved out of loop
	matTranspose(L0T, L0);

	VEC  adjustments(syn0.size());
	VEC  l1(y.size());
	VEC  l1_error(y.size());
	//PY for iter in xrange(10000):
	int  iterations = 10000;
	for (int iter = 0; iter < iterations; iter++) {

		//PY   # forward propagation
		//PY   L0 = X # for loop invariant, move out of loop

		//PY   l1 = sigmoid(np.dot(L0,syn0))  # sigmoid, was nonlin(np.dot(L0,syn0))
		matMult(l1, L0, syn0);
		for (auto& element : l1) element = sigmoid(element);

		//PY   # how much did we miss?
		//PY   l1_error = y - l1
		transform(y.begin(), y.end(), l1.begin(), l1_error.begin(), [](T y, T l1) { return y - l1; });

		//PY   # multiply how much we missed by the
		//PY   # slope of the sigmoid at the values in l1
		//PY   l1_delta = l1_error * sigmoid_d(l1)  # sigmoid derivative, was nonlin(l1,True)
		// no need for l1_delta, can re-use l1_error
		VEC  l1_delta(y.size());
		transform(l1_error.begin(), l1_error.end(), l1.begin(), l1_delta.begin(), [sigmoid_d](T e, T l1) { return e * sigmoid_d(l1); });

		//PY   # update weights
		//PY   syn0 += np.dot(L0.T,l1_delta)
		matMult(adjustments, L0T, l1_delta);
		transform(adjustments.begin(), adjustments.end(), syn0.begin(), syn0.begin(), [](T a, T s) {return a + s; });
	}
	//PY print "syn0 After Training:"
	//PY print syn0
	//PY print "l1 Output After Training:"
	//PY print l1
	cout << "syn0 After Training:";
	vecPrint(syn0);
	cout << "l1 Output After Training:";
	vecPrint(l1);
}

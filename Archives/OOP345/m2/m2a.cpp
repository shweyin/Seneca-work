// // m2a.cpp: Convert the object-orientated version of the nine line neural net from python to C++
// https://medium.com/technology-invention-and-more/how-to-build-a-simple-neural-network-in-9-lines-of-python-code-cc8f23647ca1

// g++ -O -ggdb -Ofast -Wall   m2a.cpp   -o m2a

// Embed the python code in the C++ code as a C++ comment to document what the C++ code is doing

// Why not grep the embedded python code, strip off the C++ comment, and run it?
//   grep //PY m2a.cpp | sed 's;.*//PY ;;' | grep -v ';;' | time python 
// or if you prefer,
//   grep //PY m2a.cpp | sed 's;.*//PY ;;' | grep -v ';;' > m2a.py ; time python m2a.py

//PY import numpy as np
#include <algorithm>   // transform
#include <cmath>       // exp
#include <cstdlib>     // srand, rand
#include <iomanip>     // setprecision for 8 decimal places
#include <iostream>    // cout
#include <numeric>     // inner_product
#include <string>
#include <vector>      // VECTORS: vector<T>, and MATRICES: vector<vector<T>>
using namespace std;

typedef double      T;
typedef vector<T>   VEC;
typedef vector<VEC> MAT;   // row major (C-like, neither FORTRAN-like nor OpenGL-like)

void vecPrint (VEC& V) {
    for(auto& col : V)
      cout << setprecision(8) << col << " ";
    cout << "\n";
}
void matPrint (MAT& M) {
  for(auto& row : M)
    vecPrint(row);
} 
void matTransposeMake (MAT& Y, MAT& X) {
  size_t rows =  X.size();    //  number of rows    for matrix X
  size_t cols =  X[0].size(); //  number of columns for matrix X
  Y.resize(cols);             // set number of rows for Y
  for(auto&e : Y)             // set number of cols for each row of Y
    e.resize(rows);
}
 
void matTranspose (MAT& Y, MAT& X) {
  for(size_t r = 0; r < X.size(); r++)   // copy data
    for(size_t c = 0; c < X[0].size(); c++)
      Y[c][r] = X[r][c];
}

 // C++ polymorphism.  Let the compiler figure lout which matMultiply to call based on the calling arguments
void matMult (VEC& y, MAT& M, VEC& x) { // vec y = mat M * vec x
  for(size_t r = 0; r < M.size(); r++)
    y[r] = inner_product(M[r].begin(), M[r].end(), x.begin(), 0.); // YES! mat row inner product vec, use double (0.) for IP sum
}
void matMult_NotUsed (VEC& y, VEC& x, MAT& M) { // vec y = vec x * mat M
  for(size_t r = 0; r < M.size(); r++) {
    double sum = 0;
    for(size_t c = 0; c < y.size(); c++)
      sum += x[c] * M[r][c];                                       // YES! vec inner product mat col
    y[r] = sum;
  }
}
void matMult (MAT& C, MAT& A, MAT& B) { // mat C = mat A * mat B
  if(A[0].size() != B.size())
    throw string("matMult: cannot matrix multiply A*B: A(") 
          + to_string(A.size()) + "x" + to_string(A[0].size()) + 
          ") columns not equal to B(" 
          + to_string(B.size()) + "x" + to_string(B[0].size()) + ") rows";
  for(size_t r = 0; r < A.size(); r++)
    for(size_t c = 0; c < B[0].size(); c++) {
      double sum = 0;
      for(size_t k = 0; k < A[0].size(); k++)
        sum += A[r][k] * B[k][c];
      C[r][c] = sum;
    }
}
void matMult (MAT& C, VEC& a, VEC& b) { // mat C = vec a * vec b  (OUTER PRODUCT of two vectors)
  for(size_t r = 0; r < a.size(); r++)
    for(size_t c = 0; c < b.size(); c++) {
      C[r][c] = a[r] * b[c];
    }
}

void app()
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
  auto  sigmoid   = [] (T x) { return 1. / (1. + exp(-x)); }; // activation function
  auto  sigmoid_d = [] (T x) { return x * ( 1. - x); };       // derivative (slope/gradient/steepness) of curve) of activation function
  // derivative = (f(x+ e) - f(x)) / e, as delta becomes small (tends to zero)
  // if f = y = mx+b  (a straight line)
  // derivative of f = (m(x+e) + b) - (mx+b)) / e
  //                 = (mx + me + b - mx - b) / e
  //                 = me / e
  //                 tends to m , as e becomes small (close to zero).  We can't divide by zero, but can divide by something really close...
  //                 = the slope of y=mx+b
  // if f = y = a*x*x + b*x + c (a parabola)
  // derivative of f = (a(x+e)(x+e) +b(x+e) + c - (a*x*x + b*x + c)) / e
  //                 = (a*x*x + 2a*x*e + a*e*e + b*x + b*e + c - a*x*x - b*x -c) / e
  //                 = (2*a*x*e + a*e*e +b*e) / e
  //                 = 2*a*x + a*e + b
  //                 tends to 2*a*x + b, as e becomes small (close to zero), since a*e becomes small, close to zero

  //PY # input dataset
  //PY X = np.array([  [0,0,1], [0,1,1], [1,0,1], [1,1,1] ])
  //PY # output dataset           
  //PY y = np.array([[0,1,1,0]]).T
  MAT X = {  {0,0,1}, {0,1,1}, {1,0,1}, {1,1,1} }; // inputs
  VEC y = {     0,       1,       1,       0    }; // outputs for each input
  // Are they using capital letters for MAT and lower case letters for VEC?
  // Adopt this convention, even for python

  //PY # seed random numbers to make each run repeatable (simplifies debugging)
  //PY np.random.seed(1)
  srand(1);

  //PY SYN0 = 2*np.random.random((3,4)) - 1
  //PY # print SYN0

  MAT SYN0(X[0].size());
  for(auto& row : SYN0) {
    row.resize(X.size());
    for(auto& e : row)
      e = 2. * rand() / T(RAND_MAX) - 1.;
  }
  SYN0 =  // debug with python values
    {{-0.16595599,  0.44064899, -0.99977125, -0.39533485},
    {-0.70648822, -0.81532281, -0.62747958, -0.30887855},
    {-0.20646505,  0.07763347, -0.16161097,  0.370439  }};

  //PY syn1 = 2*np.random.random((4,1)) - 1
  //PY # print syn1
  VEC syn1(X.size());
  for(auto& e : syn1)
    e = 2. * rand() / T(RAND_MAX) - 1.;
  syn1 =  // debug with python values
    { -0.5910955, 0.75623487, -0.94522481, 0.34093502 };

  ///////////////////////////////////////////////////
  // factor all declarations out of the for-loop   //
  //   1. avoid multiple alloc-dealloc inside loop //
  //   2. print values after for-loop              //
  ///////////////////////////////////////////////////
  MAT XT;
  matTransposeMake(XT, X);
  matTranspose(XT, X);

  MAT L1;
  L1.resize(X.size());
  for(auto& row: L1)
    row.resize(X.size());

  MAT L1T;
  matTransposeMake(L1T, L1);

  VEC l2(L1.size());

  VEC l2_delta(L1.size());

  MAT L1_DELTA(L1.size());
  for(auto& row : L1_DELTA)
    row.resize(L1[0].size());

  VEC temp(l2_delta.size());

  MAT TEMP(XT.size()); // SYN0 += X.T.dot(L1_DELTA) matMult(TEMP, XT, L1_DELTA)
  for(auto& row : TEMP)
    row.resize(L1_DELTA[0].size());

  //////////////
  // for-loop //
  //////////////
  //PY iterations = 60000
  //PY print "iterations=", iterations
  //PY for j in xrange(iterations):
  int  iterations = 60000;
  cout << "iterations=" << iterations << "\n";
  for(int iter = 0; iter < iterations; iter++) { // training for loop

  //PY     # L1 = 1/(1+np.exp(-(np.dot(X,SYN0))))
  //PY     L1 = sigmoid(np.dot(X,SYN0))
  //PY     # print "L1 = sigmoid(np.dot(X,SYN0))"
  //PY     # print L1
    matMult(L1, X, SYN0);
    for(auto& row: L1)
      for(auto& col: row)
        col = sigmoid(col);
    // cout << "L1 = sigmoid(np.dot(X,SYN0))\n";
    // matPrint(L1);

  //PY     # l2 = 1/(1+np.exp(-(np.dot(L1,syn1))))
  //PY     l2 = sigmoid( np.dot(L1,syn1))
  //PY     # print "l2 = sigmoid( np.dot(L1,syn1))"
  //PY     # print l2
    matMult(l2, L1, syn1);
    for(auto& e: l2)
        e = sigmoid(e);
    // cout << "l2 = sigmoid( np.dot(L1,syn1))\n";
    // vecPrint (l2);

  //PY     # l2_delta = (y - l2)*(l2*(1-l2))
  //PY     l2_delta = (y - l2) * sigmoid_d(l2)
  //PY     # print "l2_delta = (y - l2) * sigmoid_d(l2)"
  //PY     # print l2_delta
    transform(y.begin(), y.end(), l2.begin(), l2_delta.begin(), [sigmoid_d] (T y,T l2){ return (y - l2) * sigmoid_d(l2); });
    // cout << "l2_delta = (y - l2) * sigmoid_d(l2)\n";
    // vecPrint( l2_delta );

  //PY     # L1_DELTA = l2_delta.dot(syn1.T) * (L1 * (1-L1))
  //PY     L1_DELTA = l2_delta.dot(syn1.T) * sigmoid_d(L1)
  //PY     # print "l2_delta.dot(syn1.T)"
  //PY     # print l2_delta.dot(syn1.T)
  //PY     # print "L1_DELTA = l2_delta.dot(syn1.T) * sigmoid_d(L1)"
  //PY     # print L1_DELTA
    matMult(L1_DELTA, l2_delta, syn1);   // matrix = OUTER PRODUCT of two vectors
    // cout << "matMult(L1_DELTA, l2_delta, syn1); --> l2_delta.dot(syn1.T)\n";
    // matPrint( L1_DELTA );

    for(size_t r = 0; r < L1_DELTA.size(); r++)
      for(size_t c = 0; c < L1_DELTA[0].size(); c++) {
        L1_DELTA[r][c] = L1_DELTA[r][c] * sigmoid_d(L1[r][c]); // WORKS
        // L1_DELTA[r][c] = l2_delta[r] * syn1[c] * sigmoid_d(L1[r][c]); // DOES NOT WORK
      }
    // cout << "L1_DELTA = l2_delta.dot(syn1.T) * sigmoid_d(L1)\n";
    // matPrint( L1_DELTA );

  //PY     syn1 += L1.T.dot(l2_delta)
  //PY     # print "syn1 += L1.T.dot(l2_delta)"
  //PY     # print syn1
    matTranspose(L1T, L1);
    matMult(temp, L1T, l2_delta);
    transform(syn1.begin(), syn1.end(), temp.begin(), syn1.begin(), [] (T s,T t){return s + t;});
    // cout << "syn1 += L1.T.dot(l2_delta)\n";
    // vecPrint( syn1 );

  //PY     SYN0 += X.T.dot(L1_DELTA)
  //PY     # print "SYN0 += X.T.dot(L1_DELTA)"
  //PY     # print SYN0
  //PY     # exit()
    matMult(TEMP, XT, L1_DELTA);
    for(size_t r = 0; r < TEMP.size(); r++)
      for(size_t c = 0; c < TEMP[0].size(); c++)
        SYN0[r][c] += TEMP[r][c];
    // cout << "SYN0 += X.T.dot(L1_DELTA)\n";
    // matPrint( SYN0 );
    // exit(1);

  } // training for loop

  // training complete
  // or is it?
  // If we start SYN0 and syn1 off with the python values, the C++ final training after 60,000 iterations agrees with the Py results.
  // As it should.  The python and C++ are calculations are identical.
  // If we generate our own C++ random values via rand/srand, they don't agree.
  // Welcome to machine learning.  Very 'deep' indeed...
  // Guess this is a poor example of a neural net

  //PY print "SYN0", SYN0.shape
  //PY print SYN0 
  //PY print "syn1", syn1.shape
  //PY print syn1 
  cout << "SYN0:\n";
  matPrint(SYN0);
  cout << "syn1:";
  vecPrint(syn1);

  //PY print "L1", L1.shape
  //PY print L1 
  //PY print "l2", l2.shape
  //PY print l2 
  cout << "L1:\n";
  matPrint(L1);
  cout << "l2:";
  vecPrint(l2);
}

int main()
{
  try {
    app();
  } catch(const string e) {
    cerr << e << "\n";
  } catch(const char* e) {
    cerr << e << "\n";
  }
  return 0;
}

// main-28.cpp: Convert the object-orientated version of the nine line neural net from python to C++
// https://medium.com/technology-invention-and-more/how-to-build-a-simple-neural-network-in-9-lines-of-python-code-cc8f23647ca1

// Embed the python code in the C++ code as a C++ comment to document what the C++ code is doing

// Why not grep the embedded python code, strip off the C++ comment, and run it?
//   grep //PY main-28.cpp | sed 's;.*//PY ;;' | grep -v ';;' | python 

//PY from numpy import exp, array, random, dot
#include <algorithm>   // transform
#include <cmath>       // exp
#include <cstdlib>     // srand, rand
#include <iomanip>     // setprecision for 8 decimal places
#include <iostream>    // cout
#include <numeric>     // inner_product
#include <vector>      // vectors vector<->, and matrices vector<vector<->>
using namespace std;

typedef double T;
typedef vector<T> VEC;
typedef vector<VEC> MAT;

void vecPrint (VEC& V) {
    for(auto col : V)
      cout << col << " ";
    cout << "\n";
}
void matPrint (MAT& M) {
  for(auto row : M)
    vecPrint(row);
}  
void matTranspose (MAT& Y, MAT& X) {
  size_t rows =  X.size();    //  number of rows    for matrix X
  size_t cols =  X[0].size(); //  number of columns for matrix X
  Y.resize(cols);             // set number of rows for Y
  for(auto&e : Y)             // set number of cols for each row of Y
    e.resize(rows);
  for(size_t r = 0; r < rows; r++)   // copy data
    for(size_t c = 0; c < cols; c++)
      Y[c][r] = X[r][c];
}

void matMult (VEC& Y, MAT& M, VEC& X) { // Y = M * X
  for(size_t i = 0; i < M.size(); i++)
    Y[i] = inner_product(M[i].begin(), M[i].end(), X.begin(), T(0));
};

//PY class NeuralNetwork():
class NeuralNetwork {
public:
  VEC synaptic_weights;
//PY     def __init__(self):
//PY         random.seed(1)
//PY         self.synaptic_weights = 2 * random.random((3, 1)) - 1
  NeuralNetwork (int variables)   {
    synaptic_weights.resize(variables);
    srand(1);
    for(auto& e : synaptic_weights) e = 2. * rand() / T(RAND_MAX) - 1.;
  }
//PY     def __sigmoid(self, x):
//PY         return 1 / (1 + exp(-x))
  T     __sigmoid(T x)    { return 1. / (1. + exp(-x)); }
  // VEC&  __sigmoid(VEC& V) { for(auto& e : V) e = __sigmoid(e); return V; }
  VEC&  __sigmoid(VEC& V) {transform(V.begin(), V.end(), V.begin(), [this] (T e) { return __sigmoid(e);} ); return V; }

//PY     def __sigmoid_derivative(self, x):
//PY         return x * (1 - x)
  T    __sigmoid_derivative(T x)    { return x * (1. - x); }
  // VEC& __sigmoid_derivative(VEC& V) { for(auto& e : V) e = __sigmoid_derivative(e);  return V; }
  VEC& __sigmoid_derivative(VEC& V) { transform(V.begin(), V.end(), V.begin(), [this] (T e) { return __sigmoid_derivative(e);} );  return V; }

//PY     def train(self, training_set_inputs, training_set_outputs, number_of_training_iterations):
  void train(MAT& training_set_inputs, VEC& training_set_outputs, int number_of_training_iterations) {
    VEC output, error, adjustment;
    output    .resize(training_set_inputs.size());
    error     .resize(training_set_inputs.size());
    adjustment.resize(training_set_inputs[0].size());

    MAT training_set_inputsT;
    matTranspose(training_set_inputsT, training_set_inputs);

//PY         for iteration in xrange(number_of_training_iterations):
    for(int interation = 0; interation < number_of_training_iterations; interation++) {

//PY             output = self.think(training_set_inputs)
      think(output, training_set_inputs);

//PY             error = training_set_outputs - output
      transform(training_set_outputs.begin(), training_set_outputs.end(),
                output.begin(),
                error.begin(),
                [] (T t, T o) { return t - o; }
      );

//PY             adjustment = dot(training_set_inputs.T, error * self.__sigmoid_derivative(output))
      transform(error.begin(), error.end(),
                output.begin(),
                output.begin(),
                [this] (T e, T o) { return e * __sigmoid_derivative(o); }
      );
      matMult(adjustment, training_set_inputsT, output);

//PY             self.synaptic_weights += adjustment
      transform(synaptic_weights.begin(), synaptic_weights.end(),
                adjustment.begin(),
                synaptic_weights.begin(),
                [this] (T w, T a) { return w + a; }
      );
    }
  }  // train

//PY     def think(self, inputs):
//PY         return self.__sigmoid(dot(inputs, self.synaptic_weights))
  void think(VEC& output, MAT& inputs) { 
    matMult(output, inputs, synaptic_weights);
    __sigmoid(output);
  }
  T think(VEC& input) { return __sigmoid( inner_product(input.begin(), input.end(), synaptic_weights.begin(), T(0)) ); }
};
//PY if __name__ == "__main__":
int main(int argc, char*argv[])
{
  cout.precision(8); // python ues 8 decimal places.  we can too.

//PY     neural_network = NeuralNetwork()
  NeuralNetwork neural_network(3);
//PY     print "Random starting synaptic weights: "
//PY     print neural_network.synaptic_weights
  cout <<  "Random starting synaptic weights: ";
  vecPrint(neural_network.synaptic_weights);

//PY     training_set_inputs = array([[0, 0, 1], [1, 1, 1], [1, 0, 1], [0, 1, 1]])
  MAT training_set_inputs = {{0, 0, 1}, {1, 1, 1}, {1, 0, 1}, {0, 1, 1}};  // MATRIX 4 rows x 3 columns
  cout << "training_set_inputs\n";
  matPrint(training_set_inputs);

//PY     training_set_outputs = array([[0, 1, 1, 0]]).T
  VEC training_set_outputs = {0, 1, 1, 0};                                         // VECTOR
  cout << "training_set_outputs: "; 
  vecPrint(training_set_outputs);

//PY     neural_network.train(training_set_inputs, training_set_outputs, 10000)
  neural_network.train(training_set_inputs, training_set_outputs, 10000);

//PY     print "New synaptic weights after training: "
//PY     print neural_network.synaptic_weights
  cout << "New synaptic weights after training: ";
  vecPrint( neural_network.synaptic_weights );

//PY     print "Considering new situation [1, 0, 0] -> ?: "
//PY     print neural_network.think(array([1, 0, 0]))
  cout << "Considering new situation [1, 0, 0] -> ?:\n";
  VEC input = { 1, 0, 0 };
  cout << setprecision(8) << neural_network.think(input) << "\n";
}

/* python
Random starting synaptic weights:
[[-0.16595599]
 [ 0.44064899]
 [-0.99977125]]
New synaptic weights after training:
[[ 9.67299303]
 [-0.2078435 ]
 [-4.62963669]]
Considering new situation [1, 0, 0] -> ?:
[ 0.99993704]
*/

/* C++
Random starting synaptic weights: 0.68037543 -0.21123415 0.56619845
training_set_inputs
0 0 1
1 1 1
1 0 1
0 1 1
training_set_outputs: 0 1 1 0
New synaptic weights after training: 9.6730078 -0.20872393 -4.6291189
Considering new situation [1, 0, 0] -> ?:
0.99993704
*/

//Shweyin Than 115675175 - OOP345 Milestone 1
//main.cpp

//PY from numpy import exp, array, random, dot
#include <algorithm>   // transform
#include <cmath>       // exp
#include <cstdlib>     // srand, rand
#include <iomanip>     // setprecision
#include <iostream>
#include <numeric>     // inner_product
#include <vector>      // vectors vector<->, and matrices vector<vector<->>

const int iterations = 10000;

auto matMult = [](std::vector<double>& Y, std::vector<std::vector<double>>& M, std::vector<double>& X) { // Y = M * X
	for (size_t i = 0; i < M.size(); i++)
		Y[i] = std::inner_product(M[i].begin(), M[i].end(), X.begin(), 0.);
};
auto matTranspose = [](std::vector<std::vector<double>>& Y, std::vector<std::vector<double>>& X) {
	size_t rows = X.size();    //  number of rows    for matrix X
	size_t cols = X[0].size(); //  number of columns for matrix X
	Y.resize(cols);             // set nunber of rows for Y
	for (auto&e : Y)             // set nunber of cols for each row of Y
		e.resize(rows);
	for (size_t r = 0; r < rows; r++)   // copy data
		for (size_t c = 0; c < cols; c++)
			Y[c][r] = X[r][c];
};

class NeuralNetwork {
public:
	NeuralNetwork(std::vector<double>& synaptic_weights) {
		srand(1);
		for (auto& e : synaptic_weights)
			e = 2. * rand() / double(RAND_MAX) - 1.;
	};
	void train(std::vector<std::vector<double>>& training_set_inputs, std::vector<double>& training_set_outputs, int iterate, std::vector<double> output, std::vector<double> correction, std::vector<std::vector<double>> training_set_inputsT, std::vector<double> synaptic_weights) {
		
		for (int i = 0; i < iterate; i++) {
			matMult(output, training_set_inputs, synaptic_weights);
			std::transform(output.begin(), output.end(),
				output.begin(),
				[](double element) { return 1. / (1. + exp(-element)); });  // sigmoid
																			
			std::transform(training_set_outputs.begin(), training_set_outputs.end(),  
				output.begin(),
				output.begin(),
				[](double t, double o) { return (t - o) * o * (1. - o); }
			);
			matMult(correction, training_set_inputsT, output);
			std::transform(synaptic_weights.begin(), synaptic_weights.end(),
				correction.begin(),
				synaptic_weights.begin(),
				[](double weight, double correction) { return weight += correction; }
			);
		}
	};
};

auto vectorPrint = [](std::vector<double>& V) {
	for (auto col : V)
		std::cout << col << " ";
	std::cout << "\n";
};
auto matrixPrint = [](std::vector<std::vector<double>>& M) {
	for (auto row : M)
		vectorPrint(row);
};
int main(int argc, char*argv[])
{
	std::cout << "Random starting synaptic weights: ";
	std::vector<double> synaptic_weights(3);
	NeuralNetwork NN(synaptic_weights);
	vectorPrint(synaptic_weights);

	std::vector<std::vector<double>> training_set_inputs = { { 0, 0, 1 },{ 1, 1, 1 },{ 1, 0, 1 },{ 0, 1, 1 } };
	std::cout << "training_set_inputs\n";
	matrixPrint(training_set_inputs);

	std::vector<double> training_set_outputs = { 0, 1, 1, 0 };
	std::cout << "training_set_outputs: ";
	vectorPrint(training_set_outputs);
	
	std::vector<double> output(training_set_outputs.size());
	std::vector<double> correction(training_set_outputs.size());
	std::vector<std::vector<double>> training_set_inputsT;
	matTranspose(training_set_inputsT, training_set_inputs);

	NN.train(training_set_inputs, training_set_outputs, iterations, output, correction, training_set_inputsT, synaptic_weights);

	std::cout << "New synaptic weights after training: ";
	vectorPrint(synaptic_weights);

	std::vector<double> input = { 1,0,0 };
	std::cout << "input: ";
	vectorPrint(input);
	std::cout << "1 / (1 + exp(-dot(input, synaptic_weights))): ";
	std::cout << std::setprecision(8) 
		<< 1. / (1. + exp(-inner_product(input.begin(), input.end(), synaptic_weights.begin(), 0.))) << "\n";
}
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

auto matMult = [](std::vector<double>& Y, std::vector<std::vector<double>>& M, std::vector<double>& X) {
	for (size_t i = 0; i < M.size(); i++)
		Y[i] = inner_product(M[i].begin(), M[i].end(), X.begin(), 0.);
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
	std::vector<double> synaptic_weights;
	std::vector<std::vector<double>> training_set_inputs;
	std::vector<double> training_set_outputs;
public:
	NeuralNetwork(std::vector<std::vector<double>> cons_training_set_inputs, std::vector<double> cons_training_set_outputs) {
		training_set_inputs = cons_training_set_inputs;
		training_set_outputs = cons_training_set_outputs;
		srand(1);
		for (auto& e : synaptic_weights)
		{
			e = 2. * rand() / double(RAND_MAX) - 1.;
		}
	};
	double sigmoid(double x) {
		return 1 / (1 + exp(-x));
	}
	double sigmoid_derivative(double x) {
		return x * (1 - x);
	}
	void train(int iterations)
	{
		for (int i = 0; i < iterations; i++)
		{
			std::vector<double> output(training_set_outputs.size());
			std::vector<double> correction(training_set_outputs.size());

			std::vector<std::vector<double>> training_set_inputsT;
			matTranspose(training_set_inputsT, training_set_inputs);

			matMult(output, training_set_inputs, synaptic_weights);
			transform(output.begin(), output.end(),
				output.begin(),
				[](double element) { return 1. / (1. + exp(-element)); });

			transform(training_set_outputs.begin(), training_set_outputs.end(),
				output.begin(),
				output.begin(),
				[](double t, double o) { return (t - o) * o * (1. - o); }
			);
			matMult(correction, training_set_inputsT, output);
			transform(synaptic_weights.begin(), synaptic_weights.end(),
				correction.begin(),
				synaptic_weights.begin(),
				[](double weight, double correction) { return weight += correction; }
			);
		}
	}
};
int main(int argc, char* argv[])
{
	std::vector<std::vector<double>> training_set_inputs = { { 0, 0, 1 },{ 1, 1, 1 },{ 1, 0, 1 },{ 0, 1, 1 } };
	std::vector<double> training_set_outputs = { 0, 1, 1, 0 };
	
	NeuralNetwork myNN(training_set_inputs, training_set_outputs);
}
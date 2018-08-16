#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, char* argv[])
{
	class NeuralNetwork {
		std::vector<double> synaptic_weights;
		std::vector<std::vector<double>> training_set_inputs;
		std::vector<std::vector<double>> training_set_outputs;
	public:
		NeuralNetwork(std::vector<std::vector<double>> cons_training_set_inputs, std::vector<std::vector<double>> cons_training_set_outputs) {
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

		}
	};
}
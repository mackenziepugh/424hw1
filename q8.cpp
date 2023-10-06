#include <iostream>
#include <cmath>
#include <vector>
//MacKenzie Pugh
//Aersp 424
//Homework 1
//October 6, 2023

//Question 8: write a simple aircraft classifier software 

//from question 7

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double dot_product(const std::vector<double>& w, const std::vector<double>& x) {

    //make sure vectors are the same size

    if (w.size() != x.size()) {

        std::cerr << "error; vectors not same size" << std::endl;

        return 0.0; 
    }

    double result = 0.0;

    for (size_t i = 0; i < w.size(); ++i) {

        result += w[i] * x[i];

    }

    return result;
}


std::vector<double> gradient_weights(const std::vector<double>& w, const std::vector<double>& x, double y) {

    std::vector<double> gradient(w.size(), 0.0);

    double sigma_wtx = 1.0 / (1.0 + exp(-dot_product(w, x)));


    for (size_t i = 0; i < w.size(); ++i) {

        gradient[i] = 2.0 * (sigma_wtx - y) * sigma_wtx * (1.0 - sigma_wtx) * x[i];

    }

    return gradient;
}

void update_weights(std::vector<double>& w, const std::vector<double>& dw, double alpha) {

    for (size_t i = 0; i < w.size(); ++i) {

        w[i] -= alpha * dw[i];

    }
}

int main() {


//given data in chart

    std::vector<std::vector<double>> data = {
        {124, 31.89, 20.945, 1},
        {74, 51.08, 9.170, 0},
        {103, 34.67, 8.300, 1},
        {77, 52.00, 9.400, 0},
        {104, 35.63, 13.000, 1},
        {92, 56.00, 12.500, 0},
        {130, 31.29, 17.637, 1},
        {73, 52.00, 9.600, 0}
    };

    std::vector<double> w = {0.0001, 0.0001, 0.0001};
    double alpha = 0.001;

    for (int i = 0; i < 200; ++i) {
        for (const auto& aircraft : data) {
            std::vector<double> x(aircraft.begin(), aircraft.begin() + 3);
            double y = aircraft[3];
            std::vector<double> dw = gradient_weights(w, x, y);
            update_weights(w, dw, alpha);
        }
    }

//print result

    std::cout << "final weights:";
    for (const double weight : w) {
        std::cout << " " << weight;
    }
    std::cout << std::endl;

    return 0;
}

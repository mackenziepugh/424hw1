#include <iostream>
#include <cmath>
#include <vector>
//MacKenzie Pugh
//Aersp 424
//Homework 1
//October 6, 2023

//Question4: Write a function named “dot_product” that computes the dot-product
//between two vectors of an arbitrary size

//functiion

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

int main() {

    // define vectors

    std::vector<double> w = {0.0001, 0.0001, 0.0001};
    std::vector<double> x = {124, 31.89, 20.945};

    // dot product

    double z = dot_product(w, x);

    // result

    std::cout << "Dot Product (z) = " << z << std::endl;

    return 0;
}

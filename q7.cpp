#include <iostream>
#include <cmath>
#include <vector>
//MacKenzie Pugh
//Aersp 424
//Homework 1
//October 6, 2023

//Question 7: Write a function named “gradient_weights” and write 
//another function named “update_weights”


//given
//y = 1
//alpha = .001
//w = [0.0001, 0.0001, 0.0001]
//x = [124, 31.89, 20.945]

//dot product function from question 4

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


// "gradient_weights" function

std::vector<double> gradient_weights(const std::vector<double>& w, const std::vector<double>& x, double y) {

    std::vector<double> gradient(w.size(), 0.0);

    double sigma_wtx = 1.0 / (1.0 + exp(-dot_product(w, x)));


    for (size_t i = 0; i < w.size(); ++i) {

        gradient[i] = 2.0 * (sigma_wtx - y) * sigma_wtx * (1.0 - sigma_wtx) * x[i];

    }

    return gradient;
}


//"update_weights" functin

void update_weights(std::vector<double>& w, const std::vector<double>& dw, double alpha) {

    for (size_t i = 0; i < w.size(); ++i) {

        w[i] -= alpha * dw[i];

    }
}

int main() {
 
    std::vector<double> w = {0.0001, 0.0001, 0.0001};   //given
    std::vector<double> x = {124, 31.89, 20.945};       //given 
    double y = 1.0;             //given
    double alpha = 0.001;       //given


    std::vector<double> dw = gradient_weights(w, x, y);

  
    update_weights(w, dw, alpha);

  //results

    std::cout << "updated weights:";

    for (size_t i = 0; i < w.size(); ++i) {

        std::cout << " " << w[i];

    }
    
    std::cout << std::endl;

    return 0;
}

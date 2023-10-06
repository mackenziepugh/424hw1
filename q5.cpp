#include <iostream>
#include <cmath>
//MacKenzie Pugh
//Aersp 424
//Homework 1
//October 6, 2023

//Question 5: Write a function named “sigmoid” and another 
//function named “gradient_sigmoid”

//given
//z = .0176835

// "sigmoid" function

double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

// "gradient sigmoud" function

double gradient_sigmoid(double z) {
    double sigmoid_z = sigmoid(z);
    return sigmoid_z * (1.0 - sigmoid_z);
}

int main() {
 
    double z = .0176835; //given

    double sigmoid_result = sigmoid(z);
    double gradient_result = gradient_sigmoid(z);

    //result

    std::cout << "sigmoid(" << z << ") = " << sigmoid_result << std::endl;
    std::cout << "gradient sigmoid(" << z << ") = " << gradient_result << std::endl;

    return 0;
}

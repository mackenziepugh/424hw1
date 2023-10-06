#include <iostream>
#include <cmath>
//MacKenzie Pugh
//Aersp 424
//Homework 1
//October 6, 2023

//Question 6: write a function named “gradient_cost”

//given
//y = 1
//y_predict = .504421

//function

double gradient_cost(double y_predict, double y) {
    return 2.0 * (y_predict - y);
}

int main() {
    
    double y_predict = .504421;     //given
    double y = 1.0;          //given

    double gradient_result = gradient_cost(y_predict, y);

   //results
   
    std::cout << "gradient of cost: " << gradient_result << std::endl;

    return 0;
}

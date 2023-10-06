#include <iostream>
#include <cmath>
#include <vector>
//MacKenzie Pugh
//Aersp 424
//Homework 1
//October 6, 2023

//Question 9: Write a program to predict the engine type of these aircraft and print the
//result (“Jet” or “Turboprop”) for each aircraft.

// sigmoid function

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// function to predict engine type

std::string predictEngineType(const std::vector<double>& w, const std::vector<double>& x) {
    double wx = 0.0;

    for (size_t i = 0; i < w.size(); ++i) {
        wx += w[i] * x[i];
    }

    double y_predicted = sigmoid(wx);

    if (y_predicted > 0.5) {
        return "Jet";
    } else {
        return "Turboprop";
    }
}

int main() {
    
    //final weights from number 8

    std::vector<double> w = {.107576, -.229138, -.001577417};

    // given for new aircraft
    std::vector<std::vector<double>> newAircraftData = {
        {87, 38.67, 6.000},
        {79, 52.08, 8.000},
        {92, 33.75, 7.804},
        {91, 59.25, 16.000}
    };

    std::cout << "predicted engine type:" << std::endl;

    //print result

    for (const auto& aircraft : newAircraftData) {
        std::string engineType = predictEngineType(w, aircraft);
        std::cout << "Aircraft: Approach Speed=" << aircraft[0] << " ft/s, Wingspan=" << aircraft[1] << " ft, MTOW=" << aircraft[2] << " kilopound, Engine Type=" << engineType << std::endl;
    }

    return 0;
}

#include <iostream>
#include <cmath>
//MacKenzie Pugh
//Aersp 424
//Homework 1
//October 6, 2023


//Question 2: Write a program to predict the roll rate of the aircraft up to 5 seconds and print out the result at every time step using autopilot.

//given
//feedback control gain (K) between [-3,3]
//delta t = .01 sec
#include <iostream>
#include <cmath>

int main() {
   
    double Lp = 0.2;  //roll damping coefficient
    double Ldelta = 0.1;  // aileron effectiveness
    double delta = 1.0;  // aileron deflection angle (during 2 sec)
    double delta_release = 0.0;  // aileron deflection angle (after 2 sec)
    double p0 = 1.0;  // initial roll rate (rad/s)
    double delta_t = 0.01;  // time step size
    double time = 0.0;  // start time


    double K = -1.0;  // feedback control gain

    while (time <= 5.0) {
    
        double delta = -K * p0; // control input based on the feedback control law

        // roll rate using the simplified equation of motion

        double pdot = Lp * p0 + Ldelta * delta;
        p0 = p0 + pdot * delta_t;

        time += delta_t;

         // result

        std::cout << "Time: " << time << " seconds, Roll Rate: " << p0 << " rad/s" << std::endl;
    }

    return 0;
}

#include <iostream>
#include <cmath>
//MacKenzie Pugh
//Aersp 424
//Homework 1
//October 6, 2023


//Question 1: Write a program to predict the roll rate of the aircraft up to 5 seconds and print out the result at every time step.

//Given
//Lp and Ld between [-1,1]
//p0 is 1 rad/s
//pilot applied the aileron deflection of 1 radian for 2 seconds, then releases
//delta t= .01 sec

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

    while (time <= 5.0) {

        double pdot = Lp * p0 + Ldelta * delta;
        p0 = p0 + pdot * delta_t;

        time += delta_t;

        //aileron deflection after 2 seconds

        if (time > 2.0) {
            delta = delta_release;
        }

         // result

        std::cout << "Time: " << time << " seconds, Roll Rate: " << p0 << " rad/s" << std::endl;
    }

    return 0;
}

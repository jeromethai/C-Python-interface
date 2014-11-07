/*
 * greatCircleCalculation.h
 *
 *  Created on: Nov 7, 2014
 *      Author: jeromethai
 */

#include<iostream>
#include <math.h>
#include <stdio.h>
#define NUM 500000


float great_circle(float lon1, float lat1, float lon2, float lat2){
    float radius = 3956.0;
    float pi = 3.14159265;
    float x = pi/180.0;
    float a,b,theta,c;

    a = (90.0-lat1)*(x);
    b = (90.0-lat2)*(x);
    theta = (lon2-lon1)*(x);
    c = acos((cos(a)*cos(b)) + (sin(a)*sin(b)*cos(theta)));
    return radius*c;
}


void run_great_circ_calc() {
    int i;
    float x;
    for (i=0; i <= NUM; i++) {
            x = great_circle(-72.345, 34.323, -61.823, 54.826);
    }
    printf("%f", x);
    std::cout << std::endl << "Done!" << std::endl;
}

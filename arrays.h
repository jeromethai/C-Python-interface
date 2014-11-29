/*
 * arrays.h
 *
 *  Created on: Nov 27, 2014
 *      Author: jeromethai
 */

#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;

const int SIZE = 7;

void proj_l1ball(double *y, int start, int end) {
    double u[end-start];
	std::copy(y+start, y+end, u);
    std::sort(u, u+end-start, std::greater<double>());
    double sum = u[0];
    double lambda = 1.-sum;
    double tmp;
    int i;
    for (i = 1; i < end-start; i++) {
        sum += u[i];
        tmp = (1.-sum) / ((double)i + 1.);
        if (u[i] + tmp > 0) {
            lambda = tmp;
        }
    }
    for (i = start; i < end; i++) {
        y[i] = std::max(lambda + y[i], 0.);
    }   
  
}


void proj_multi_l1ball(double *y, int *blocks, int numblocks, int n) {
/*
Do multiple projections where blocks is an array of integers that
constains the first index of each block and n the length of the array
*/
    int i;
    for (i = 0; i < numblocks-1; i++) {
        proj_l1ball(y, blocks[i], blocks[i+1]);
    } 
    proj_l1ball(y, blocks[numblocks-1], n);
}


void proj_multi_l1ball_hack(double *y, double *blocks, int numblocks, int n) {
/*
Do multiple projections where blocks is an array of integers that
constains the first index of each block and n the length of the array
*/
    int i;
    for (i = 0; i < numblocks-1; i++) {
        proj_l1ball(y, (int)floor(blocks[i]), (int)floor(blocks[i+1]));
    } 
    proj_l1ball(y, (int)floor(blocks[numblocks-1]), n);
}


int testArray() {

    double doubleArray[SIZE] = {5.352, 3.23, 32.78, -1.234, 1.7, 104., 53.};
    int blocks[] = {0, 2, 4};

    proj_multi_l1ball(doubleArray, blocks, 3, 7);
    cout << "Projected block-vector is this." << endl;
    for (size_t i = 0; i != SIZE; ++i)
        cout << doubleArray[i] << " ";
        cout << endl;

    double doubleArray2[SIZE] = {5.352, 3.23, 32.78, -1.234, 1.7, 104., 53.};
    double blocks2[] = {0., 2., 4.};

    proj_multi_l1ball_hack(doubleArray2, blocks2, 3, 7);
    cout << "Projected block-vector is this." << endl;
    for (size_t i = 0; i != SIZE; ++i)
        cout << doubleArray2[i] << " ";
        cout << endl;

    return 0;
}

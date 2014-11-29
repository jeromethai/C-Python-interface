'''
Created on 29 nov. 2014

Example of C++11 wrapping with cython.
Compile with python setup.py build_ext --inplace

@author: jerome thai
'''

cimport numpy as np
import numpy as np

cdef extern from "arrays.h":
    void proj_l1ball(double *y, int start, int end)

def proj_l1ball_c(np.ndarray[np.double_t,ndim=1] y, start, end):
    proj_l1ball(&y[0], start, end)
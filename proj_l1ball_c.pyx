'''
Created on 29 nov. 2014

Example of C++11 wrapping with cython.
Compile with python setup.py build_ext --inplace

@author: jerome thai

see
http://stackoverflow.com/questions/3046305/simple-wrapping-of-c-code-with-cython
'''

cimport numpy as np
import numpy as np


cdef extern from "arrays.h":
    void proj_l1ball(double *y, int start, int end)
    void proj_multi_l1ball_hack(double *y, double *blocks, int numblocks, int n)

def proj_l1ball_c(np.ndarray[np.double_t,ndim=1] y, start, end):
    cdef np.ndarray[np.double_t, ndim=1, mode="c"] y_c
    y_c = np.ascontiguousarray(y, dtype=np.double)
    proj_l1ball(&y_c[0], start, end)

def proj_multi_l1ball_c(np.ndarray[np.double_t,ndim=1] y,
    np.ndarray[np.double_t,ndim=1] blocks):
    cdef np.ndarray[np.double_t, ndim=1, mode="c"] y_c
    cdef np.ndarray[np.double_t, ndim=1, mode="c"] b_c
    y_c = np.ascontiguousarray(y, dtype=np.double)
    b_c = np.ascontiguousarray(blocks, dtype=np.double)
    proj_multi_l1ball_hack(&y_c[0], &b_c[0], blocks.shape[0], y.shape[0])
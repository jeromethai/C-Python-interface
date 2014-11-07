'''
Created on 5 nov. 2013

Example of C++11 wrapping with cython.
Compile with python setup.py build_ext --inplace

@author: jerome thai
'''

cimport libc.stdlib
import ctypes

# Linking with c code
cdef extern from "greatCircleCalculation.h":
    void run_great_circ_calc()

# Great circle calculation function that can be called from Python
def circ_print():
    run_great_circ_calc()

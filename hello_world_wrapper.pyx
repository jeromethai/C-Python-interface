'''
Created on 5 nov. 2014

Example of C++11 wrapping with cython.
Compile with python setup.py build_ext --inplace

@author: jerome thai
'''

cimport libc.stdlib
import ctypes

# Linking with c code
cdef extern from "hello_world.h":
    void print_hw()

# Hello world function that can be called from Python
def cython_print():
    print_hw()


'''
Created on 5 nov. 2013

@author: francois belletti
'''

from hello_world_wrapper import cython_print
from p1 import circ_print_python
import timeit


cython_print()
circ_print_python()
t = timeit.Timer("greatCircCalc_wrapper.circ_print()", "import greatCircCalc_wrapper")
print "Pure C++ function", t.timeit(1), "sec"
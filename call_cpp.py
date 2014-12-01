
'''
Created on 5 nov. 2014

@author: jerome thai
'''

from hello_world_wrapper import cython_print
from proj_l1ball_c import proj_l1ball_c, proj_multi_l1ball_c
from p1 import circ_print_python
import timeit
import numpy as np

#cython_print()
#circ_print_python()
#t = timeit.Timer("greatCircCalc_wrapper.circ_print()", "import greatCircCalc_wrapper")
#print "Pure C++ function", t.timeit(1), "sec"


y = np.array([5.352, 3.23, 32.78, -1.234, 1.7, 104., 53.])
print y
proj_l1ball_c(y, 2, 4)
print y


blocks = np.array([0.,2.,4.])
y2 = np.array([5.352, 3.23, 32.78, -1.234, 1.7, 104., 53.])
print y2
proj_multi_l1ball_c(y2, blocks)
print y2
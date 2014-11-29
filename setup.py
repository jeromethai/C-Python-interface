'''
Created on 5 nov. 2013

compile with command line 
python setup.py build_ext --inplace

@author: jerome thai
'''

import numpy

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

#sourcefiles = ["hello_world_wrapper.pyx"]
#sourcefiles = ["greatCircCalc_wrapper.pyx"]
sourcefiles = ["proj_l1ball_c.pyx"]
name1 = "hello_world_wrapper"
name2 = "greatCircCalc_wrapper"
name3 = "proj_l1ball_c"

setup(
    cmdclass = {"build_ext" : build_ext},
    ext_modules = [Extension(name3,
            sourcefiles,
            include_dirs = [numpy.get_include()],
                        language = 'c++',
            )]
)

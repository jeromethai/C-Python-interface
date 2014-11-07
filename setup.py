'''
Created on 5 nov. 2013

compile with command line 
python setup.py build_ext --inplace

@author: jerome thai
'''

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

#sourcefiles = ["hello_world_wrapper.pyx"]
sourcefiles = ["greatCircCalc_wrapper.pyx"]
name1 = "hello_world_wrapper"
name2 = "greatCircCalc_wrapper"

setup(
    cmdclass = {"build_ext" : build_ext},
    ext_modules = [Extension(name2,
            sourcefiles,
            include_dirs = ["."],
                        language = 'c++',
            )]
)

'''
Created on 5 nov. 2013

compile with command line 
python setup.py build_ext --inplace

@author: jerome thai
'''

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

sourcefiles = ["hello_world_wrapper.pyx"]

setup(
    cmdclass = {"build_ext" : build_ext},
    ext_modules = [Extension("hello_world_wrapper",
            sourcefiles,
            include_dirs = ["."],
                        language = 'c++',
            )]
)

from setuptools import find_packages
from setuptools import setup

setup(
    name='module_interface',
    version='0.0.0',
    packages=find_packages(
        include=('module_interface', 'module_interface.*')),
)

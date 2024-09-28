from setuptools import find_packages
from setuptools import setup

setup(
    name='can_msgs',
    version='2.0.0',
    packages=find_packages(
        include=('can_msgs', 'can_msgs.*')),
)

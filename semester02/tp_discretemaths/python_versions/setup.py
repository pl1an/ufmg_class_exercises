from setuptools import setup
from Cython.Build import cythonize
from setuptools.extension import Extension

# Define the extension module with the standalone executable
extensions = [
    Extension(
        "fractalplotter",                  # Name of the executable
        sources=["main.py"],          # Source file
        extra_compile_args=["-O2"],       # Optimization level
    )
]

setup(
    name="fractalplotter",
    ext_modules=cythonize(
        extensions,
        compiler_directives={"language_level": "3"},  # Python 3 compatibility
    ),
)

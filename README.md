# Register Machine

Register Machine is a C library to generate and execute register machine bytecode.
A register machine (<https://en.wikipedia.org/wiki/Register_machine>)is an alternative
to the stack machine used in many programming languages to interpret the code.

# Features

- Unlimited number of registers.
- 3-operand arithmetic operations.
- ANSI C compilant (No thread dispatching is used).
- Cross-platform static / shared library.
- Fast and efficient.
- Fully documented.

# Compiling the library

To compile the library you may use CMake. This library comes with
the necessary files to compile the library by using the main file
`CMakeLists.txt` found in the root directory.

# License

```
MIT License

Copyright (c) 2019 Erik Campobadal

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

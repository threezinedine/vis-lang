# A Visual Programming Language for System Dynamics Modeling

## Table of Contents

-   [A Visual Programming Language for System Dynamics Modeling](#a-visual-programming-language-for-system-dynamics-modeling)
    -   [Table of Contents](#table-of-contents)
    -   [Introduction](#introduction)
    -   [Features](#features)
    -   [Installation](#installation)
        -   [By cloning the repository](#by-cloning-the-repository)
            -   [Prerequisites](#prerequisites)
                -   [Windows](#windows)
                -   [Linux](#linux)
            -   [Compiling from source](#compiling-from-source)
    -   [Contact](#contact)

## Introduction

A lightweight visual programming language for system dynamics modeling. The language is designed to be simple and easy to use, with a focus on representing the data flow of a system visually. The main goal of the language is to provide the tools for illustrating the relationships between different components/threads/processes of a system, and to make it easier to understand how they interact with each other.

## Features

-   [ ] Static typing for variables
-   [ ] Blocks for representing different components of a system
-   [ ] Connections between blocks to represent data flow
-   [ ] Native support for multi-threading and parallel processing
-   [ ] Support modulization and reusability of code, with the ability to import/export modules for reuse (similar to libraries in other languages)
-   [ ] Built-in support for common data structures (lists, arrays, dictionaries, JSON, etc.)
-   [ ] Integrated with Python for scripting and data analysis
-   [ ] Native support for UI components (buttons, sliders, text fields, etc.) which each have their own block in the logic flow. This allows for easy creation of interactive applications with minimal code.

## Installation

### By cloning the repository

#### Prerequisites

##### Windows

Some prerequisites are required for Windows:

-   MinGW (can be installed using [MSYS2](https://www.msys2.org/))
-   CMake version 3.10 or later (can be installed using [CMake](https://cmake.org/))

##### Linux

No prerequisites are required for Linux.

#### Compiling from source

1. Clone the repository using the following command:

```cmd
git clone --recursive git@github.com:threezinedine/vis-lang.git
cd vis-lang
git submodule update --init --recursive
```

2. Create a build directory and navigate to it:

```cmd
mkdir build
cd build
```

3. Compile the project using CMake:

-   For Windows:

```cmd
cmake -G "MinGW Makefiles" -S .. -B . -DCMAKE_BUILD_TYPE=Release

mingw32-make
```

-   For Linux:

```bash
cmake -G "Unix Makefiles" -S .. -B . -DCMAKE_BUILD_TYPE=Release
make
```

5. The compiled executable will be located in the `build` directory with the name `VisLang`.
6. (Optional) for Linux, you can install the executable by running the following command:

```bash
sudo make install
```

7. (Optinal) If you want to generate the documentation, you can run the following command (you need to have Doxygen installed on your system in [Doxygen](http://www.doxygen.nl/)):

```bash
cd docs
doxygen Doxyfile
html/index.html
```

## Contact

If you have any questions or suggestions, feel free to contact me at [threezinedine@gmail.com](mailto:threezinedine@gmail.com).

```

```

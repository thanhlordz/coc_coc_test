# Robot Grid Movement Simulation

A C++ implementation of a robot that moves and draws lines on a 2D grid based on commands from an input file.

## Project Overview

This project demonstrates:
- Command pattern implementation
- File I/O handling
- 2D grid manipulation
- Object-oriented design principles

## Directory Structure

```
coc_coc_test/
├── app/                  # Contains executable
├── include/             # Header files
│   ├── command.hpp      # Command interface
│   ├── grid.hpp        # Grid class definition (Receiver)
│   ├── invoker.hpp     # Parsing Command definition (Invoker)
│   └── robot.hpp       # Robot class definition (Receiver)
├── src/                # Source files
│   ├── command.cpp
│   ├── grid.cpp
│   ├── invoker.cpp
│   ├── main.cpp
│   └── robot.cpp
└── input_file/         # Input files containing commands
    └── commands.txt
```

## Prerequisites

- C++17 compatible compiler
- CMake 3.15 or higher
- Windows operating system

## Building the Project

1. Create and build the project:
```batch
cmake -B build
cmake --build build
```

2. The executable `CocCoc_T.exe` will be generated in the `app` directory

## Input File Format

The `commands.txt` file should follow this format:
```
DIMENSION <grid_size>
MOVE_TO <x>, <y>
LINE_TO <x>, <y>
```

Example:
```
DIMENSION 5
MOVE_TO 1, 1
LINE_TO 3, 3
LINE_TO 3, 2
```

## Running the Program

Navigate to the app directory and run:
```batch
cd app
.\CocCoc_T.exe
```

## Command Description

- `DIMENSION`: Sets the size of the grid
- `MOVE_TO`: Moves the robot to specified coordinates
- `LINE_TO`: Draws a line from current position to specified coordinates
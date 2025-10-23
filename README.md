## Overview

Implementation of a robot that moves and draws lines on a 2D grid by executing commands from a text file (`commands.txt`). The program outputs the final grid to the console, marking unvisited cells with "." and drawn cells with "+".

**Input:** .txt files containing commands  
**Output:** Final grid printed to console

## Directory Structure

```
coc_coc_test/
├── app/                  # Contains executable
├── include/             # Header files
│   ├── command.hpp      # Command interface
│   ├── grid.hpp        # Grid class definition (Receiver)
│   ├── invoker.hpp     # Parsing command class definition (Invoker)
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

## Build & Run

```batch
cmake -B build
cmake --build build
cd app
.\CocCoc_T.exe
```

The executable CocCoc_T.exe will run the simulation and print the final grid.

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
## Example Output

The console should output like this:
```
. . . . .
. + . . .
. . + + .
. . . + .
. . . . .
```
- "." indicates an unvisited cell
- "+" marks cells visited while drawing lines with LINE_TO

## Command Description

- `DIMENSION`: Sets the size of the grid
- `MOVE_TO`: Moves the robot to specified coordinates
- `LINE_TO`: Draws a line from the current position to the target cell using the Bresenham line algorithm.

### Code Logic & Approach

1. Requirement Analysis

- Read commands from a text file and simulate a robot moving on an N×N grid.
- Commands: DIMENSION N, MOVE_TO x,y, LINE_TO x,y.
- Output: final grid with "." for unvisited cells and "+" for drawn cells.
- Constraints: robot starts at (0,0); coordinates must be in [0, N-1].

**Objective:** Read commands and simulate a robot moving on an N×N grid, with output showing drawn paths.

2. Object-Oriented Design (Command Pattern)

- **Entities:** Robot, Grid, Invoker, Command
- **Responsibilities:**
    - Robot → movement & line drawing
    - Grid → manages cells and printing
    - Command → encapsulates actions (execute())
    - Invoker → parses input and executes commands

Command Pattern:
- **Command Interface:** Defines execute() for all commands.
- **Concrete Commands:** DimensionCommand, MoveToCommand, LineToCommand. Each interacts with Robot/Grid and implements execute().
- **Receiver:** Robot and Grid handle actual movement and drawing.
- **Invoker:** Invoker class parses the input file, creates the appropriate command objects, and calls execute() on each.

This pattern enhances extensibility: adding a new command requires creating only a new concrete command class without modifying existing code.

3. Algorithm Choices

- **Bresenham Line Algorithm:** Used in LINE_TO to mark all cells along the line, including diagonals.
- **Grid Representation:** 2D vector of characters allows O(1) access for marking and printing.

## Overview

Implementation of a robot that moves and draws lines on a 2D grid by executing commands from a text file (`commands.txt`). The program outputs the final grid to the console, marking unvisited cells with "." and drawn cells with "+".

**Input:** .txt files containing commands  
**Output:** Final grid printed to console

## Directory Structure

```
coc_coc_test/
├── app/ # Contains executable
├── include/ # Header files
│ ├── command.hpp # Command interface
│ ├── grid.hpp # Grid class definition (Receiver)
│ ├── parser.hpp #  Parsing class (Invoker)
│ └── robot.hpp # Robot class definition (Receiver)
├── src/ # Source files
│ ├── command.cpp 
│ ├── grid.cpp
│ ├── parser.cpp
│ ├── main.cpp
│ └── robot.cpp
├── input_file/ # Input files containing commands
│ └── commands.txt
├── test/ # Unit tests
│ ├── test_grid.cpp # Grid class test
│ ├── test_robot.cpp # Robot class test
│ └── test_parser.hpp # Parser class test
└── test_framework # Contains GoogleTest git
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

## Code Logic & Approach

1. Requirement Analysis

- **Goal:** Simulate a robot moving and drawing on an N×N grid.
- **Commands:** DIMENSION N, MOVE_TO x,y, LINE_TO x,y.
- **Constraints:**
    - Robot starts at (0,0).
    - Coordinates must be within [0, N-1].
- **Output:** Final grid printed to the console with "." and "+".

2. Object-Oriented Design (Command Pattern)

- **Entities and Responsibilities:**

| Class       | Responsibility                                        |
| ----------- | ----------------------------------------------------- |
| **Robot**   | Executes movement and line drawing                    |
| **Grid**    | Stores and prints cell data                           |
| **Command** | Abstract interface for all commands (`execute()`)     |
| **Parser**  | Parses commands from the input file and executes them |

- **Command Pattern Structure:**
[Parser] → creates → [Command*] → execute() → [Robot / Grid]

    - Command Interface: Defines execute().

    - Concrete Commands:
        - DimensionCommand → sets grid size
        - MoveToCommand → moves robot
        - LineToCommand → draws line

    - Receivers: Robot and Grid handle actual execution.

    - Invoker: Reads input, creates commands, executes them in order.

    - Extensibility: To add a new command (e.g., CIRCLE_TO), define a new subclass of Command and register it in the Invoker.

3. Execution
```
[1] Parser reads line
    ↓
[2] Recognize command type
    ↓
[3] Create a Command object
    ↓
[4] Store in a list
    ↓
[5] Later: loop → cmd->execute()
```

## Testing

Unit testing is implemented using Google Test to verify core functionalities.

Test Execution:
```batch
cd app
.\test_runner.exe
```
Test Coverage
| Component   | Test Focus                                              |
| ----------- | ------------------------------------------------------- |
| **Grid**    | Initialization, marking, printing, and bounds checking  |
| **Robot**   | Movement accuracy, Bresenham line drawing correctness   |
| **Parser**  | Command parsing, invalid inputs, and sequence execution |

All tests are located under the test\ directory.

## Performance Notes

- Grid complexity: O(N²) memory usage — efficient for N ≤ 10⁴
- Line drawing complexity: O(length) per LINE_TO command
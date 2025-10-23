#include "command.hpp"

Dimension_Command::Dimension_Command(Grid &g, int N) : grid(g), size(N) {};

void Dimension_Command::execute(){
    grid.set_size(size);
};

Move_Command::Move_Command(Robot &r, int x, int y) : robot(r), pos_x(x), pos_y(y) {};

void Move_Command::execute(){
    robot.move_to(pos_x, pos_y);
}

Line_Command::Line_Command(Robot &r, int x, int y) : robot(r), sub_x(x), sub_y(y) {};

void Line_Command::execute(){
    robot.bresenham_line(robot.get_x(), robot.get_y(), sub_x, sub_y);
}
#include "robot.hpp"

Robot::Robot(Grid *grid) : grid(grid){};

void Robot::set_grid(Grid *grid){
    this->grid = grid;
}

void Robot::move_to(int x, int y){
    pos_x = x;
    pos_y = y;
}

void Robot::bresenham_line(int x0, int y0, int x1, int y1){
    int dx = x1 - x0;
    int dy = y1 - y0;
    int D = 2*dy - dx;
    int y = y0;

    for (int i = 0; i <= dx; i++){
        grid->mark(x0 + i, y);

        if(D > 0){
            y = y + 1;
            D = D - 2*dx;
        }
        D = D + 2*dy;
    }
}

int Robot::get_x() const{
    return pos_x;
};

int Robot::get_y() const{
    return pos_y;
};
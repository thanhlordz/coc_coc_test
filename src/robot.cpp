#include "robot.hpp"

Robot::Robot(Grid *g) : grid(g){};

void Robot::set_grid(Grid *g){
    grid = g;
}

void Robot::move_to(int x, int y){
    if(grid == nullptr) throw std::runtime_error("Grid isn't set for Robot");
    pos_x = x;
    pos_y = y;
}

void Robot::bresenham_line(int x0, int y0, int x1, int y1) {
    if(grid == nullptr) throw std::runtime_error("Grid isn't set for Robot");
    int dx = std::abs(x1 - x0);
    int dy = std::abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    bool steep = dy > dx;
    if (steep) std::swap(dx, dy);

    int err = 2 * dy - dx;
    for (int i = 0; i <= dx; ++i) {
        grid->mark(x0, y0);
        if (x0 == x1 && y0 == y1) break;

        while (err >= 0) {
            if (steep)
                x0 += sx;
            else
                y0 += sy;
            err -= 2 * dx;
        }

        if (steep)
            y0 += sy;
        else
            x0 += sx;

        err += 2 * dy;
    }
}


int Robot::get_x() const{
    return pos_x;
};

int Robot::get_y() const{
    return pos_y;
};
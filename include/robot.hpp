#ifndef ROBOT_H
#define ROBOT_H
#include "grid.hpp"

class Robot{
public:
    Robot(Grid *g);
    void set_grid(Grid *g);
    void move_to(int x, int y);
    void bresenham_line(int x1, int y1, int x2, int y2);

    int get_x() const;
    int get_y() const;

private:
    int pos_x{0}, pos_y{0};
    Grid *grid = nullptr;
};


#endif 
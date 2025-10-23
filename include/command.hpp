#ifndef COMMAND_H
#define COMMAND_H
#include "robot.hpp"
#include "grid.hpp"

class Command{
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class Dimension_Command : public Command{
public:
    Dimension_Command(Grid &g, int N);
    void execute() override;

private:
    Grid &grid;
    int size;
};

class Move_Command : public Command{
public:
    Move_Command(Robot &r, int x, int y);
    void execute() override;

private:
    Robot &robot;
    int pos_x, pos_y;
};

class Line_Command : public Command{
public:
    Line_Command(Robot &r, int x, int y);
    void execute() override;
    
private:
    Robot &robot;
    int sub_x, sub_y;
};
#endif
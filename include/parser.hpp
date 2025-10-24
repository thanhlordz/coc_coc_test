#ifndef INVOKER_H
#define INVOKER_H
#include "command.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "robot.hpp"

class Parser{
public:
    static std::vector<Command*> command_call(const std::string &filename, Grid &grid, Robot &robot);
};
#endif
#include "invoker.hpp"

std::vector<Command*> Parser::command_call(const std::string &filename, Grid &grid, Robot &robot){
    std::vector<Command*> commands;
    std::ifstream file(filename);
    if (!file.is_open()){
        throw std::runtime_error("Could not open file");
    }

    std::string line;

    while (std::getline(file, line)){
        for (char &c : line) if(c == ',') c = ' ';
        
        std::istringstream iss(line);
        std::string command_type;
        iss >> command_type;

        if (command_type == "DIMENSION"){
            int size;
            iss >> size;
            commands.push_back(new Dimension_Command(grid, size));
        }
        else if (command_type == "MOVE_TO"){
            int x, y;
            if (!(iss >> x >> y)) {
                throw std::runtime_error("Invalid command syntax: " + line);
            }
            commands.push_back(new Move_Command(robot, x, y));
        }
        else if (command_type == "LINE_TO"){
            int x, y;
            if (!(iss >> x >> y)) {
                throw std::runtime_error("Invalid command syntax: " + line);
            }
            commands.push_back(new Line_Command(robot, x, y));
        }
        else continue;
    }

    file.close();
    return commands;
}
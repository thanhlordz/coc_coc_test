#include "parser.hpp"

int is_positive_int(const std::string &s) {
    if (s.empty()) {
        throw std::invalid_argument("Value is empty");
    }

    int start = 0;
    if (s[0] == '+') {
        if (s.size() == 1)
            throw std::invalid_argument("Value contains only '+' sign");
        start = 1;
    } 
    else if (s[0] == '-') {
        throw std::invalid_argument("Negative integers are not allowed");
    }

    for (int i = start; i < static_cast<int>(s.size()); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) {
            throw std::invalid_argument("Value contains non-digit characters");
        }
    }

    int value = std::stoi(s);
    if (value <= 0) {
        throw std::invalid_argument("Value must be greater than 0");
    }

    return static_cast<int>(value);
}

std::vector<Command*> Parser::command_call(const std::string &filename, Grid &grid, Robot &robot) {
    std::vector<Command*> commands;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        for (char &c : line) {
            if (c == ',') c = ' ';
        }

        std::istringstream iss(line);
        std::string command_type;
        iss >> command_type;

        if (command_type.empty()) continue; // skip empty lines

        if (command_type == "DIMENSION") {
            std::string holder;
            if (!(iss >> holder)) {
                throw std::runtime_error("Missing size value in DIMENSION command");
            }

            int size = is_positive_int(holder);

            std::string extra;
            if (iss >> extra) {
                throw std::runtime_error("Too many arguments in DIMENSION command");
            }

            commands.push_back(new Dimension_Command(grid, size));
        }
        else if (command_type == "MOVE_TO" || command_type == "LINE_TO") {
            std::string x_str, y_str;
            if (!(iss >> x_str >> y_str)) {
                throw std::runtime_error("Missing coordinates in " + command_type);
            }

            int x = is_positive_int(x_str);
            int y = is_positive_int(y_str);

            std::string extra;
            if (iss >> extra) {
                throw std::runtime_error("Too many arguments in " + command_type);
            }

            if (command_type == "MOVE_TO") {
                commands.push_back(new Move_Command(robot, x, y));
            } else {
                commands.push_back(new Line_Command(robot, x, y));
            }
        }
        else {
            throw std::runtime_error("Unknown command: " + command_type);
        }
    }

    file.close();
    return commands;
}

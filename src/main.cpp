#include <iostream>
#include "parser.hpp"

int main(){
    Grid grid;
    Robot robot(&grid);

    try{
        std::vector<Command*> commands = Parser::command_call(COMMANDS_PATH, grid, robot);

        for (Command* cmd : commands){
            cmd->execute();
            delete cmd; 
        }

        grid.print();
    }
    catch (const std::exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
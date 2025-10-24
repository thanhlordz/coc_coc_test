#include "grid.hpp"

Grid::Grid(int N) : size(N), cells(N, std::vector<char>(N, '.')){}

int Grid::get_size() const{
    return size;
}

char Grid::get_cell(int x, int y) const{
    if (x < 0 || y < 0 || x >= size || y >= size) 
        throw std::out_of_range("Coordinate out of grid range");
    return cells[y][x];
}

void Grid::set_size(int N){
    if (N <= 0) throw std::runtime_error("Size must be a positive number");
    size = N;
    cells.assign(N, std::vector<char>(N, '.'));
}

void Grid::mark(int x, int y){
    if (x < 0 || y < 0 || x >= size || y >= size)
        throw std::out_of_range("Coordinate out of grid range"); 
    cells[y][x] = '+';
}

void Grid::print(){
    for (const auto& row : cells){
        for (const auto& column : row){
            std:: cout << column << ' ';
        }
        std:: cout << std::endl;
    }
}


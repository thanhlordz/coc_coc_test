#include "grid.hpp"

Grid::Grid(int N) : size(N), cells(N, std::vector<char>(N, '.')){}

int Grid::get_size() const{
    return size;
}

void Grid::set_size(int N){
    if (N <= 0) throw std::runtime_error("Size must be a positive number");
    size = N;
    cells.assign(N, std::vector<char>(N, '.'));
}

void Grid::mark(int x, int y){
    if (x >= 0 && x < size && y >= 0 && y < size) 
        cells[y][x] = '+';
}

void Grid::print(){
    for (const auto& row : cells){
        for (const auto& columm : row){
            std:: cout << columm << ' ';
        }
        std:: cout << std::endl;
    }
}


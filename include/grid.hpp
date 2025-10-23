#ifndef GRID_H
#define GRID_H
#include <vector>
#include <iostream>

class Grid {
public:
    Grid(int N=0);
    int get_size() const;
    void set_size(int N);
    void mark(int x, int y);
    void print();

private:
    int size;
    std::vector<std::vector<char>> cells;
};
#endif 
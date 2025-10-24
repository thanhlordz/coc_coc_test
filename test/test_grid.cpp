// === test_grid.cpp ===
#include <gtest/gtest.h>
#include "grid.hpp"
#include <sstream>

// Test: Set grid size and mark a cell
TEST(GridTest, test_set_size_and_mark_cell) {
    Grid grid;
    grid.set_size(3);
    grid.mark(1, 1);

    EXPECT_EQ(grid.get_cell(1, 1), '+');
    EXPECT_EQ(grid.get_cell(0, 0), '.');
}

// Test: Mark outside grid
TEST(GridTest, test_out_of_bounds) {
    Grid grid(2);
    EXPECT_THROW(grid.mark(-1, 0), std::out_of_range);
    EXPECT_THROW(grid.mark(2, 0), std::out_of_range);
    EXPECT_EQ(grid.get_cell(0, 0), '.');
}

// Test: Print grid
TEST(GridTest, test_print_output) {
    Grid grid(2);
    grid.mark(0, 0);
    grid.mark(1, 1);

    std::ostringstream out;
    std::streambuf* old = std::cout.rdbuf(out.rdbuf());
    grid.print();
    std::cout.rdbuf(old);

    EXPECT_EQ(out.str(), "+ . \n. + \n");
}

// Test: Invalid size
TEST(GridTest, test_invalid_grid_size) {
    Grid grid;
    EXPECT_THROW(grid.set_size(0), std::runtime_error);
    EXPECT_THROW(grid.set_size(-5), std::runtime_error);
}
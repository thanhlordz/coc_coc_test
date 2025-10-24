#include <gtest/gtest.h>
#include "robot.hpp"
#include "grid.hpp"

// Test: Robot starts at (0,0)
TEST(RobotTest, test_start_position) {
    Grid grid;
    grid.set_size(5);
    Robot robot(&grid);

    int pos_x = robot.get_x();
    int pos_y = robot.get_y();

    EXPECT_EQ(pos_x, 0);
    EXPECT_EQ(pos_y, 0);
}

// Test: MOVE_TO moves robot without drawing
TEST(RobotTest, test_move_to) {
    Grid grid;
    grid.set_size(5);
    Robot robot(&grid);

    robot.move_to(2, 3);

    int pos_x = robot.get_x();
    int pos_y = robot.get_y();

    EXPECT_EQ(pos_x, 2);
    EXPECT_EQ(pos_y, 3);

    // No drawing → all cells == '.'
    EXPECT_EQ(grid.get_cell(2, 3), '.');
}

TEST(RobotTest, test_bresenham_line) {
    Grid grid;
    grid.set_size(5);                  // 5x5 grid
    Robot robot(&grid);

    // draw from (0,0) to (3,3)
    robot.bresenham_line(0, 0, 3, 3);  

    // Check all cells on the diagonal line are marked '+'
    EXPECT_EQ(grid.get_cell(0, 0), '+');
    EXPECT_EQ(grid.get_cell(1, 1), '+');
    EXPECT_EQ(grid.get_cell(2, 2), '+');
    EXPECT_EQ(grid.get_cell(3, 3), '+');

    // Check robot moved to end point (3,3)
    EXPECT_EQ(robot.get_x(), 3);       
    EXPECT_EQ(robot.get_y(), 3);

    // Check unvisited cells are still '.'
    EXPECT_EQ(grid.get_cell(4, 0), '.');
    EXPECT_EQ(grid.get_cell(0, 4), '.');
}

// Test: Out of bounds
TEST(RobotTest, test_out_of_bounds) {
    Grid grid;
    grid.set_size(3);
    Robot robot(&grid);

    // Try move to (3,0) → out of range
    EXPECT_THROW(robot.move_to(3, 0), std::out_of_range);

    // Try draw to (3,0) → out of range
    EXPECT_THROW(robot.bresenham_line(0, 0, 3, 0), std::out_of_range);
}

// Test: Grid not set 
TEST(RobotTest, test_grid_not_set) {
    Robot robot(nullptr);  // no grid

    EXPECT_THROW(robot.move_to(1, 1), std::runtime_error);
    EXPECT_THROW(robot.bresenham_line(0, 0, 1, 1), std::runtime_error);
}
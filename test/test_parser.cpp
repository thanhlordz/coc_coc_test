#include <gtest/gtest.h>
#include "parser.hpp"
#include "command.hpp"   
#include <fstream>
#include <string>

// write content to a temp file
void write_file(const std::string& content, const std::string& file_name = "temp_input.txt") {
    std::ofstream file(file_name);
    file << content;
    file.close();
}

// delete temp file after test
void delete_file(const std::string& file_name = "temp_input.txt") {
    std::remove(file_name.c_str());
}

class ParserTest : public ::testing::Test {
public:
    void SetUp() override {
        grid = Grid();           
        robot = Robot(&grid);    // robot starts at (0,0)
    }

    void TearDown() override {
        delete_file();           // clean up file
    }

    Grid grid;
    Robot robot;
};

// TEST 1: Valid commands 
TEST_F(ParserTest, test_valid_commands) {
    write_file(R"(
        DIMENSION 4
        MOVE_TO 1, 2
        LINE_TO 3, 3
    )");

    EXPECT_NO_THROW({
        Parser::command_call("temp_input.txt", grid, robot);
    });
}

// TEST 2: Float value 
TEST_F(ParserTest, test_float_value) {
    write_file("MOVE_TO 1, 2.5\n");

    EXPECT_THROW({
        Parser::command_call("temp_input.txt", grid, robot);
    }, std::invalid_argument);
}

// TEST 3: Negative size 
TEST_F(ParserTest, test_negative_size) {
    write_file("DIMENSION -5\n");

    EXPECT_THROW({
        Parser::command_call("temp_input.txt", grid, robot);
    }, std::invalid_argument);
}

// TEST 4: Letters value 
TEST_F(ParserTest, test_letter_input) {
    write_file("MOVE_TO abc, 2\n");

    EXPECT_THROW({
        Parser::command_call("temp_input.txt", grid, robot);
    }, std::invalid_argument);
}

// TEST 5: Extra word after command 
TEST_F(ParserTest, test_extra_word) {
    write_file("MOVE_TO 1 2 hello\n");

    EXPECT_THROW({
        Parser::command_call("temp_input.txt", grid, robot);
    }, std::runtime_error);
}

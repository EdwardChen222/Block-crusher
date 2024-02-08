#pragma once
#include <ge211.hxx>
#include <iostream>
#include <position_set.hxx>
#include <brick.hxx>

class Board{
public:
    explicit Board();

    //returns the dimensions of a board
    ge211::Dims<int> dimensions() const;

    //returns true if a block is occupying the current position
    bool operator[](ge211::Posn<int> pos) const;

    //returns the color of the position of the board
    int get_color(ge211::Posn<int> pos) const;

    //checks if the certain row of the board is full
    bool check_row_occupied(int i) const;

    //checks if the game is over
    bool check_game_over() const;

    void add_position(ge211::Posn<int> pos);

    void add_color(ge211::Posn<int> pos, int num);

    void clear_row(int i);

    Position_set positions() const;
    static constexpr int board_height = 25;
    static constexpr int board_width  = 10;

    //function only for testing
    void remove_position(ge211::Posn<int> pos);

private:
    //stores the dimensions of the board
    ge211::Dims<int> dims;

    //stores which positions on the board are occupied
    Position_set occupied;

    //stores the index of the colors of each grid
    //when there is no block it is black
    int board_colors[board_width][board_height];
};
#pragma once
#include <ge211.hxx>
#include <iostream>
#include <position_set.hxx>
#include<board.hxx>

class Brick{
public:
    explicit Brick(ge211::Posn<int> pos, Position_set positions, int
    num);

    Brick rotate_left();

    Brick rotate_right();

    int get_color() const;

    Position_set get_positions() const;

    Brick move_left();

    Brick move_right();

    Brick move_up();

    Brick move_down();

    bool hit_left();

    bool hit_right();

    ge211::Posn<int> get_center() const;

private:
    ge211::Posn<int> center;

    Position_set positions_;

    int color_num;
};
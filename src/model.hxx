#pragma once

#include <ge211.hxx>
#include <board.hxx>
#include <brick.hxx>
#include <iostream>
#include <position_set.hxx>

class Model
{
public:
    explicit Model();

    Model(Model const& model);

    void set_game_over();

    bool is_game_over() const;

    int get_score() const;

    Brick new_random_brick();

    void increment_speed(int i);

    void increment_score(int i);

    void advanced_rotate_left();

    void advanced_rotate_right();

    void advanced_move_left();

    void advanced_move_right();

    void advanced_hit_bottom();

    Brick advanced_hit_bottom2() const;

    bool hits_something(Brick brick) const;

    //only use this function if checked if brick and board don't collide
    Position_set expected_land() const;

    Board board() const;

    Brick brick() const;

    bool check_brick_board_collide(Brick brick);

    bool get_game_status() const;

    //increment the frames passed, if frames passed > 30 (0.5s) then proceed

    void on_frame(double dt);

    //set a counter to count the number of lines cleared in this refresh
    //if the brick collides with anything on the board set the game to end
    //check if the brick is on any brick or is at the bottom
    //if it is set all the positions in brick to the board and set all the
    // colors
    //then check the numbers of rows full
    //add the numbers of the rows fulled to the counter
    //clear the fulled rows
    //make brick_ a random brick
    //if it isn't move down
    void refresh_model();

    const Position_set block[7]=
            {{{3,1},{4,1},{6,1},{5,1}},
             {{5,0},{6,0},{4,1},{5,1}},
             {{6,1},{5,0},{4,0},{5,1}},
             {{4,0},{5,0},{4,1},{5,1}},
             {{5,0},{4,1},{6,1},{5,1}},
             {{4,1},{6,1},{6,0},{5,1}},
             {{4,0},{4,1},{6,1},{5,1}}};

    const ge211::Color color[5] = {ge211::Color{255,0,0},
                                   ge211::Color{0,255,0},
                                   ge211::Color{0,0,255},
                                   ge211::Color{255,0,255},
                                   ge211::Color{0,0,0}};

    //these getter methods are only used for tests
    Board test_board();
    Brick test_brick();
    void add_board_position(ge211::Posn<int> pos);
    void remove_board_position(ge211::Posn<int> pos);
    void set_brick(ge211::Posn<int> pos, Position_set positions, int num);
    double get_loop_time();
    int get_lines_cleared();

private:
    Board board_;
    Brick brick_;
    int score_;
    int lines_cleared;
    double frames_passed;
    ge211::Random_source<int> random_brick_source;
    ge211::Random_source<int> random_color_source;
    double loop_time;
    bool game;
};

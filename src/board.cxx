#include "board.hxx"
using namespace ge211;

Board::Board()
    :dims({Board::board_width,Board::board_height}),
    occupied({})
{
    for (int i = 0; i < board_width; ++i) {
        for(int j = 0; j < board_height;j++){
            board_colors[i][j] = 4;
        }
    }
}

ge211::Dims<int>
Board::dimensions() const
{
    return dims;
}

bool
Board::operator[](ge211::Posn<int> pos) const
{
    return occupied[pos];
}

int
Board::get_color(ge211::Posn<int> pos) const
{
    return board_colors[pos.x][pos.y];
}

bool
Board::check_row_occupied(int i) const
{
    for(int j = 0;j < Board::board_width; j++)
    {
        if(!occupied[{j,i}])
        {
            return false;
        }
    }
    return true;
}

bool
Board::check_game_over() const
{
    for(int i = 0; i < Board::board_width; i++)
    {
        if(occupied[{i,0}])
        {
            return true;
        }
    }
    return false;
}

Position_set
Board::positions() const
{
    return occupied;
}

void
Board::add_position(ge211::Posn<int> pos)
{
    occupied[pos] = true;
}

void
Board::add_color(ge211::Posn<int> pos, int num)
{
    board_colors[pos.x][pos.y] = num;
}

void
Board::clear_row(int j)
{
    Position_set new_positions{};
    for(ge211::Posn<int> pos : positions())
    {
        if(pos.y < j)
        {
            new_positions[{pos.x, pos.y + 1}] = true;
            add_color({pos.x, pos.y + 1}, get_color(pos));
        }
        else if(pos.y > j)
        {
            new_positions[{pos.x, pos.y}] = true;
        }
        occupied = new_positions;
    }
}

void
Board::remove_position(ge211::Posn<int> pos)
{
    occupied[pos] = false;
}
#include "brick.hxx"
using namespace ge211;

Brick::Brick(ge211::Posn<int> pos,Position_set positions, int num)
    :center(pos),
    positions_(positions),
    color_num(num)
{
}

Brick
Brick::rotate_left()
{
    std::vector<ge211::Posn<int>> pset = {};
    Position_set positions{};
    ge211::Dims<int> diff;
    for(ge211::Posn<int> pos : positions_)
    {

        diff = pos - center;
        pos = {center.x + diff.height,
               center.y - diff.width};
        pset.push_back(pos);
    }
    int x_max_neg = 0;
    int y_max_neg = 0;
    int x_max_pos = Board::board_width - 1;
    int y_max_pos = Board::board_height - 1;
    for(ge211::Posn<int> pos : pset)
    {
        if(pos.x < x_max_neg)
        {
            x_max_neg = pos.x;
        }
        if(pos.x > x_max_pos)
        {
            x_max_pos = pos.x;
        }
        if(pos.y < y_max_neg)
        {
            y_max_neg = pos.y;
        }
        if(pos.y > y_max_pos)
        {
            y_max_pos = pos.y;
        }
    }
    x_max_pos = x_max_pos - (Board::board_width - 1);
    y_max_pos = y_max_pos - (Board::board_height - 1);
    for(ge211::Posn<int> pos : pset)
    {
        pos.x += -x_max_neg;
        pos.x -= x_max_pos;
        pos.y += -y_max_neg;
        pos.y -= y_max_pos;
        positions[pos] = true;
    }
    ge211::Posn<int> new_center = {center.x - x_max_neg - x_max_pos,
                                   center.y - y_max_neg - y_max_pos};
    Brick rotated_brick(new_center,positions,get_color());
    return rotated_brick;
}

Brick
Brick::rotate_right()
{
    std::vector<ge211::Posn<int>> pset = {};
    Position_set positions{};
    ge211::Dims<int> diff;
    for(ge211::Posn<int> pos : positions_)
    {

        diff = pos - center;
        pos = {center.x - diff.height,
               center.y + diff.width};
        pset.push_back(pos);
    }
    int x_max_neg = 0;
    int y_max_neg = 0;
    int x_max_pos = Board::board_width - 1;
    int y_max_pos = Board::board_height - 1;
    for(ge211::Posn<int> pos : pset)
    {
        if(pos.x < x_max_neg)
        {
            x_max_neg = pos.x;
        }
        if(pos.x > x_max_pos)
        {
            x_max_pos = pos.x;
        }
        if(pos.y < y_max_neg)
        {
            y_max_neg = pos.y;
        }
        if(pos.y > y_max_pos)
        {
            y_max_pos = pos.y;
        }
    }
    x_max_pos = x_max_pos - (Board::board_width - 1);
    y_max_pos = y_max_pos - (Board::board_height - 1);
    for(ge211::Posn<int> pos : pset)
    {
        pos.x += -x_max_neg;
        pos.x -= x_max_pos;
        pos.y += -y_max_neg;
        pos.y -= y_max_pos;
        positions[pos] = true;
    }
    ge211::Posn<int> new_center = {center.x - x_max_neg - x_max_pos,
                                   center.y - y_max_neg - y_max_pos};
    Brick rotated_brick(new_center,positions,get_color());
    return rotated_brick;
}

int
Brick::get_color() const
{
    return color_num;
}

Position_set
Brick::get_positions() const
{
    return positions_;
}

Brick
Brick::move_down()
{
    Position_set moved_positions{};
    ge211::Posn<int> moved_center = {center.x, center.y + 1};
    for(ge211::Posn<int> pos : positions_)
    {
        if(pos.y == Board::board_height-1)
        {
            return *this;
        }
    }
    for(ge211::Posn<int> pos : positions_)
    {
        moved_positions[{pos.x,pos.y + 1}] = true;
    }
    Brick moved_brick(moved_center, moved_positions, color_num);
    return moved_brick;
}

Brick
Brick::move_left()
{
    Position_set moved_positions{};
    ge211::Posn<int> moved_center = {center.x - 1, center.y};
    for(ge211::Posn<int> pos : positions_)
    {
        if(pos.x == 0)
        {
            return *this;
        }
    }
    for(ge211::Posn<int> pos : positions_)
    {
        moved_positions[{pos.x - 1,pos.y}] = true;
    }
    Brick moved_brick(moved_center, moved_positions, color_num);
    return moved_brick;
}

Brick
Brick::move_right()
{
    Position_set moved_positions{};
    ge211::Posn<int> moved_center = {center.x + 1, center.y};
    for(ge211::Posn<int> pos : positions_)
    {
        if(pos.x == Board::board_width-1)
        {
            return *this;
        }
    }
    for(ge211::Posn<int> pos : positions_)
    {
        moved_positions[{pos.x+1,pos.y}] = true;
    }
    Brick moved_brick(moved_center, moved_positions, color_num);
    return moved_brick;
}

Brick
Brick::move_up()
{
    Position_set moved_positions{};
    ge211::Posn<int> moved_center = {center.x, center.y - 1};
    for(ge211::Posn<int> pos : positions_)
    {
        if(pos.y == 0)
        {
            return *this;
        }
    }
    for(ge211::Posn<int> pos : positions_)
    {
        moved_positions[{pos.x,pos.y - 1}] = true;
    }
    Brick moved_brick(moved_center, moved_positions, color_num);
    return moved_brick;
}

bool
Brick::hit_left()
{
    for(ge211::Posn<int> pos : positions_)
    {
        if(pos.x < 0)
        {
            return true;
        }
    }
    return false;
}

bool
Brick::hit_right()
{
    for(ge211::Posn<int> pos : positions_)
    {
        if(pos.x == Board::board_width - 1)
        {
            return true;
        }
    }
    return false;
}

ge211::Posn<int>
Brick::get_center() const
{
    return center;
}

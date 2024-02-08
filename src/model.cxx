#include "model.hxx"

Model::Model()
    :board_(Board()),
    brick_({5,1},block[0],0),
    score_(0),
    lines_cleared(0),
    frames_passed(0),
     random_brick_source(0,6),
     random_color_source(0,3),
     loop_time(1),
     game(true)
{
}

Model::Model(Model const& model)
    :board_(model.board_),
    brick_(model.brick_),
    score_(model.score_),
    lines_cleared(model.lines_cleared),
    frames_passed(model.frames_passed),
     random_brick_source(0,6),
     random_color_source(0,3),
     loop_time(model.loop_time),
     game(true)
{}


bool
Model::is_game_over() const
{
    return board_.check_game_over();
}

int
Model::get_score() const
{
    return score_;
}

bool
Model::check_brick_board_collide(Brick brick)
{
    for(ge211::Posn<int> pos : brick.get_positions())
    {
        if(board_[pos])
        {
            return true;
        }
    }
    return false;
}

Board
Model::board() const
{
    return board_;
}

Brick
Model::brick() const
{
    return brick_;
}

void
Model::advanced_rotate_left()
{
    Brick tbrick = brick_.rotate_left();
    if(!check_brick_board_collide(tbrick))
    {
        brick_ = tbrick;
    }
    else
    {
        if(!check_brick_board_collide(tbrick.move_up()))
        {
            brick_ = tbrick.move_up();
        }
        else
        {
            if(!check_brick_board_collide(tbrick.move_down().move_left()))
            {
                brick_ = tbrick.move_down().move_left();
            }
            else
            {
                if(!check_brick_board_collide(tbrick.move_right()
                .move_right()))
                {
                    brick_ = tbrick.move_right().move_right();
                }
            }
        }
    }
}

void
Model::advanced_rotate_right()
{
    Brick tbrick = brick_.rotate_right();
    if(!check_brick_board_collide(tbrick))
    {
        brick_ = tbrick;
    }
    else
    {
        if(!check_brick_board_collide(tbrick.move_up()))
        {
            brick_ = tbrick.move_up();
        }
        else
        {
            if(!check_brick_board_collide(tbrick.move_down().move_left()))
            {
                brick_ = tbrick.move_down().move_left();
            }
            else
            {
                if(!check_brick_board_collide(tbrick.move_right()
                                                    .move_right()))
                {
                    brick_ = tbrick.move_right().move_right();
                }
            }
        }
    }
}

void
Model::advanced_move_left()
{
    Brick moved_brick = brick_.move_left();
    if(!check_brick_board_collide(moved_brick))
    {
        brick_ = moved_brick;
    }
}

void
Model::advanced_move_right()
{
    Brick moved_brick = brick_.move_right();
    if(!check_brick_board_collide(moved_brick))
    {
        brick_ = moved_brick;
    }
}

Brick
Model::new_random_brick()
{
    int block_num = random_brick_source.next();
    int color_num = random_color_source.next();
    Brick random_brick = Brick({5,1},
                               block[block_num],
                               color_num);
    return random_brick;
}

void
Model::increment_speed(int i)
{
    lines_cleared += i;
    if(lines_cleared >= 10)
    {
        lines_cleared -= 10;
        loop_time *= 0.9;
    }
}

void
Model::increment_score(int i)
{
    score_ += i * 10;
    if(i > 0)
    {
        score_ += (i - 1) * 10;
    }
}

void
Model::on_frame(double dt)
{
    if(game)
    {
        frames_passed += dt;
        if (frames_passed >= loop_time) {
            refresh_model();
            frames_passed = 0;
        }
    }
}

void
Model::refresh_model()
{
    bool flag = false;
    int current_lines_cleared = 0;
    if(check_brick_board_collide(brick_) || is_game_over()){
        set_game_over();
        ;
    }
    for(ge211::Posn<int> pos : brick_.get_positions())
    {

        if(pos.y == Board::board_height - 1 || board_[{pos.x,pos.y + 1}])
        {
            for(ge211::Posn<int> pos2 : brick_.get_positions())
            {
                board_.add_position(pos2);
                board_.add_color(pos2,brick_.get_color());
            }
            flag = true;
            break;
        }
    }
    if(flag)
    {
        //std::vector<int> rows = {};
        for(int i = 0; i < Board::board_height; i++)
        {
            if(board_.check_row_occupied(i))
            {
                current_lines_cleared++;
                board_.clear_row(i);
            }
        }
        increment_score(current_lines_cleared);
        increment_speed(current_lines_cleared);
        brick_ = new_random_brick();
    }
    else
    {
        brick_ = brick_.move_down();
    }
}

void
Model::set_game_over()
{
    game = false;
}

Brick
Model::advanced_hit_bottom2() const
{
    Brick changed_brick = brick_;
    while(!hits_something(changed_brick))
    {
        changed_brick = changed_brick.move_down();
    }
    return changed_brick;
}

void
Model::advanced_hit_bottom()
{
    brick_ = advanced_hit_bottom2();
}

Position_set
Model::expected_land() const
{
    Brick brick = advanced_hit_bottom2();
    return brick.get_positions();
}

bool
Model::hits_something(Brick brick) const
{
    for(ge211::Posn<int> pos : brick.get_positions())
    {
        if(pos.y == Board::board_height - 1 || board_[{pos.x,pos.y + 1}])
        {
            return true;
        }
    }
    return false;
}

bool
Model::get_game_status() const
{
    return game;
}

Board
Model::test_board()
{
    return board_;
}

Brick
Model::test_brick()
{
    return brick_;
}

void
Model::add_board_position(ge211::Posn<int> pos)
{
    board_.add_position(pos);
}

void
Model::remove_board_position(ge211::Posn<int> pos)
{
    board_.remove_position(pos);
}

void
Model::set_brick(ge211::Posn<int> pos, Position_set positions, int num)
{
    brick_ = Brick{pos, positions, num};
}


double
Model::get_loop_time()
{
    return loop_time;
}

int
Model::get_lines_cleared()
{
    return lines_cleared;
}
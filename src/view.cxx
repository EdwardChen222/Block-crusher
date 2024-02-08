#include "view.hxx"

int const grid_size = 20;
static ge211::Dims<int> grid_dims {grid_size, grid_size};
static ge211::Color const black_color{0,0,0};
static ge211::Color const grey_color{200,200,200};
static std::string str = "score : ";
View::View(Model const& model)
        : model_(model),
          background_sprite(boarddims, black_color),
          grid_sprites({}),
          expected_sprite(grid_dims,grey_color),
          return_sprite(str, ge211::Font("sans.ttf", 30)),
          flag(true)
{
    grid_sprites.push_back(ge211::Rectangle_sprite(grid_dims,model_.color[0]));
    grid_sprites.push_back(ge211::Rectangle_sprite(grid_dims,model_.color[1]));
    grid_sprites.push_back(ge211::Rectangle_sprite(grid_dims,model_.color[2]));
    grid_sprites.push_back(ge211::Rectangle_sprite(grid_dims,model_.color[3]));
}

void
View::draw(ge211::Sprite_set& set)
{
    set.add_sprite(background_sprite,{0,0},0);
    add_board_sprites(set);
    add_brick_sprites(set);
    add_expected_sprites(set);
    add_gameover_sprite(set);
}

void
View::add_board_sprites(ge211::Sprite_set& set)
{
    for(ge211::Posn<int> pos : model_.board().positions())
    {
        set.add_sprite(grid_sprites[model_.board().get_color(pos)],
                       board_to_screen(pos),
                       2);
    }
}

void
View::add_brick_sprites(ge211::Sprite_set& set)
{
    for(ge211::Posn<int> pos : model_.brick().get_positions())
    {
        set.add_sprite(grid_sprites[model_.brick().get_color()],
                       board_to_screen(pos),
                       2);
    }
}


void
View::add_expected_sprites(ge211::Sprite_set& set)
{
    for(ge211::Posn<int> pos : model_.expected_land())
    {
        set.add_sprite(expected_sprite, board_to_screen(pos), 1);
    }
}

void
View::add_gameover_sprite(ge211::Sprite_set& set)
{
    if(!model_.get_game_status())
    {
        if(flag)
        {
            str += std::to_string(model_.get_score());
            flag = false;
        }
        return_sprite = ge211::Text_sprite(str,
                                           ge211::Font("sans.ttf",
                                                       20));
        set.add_sprite(return_sprite,
                       {20,10}, 4);
    }
}


ge211::Posn<int>
View::board_to_screen(ge211::Posn<int> logical) const
{
return {logical.x * (grid_size + 2), logical.y * (grid_size + 2)};
}

ge211::Dims<int>
View::initial_window_dimensions() const
{
    return boarddims;
}

std::string
View::initial_window_title() const
{
    return "Tetris";
}
#pragma once

#include "model.hxx"

class View
{
public:
    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

    ge211::Dims<int> initial_window_dimensions() const;

    std::string initial_window_title() const;

private:
    Model const& model_;

    int const grid_size = 20;
    ge211::Dims<int> boarddims ={model_.board().dimensions().width *
                                  (grid_size + 2) - 2,
                                  model_.board().dimensions().height *
                                  (grid_size + 2) - 2};

    ge211::Rectangle_sprite const background_sprite;
    std::vector<ge211::Rectangle_sprite> grid_sprites;
    ge211::Rectangle_sprite const expected_sprite;
    ge211::Text_sprite return_sprite;

    void add_board_sprites(ge211::Sprite_set& set);

    void add_brick_sprites(ge211::Sprite_set& set);

    void add_expected_sprites(ge211::Sprite_set& set);

    void add_gameover_sprite(ge211::Sprite_set& set);

    ge211::Posn<int> board_to_screen(ge211::Posn<int> logical) const;

    bool flag;
};

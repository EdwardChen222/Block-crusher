#include "controller.hxx"

Controller::Controller()
        : model_(),
        view_(model_)
{}

void
Controller::on_key(ge211::Key key)
{
    if(key == ge211::Key::left())
    {
        model_.advanced_move_left();
    }
    if(key == ge211::Key::right())
    {
        model_.advanced_move_right();
    }
    if(key == ge211::Key::code('z'))
    {
        model_.advanced_rotate_left();
    }
    if(key == ge211::Key::code('c'))
    {
        model_.advanced_rotate_right();
    }
    if(key == ge211::Key::down())
    {
        model_.advanced_hit_bottom();
    }
}

ge211::Dims<int>
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string
Controller::initial_window_title() const
{
    return view_.initial_window_title();
}

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

void
Controller::on_frame(double dt)
{
    model_.on_frame(dt);
}

#include "brick.hxx"
#include <catch.hxx>
using namespace ge211;

TEST_CASE("Brick::Brick")
{
    Brick test_brick({5,1},
                     {{3,1},{4,1},{6,1},{5,1}},
                     1);
    CHECK(test_brick.get_center().x == 5);
    CHECK(test_brick.get_center().y == 1);

    CHECK(test_brick.get_positions()[{3,1}] == true);
    CHECK(test_brick.get_positions()[{4,1}] == true);
    CHECK(test_brick.get_positions()[{6,1}] == true);
    CHECK(test_brick.get_positions()[{5,1}] == true);
    CHECK(test_brick.get_color() == 1);
}

TEST_CASE("Brick::move_left")
{
    Brick test_brick({5,1},
                     {{3,1},{4,1},{6,1},{5,1}},
                     1);
    Brick b = test_brick.move_left();
    CHECK(b.get_center().x == 4);
    CHECK(b.get_center().y == 1);

    CHECK(b.get_positions()[{2,1}] == true);
    CHECK(b.get_positions()[{3,1}] == true);
    CHECK(b.get_positions()[{5,1}] == true);
    CHECK(b.get_positions()[{4,1}] == true);
    CHECK(b.get_positions()[{6,1}] == false);
    CHECK(b.get_color() == 1);

    b = b.move_left();

    CHECK(b.get_center().x == 3);
    CHECK(b.get_center().y == 1);

    CHECK(b.get_positions()[{1,1}] == true);
    CHECK(b.get_positions()[{2,1}] == true);
    CHECK(b.get_positions()[{4,1}] == true);
    CHECK(b.get_positions()[{3,1}] == true);
    CHECK(b.get_positions()[{5,1}] == false);
    CHECK(b.get_color() == 1);
}

TEST_CASE("Brick::move_right")
{
    Brick test_brick({5,1},
                     {{3,1},{4,1},{6,1},{5,1}},
                     1);
    Brick b = test_brick.move_right();
    CHECK(b.get_center().x == 6);
    CHECK(b.get_center().y == 1);

    CHECK(b.get_positions()[{4,1}] == true);
    CHECK(b.get_positions()[{5,1}] == true);
    CHECK(b.get_positions()[{7,1}] == true);
    CHECK(b.get_positions()[{6,1}] == true);
    CHECK(b.get_positions()[{8,1}] == false);
    CHECK(b.get_color() == 1);

    b = b.move_right();

    CHECK(b.get_center().x == 7);
    CHECK(b.get_center().y == 1);

    CHECK(b.get_positions()[{5,1}] == true);
    CHECK(b.get_positions()[{6,1}] == true);
    CHECK(b.get_positions()[{8,1}] == true);
    CHECK(b.get_positions()[{7,1}] == true);
    CHECK(b.get_positions()[{4,1}] == false);
    CHECK(b.get_color() == 1);
}
#include "model.hxx"
#include <catch.hxx>

TEST_CASE("Test left right moving, rotating and advanced rotating")
{
    /*
     *x represents occupied, b represents brick, e represents empty, in this
     * situation the brick should not be allowed to rotate
     * x    e   e   x
     * x    e   b   x
     * x    e   b   x
     * x    e   b   x
     * x    e   b   x
     * x    e   e   x
     * x    e   e   x
     * x    e   e   x  board_height - 1
     * */
    Model m;
    for(int i = 0; i < 8; i++)
    {
        m.add_board_position({0,Board::board_height - 1 -i});
        m.add_board_position({4,Board::board_height - 1 -i});
    }
    m.test_brick() = Brick({5, 1},
                                  m.block[0],
                                   0);
    m.advanced_move_left();
    for(int i = 0; i < 4; i++)
    {
        Position_set moved_pos = m.test_brick().get_positions();
        CHECK(moved_pos[{2 + i, 1}]);
    }
    m.advanced_move_left();
    for(int i = 0; i < 4; i++)
    {
        Position_set moved_pos = m.test_brick().get_positions();
        CHECK(moved_pos[{1 + i, 1}]);
    }
    m.advanced_move_left();
    for(int i = 0; i < 4; i++)
    {
        Position_set moved_pos = m.test_brick().get_positions();
        CHECK(moved_pos[{i, 1}]);
    }
    //when brick hits left side, should not move
    m.advanced_move_left();
    for(int i = 0; i < 4; i++)
    {
        Position_set moved_pos = m.test_brick().get_positions();
        CHECK(moved_pos[{i, 1}]);
    }
    //sets the position to be occupied at
    m.advanced_rotate_left();
    for(int i = 0; i < 4; i++)
    {
        Position_set moved_pos = m.test_brick().get_positions();
        CHECK(moved_pos[{2, i}]);
    }
    ge211::Posn<int> c = {2,1};
    CHECK(m.test_brick().get_center() == c);

    m.advanced_rotate_right();
    for(int i = 0; i < 4; i++)
    {
        Position_set moved_pos = m.test_brick().get_positions();
        CHECK(moved_pos[{i, 1}]);
    }
    m.advanced_rotate_right();
    for(int i = 0; i < 4; i++)
    {
        Position_set moved_pos = m.test_brick().get_positions();
        CHECK(moved_pos[{2, i}]);
    }
    ge211::Posn<int> c2 = {2,2};
    CHECK(m.test_brick().get_center() == c2);

    for(int j = 0; j < 17;j++)
    {
        m.refresh_model();
        for(int i = 0; i < 4; i++)
        {
            Position_set moved_pos = m.test_brick().get_positions();
            CHECK(moved_pos[{2, i + j + 1}]);
        }
    }
    //now the brick shouldn't move because the brick is "trapped"
    m.advanced_rotate_left();
    for(int i = 0; i < 4; i++)
    {
        Position_set moved_pos = m.test_brick().get_positions();
        CHECK(moved_pos[{2, i + 17}]);
    }
    ge211::Posn<int> c3 = {2,19};
    CHECK(m.test_brick().get_center() == c3);

    //also shouldn't move
    m.advanced_rotate_right();
    for(int i = 0; i < 4; i++)
    {
        Position_set moved_pos = m.test_brick().get_positions();
        CHECK(moved_pos[{2, i + 17}]);
    }
    CHECK(m.test_brick().get_center() == c3);

    //even though the center is one grid under the two open spots to rotate,
    //advanced rotate will automatically move one grid up
    m.remove_board_position({0,18});
    m.remove_board_position({3,18});
    m.advanced_rotate_left();
    for(int i = 0; i < 4; i++)
    {
        Position_set moved_pos = m.test_brick().get_positions();
        CHECK(moved_pos[{i, 18}]);
    }
}

TEST_CASE("Test if bricks correctly land on each other")
{
    Model m;
    for(int i = 0; i < 23; i++)
    {
        m.refresh_model();
    }
    for(int i = 0; i < 4; i++)
    {
        Position_set moved_pos = m.test_brick().get_positions();
        CHECK(moved_pos[{3 + i, 24}]);
    }
    //on this play the positions of the brick should be set to the board
    m.refresh_model();
    for(int i = 0; i < 4; i++)
    {
        CHECK(m.test_board()[{3 + i,24}]);
    }
    //
    ge211::Posn<int> c = {2,21};
    Position_set positions{{2,20},{2,21},
                           {2,22},{2,23}};
    m.set_brick(c,positions,0);
    m.refresh_model();
    for(int i = 0; i < 4; i++)
    {
        Position_set moved_pos = m.test_brick().get_positions();
        CHECK(moved_pos[{2, 21 + i}]);
    }
    m.refresh_model();
    m.refresh_model();
    for(int i = 0; i < 4; i++)
    {
        CHECK(m.test_board()[{2,21 + i}]);
    }
    ge211::Posn<int> c2 = {3,19};
    Position_set positions2{{2,19},{3,19},
                            {3,20},{3,21}};
    m.set_brick(c2,positions2,0);
    m.refresh_model();
    m.refresh_model();
    CHECK(m.test_board()[{2,20}]);
    CHECK(m.test_board()[{3,20}]);
    CHECK(m.test_board()[{3,21}]);
    CHECK(m.test_board()[{3,22}]);
}

TEST_CASE("test removing one line and seeing if the score and loop time is "
          "correct and if the block moves down")
{
    Model m;
    CHECK(m.get_score() == 0);
    CHECK(m.get_loop_time() == 1);
    //no rotation in this test so center is assigned randomly
    ge211::Posn<int> c = {3,19};
    Position_set positions{{0,24},{1,24},
                           {2,24},{3,24}};
    m.set_brick(c,positions,0);
    m.add_board_position({3,23});
    m.add_board_position({5,1});
    for(int i = 0; i < 6; i++) {
        m.add_board_position({4 + i, 24});
    }
    m.refresh_model();
    CHECK(m.get_score() == 10);
    CHECK(m.get_loop_time() == 1);
    CHECK(m.test_board()[{3,24}]);
    CHECK(m.test_board()[{5,2}]);
    m.test_board().remove_position({3,24});
    m.test_board().remove_position({5,2});
}

TEST_CASE("test removing ten lines and seeing if the score and loop time is "
          "correct")
{
    Model m;
    CHECK(m.get_score() == 0);
    CHECK(m.get_loop_time() == 1);
    //no rotation in this test so center is assigned randomly
    ge211::Posn<int> c = {3,19};
    Position_set positions{{0,24},{0,23},
                           {0,22},{0,21}};
    m.set_brick(c,positions,0);
    for(int i = 1; i < 10; i++) {
        m.add_board_position({i, 24});
    }
    for(int i = 1; i < 10; i++) {
        m.add_board_position({i, 23});
    }
    for(int i = 1; i < 10; i++) {
        m.add_board_position({i, 22});
    }
    for(int i = 1; i < 10; i++) {
        m.add_board_position({i, 21});
    }
    m.refresh_model();
    CHECK(m.get_lines_cleared() == 4);
    CHECK(m.get_score() == 70);
    CHECK(m.get_loop_time() == 1);
    m.set_brick(c,positions,0);
    for(int i = 1; i < 10; i++) {
        m.add_board_position({i, 24});
    }
    for(int i = 1; i < 10; i++) {
        m.add_board_position({i, 23});
    }
    for(int i = 1; i < 10; i++) {
        m.add_board_position({i, 22});
    }
    for(int i = 1; i < 10; i++) {
        m.add_board_position({i, 21});
    }
    m.refresh_model();
    CHECK(m.get_lines_cleared() == 8);
    CHECK(m.get_score() == 140);
    CHECK(m.get_loop_time() == 1);

    m.set_brick(c,positions,0);
    for(int i = 1; i < 10; i++) {
        m.add_board_position({i, 24});
    }
    for(int i = 1; i < 10; i++) {
        m.add_board_position({i, 23});
    }
    for(int i = 1; i < 10; i++) {
        m.add_board_position({i, 22});
    }
    for(int i = 1; i < 10; i++) {
        m.add_board_position({i, 21});
    }
    m.refresh_model();
    CHECK(m.get_lines_cleared() == 2);
    CHECK(m.get_score() == 210);
    CHECK(m.get_loop_time() == 0.9);
}

TEST_CASE("playing the game till death")
{
    Model m;
    ge211::Posn<int> c = {0,0};
    Position_set positions = {{4,24},{4,23},
                              {4,22},{4,21}};
    m.set_brick(c,positions,0);
    m.refresh_model();
    positions = {{4,20},{4,19},{4,18},{4,17}};
    m.set_brick(c,positions,0);
    m.refresh_model();
    positions = {{4,16},{4,15},{4,14},{4,13}};
    m.set_brick(c,positions,0);
    m.refresh_model();
    positions = {{4,12},{4,11},{4,10},{4,9}};
    m.set_brick(c,positions,0);
    m.refresh_model();
    positions = {{4,8},{4,7},{4,6},{4,5}};
    m.set_brick(c,positions,0);
    m.refresh_model();
    positions = {{4,4},{4,3},{4,3},{4,2},
                 {4,1},{4,0}};
    m.set_brick(c,positions,0);
    m.refresh_model();
    CHECK(m.is_game_over());
}
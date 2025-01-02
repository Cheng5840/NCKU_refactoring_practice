#include <assert.h>
#include <stdio.h>
#include "../game_logic.h"

// 測試處理移動
void test_process_move() {
    GameState state = {
        .screen = {
            {'X', 'X', 'X', 'X', 'X'},
            {'X', '.', '.', '.', 'X'},
            {'X', '.', '@', '$', 'X'},
            {'X', '.', '.', 'E', 'X'},
            {'X', 'X', 'X', 'X', 'X'},
        },
        .pos_x = 2,
        .pos_y = 2,
    };

    process_move(&state, 1, 0); // 向右移動
    assert(state.pos_x == 3);
    assert(state.pos_y == 2);
    assert(state.gems_collected == 1);
    assert(state.screen[2][2] == ' ');
    assert(state.screen[2][3] == '@');
    printf("move right correct!\n");

    process_move(&state, 0, 1); // 向下移動到出口
    assert(state.pos_x == 3);
    assert(state.pos_y == 3);
    assert(state.won == 1);
    assert(state.screen[3][3] == '@');

    printf("test_process_move passed!\n");
}

// 測試處理玩家輸入
void test_handle_player() {
    GameState state = {
        .screen = {
            {'X', 'X', 'X', 'X', 'X'},
            {'X', '.', '.', '.', 'X'},
            {'X', '.', '@', '$', 'X'},
            {'X', '.', '.', 'E', 'X'},
            {'X', 'X', 'X', 'X', 'X'},
        },
        .pos_x = 2,
        .pos_y = 2,
        .key = 3, // 向右
    };

    handle_player(&state);
    assert(state.pos_x == 3);
    assert(state.pos_y == 2);
    assert(state.gems_collected == 1);
    assert(state.screen[2][2] == ' ');
    assert(state.screen[2][3] == '@');

    state.key = 2; // 向下
    handle_player(&state);
    assert(state.pos_x == 3);
    assert(state.pos_y == 3);
    assert(state.won == 1);
    assert(state.screen[3][3] == '@');

    printf("test_handle_player passed!\n");
}

int main() {
    test_process_move();
    test_handle_player();
    return 0;
}

#include <assert.h>
#include <stdio.h>
#include "../game_logic.h"

// 測試靜止岩石處理
void test_handle_rocks() {
    GameState state = {
        .screen = {
            {'X', 'X', 'X', 'X', 'X'},
            {'X', ' ', 'O', ' ', 'X'},
            {'X', ' ', ' ', ' ', 'X'},
            {'X', 'X', 'X', 'X', 'X'},
        },
    };

    handle_rocks(&state, 2, 1);
    assert(state.screen[1][2] == 'o');
    printf("test_handle_rocks passed!\n");
}

// 測試下落岩石處理
void test_handle_falling_rocks() {
    GameState state = {
        .screen = {
            {'X', 'X', 'X', 'X', 'X'},
            {'X', ' ', 'o', 'o', 'X'},
            {'X', ' ', ' ', '@', 'X'},
            {'X', 'X', 'X', 'X', 'X'},
        },
        .dead = 0,
    };

    handle_falling_rocks(&state, 2, 1);
    assert(state.screen[1][2] == ' ');
    assert(state.screen[2][2] == 'o');
    assert(state.dead == 0);

    handle_falling_rocks(&state, 3, 1);
    assert(state.dead == 1);
    printf("test_handle_falling_rocks passed!\n");
}

// 測試更新所有元素
void test_update_all_elements() {
    GameState state = {
        .screen = {
            {'X', 'X', 'X', 'X', 'X'},
            {'X', ' ', '$', 'o', 'X'},
            {'X', ' ', ' ', '@', 'X'},
            {'X', 'X', 'X', 'X', 'X'},
        },
        .dead = 0,
    };

    initialize_element_handlers();
    update_all_elements(&state);

    assert(state.screen[1][2] == 'S');
    assert(state.screen[1][3] == 'o');
    assert(state.dead == 1);

    printf("test_update_all_elements passed!\n");
}

int main() {
    test_handle_rocks();
    test_handle_falling_rocks();
    test_update_all_elements();
    return 0;
}

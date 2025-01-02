#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../game_logic.h"


void test_move_player() {
    // 初始化遊戲狀態
    GameState state = {
        .screen = {
            {'X', 'X', 'X', 'X', 'X'},
            {'X', '.', '.', '.', 'X'},
            {'X', '.', '@', '$', 'X'},
            {'X', '.', '.', 'E', 'X'},
            {'X', 'X', 'X', 'X', 'X'},
        },
        .pos_x = 2, // 玩家初始位置 // 第幾col
        .pos_y = 2,                // 第幾row
    };

    // 測試向右移動到寶石
    move_player(&state, 1, 0);
    assert(state.pos_x == 3); // 玩家應移動到 (2, 3)
    assert(state.pos_y == 2);
    assert(state.gems_collected == 1); // 應收集到 1 顆寶石
    assert(state.screen[2][2] == ' '); // 原位置應變為空
    assert(state.screen[2][3] == '@'); // 新位置為玩家
    printf("move right correct!\n");

    // 測試向下移動到出口
    move_player(&state, 0, 1);
    assert(state.pos_x == 3); // 玩家應移動到 (3, 3)
    assert(state.pos_y == 3);
    assert(state.won == 1);   // 玩家應達到勝利條件
    assert(state.screen[3][3] == '@'); // 新位置為玩家

    printf("test_move_player passed!\n");
}


int main() {
    test_move_player(); // 測試移動功能
    return 0;
}

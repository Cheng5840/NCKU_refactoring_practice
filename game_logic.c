#include "game_logic.h"

// 處理玩家移動的共用邏輯
void process_move(GameState* state, int dx, int dy) {
    int target_x = state->pos_x + dx;
    int target_y = state->pos_y + dy;
    char target_cell = state->screen[target_y][target_x];

    switch (target_cell) {
        case '$': // 收集寶石
            state->gems_collected++;
            /* fall through */
        case ' ': // 空格
        case '.': // 泥土
            state->screen[state->pos_y][state->pos_x] = ' ';
            state->screen[target_y][target_x] = '@';
            state->pos_x = target_x;
            state->pos_y = target_y;
            break;
        case 'E': // 出口
            state->screen[state->pos_y][state->pos_x] = ' ';
            state->screen[target_y][target_x] = '@';
            state->pos_x = target_x;
            state->pos_y = target_y;
            state->won = 1;
            break;
        case 'o': // 下落岩石
        case 'S': // 下落寶石
            state->dead = 1;
            break;
        case 'O': // 推動岩石
            if (state->screen[target_y][target_x + dx] == ' ') {
                state->screen[target_y][target_x + dx] = 'O';
                state->screen[state->pos_y][state->pos_x] = ' ';
                state->screen[target_y][target_x] = '@';
                state->pos_x = target_x;
                state->pos_y = target_y;
            }
            break;
        default:
            break;
    }
}

// 處理玩家輸入
void handle_player(GameState* state) {
    switch (state->key) {
        case 1: process_move(state, 0, -1); break; // 上
        case 2: process_move(state, 0, 1); break;  // 下
        case 3: process_move(state, 1, 0); break;  // 右
        case 4: process_move(state, -1, 0); break; // 左
        default: break;
    }
}

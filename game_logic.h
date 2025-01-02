#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

// 遊戲狀態結構
typedef struct {
    int key;                // 玩家輸入
    int pos_x, pos_y;       // 玩家位置
    unsigned int count;     // 更新次數
    int gems_collected;     // 收集的寶石數
    int dead;               // 玩家是否死亡
    int won;                // 玩家是否贏得遊戲
    char old_screen[26][60]; // 上一幀畫面
    char screen[26][60];     // 當前畫面
} GameState;

// 遊戲邏輯函數
void initialize_element_handlers();
void handle_rocks(GameState* state, int x, int y);
void handle_falling_rocks(GameState* state, int x, int y);
void for_each_screen_element(GameState* state, void (*callback)(GameState*, int, int));
void process_element(GameState* state, int x, int y);
void update_all_elements(GameState* state);
void process_move(GameState* state, int dx, int dy);
void handle_player(GameState* state);

#endif // GAME_LOGIC_H

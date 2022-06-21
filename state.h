#ifndef _SNK_STATE_H
#define _SNK_STATE_H

#include <stdbool.h>
#include <stdio.h>

typedef struct snake_t {
  unsigned int tail_x;
  unsigned int tail_y;
  unsigned int head_x;
  unsigned int head_y;

  bool live;
} snake_t;

const unsigned int board_width = 10;
const unsigned int board_length = 14;
const unsigned int board_snake_num = 1;
const unsigned int fruit_row = 2;
const unsigned int fruit_col = 9;
const unsigned int tail_row = 4;
const unsigned int tail_col = 4;
const unsigned int head_row = 4;
const unsigned int head_col = 5;

typedef struct game_state_t {
  unsigned int x_size;
  unsigned int y_size;

  char **board;

  unsigned int num_snakes;
  snake_t* snakes;
} game_state_t;

game_state_t* create_default_state();
void free_state(game_state_t* state);
void print_board(game_state_t* state, FILE* fp);
void save_board(game_state_t* state, char* filename);
void update_state(game_state_t* state, int (*add_food)(game_state_t* state));
game_state_t * initialize_snakes(game_state_t* state);
game_state_t* load_board(char* filename);

#endif

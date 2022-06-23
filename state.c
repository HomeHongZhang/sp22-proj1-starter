#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snake_utils.h"
#include "state.h"

static const unsigned int board_x = 14;
static const unsigned int board_y = 10;
static const unsigned int board_snake_num = 1;
static const unsigned int fruit_x = 9;
static const unsigned int fruit_y = 2;
static const unsigned int tail_x = 4;
static const unsigned int tail_y = 4;
static const unsigned int head_x = 5;
static const unsigned int head_y = 4;

/* Helper function definitions */
static char get_board_at(game_state_t* state, int x, int y);
static void set_board_at(game_state_t* state, int x, int y, char ch);
static bool is_tail(char c);
static bool is_snake(char c);
static char body_to_tail(char c);
static int incr_x(char c);
static int incr_y(char c);
static void find_head(game_state_t* state, int snum);
static char next_square(game_state_t* state, int snum);
static void update_tail(game_state_t* state, int snum);
static void update_head(game_state_t* state, int snum);

/* Helper function to get a character from the board (already implemented for you). */
static char get_board_at(game_state_t* state, int x, int y) {
  return state->board[y][x];
}

/* Helper function to set a character on the board (already implemented for you). */
static void set_board_at(game_state_t* state, int x, int y, char ch) {
  state->board[y][x] = ch;
}

/* Task 1 */
game_state_t* create_default_state() {
  // TODO: Implement this function.
  game_state_t * state_ptr = (game_state_t *)malloc(sizeof(struct game_state_t));
  state_ptr->x_size = board_x;
  state_ptr->y_size = board_y;
  state_ptr->board = (char**)malloc(state_ptr->y_size*sizeof(char*));
  for (int idx = 0; idx < state_ptr->y_size; idx++)
  {
    state_ptr->board[idx] = (char*)malloc(state_ptr->x_size*sizeof(char));
  }

  // create the wall
  for (int i = 0; i < state_ptr->y_size; i++)
  {
    for (int j = 0; j < state_ptr->x_size; j++)
    {
      if (i == 0 || j == 0 || i == state_ptr->y_size-1 || j == state_ptr->x_size-1)
      {
        state_ptr->board[i][j] = '#';
        continue;
      }
      state_ptr->board[i][j] = ' ';
    }
  }

  // the fruit
  state_ptr->board[fruit_y][fruit_x] = '*';

  state_ptr->num_snakes = board_snake_num;
  state_ptr->snakes = (snake_t*)malloc(state_ptr->num_snakes*sizeof(struct snake_t));
  state_ptr->snakes[0].tail_x = tail_x;
  state_ptr->snakes[0].tail_y = tail_y;
  state_ptr->snakes[0].head_x = head_x;
  state_ptr->snakes[0].head_y = head_y;
  state_ptr->snakes[0].live = true;
  state_ptr->board[tail_y][tail_y] = 'd';
  state_ptr->board[head_y][head_x] = '>';

  return state_ptr;
}

/* Task 2 */
void free_state(game_state_t* state_ptr) {
  // TODO: Implement this function.
  free(state_ptr->snakes);
  state_ptr->snakes = NULL;

  for (int i = 0; i < state_ptr->y_size; i++)
  {
    free(state_ptr->board[i]);
    state_ptr->board[i] = NULL;
  }

  free(state_ptr->board);
  state_ptr->board = NULL;

  return;
}

/* Task 3 */
void print_board(game_state_t* state, FILE* fp) {
  // TODO: Implement this function.
  if (fp == NULL) 
  {
    fprintf(stderr, "%s", "Open file failed\n");
    return;
  } 

  for (int i = 0; i < state->y_size; i++)
  {
    for (int j = 0; j < state->x_size; j++)
    {
      fprintf(fp, "%c", state->board[i][j]);
    }
    fprintf(fp, "\n");
  }

  return;
}

/* Saves the current state into filename (already implemented for you). */
void save_board(game_state_t* state, char* filename) {
  FILE* f = fopen(filename, "w");
  print_board(state, f);
  fclose(f);
}

/* Task 4.1 */
static bool is_tail(char c) {
  // TODO: Implement this function.
  return true;
}

static bool is_snake(char c) {
  // TODO: Implement this function.
  return true;
}

static char body_to_tail(char c) {
  // TODO: Implement this function.
  return '?';
}

static int incr_x(char c) {
  // TODO: Implement this function.
  return 0;
}

static int incr_y(char c) {
  // TODO: Implement this function.
  return 0;
}

/* Task 4.2 */
static char next_square(game_state_t* state, int snum) {
  // TODO: Implement this function.
  return '?';
}

/* Task 4.3 */
static void update_head(game_state_t* state, int snum) {
  // TODO: Implement this function.
  return;
}

/* Task 4.4 */
static void update_tail(game_state_t* state, int snum) {
  // TODO: Implement this function.
  return;
}

/* Task 4.5 */
void update_state(game_state_t* state, int (*add_food)(game_state_t* state)) {
  // TODO: Implement this function.
  return;
}

/* Task 5 */
game_state_t* load_board(char* filename) {
  // TODO: Implement this function.
  return NULL;
}

/* Task 6.1 */
static void find_head(game_state_t* state, int snum) {
  // TODO: Implement this function.
  return;
}

/* Task 6.2 */
game_state_t* initialize_snakes(game_state_t* state) {
  // TODO: Implement this function.
  return NULL;
}

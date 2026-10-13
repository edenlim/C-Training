#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include <string.h>

#define ROW_SIZE 3
#define COL_SIZE 3

// --- Define Type
typedef struct {
  char grid[ROW_SIZE][COL_SIZE];
} Board;

// --- Function Prototypes
void print_board(Board b);
Board create_board(void);
bool exist_empty_cell(Board b);
int validate_input(const char[]);
bool check_cell_is_empty(Board b, int row, int col);
void get_input(Board *b);
bool check_score(Board b);
void print_winner(char c);

// --- Global Variable
int player = 1;
bool game_over = false;
bool winner_exists = false;

// --- Main
int main(void) {
  Board my_board = create_board();
  print_board(my_board);

  bool has_empty_cell = exist_empty_cell(my_board);
  while (has_empty_cell && !game_over) {
    char alphabet = (player > 0) ? 'A' : 'B';
    printf("Player %c's turn\n", alphabet);
    get_input(&my_board);
    print_board(my_board);

    player *= -1;
    game_over = check_score(my_board);
    has_empty_cell = exist_empty_cell(my_board);
  }
  if (!winner_exists) {
    printf("Game is over! No one won!");
  }

  return 0;
}

// --- Custom function
Board create_board() {
  Board board = {0};
  // clang-format off
  // Board board = {{{'\0', '\0', '\0'}, {'\0', '\0', '\0'}, {'\0', '\0', '\0'}}}; // --- Explicit way of declaring
  // clang-format on
  return board;
}
bool exist_empty_cell(Board b) {
  for (int row = 0; row < ROW_SIZE; row++) {
    for (int col = 0; col < COL_SIZE; col++) {
      if (b.grid[row][col] == '\0') {
        return true;
      }
    }
  }
  return false;
}

void print_board(Board b) {
  char output[100] = "";
  for (int row = 0; row < ROW_SIZE; row++) {
    for (int col = 0; col < COL_SIZE; col++) {
      char value_of_cell = b.grid[row][col];
      if (value_of_cell == '\0') {
        strcat(output, "[ ]");
      } else {
        char temp[10];
        snprintf(temp, sizeof(temp), "[%c]", value_of_cell);
        strcat(output, temp);
      }
    }
    strcat(output, "\n");
  }
  printf("%s", output);
}

int validate_input(const char *prompt) {
  char input_buffer[32];
  int coordinate;

  while (true) {
    printf("%s", prompt);
    if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL) {
      if (sscanf(input_buffer, "%d", &coordinate) == 1 && coordinate >= 0 &&
          coordinate <= 2) {
        return coordinate; // Valid integer returned
      }
    }

    printf("Invalid! Must be an integer between 0 and 2.\n");
  }
}

bool check_cell_is_empty(Board b, int row, int col) {
  if (b.grid[row][col] == '\0') {
    return true;
  } else {
    return false;
  }
}

void get_input(Board *b) {
  char token = (player > 0) ? 'X' : 'O';
  while (true) {
    int row_selected = validate_input("Select your row:\n");
    int col_selected = validate_input("Select your col:\n");
    bool cell_is_empty = check_cell_is_empty(*b, row_selected, col_selected);
    if (cell_is_empty) {
      b->grid[row_selected][col_selected] = token;
      return;
    } else {
      printf("Invalid position, it is already occupied\n");
    }
  }
}

bool check_score(Board b) {
  for (int row = 0; row < ROW_SIZE; row++) {
    if (b.grid[row][0] != '\0' && b.grid[row][0] == b.grid[row][1] &&
        b.grid[row][1] == b.grid[row][2]) {
      print_winner(b.grid[row][0]);
      return true; // Returns 'X' or 'O'
    }
  }

  // 2. Check all 3 Columns
  for (int col = 0; col < COL_SIZE; col++) {
    if (b.grid[0][col] != '\0' && b.grid[0][col] == b.grid[1][col] &&
        b.grid[1][col] == b.grid[2][col]) {
      print_winner(b.grid[0][col]);
      return true;
    }
  }

  // 3. Check Main Diagonal (Top-Left to Bottom-Right)
  if (b.grid[0][0] != '\0' && b.grid[0][0] == b.grid[1][1] &&
      b.grid[1][1] == b.grid[2][2]) {
    print_winner(b.grid[0][0]);
    return true;
  }

  // 4. Check Anti-Diagonal (Top-Right to Bottom-Left)
  if (b.grid[0][2] != '\0' && b.grid[0][2] == b.grid[1][1] &&
      b.grid[1][1] == b.grid[2][0]) {
    print_winner(b.grid[0][2]);
    return true;
  }

  // No winner yet
  return false;
}

void print_winner(char token) {
  winner_exists = true;
  if (token == 'X') {
    printf("Player 1 Wins!");
  } else {
    printf("Player 2 Wins!");
  }
}
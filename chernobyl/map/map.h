#ifndef MAP_H
#define MAP_H

#define MAX_ROWS 10
#define MAX_COLS 10

// --- Type Definition Structure
typedef struct {
  const char *grid[MAX_ROWS][MAX_COLS];
  int rows;
  int cols;
  const char *name;
} Floor;

// --- Function Prototype
void print_floor(const Floor *f);
void print_centered_cell(const char *location, int width);
int calculate_floor_box_len(const Floor *f);

#endif
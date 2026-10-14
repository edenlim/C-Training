#include "map.h"
#include "stdio.h"
#include "string.h"

// --- print floor Function
void print_floor(const Floor *floor) {
  // clang-format off
  for (int row = 0; row < floor->rows; row++) {
    for (int col = 0; col < floor->cols; col++) {
      print_centered_cell(floor->grid[row][col],calculate_floor_box_len(floor));
    }
    printf("\n");
  }
  // clang-format on
}

void print_centered_cell(const char *text, int width) {
  if (text == NULL) {
    text = "";
  }

  int text_length = (int)strlen(text);
  if (text_length >= width) {
    printf("[%s]", text);
    return;
  }

  int total_padding = width - text_length;
  int left_padding = total_padding / 2;
  int right_padding = total_padding - left_padding;

  printf("[%*s%s%*s]", left_padding, "", text, right_padding, "");
}

int calculate_floor_box_len(const Floor *f) {
  int len = 0;
  for (int row = 0; row < f->rows; row++) {
    for (int col = 0; col < f->cols; col++) {
      const char *cell = f->grid[row][col];
      if (cell != NULL) {
        int cell_len = (int)strlen(cell);
        if (cell_len > len) {
          len = cell_len;
        }
      }
    }
  }
  return len + 2;
}

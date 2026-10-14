#include "map/map.h"
#include "stdio.h"
#include "string.h"

// --- Main
int main(void) {
  // clang-format off
  Floor ground_floor = {
    .rows = 3,
    .cols = 3,
    .name = "Ground Floor",
    .grid = {
      {"lift", "lobby", "office"},
      {"cafeteria", "registration", "toilet"},
      {"", "entrance", ""}
    }
  };
  // clang-format on
  print_floor(&ground_floor);
  return 0;
}

// clang -Wall chernobyl/main.c chernobyl/map/map.c -o ./chernobyl/main
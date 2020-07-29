#include <stdio.h>

int main(int argc, char const * argv[]) {

  int mtx[][4] = {        //  matrix
    { 0, 10, 20, 30, },
    { 1, 11, 21, 31, },
    { 2, 12, 22, 32, },
    { 3, 13, 23, 33, },
  };
  size_t const mtx_s = sizeof(mtx);                         //  size
  size_t const mtx_r = sizeof(mtx) / sizeof(mtx[0]);        //  rows
  size_t const mtx_c = sizeof(mtx[0]) / sizeof(mtx[0][0]);  //  columns
  size_t const mtx_z = mtx_r * mtx_c;                       //  cells

  int (*row)[mtx_c];      // pointer to array of mtx_c elements
  size_t const row_s = sizeof(*row);                        //  size
  size_t const row_e = sizeof(*row) / sizeof(int);          //  elements

  printf("mtx - size: %zu, rows: %zu, cols: %zu, cells: %zu\n", mtx_s, mtx_r, mtx_c, mtx_z);
  printf("row = size: %zu, elements in each array: %zu\n", row_s, row_e);

  row = mtx;  // let pointer to array -> mtx[0][0]

  //  loop over mtx and display address of each row
  printf("mtx address: ");
  for (size_t r_ = 0; r_ < mtx_r; ++r_) {
    printf("[%zu][0] %p ", r_, &mtx[r_][0]);
  }
  putchar('\n');
  
  //  loop over row and show address of each element
  printf("row address: ");
  for (size_t r_ = 0; r_ < mtx_r; ++r_) {
    printf("[%zu]    %p ", r_, row[r_]);
  }
  putchar('\n');
  
  //  loop over row and show address by dereferencing
  printf("row address: ");
  for (size_t r_ = 0; r_ < mtx_r; ++r_) {
    printf("*+%zu    %p ", r_, *row++);
  }
  putchar('\n');

  //  loop over mtx row by row
  for (size_t r_ = 0; r_ < mtx_r; ++r_) {
    // loop over mtx rows and display each column element
    printf("mtx[%zu] - %p: ", r_, &mtx[r_][0]);
    for (size_t c_ = 0; c_ < mtx_c; ++c_) {
      printf("%2d ", mtx[r_][c_]);
    }
    putchar('\n');

    //  loop over a row and display each column element
    row = mtx;  // reset row pointer to array -> mtx[0][0]
    printf("row[%zu] - %p: ", r_, row[r_]);
    for (size_t c_ = 0; c_ < mtx_c; ++c_) {
      printf("%2d ", row[r_][c_]);
    }
    putchar('\n');

    //  loop over a row and display each column via dereferencing
    row += r_;  // index row pointer to current row
    printf("*row+%zu - %p: ", r_, *row);
    int * e_ = *row;
    for (size_t c_ = 0; c_ < mtx_c; ++c_) {
      printf("%2d ", *e_++);
    }
    putchar('\n');
  }

  return 0;
}

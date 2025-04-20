#include "Sudoku.h"
int isValidSudoku(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        int used[10] = {0}; 
        for (int j = 0; j < 9; j++) {
            int num = board[i][j];
            if (num < 1 || num > 9) {
                return 0; 
            }
            
            if (used[num]) {
                return 0; 
            }
            used[num] = 1; 
        }
    }
    
    for (int j = 0; j < 9; j++) {
        int used[10] = {0};
        for (int i = 0; i < 9; i++) {
            int num = board[i][j];
            if (used[num]) {
                return 0;
            }
            used[num] = 1;
        }
    }
    
    for (int box_i = 0; box_i < 3; box_i++) {
        for (int box_j = 0; box_j < 3; box_j++) {
            int used[10] = {0};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = board[box_i * 3 + i][box_j * 3 + j];
                    if (used[num]) {
                        return 0;
                    }
                    used[num] = 1;
                }
            }
        }
    }
    
    return 1;
}

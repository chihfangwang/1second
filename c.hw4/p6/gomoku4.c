#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 19  
#define EMPTY '.'
#define BLACK '1'
#define WHITE '0'

char board[MAX_SIZE][MAX_SIZE];
int size;  

const int dx[4] = {1, 0, 1, 1};
const int dy[4] = {0, 1, 1, -1};

void posToCoord(int x, int y, char *buf) {
    sprintf(buf, "(%c, %2d)", 'A' + x, y + 1);
}

bool isValid(int x, int y) {
    return x >= 0 && x < size && y >= 0 && y < size;
}

bool isPiece(int x, int y, char piece) {
    return isValid(x, y) && board[y][x] == piece;
}

bool isEmpty(int x, int y) {
    return isValid(x, y) && board[y][x] == EMPTY;
}

bool isOpponent(int x, int y, char piece) {
    return isValid(x, y) && board[y][x] != EMPTY && board[y][x] != piece;
}

bool findDeadFour() {
    bool found = false;
    
    for (char piece = BLACK; piece >= WHITE; piece--) {
        
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                
                if (board[y][x] != piece) continue;
                
                for (int dir = 0; dir < 4; dir++) {
                    int count = 1;
                    int tx = x, ty = y;
                    
                    for (int i = 0; i < 3; i++) {
                        tx += dx[dir];
                        ty += dy[dir];
                        if (isPiece(tx, ty, piece)) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    
                    if (count == 4) {
                        int fx = x + 4 * dx[dir];
                        int fy = y + 4 * dy[dir];
                        
                        int bx = x - dx[dir];
                        int by = y - dy[dir];
                        
                        bool forwardBlocked = !isValid(fx, fy) || isOpponent(fx, fy, piece);
                        bool backwardBlocked = !isValid(bx, by) || isOpponent(bx, by, piece);
                        bool forwardEmpty = isValid(fx, fy) && isEmpty(fx, fy);
                        bool backwardEmpty = isValid(bx, by) && isEmpty(bx, by);
                        
                        if ((forwardBlocked && backwardEmpty) || (backwardBlocked && forwardEmpty)) {
                            if (!found) {
                                printf("Dead Four found: ");
                                found = true;
                            } else {
                                printf("\nDead Four found: ");
                            }
                            
                            char buf[10];
                            for (int i = 0; i < 4; i++) {
                                int px = x + i * dx[dir];
                                int py = y + i * dy[dir];
                                posToCoord(px, py, buf);
                                printf("%s ", buf);
                            }
                        }
                    }
                }
            }
        }
    }
    
    return found;
}

int main() {
    char line[100];
    int row = 0;
    
    while (fgets(line, sizeof(line), stdin) && line[0] != '\n') {
        int col = 0;
        for (int i = 0; line[i] && line[i] != '\n'; i++) {
            if (line[i] != ' ') {  
                board[row][col++] = line[i];
            }
        }
        size = col > size ? col : size; 
        row++;
    }
    size = row > size ? row : size;  
    
    if (!findDeadFour()) {
        printf("Dead Four does not exist.\n");
    } else {
        printf("\n");
    }
    
    return 0;
}

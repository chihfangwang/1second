#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 19  
#define EMPTY 2       
#define BLACK 1        
#define WHITE 0       

typedef struct {
    int x;
    int y;
} Position;

int readBoardFromStream(FILE* file, int board[MAX_SIZE][MAX_SIZE]) {
    if (file == NULL) {
        printf("Live three does not exist.\n");
        return 0;
    }

    for (int i = 0; i < MAX_SIZE; i++)
        for (int j = 0; j < MAX_SIZE; j++)
            board[i][j] = EMPTY;

    char line[MAX_SIZE * 2 + 1];
    int row = 0;

    while (fgets(line, sizeof(line), file) && row < MAX_SIZE) {
        int len = strlen(line);
        int col = 0;

        for (int i = 0; i < len && col < MAX_SIZE; i++) {
            if (line[i] == '1') board[row][col++] = BLACK;
            else if (line[i] == '0') board[row][col++] = WHITE;
            else if (line[i] == '.') board[row][col++] = EMPTY;
        }
        row++;
    }

    return row;
}

bool isLiveThree(int board[MAX_SIZE][MAX_SIZE], int size, int color, Position stones[3]) {
    for (int i = 0; i < 3; i++) {
        int x = stones[i].x;
        int y = stones[i].y;
        if (x < 0 || x >= size || y < 0 || y >= size || board[y][x] != color)
            return false;
    }

    int dx = stones[1].x - stones[0].x;
    int dy = stones[1].y - stones[0].y;

    if (stones[2].x - stones[1].x != dx || stones[2].y - stones[1].y != dy)
        return false;

    Position start = {stones[0].x - dx, stones[0].y - dy};
    Position end = {stones[2].x + dx, stones[2].y + dy};

    if (start.x < 0 || start.x >= size || start.y < 0 || start.y >= size ||
        end.x < 0 || end.x >= size || end.y < 0 || end.y >= size)
        return false;

    return board[start.y][start.x] == EMPTY && board[end.y][end.x] == EMPTY;
}

void findLiveThree(int board[MAX_SIZE][MAX_SIZE], int size) {
    bool found = false;

    for (int color = 0; color <= 1; color++) {
        for (int y = 0; y < size; y++)
            for (int x = 0; x < size - 2; x++) {
                Position stones[3] = {{x, y}, {x+1, y}, {x+2, y}};
                if (isLiveThree(board, size, color, stones)) {
                    printf("Live three found: ");
                    printf("(%c, %2d)(%c, %2d)(%c, %2d)\n", x+'A', y+1, x+1+'A', y+1, x+2+'A', y+1);
                    found = true;
                }
            }

        for (int x = 0; x < size; x++)
            for (int y = 0; y < size - 2; y++) {
                Position stones[3] = {{x, y}, {x, y+1}, {x, y+2}};
                if (isLiveThree(board, size, color, stones)) {
                    printf("Live three found: ");
                    printf("(%c, %2d)(%c, %2d)(%c, %2d)\n", x+'A', y+1, x+'A', y+2, x+'A', y+3);
                    found = true;
                }
            }

        for (int y = 0; y < size - 2; y++)
            for (int x = 0; x < size - 2; x++) {
                Position stones[3] = {{x, y}, {x+1, y+1}, {x+2, y+2}};
                if (isLiveThree(board, size, color, stones)) {
                    printf("Live three found: ");
                    printf("(%c, %2d)(%c, %2d)(%c, %2d)\n", x+'A', y+1, x+1+'A', y+2, x+2+'A', y+3);
                    found = true;
                }
            }

        for (int y = 0; y < size - 2; y++)
            for (int x = 2; x < size; x++) {
                Position stones[3] = {{x, y}, {x-1, y+1}, {x-2, y+2}};
                if (isLiveThree(board, size, color, stones)) {
                    printf("Live three found: ");
                    printf("(%c, %2d)(%c, %2d)(%c, %2d)\n", x+'A', y+1, x-1+'A', y+2, x-2+'A', y+3);
                    found = true;
                }
            }
    }

    if (!found)
        printf("Live three does not exist.\n");
}

int main(int argc, char* argv[]) {
    FILE* input = stdin;

    if (argc == 2) {
        input = fopen(argv[1], "r");
        if (!input) {
            perror("Failed to open file");
            return 1;
        }
    } else if (argc > 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    int board[MAX_SIZE][MAX_SIZE];
    int size = readBoardFromStream(input, board);

    if (argc == 2)
        fclose(input);

    if (size > 0)
        findLiveThree(board, size);

    return 0;
}

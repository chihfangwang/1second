#include <stdio.h>
#include "Score.h"
int main(){
    hw score;
    int input;
    printf("Please input 10 scores: ");
    for(int i = 0; i < 10; i++){
        scanf(" %d", &input);
        if(input < 0 || input > 100){
            printf("Invalid score\n");
            return 0;
        } else {
            score.scores[i] = input;
        }
    }
    hw processed = processScore(score);
    printf("Processing [done]\n");
    printf("Average: %0.1lf\n", processed.average);
    printf("Highest: %d\n", processed.highest);
    printf("Lowest: %d\n", processed.lowest);
}
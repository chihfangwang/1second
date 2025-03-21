#include "Score.h"

hw processScore(hw score) {
    hw processed = score;
    
    processed.highest = score.scores[0];
    processed.lowest = score.scores[0];
    
    double sum = 0;
    
    for (int i = 0; i < 10; i++) {
        sum += score.scores[i];
        
        if (score.scores[i] > processed.highest) {
            processed.highest = score.scores[i];
        }
        
        if (score.scores[i] < processed.lowest) {
            processed.lowest = score.scores[i];
        }
    }
    
    processed.average = sum / 10;
    
    return processed;
}

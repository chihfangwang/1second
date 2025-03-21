#include <stdio.h>
#include "TimeAdder.h"

void addTime(Time t1, Time t2) {
    Time result;
    
    result.second = t1.second + t2.second;
    
    result.minute = t1.minute + t2.minute + (result.second / 60);
    result.second %= 60;
    
    result.hour = t1.hour + t2.hour + (result.minute / 60);
    result.minute %= 60;
    
    printf("%02d:%02d:%02d\n", result.hour, result.minute, result.second);
}

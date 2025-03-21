#include <stdio.h>
#include "LocalData.h"

locinfo_t Local_Initialize() {
    locinfo_t tmp;
    
    for (int i = 0; i < 50; i++) {
        tmp.city[i] = '\0';
        tmp.district[i] = '\0';
    }
    tmp.weather.environ = UNDEFINED;
    tmp.weather.temperature = 0.0;

    return tmp;
}

int main() {
    locinfo_t local;

    local = Local_Initialize();
    local = Local_SetCity(local);
    local = Local_SetDistrict(local);
    local = Local_SetWeather(local);

    Local_Describe(local);

    return 0;
}
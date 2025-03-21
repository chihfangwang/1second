#include <stdio.h>
#include <string.h>
#include "LocalData.h"
locinfo_t Local_SetCity(locinfo_t local) {
    printf("City? ");
    fgets(local.city, 50, stdin);
    int len = strlen(local.city);
    if (len > 0 && local.city[len-1] == '\n') {
        local.city[len-1] = '\0';
    }
    return local;
}
locinfo_t Local_SetDistrict(locinfo_t local) {
    printf("District? ");
    fgets(local.district, 50, stdin);
    int len = strlen(local.district);
    if (len > 0 && local.district[len-1] == '\n') {
        local.district[len-1] = '\0';
    }
    return local;
}
locinfo_t Local_SetWeather(locinfo_t local) {
    int weather_input;
    
    printf("Weather (1: Sunny, 2: Rainy, 3: Snowy, 4: Cloudy)? ");
    scanf("%d", &weather_input);
    switch (weather_input) {
        case 1:
            local.weather.environ = SUNNY;
            break;
        case 2:
            local.weather.environ = RAINY;
            break;
        case 3:
            local.weather.environ = SNOWY;
            break;
        case 4:
            local.weather.environ = CLOUDY;
            break;
        default:
            local.weather.environ = UNDEFINED;
            break;
    }
    printf("Temperature? ");
    scanf("%lf", &local.weather.temperature);
    return local;
}
void Local_Describe(locinfo_t local) {
    char city_display[50];
    if (strlen(local.city) == 0) {
        strcpy(city_display, "Unknown");
    } else {
        strcpy(city_display, local.city);
    }
    char district_display[50];
    if (strlen(local.district) == 0) {
        strcpy(district_display, "Unknown");
    } else {
        strcpy(district_display, local.district);
    }
    char environ_display[20];
    switch (local.weather.environ) {
        case SUNNY:
            strcpy(environ_display, "Sunny");
            break;
        case RAINY:
            strcpy(environ_display, "Rainy");
            break;
        case SNOWY:
            strcpy(environ_display, "Snowy");
            break;
        case CLOUDY:
            strcpy(environ_display, "Cloudy");
            break;
        case UNDEFINED:
        default:
            strcpy(environ_display, "Unknown");
            break;
    }
    double temp = local.weather.temperature;
    temp = (int)(temp * 100 + 0.5) / 100.0;
    printf("In the city of %s, located in the district of %s, the weather is currently %s with a temperature of %.2f degrees.\n", 
           city_display, district_display, environ_display, temp);
}

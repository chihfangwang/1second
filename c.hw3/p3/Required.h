typedef enum {
    UNDEFINED,
    SUNNY,
    RAINY,
    SNOWY,
    CLOUDY
} env_t;

typedef struct {
    env_t environ;
    double temperature;
} weather_t;

typedef struct {
    char city[50];
    char district[50];
    weather_t weather;
} locinfo_t;

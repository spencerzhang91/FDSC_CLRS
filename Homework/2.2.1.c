/* E2.2.1.c */
/* Using struct to represent planets in solar system */
#define N 20

struct planet {
    char name[N];
    long double distance;
    int moons;
};

struct planet Earth = {
    "Earth",
    92955887.62,
    1
};

struct planet Vinus = {
    "Vinus",
    67232363.00,
    0
};


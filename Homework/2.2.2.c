/* Exercise 2.2.2.c */
#include <stdio.h>

typedef struct {
    int month;
    int day;
    int year;
} Date;

typedef struct {
    enum gender {female, male};
    union {
            int children;
            int beard;
          } u;
} Sex;

typedef struct {;} Single;
typedef struct {Date dvc; int times;} Divorced;
typedef struct {Date died; Date mrd;} Widowed;
typedef struct {Date mrd;} Married;
    
typedef struct {    
    enum marriage_state {
        S, M,
        D, W
    };
    
    union states{
        Single sgstate;
        Married mrdstate;
        Divorced dvcstate;
        Widowed wdstate;
    };
} Marriage;
typedef struct {
    char name[10];
    int age;
    float salary;
    Date dob;
    Sex sexinfo;
    Marriage ms;
} Human;

int main(void)
{
    
    
    return 0;
}

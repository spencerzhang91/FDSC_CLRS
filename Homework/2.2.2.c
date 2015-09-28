/* Exercise 2.2.2.c */
#include <stdio.h>
#include <string.h>

typedef struct {
    int month;
    int day;
    int year;
} Date;

enum gender {female, male};

typedef struct {
    enum gender gst;
    union u {
            int children;
            int beard;
          };
} Sex;

typedef struct {;} Single;
typedef struct {Date dvc; int times;} Divorced;
typedef struct {Date died; Date mrd;} Widowed;
typedef struct {Date mrd;} Married;

enum marriage_state {S, M, D, W};
  
typedef struct {
    enum marrige_state mst;
    
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

int main()
{
    Human p1;
    p1.name = "Bob";
	p1.age = 44;
	p1.salary = 101010.0;
	p1.dob.day = 1;
	p1.dob.month = 1;
	p1.dob.year = 1943;
	p1.sexinfo.gst = male;
	p1.ms.mst = M;
	p1.ms.states.mrdstate.mrd.day = 1;
	p1.ms.states.mrdstate.mrd.month = 1;
	p1.ms.states.mrdstate.mrd.year = 2005;
    
    return 0;
}


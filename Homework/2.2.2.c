/* Exercise 2.2.2.c */
#include <stdio.h>
#include <string.h>

typedef struct {
    int month;
    int day;
    int year;
} Date;

enum gender {female, male};
union su {
    int children;
    int beard;
};

typedef struct {
    enum gender gst;
    union su sex_state;
} Sex;

typedef struct {;} Single;
typedef struct {Date dvc; int times;} Divorced;
typedef struct {Date died; Date mrd;} Widowed;
typedef struct {Date mrd;} Married;

enum marriage_state {single, married, divorced, widowed};

union mar_state {
    Single sgstate;
    Married mrdstate;
    Divorced dvcstate;
    Widowed wdstate;
};

typedef struct {
    enum marriage_state mrgst;
    union mar_state mst;
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
	p1.age = 44;
	p1.salary = 101010.0;
	p1.dob.day = 1;
	p1.dob.month = 1;
	p1.dob.year = 1943;
	p1.sexinfo.gst = male;
	p1.ms.mrgst = married;
	p1.ms.mst.mrdstate.mrd.day = 1;
	p1.ms.mst.mrdstate.mrd.month = 1;
	p1.ms.mst.mrdstate.mrd.year = 1111;
	
    return 0;
}


/* The maze problem project*/
/* project 3.3.5.c */
#include <stdio.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100
#define EXIT_ROW 6
#define EXIT_COL 6

typedef struct {                             // move struct (8 directions)
	short int vert;
	short int horiz;
} offsets;

offsets move[8] = {{-1,0}, {-1,1}, {0,1}, {1,1},
                   {1,0}, {1,-1}, {0,-1}, {-1,-1}};

typedef struct {
	short int row;
	short int col;
	short int dir;
} element;

element stack[MAX_STACK_SIZE];
/* 2d array representation of maze */
int maze[6][6] = {{0,0,0,0,0,1}, {1,1,1,1,1,0},
                  {1,0,0,0,0,1}, {0,1,1,1,1,1},
                  {1,0,0,0,0,1}, {1,1,1,1,1,0}};
/* record visited move */
int mark[6][6] = {{0,0,0,0,0,0}, {0,0,0,0,0,0},
                  {0,0,0,0,0,0}, {0,0,0,0,0,0},
                  {0,0,0,0,0,0}, {0,0,0,0,0,0}};
/* The maze problem project*/
/* project 3.3.5.c */
#include <stdio.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100
#define EXIT_ROW 6
#define EXIT_COL 6

void path(void);

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

int main(void)
{
	return 0;
}

void path(void)
{
	/* output a path through the maze if such a path exists */
	int i, row, col, next_row, next_col, dir;
	bool found = false;
	element position;
	mark[1][1] = 1;
	top = 0; // a global variable defined outside of path()
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 1;
	while (top > -1 && !found)
	{
		position = delete(&top);
		row = position.row;
		col = position.col;
		dir = position.dir;
		while (dir < 8 && !found)
		{
			/* move in direction dir */
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;
			if (next_row == EXIT_ROW && next_col == EXIT_COL)
				found = true;
			else if (!maze[next_row][next_col] && !mark[next_row][next_col])
			{
				mark[next_row][next_col] = 1;
				position.row = row;
				position.col = col;
				position.dir = ++dir;
				add(&top, position);
				row = next_row;
				col = next_col;
				dir = 0;
			}
			else
				++dir;
		}
	}
	if (found)
	{
		printf("The path is:\n");
		printf("row  col");
		for (i = 0; i <= top; i++)
			printf("%2d%5d", stack[i].row, stack[i].col);
		printf("%2d%5d\n", row, col);
		printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
	}
	else
		printf("The maze does not have a path.\n");
}
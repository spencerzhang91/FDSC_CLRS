/* 4-10, 4-11, 4-12 */
/* On page 98 to 100 of book FDSC */
#define COMPARE(x, y) ((x)>=(y))? (((x)>(y))? 1: 0): -1

struct Node {
	int coef;
	int expo;
	struct Node next;
};

typedef struct Node *Linked;

Linked padd(Linked a, Linked b)
{
	/* return a poly which is sum of a & b */
	int sum;
	Linked front, rear, temp;
	rear = (Linked)malloc(sizeof(struct Node));
	front = rear;
	while (a & b)
		switch (COMPARE(a->expo, b->expo))
		{
			case -1: // a->expo < b->expo
				attach(b->coef, b->expo, &rear);
				b = b->next;
				break;
			case 0: // a->expo == b->expo
				sum = a->coef + b->coef;
				if (sum)
					attach(sum, a->expo, &rear);
				a = a->next;
				b = b->next;
			case 1: // a->expo > b->expo
				attach(a->coef, a->expo, &rear)
				a = a->next;
		}
		/* copy rest of list a and then list b */
		for (; a; a = a->next)
			attach(a->coef, a->expo, &rear);
		for (; b; b = b->next)
			attach(b->coef, b->expo, &rear);
		rear->next = NULL;
		/* delete extra initial node */
		temp = front;
		front = front->next;
		free(temp);
		return front;
}

void attach(float coefficient, int exponent, Linked ptr)
{
	/* create a new node with coef = coefficient, 
	expo = exponent, attach it to the node pointed to by
	ptr. ptr is updated to point to this new node */
	Linked temp = (Linked)malloc(sizeof(struct Node ));
	temp->coef = coefficient;
	temp->expo = exponent;
	(*ptr)->next = temp;
	*ptr = temp;
}
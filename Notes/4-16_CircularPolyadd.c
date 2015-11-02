/* Polynomial addition based on circular linked list */
Linked cpadd(Linked a, linked b)
{
	/* poly a and b are singly linked circular lists with a head node. return 
	a poly which is the sum of a and b. */
	Linked starta, d, lastd;
	int sum, done = 0;
	starta = a; // record start of a
	a = a->next;
	b = b->next; // skip head node for a and b
	d = get_node(); // get a head node for sum from avail
	d->expo = -1; lastd = d;
	do
	{
		switch (COMPARE(a->expo, b->expo))
		{
			case -1:
				attach(b->coef, b->expo, &lastd);
				b = b->next;
				break;
			case  0:
				if (starta == a)
					done = 1;
				else
				{
					sum = a->coef + b->coef;
					if (sum)
						attach(sum, a->expo, &lastd)
					a = a->next;
					b = b->next;
				}
				break;
			case  1:
				attach(a->coef, a->expo, &lastd);
				a = a->next;
		}
	} while (!done);
	lastd->next = d;
	return d;
}
/* Excercise 1.3.1 on page 12 of FDSC */
#include <stdio.h>
#include <stdbool.h>
#define NAT int
#define MAX_NAT 65536

NAT Predecessor(NAT num);
bool Is_Greater(NAT x, NAT Y);
NAT Multiply(NAT x, NAT y);
NAT Divide(NAT x, NAT y);

int main(void)
{
	printf("%f", 3 / 2);
	return 0;
}

NAT Predecessor(NAT num)
{
	if (num == 1)
		return num;
	return --num;
}

bool Is_Greater(NAT x, NAT y)
{
	if (x > y)
		return true;
	return false;
}

NAT Multiply(NAT x, NAT y)
{
	if (x * y >= MAX_NAT)
		return MAX_NAT;
	return x * y;
}

NAT Divide(NAT x, NAT y)
{
	if (x % y == 0 && x / y >= 1)
		return x / y;
	return x / y;
}

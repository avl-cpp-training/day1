#include "stdafx.h"
#include "code.h"
void f2(int* a1, int* a2)
{
	int diff = a2 - a1;
	for (int i = 0; i < diff; i++)
		*(a1 + i) = *(a1 + i) + 1;
}

void f1(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

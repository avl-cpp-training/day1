#include "stdafx.h"
#include "code.h"

void f1(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void f2(int* begin, int* end)
{
	while (end != begin)
	{
		*begin = (*begin) + 1;
		begin++;
	}
}

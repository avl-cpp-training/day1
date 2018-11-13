#include "stdafx.h"
#include "code.h"

void f1(int& a,int& b)
{
	int temp = a;
	a = b;
	b = temp;
	
}
void f2(int* begin, const int* const end)
{
	for (; begin < end; begin++)
		(*begin)++;
}
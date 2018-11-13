#include "stdafx.h"
#include "code.h"

void f1(int& a, int& b) 
{
	int temp = b;
	b = a;
	a = temp;
}

void f2(int* start, int* end) 
{
	for (int* i = start; i != end; i++) 
	{
		(* i) ++;
	}
}

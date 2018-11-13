#include "stdafx.h"
#include "code.h"

//f1(a, b);
void f1(int& a, int& b)			// void f1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	//std::swap(a,b);
}

//f2(arr, arr+3);
void f2(int* array, int* end)
{
	//int i = (&end - &array) / sizeof(int);
	for (int* position = array; position < end; position++)
	{
		(*position)++; //*position++ ne radi
		//std::transform(be,b, [] (int n) {return n+1});
	}

}
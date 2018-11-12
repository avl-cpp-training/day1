#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "code.h"

namespace simple_test
{		
	TEST_CLASS(Test1)
	{
	public:
		
		TEST_METHOD(f1_changes_values)
		{
			int a=1, b=2;
			f1(&a, &b);
			Assert::AreEqual(2, a);
			Assert::AreEqual(1, b);
		}
		TEST_METHOD(f2_increases_all_values_by_one)
		{
			int arr[] = { 1, 2, 3 };
			f2(arr, arr+3);
			Assert::AreEqual(2, arr[0]);
			Assert::AreEqual(3, arr[1]);
			Assert::AreEqual(4, arr[2]);
		}
		TEST_METHOD(f2_works_for_different_number_of_values)
		{
			int arr[] = { 2, 4, 6, 8, 10 };
			f2(arr, arr+5);
			Assert::AreEqual(3, arr[0]);
			Assert::AreEqual(5, arr[1]);
			Assert::AreEqual(7, arr[2]);
			Assert::AreEqual(9, arr[3]);
			Assert::AreEqual(11, arr[4]);
		}
	};
}

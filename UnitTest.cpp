#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\HP\source\repos\Ипз лаба 3(1)\Ипз лаба 3(1)\Ипз лаба 3(1).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	//Test the calculate function
	TEST_CLASS(calculate_Tests)
	{
	public:
		
		TEST_METHOD(calculate_get2and2_5point5returned)
		{
			int n = 2;
			float x = 2;
			float expected = 5.5;

			float actual = calculate(x, n);

			Assert::AreEqual(expected, actual);
		}
public:
	TEST_METHOD(calculate_getminus6and4_0returned)
	{
		int n = 4;
		float x = -6;
		float expected = 0;

		float actual = calculate(x, n);

		Assert::AreEqual(expected, actual);
	}
};
	//PrintValues function test
	TEST_CLASS(printValues_Tests)
	{
	public:

		TEST_METHOD(printValues_getminus4and2and2and2_0and0and0and5point5returned)
		{
			float start = -4;
			float step = 2;
			float end = 2;
			int n = 2;
			for (float x = start; x <= end; x += step)
			{
				float actual = calculate(x, n);
				if (x == -4)
				{
					float expected = 0;
					Assert::AreEqual(expected, actual);
				}
				if (x == -2 )
				{
					float expected = 0;
					Assert::AreEqual(expected, actual);
				}
				if (x == 0)
				{
					float expected = 0;
					Assert::AreEqual(expected, actual);
				}
				if (x == 2)
				{
					float expected = 5.5;
					Assert::AreEqual(expected, actual);
				}

			}
		}
	};
	//Checkvalidparams function test
	TEST_CLASS(checkVaildParams_Tests)
	{
	public:

		TEST_METHOD(checkVaildParams_get1and2_expectionNotThrown)
		{
			float start = 1;
			float step = 2 ;
			try
			{
				checkVaildParams(start, step);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(checkVaildParams_get1and2and0_expectionThrown)
		{
			float start = 1;
			float step = 2;
			float end = 0;
			try
			{
				checkVaildParams(start, step, end);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	public:
		TEST_METHOD(checkVaildParams_get1and2and5andminus3_expectionThrown)
		{
			float start = 1;
			float step = 2;
			float end = 5;
			int n = -3;
			try
			{
				checkVaildParams(start, step, end, n);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	public:
		TEST_METHOD(checkVaildParams_get1and2and5and3and1_expectionNotThrown)
		{
			float start = 1;
			float step = 2;
			float end = 5;
			int n = 3;
			int save = 1;
			try
			{
				checkVaildParams(start, step, end, n, save);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};
}

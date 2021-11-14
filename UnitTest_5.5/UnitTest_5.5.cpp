#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_5.5/lab_5.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest55
{
	TEST_CLASS(UnitTest55)
	{
	public:
		
		TEST_METHOD(Test_f)
		{
			double res, res_f;
			res_f = round(f(1) * 100000) / 100000;
			res = round(0.301168679 * 100000) / 100000;
			Assert::AreEqual(res_f, res);
		}

		TEST_METHOD(Test_findX)
		{
			double res, res_findX;
			int deep = 0;

			res_findX = round(findX(-2, 2, 0.000001, deep) * 100000) / 100000;

			res = round(atan(1) * 100000) / 100000;
			Assert::AreEqual(res_findX, res);
		}
	};
}

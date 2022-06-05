#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Misha\source\repos\5.1 d oop\5.1 d oop\Money.cpp"
#include "C:\Users\Misha\source\repos\5.1 d oop\5.1 d oop\Pair.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Money a(15, 14);
			
			double grn = a.getGrn();
			double kop = a.getKop();
			double res = grn - kop;
			Assert::AreEqual(1., res);
		}
	};
}

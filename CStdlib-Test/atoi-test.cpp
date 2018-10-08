#include "CppUnitTest.h"
#include "../CStdlib/CStdlib.h"
#include <cstring>
#include <limits>
#include <string>
#include <cfloat>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CStdlibTest
{
	TEST_CLASS(atoiTest)
	{
	private:
		CStdlib cstdlib{};
	public:

		TEST_METHOD(TestHelloWorld)
		{
			Assert::AreEqual(atoi("31415926"), cstdlib.atoi("31415926"));
		}
		TEST_METHOD(TestPositive)
		{
			Assert::AreEqual(atoi("+31415926"), cstdlib.atoi("+31415926"));
		}
		TEST_METHOD(TestNegative)
		{
			Assert::AreEqual(atoi("-31415926"), cstdlib.atoi("-31415926"));
		}
		TEST_METHOD(TestWhole)
		{
			Assert::AreEqual(atoi("3"), cstdlib.atoi("3"));
		}
		TEST_METHOD(TestFractional)
		{
			Assert::AreEqual(atoi(".1415926"), cstdlib.atoi(".1415926"));
		}
		TEST_METHOD(TestDecimal)
		{
			Assert::AreEqual(atoi("3.1415926"), cstdlib.atoi("3.1415926"));
		}
		TEST_METHOD(TestSpacePrefix)
		{
			Assert::AreEqual(atoi("    31415926"), cstdlib.atoi("    31415926"));
		}
		TEST_METHOD(TestZeroPrefix)
		{
			Assert::AreEqual(atoi("031415926"), cstdlib.atoi("031415926"));
		}
		TEST_METHOD(TestScientific)
		{
			Assert::AreEqual(atoi("3.1415926e1"), cstdlib.atoi("3.1415926e1"));
		}
		TEST_METHOD(TestScientificPositivePower)
		{
			Assert::AreEqual(atoi("3.1415926e+1"), cstdlib.atoi("3.1415926e+1"));
		}
		TEST_METHOD(TestScientificNegativePower)
		{
			auto tolerance = pow(0.1, DBL_DIG);
			Assert::AreEqual(atoi("3.1415926e-1"), cstdlib.atoi("3.1415926e-1"), tolerance);
		}
		TEST_METHOD(TestMaxint)
		{
			Assert::AreEqual(atoi(std::to_string(std::numeric_limits<int>::max()).c_str()),
				cstdlib.atoi(std::to_string(std::numeric_limits<int>::max()).c_str()));
		}
		TEST_METHOD(TestMinint)
		{
			Assert::AreEqual(atoi(std::to_string(std::numeric_limits<int>::min()).c_str()),
				cstdlib.atoi(std::to_string(std::numeric_limits<int>::min()).c_str()));
		}
		TEST_METHOD(TestHexadecimal)
		{
			Assert::AreEqual(atoi("0x3243F69A25B093B1"), cstdlib.atoi("0x3243F69A25B093B1"));
		}
		TEST_METHOD(TestInfinity)
		{
			Assert::AreEqual(atoi("infinity"), cstdlib.atoi("infinity"));
		}
	};
}
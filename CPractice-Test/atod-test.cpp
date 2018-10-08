#include "CppUnitTest.h"
#include "../CPractice/CStdlib.h"
#include <cstring>
#include <limits>
#include <string>
#include <cfloat>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CStdlibTest
{
	TEST_CLASS(atofTest)
	{
	private:
		CStdlib cstdlib{};
	public:

		TEST_METHOD(TestHelloWorld)
		{
			Assert::AreEqual(atof(" 031.415926e-001 2"), cstdlib.atof(" 031.415926e-001 2"));
		}
		TEST_METHOD(TestPositive)
		{
			Assert::AreEqual(atof("3.1415926"), cstdlib.atof("3.1415926"));
		}
		TEST_METHOD(TestNegative)
		{
			Assert::AreEqual(atof("-3.1415926"), cstdlib.atof("-3.1415926"));
		}
		TEST_METHOD(TestWhole)
		{
			Assert::AreEqual(atof("3"), cstdlib.atof("3"));
		}
		TEST_METHOD(TestFractional)
		{
			Assert::AreEqual(atof(".1415926"), cstdlib.atof(".1415926"));
		}
		TEST_METHOD(TestSpacePrefix)
		{
			Assert::AreEqual(atof("    .1415926"), cstdlib.atof("    .1415926"));
		}
		TEST_METHOD(TestZeroPrefix)
		{
			Assert::AreEqual(atof("0.1415926"), cstdlib.atof("0.1415926"));
		}
		TEST_METHOD(TestScientific)
		{
			Assert::AreEqual(atof("3.1415926e1"), cstdlib.atof("3.1415926e1"));
		}
		TEST_METHOD(TestScientificPositivePower)
		{
			Assert::AreEqual(atof("3.1415926e+1"), cstdlib.atof("3.1415926e+1"));
		}
		TEST_METHOD(TestScientificNegativePower)
		{
			auto v1 = atof("3.1415926e-1");
			auto v2 = cstdlib.atof("3.1415926e-1");
			auto tolerance = pow(0.1, DBL_DIG);
			Assert::AreEqual(atof("3.1415926e-1"), cstdlib.atof("3.1415926e-1"), tolerance);
		}
		TEST_METHOD(TestMaxFloat)
		{
			Assert::AreEqual(atof(std::to_string(std::numeric_limits<float>::max()).c_str()), 
				             cstdlib.atof(std::to_string(std::numeric_limits<float>::max()).c_str()));
		}
		TEST_METHOD(TestHexadecimal)
		{
			Assert::AreEqual(atof("0x3.243F69A25B093B1"), cstdlib.atof("0x3.243F69A25B093B1"));
		}
		TEST_METHOD(TestInfinity)
		{
			Assert::AreEqual(atof("infinity"), cstdlib.atof("infinity"));
		}
		TEST_METHOD(TestNan)
		{
			Assert::IsTrue(isnan(atof("nan")));
		}
	};
}
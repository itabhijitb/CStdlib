#include "CppUnitTest.h"
#include "../CStdlib/CString.h"
#include <cstring>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CStringTest
{
	TEST_CLASS(StrchrTest)
	{
	private:
		CString cstring{};
	public:

		TEST_METHOD(TestHelloWorld)
		{
			Assert::AreEqual(
				strchr("Hello World", 'W'),
				cstring.strchr("Hello World", 'W'));
		}
		TEST_METHOD(TestNegative)
		{
			Assert::AreEqual(
				strchr("Hello World", 'w'),
				cstring.strchr("Hello World", 'w'));
		}
		TEST_METHOD(TestEmptyString)
		{
			Assert::AreEqual(
				strchr("", 'w'),
				cstring.strchr("", 'w'));
		}
		TEST_METHOD(TestEmptyChar)
		{
			Assert::AreEqual(
				strchr("Hello World", '\0'),
				cstring.strchr("Hello World", '\0'));
		}
		TEST_METHOD(TestEmpty)
		{
			Assert::AreEqual(
				strchr("", '\0'),
				cstring.strchr("", '\0'));
		}
	};
}
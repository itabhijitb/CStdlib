#include "CppUnitTest.h"
#include "../CStdlib/CString.h"
#include <cstring>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CStringTest
{
	TEST_CLASS(StrspnTest)
	{
	private:
		CString cstring{};
	public:

		TEST_METHOD(TestHelloWorld)
		{
			Assert::AreEqual(
				strspn("Hello World", "elo"),
				cstring.strspn("Hello World", "elo"));
		}
		TEST_METHOD(TestPositive)
		{
			Assert::AreEqual(
				strspn("Hello World", "elo"),
				cstring.strspn("Hello World", "elo"));
		}
		TEST_METHOD(TestNegative)
		{
			Assert::AreEqual(
				strspn("Hello World", "xyz"),
				cstring.strspn("Hello World", "xyz"));
		}
		TEST_METHOD(TestRepeat)
		{
			Assert::AreEqual(
				strspn("Hello World", "Hello"),
				cstring.strspn("Hello World", "Hello"));
		}
		TEST_METHOD(TestNonEmptyEmpty)
		{
			Assert::AreEqual(
				strspn("World", ""),
				cstring.strspn("World", ""));
		}
		TEST_METHOD(TestEmptyNonEmpty)
		{
			Assert::AreEqual(
				strspn("", "World"),
				cstring.strspn("", "World"));
		}
		TEST_METHOD(TestEmpty)
		{
			Assert::AreEqual(
				strspn("", ""),
				cstring.strspn("", ""));
		}
	};
};
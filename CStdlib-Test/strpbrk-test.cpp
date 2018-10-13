#include "CppUnitTest.h"
#include "../CStdlib/CString.h"
#include <cstring>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CStringTest
{
	TEST_CLASS(StrpbrkTest)
	{
	private:
		CString cstring{};
	public:

		TEST_METHOD(TestHelloWorld)
		{
			Assert::AreEqual(
				strpbrk("Hello World", "elo"),
				cstring.strpbrk("Hello World", "elo"));
		}
		TEST_METHOD(TestPositive)
		{
			Assert::AreEqual(
				strpbrk("Hello World", "elo"),
				cstring.strpbrk("Hello World", "elo"));
		}
		TEST_METHOD(TestNegative)
		{
			Assert::AreEqual(
				strpbrk("Hello World", "xyz"),
				cstring.strpbrk("Hello World", "xyz"));
		}
		TEST_METHOD(TestRepeat)
		{
			Assert::AreEqual(
				strpbrk("Hello World", "Hello"),
				cstring.strpbrk("Hello World", "Hello"));
		}
		TEST_METHOD(TestNonEmptyEmpty)
		{
			Assert::AreEqual(
				strpbrk("World", ""),
				cstring.strpbrk("World", ""));
		}
		TEST_METHOD(TestEmptyNonEmpty)
		{
			Assert::AreEqual(
				strpbrk("", "World"),
				cstring.strpbrk("", "World"));
		}
		TEST_METHOD(TestEmpty)
		{
			Assert::AreEqual(
				strpbrk("", ""),
				cstring.strpbrk("", ""));
		}
	};
};
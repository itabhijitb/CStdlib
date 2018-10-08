#include "CppUnitTest.h"
#include "../CPractice/CString.h"
#include <cstring>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CStringTest
{
	TEST_CLASS(StrcmpTest)
	{
	private:
		CString cstring{};
	public:

		TEST_METHOD(TestHelloWorld)
		{
			Assert::AreEqual(
				strcmp("Hello World", "Hello World"),
				cstring.strcmp("Hello World", "Hello World"));
		}
		TEST_METHOD(TestLess)
		{
			Assert::AreEqual(
				strcmp("Hello", "World"),
				cstring.strcmp("Hello", "World"));
		}
		TEST_METHOD(TestGreater)
		{
			Assert::AreEqual(
				strcmp("World", "Hello"),
				cstring.strcmp("World", "Hello"));
		}
		TEST_METHOD(TestEmptyNonEmpty)
		{
			Assert::AreEqual(
				strcmp("", "Hello"),
				cstring.strcmp("", "Hello"));
		}
		TEST_METHOD(TestNonEmptyEmpty)
		{
			Assert::AreEqual(
				strcmp("World", ""),
				cstring.strcmp("World", ""));
		}
		TEST_METHOD(TestEmpty)
		{
			Assert::AreEqual(
				strcmp("", ""),
				cstring.strcmp("", ""));
		}
	};
};
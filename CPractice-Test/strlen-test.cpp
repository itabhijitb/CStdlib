#include "CppUnitTest.h"
#include "../CPractice/CString.h"
#include <cstring>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CStringTest
{		
	TEST_CLASS(StrlenTest)
	{
	private:
		CString cstring{};
	public:
		
		TEST_METHOD(TestEmpty)
		{
			Assert::AreEqual(cstring.strlen(""), strlen(""));
		}
		TEST_METHOD(TestEmptyWithNonEmpty)
		{
			Assert::AreNotEqual(cstring.strlen(""), strlen("NonEmpty"));
		}
		TEST_METHOD(TestNonEmptyWithEmpty)
		{
			Assert::AreNotEqual(cstring.strlen("NonEmpty"), strlen(""));
		}
		TEST_METHOD(TestNonNonEmptyWithNonEmpty)
		{
			Assert::AreEqual(cstring.strlen("NonEmpty"), strlen("NonEmpty"));
		}
		TEST_METHOD(TestLen1With2)
		{
			Assert::AreNotEqual(cstring.strlen("1"), strlen("12"));
		}
		TEST_METHOD(TestLen2With1)
		{
			Assert::AreNotEqual(cstring.strlen("1"), strlen("12"));
		}
		TEST_METHOD(TestLen1With1)
		{
			Assert::AreEqual(cstring.strlen("1"), strlen("1"));
		}
	};
}
#include "CppUnitTest.h"
#include "../CPractice/CString.h"
#include <cstring>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CStringTest
{
	TEST_CLASS(StrcatTest)
	{
	private:
		CString cstring{};
	public:

		TEST_METHOD(TestHelloWorld)
		{
			Assert::AreEqual(
				[&]() {char buffer[12] = "Hello"; return cstring.strcat(buffer, "world"); }(),
				[]() {char buffer[12] = "Hello"; return strcat(buffer, "world"); }());
		}
		TEST_METHOD(TestEmptyWorld)
		{
			Assert::AreEqual(
				[&]() {char buffer[12] = ""; return cstring.strcat(buffer, "world"); }(),
				[]() {char buffer[12] = ""; return strcat(buffer, "world"); }());
		}
		TEST_METHOD(TestHelloEmpty)
		{
			Assert::AreEqual(
				[]() {
				char buffer[12] = "Hello";
				auto result = strcat(buffer, "");
				return result;
			}(),
				[&]() {
				char buffer[12] = "Hello"; 
				char *result = cstring.strcat(buffer, "");
				return result;
			}()
				);
		}
		TEST_METHOD(TestEmptyEmpty)
		{
			Assert::AreEqual(
				[&]() {char buffer[12] = ""; return cstring.strcat(buffer, ""); }(),
				[]() {char buffer[12] = ""; return strcat(buffer, ""); }());
		}
	};
}
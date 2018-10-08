#include "CppUnitTest.h"
#include "../CStdlib/CString.h"
#include <cstring>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CStringTest
{
	TEST_CLASS(StrncatTest)
	{
	private:
		CString cstring{};
	public:

		TEST_METHOD(TestHelloWorld)
		{
			Assert::AreEqual(
				[]() {
				char buffer[12] = "Hello";
				return strncat(buffer, "world", std::size(buffer) - 1); }(),
				[&]() {
					char buffer[12] = "Hello";
					return cstring.strncat(buffer, "world", std::size(buffer) - 1); }());
		}
		TEST_METHOD(TestEmptyWorld)
		{
			Assert::AreEqual(
				[]() {char buffer[12] = ""; return strncat(buffer, "world", std::size(buffer) - 1); }(),
				[&]() {char buffer[12] = ""; return cstring.strncat(buffer, "world", std::size(buffer) - 1); }());
		}
		TEST_METHOD(TestHelloEmpty)
		{
			Assert::AreEqual(
				[]() {
				char buffer[12] = "Hello";
				return strncat(buffer, "", std::size(buffer) - 1);
			}(),
				[&]() {
				char buffer[12] = "Hello";
				char *result = cstring.strncat(buffer, "", std::size(buffer) - 1);
				return result;
			}()
				);
		}
		TEST_METHOD(TestEmptyEmpty)
		{
			Assert::AreEqual(
				[]() {char buffer[12] = ""; return strncat(buffer, "", std::size(buffer) - 1); }(),
				[&]() {char buffer[12] = ""; return cstring.strncat(buffer, "", std::size(buffer) - 1); }());
		}
		TEST_METHOD(TestZeroLength)
		{
			Assert::AreEqual(
				[]() {char buffer[12] = "Hello"; return strncat(buffer, "World", 0); }(),
				[&]() {char buffer[12] = "Hello"; return cstring.strncat(buffer, "World", 0); }());
		}
		TEST_METHOD(TestShorterLength)
		{
			Assert::AreEqual(
				[]() {char buffer[12] = "Hello"; return strncat(buffer, "World", std::size(buffer) - 1); }(),
				[&]() {char buffer[12] = "Hello"; return cstring.strncat(buffer, "World", std::size(buffer) - 1); }());
		}
	};
}
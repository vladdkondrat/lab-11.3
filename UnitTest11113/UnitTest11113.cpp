#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 11.3/lab 11.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest11113
{
	TEST_CLASS(UnitTest11113)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const string fileName = "test_phonebook.txt";

			CreatePhonebook(fileName);

			ifstream file(fileName);
			Assert::IsTrue(file.is_open(), L"File was not created successfully.");
			file.close();
		}
	};
}

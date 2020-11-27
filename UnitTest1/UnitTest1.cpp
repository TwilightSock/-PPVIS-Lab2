#include "CppUnitTest.h"
#include "../Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(2 == 2);
		}
	};
}

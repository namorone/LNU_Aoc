#include "pch.h"
#include "CppUnitTest.h"
#include "../Множини/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(test_append)
		{
			Set s;
			s.append('q');
			Assert::AreEqual(s.inSet('q'), true);
		}

		TEST_METHOD(test_remove)
		{
			Set s;
			s.append('q');
			Assert::AreEqual(s.inSet('q'), true);
			s.remove('q');
			Assert::AreEqual(s.inSet('q'), false);
		}

		TEST_METHOD(test_unit)
		{
			Set s;
			s.append('u');
			s.append('k');

			Set s1;
			s1.append('4');
			s1.append('1');
			s.unit(s1);
			Assert::AreEqual(s.inSet('4'), true);
		}

		TEST_METHOD(test_across)
		{
			Set s;
			s.append('1');
			s.append('k');

			Set s1;
			s1.append('4');
			s1.append('1');
			s.across(s1);
			Assert::AreEqual(s.inSet('4'), false);
			Assert::AreEqual(s.inSet('1'), true);
		}
	};
}

#include "pch.h"
#include "CppUnitTest.h"
#include "../BinarySearchTree/BinarySearchTree.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LCATests
{
	TEST_CLASS(LCATests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			BinarySearchTree testBST;
			testBST.put(7, '7');
			testBST.put(8, '8');
			testBST.put(3, '3');
			testBST.put(1, '1');
			testBST.put(2, '2');
			testBST.put(6, '6');
			testBST.put(4, '4');
			testBST.put(5, '5');

			int expectedResult = 3;
			Assert::AreEqual(expectedResult, testBST.LCA(2, 4));

			expectedResult = 3;
			Assert::AreEqual(expectedResult, testBST.LCA(2, 5));

			expectedResult = 7;
			Assert::AreEqual(expectedResult, testBST.LCA(3, 8));

			expectedResult = 6;
			Assert::AreEqual(expectedResult, testBST.LCA(4, 5));

			expectedResult = NULL;
			Assert::AreEqual(expectedResult, testBST.LCA(7, 3));

		}
	};
}

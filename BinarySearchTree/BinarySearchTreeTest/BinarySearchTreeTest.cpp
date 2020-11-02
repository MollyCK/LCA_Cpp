#include "pch.h"
#include "CppUnitTest.h"
#include "../BinarySearchTree/BinarySearchTree.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinarySearchTreeTest
{
	TEST_CLASS(BinarySearchTreeTest)
	{
	public:

		TEST_METHOD(testIsEmpty) 
		{
			BinarySearchTree testBST = BinarySearchTree();
			//Test empty tree
			Assert::AreEqual(true, testBST.isEmpty());

			//Test not empty tree
			testBST.put(7, '7');
			Assert::AreEqual(false, testBST.isEmpty());
		}
		
		TEST_METHOD(testPrettyPrint)
		{
			BinarySearchTree testBST = BinarySearchTree();
		//Test empty tree
			string expectedResult = "-null\n";
			Assert::AreEqual(expectedResult, testBST.prettyPrintKeys(), false);

			//Test non-empty tree

										//  -7
										//   |-3
										//   | |-1
										//   | | |-null
			testBST.put(7, '7');        //   | |  -2
			testBST.put(8, '8');        //   | |   |-null
			testBST.put(3, '3');        //   | |    -null
			testBST.put(1, '1');        //   |  -6
			testBST.put(2, '2');        //   |   |-4
			testBST.put(6, '6');        //   |   | |-null
			testBST.put(4, '4');        //   |   |  -5
			testBST.put(5, '5');        //   |   |   |-null
										//   |   |    -null
										//   |    -null
										//    -8
										//     |-null
										//      -null
			string a = "-7\n";
			expectedResult = 
				a +
				" |-3\n" +
				" | |-1\n" +
				" | | |-null\n" +
				" | |  -2\n" +
				" | |   |-null\n" +
				" | |    -null\n" +
				" |  -6\n" +
				" |   |-4\n" +
				" |   | |-null\n" +
				" |   |  -5\n" +
				" |   |   |-null\n" +
				" |   |    -null\n" +
				" |    -null\n" +
				"  -8\n" +
				"   |-null\n" +
				"    -null\n";
			Assert::AreEqual(expectedResult, testBST.prettyPrintKeys(), false);
		}

		TEST_METHOD(testLCA)
		{
			BinarySearchTree testBST = BinarySearchTree();;
			//Test empty tree
			int expectedResult = NULL;
			Assert::AreEqual(expectedResult, testBST.LCA(2, 4));

			//Test non-empty tree
			testBST.put(7, '7');
			testBST.put(8, '8');
			testBST.put(3, '3');
			testBST.put(1, '1');
			testBST.put(2, '2');
			testBST.put(6, '6');
			testBST.put(4, '4');
			testBST.put(5, '5');

			expectedResult = 3;
			Assert::AreEqual(expectedResult, testBST.LCA(2, 4));

			expectedResult = 3;
			Assert::AreEqual(expectedResult, testBST.LCA(2, 5));

			expectedResult = 7;
			Assert::AreEqual(expectedResult, testBST.LCA(3, 8));

			expectedResult = 6;
			Assert::AreEqual(expectedResult, testBST.LCA(4, 5));

			expectedResult = NULL;
			Assert::AreEqual(expectedResult, testBST.LCA(7, 3));

			//Test 'single line' tree
			testBST = BinarySearchTree();

			testBST.put(7, '7');   //        7
			testBST.put(5, '5');   //       /
			testBST.put(3, '3');   //      5    
			testBST.put(1, '1');   //     /
								   //	 3
								   //   /
								   //  1
			expectedResult = 5;
			Assert::AreEqual(expectedResult, testBST.LCA(1, 3));

			expectedResult = NULL;
			Assert::AreEqual(expectedResult, testBST.LCA(7, 3));

			expectedResult = 7;
			Assert::AreEqual(expectedResult, testBST.LCA(5, 1));
		}
	};
}

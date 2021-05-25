#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SinglyListTest
{
	TEST_CLASS(SinglyListTest)
	{
	public:
		
#pragma region Create Tests

		TEST_METHOD(Create_Nullptr)
		{
			int expectedLength = 0;
			
			int length = DSLib::List::SinglyList::Create(nullptr, 10);
			
			Assert::AreEqual(expectedLength, length);
		}

		TEST_METHOD(Create_ZeroLength)
		{
			DSLib::List::SinglyListNode* head = nullptr;
			
			int expectedLength = 0;
			
			int length = DSLib::List::SinglyList::Create(&head, expectedLength);
			
			Assert::IsNull(head);
			Assert::AreEqual(expectedLength, length);
		}

		TEST_METHOD(Create_NegativeLength)
		{
			DSLib::List::SinglyListNode* head = nullptr;

			int expectedLength = 0;

			int length = DSLib::List::SinglyList::Create(&head, -10);

			Assert::IsNull(head);
			Assert::AreEqual(expectedLength, length);
		}

		TEST_METHOD(Create_OneNode)
		{
			DSLib::List::SinglyListNode* head = nullptr;
			
			int expectedLength = 1;
			int expectedValue = 0;

			int length = DSLib::List::SinglyList::Create(&head, expectedLength);

			Assert::IsNotNull(head, L"Expected nullptr");
			Assert::AreEqual(expectedLength, length, L"Expected length does not match");

			DSLib::List::SinglyListNode* current = head;
			while (current)
			{
				Assert::AreEqual(current->data, expectedValue, L"Expected value does not match");
				current = current->next;
			}

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(Create_TenNodes)
		{
			DSLib::List::SinglyListNode* head = nullptr;

			int expectedLength = 10;
			int expectedValue = 0;

			int length = DSLib::List::SinglyList::Create(&head, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			DSLib::List::SinglyListNode* current = head;
			while (current)
			{
				Assert::AreEqual(current->data, expectedValue);
				current = current->next;
			}

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(Create_NullptrWithData)
		{
			int expectedLength = 0;
			int expectedValues[] = { 10, 20, 30, 40, 50 };
			int count = 5;

			int length = DSLib::List::SinglyList::Create(nullptr, expectedValues, count);

			Assert::AreEqual(expectedLength, length);
		}


		TEST_METHOD(Create_NoDataLength)
		{
			DSLib::List::SinglyListNode* head = nullptr;
			int expectedLength = 0;
			int* expectedValues = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, expectedValues, 5);

			Assert::IsNull(head);
			Assert::AreEqual(expectedLength, length);
		}

		TEST_METHOD(Create_DataLength_One)
		{
			DSLib::List::SinglyListNode* head = nullptr;
			int expectedLength = 1;
			int expectedValues[] = { 10 };

			int length = DSLib::List::SinglyList::Create(&head, expectedValues, expectedLength);

			Assert::IsNotNull(head, L"nullptr not expected");
			Assert::AreEqual(expectedLength, length, L"Length mis-match");

			DSLib::List::SinglyListNode* current = head;
			int i = 0;
			while (current && i < expectedLength)
			{
				Assert::AreEqual(current->data, expectedValues[i++]);
				current = current->next;
			}

			Assert::IsNull(current, L"Expected nullptr");
			Assert::AreEqual(i, expectedLength, L"Length mis-match after traversing");

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(Create_DataLength_Five)
		{
			DSLib::List::SinglyListNode* head = nullptr;
			int expectedLength = 5;
			int expectedValues[] = { 10, 20, 30, 40, 50 };

			int length = DSLib::List::SinglyList::Create(&head, expectedValues, expectedLength);

			Assert::IsNotNull(head, L"nullptr not expected");
			Assert::AreEqual(expectedLength, length, L"Length mis-match");

			DSLib::List::SinglyListNode* current = head;
			int i = 0;
			while (current && i < expectedLength)
			{
				Assert::AreEqual(current->data, expectedValues[i++]);
				current = current->next;
			}

			Assert::IsNull(current, L"Expected nullptr");
			Assert::AreEqual(i, expectedLength, L"Length mis-match after traversing");

			DSLib::List::SinglyList::Delete(&head);
		}

#pragma endregion

#pragma region Delete Tests

		TEST_METHOD(Delete_Nullptr)
		{
			DSLib::List::SinglyList::Delete(nullptr);
		}

		TEST_METHOD(Delete_Empty)
		{
			DSLib::List::SinglyListNode* head = nullptr;

			DSLib::List::SinglyList::Create(&head, 0);

			DSLib::List::SinglyList::Delete(&head);

			Assert::IsNull(head);
		}

		TEST_METHOD(Delete_FiveNodeList)
		{
			DSLib::List::SinglyListNode* head = nullptr;

			DSLib::List::SinglyList::Create(&head, 5);

			DSLib::List::SinglyList::Delete(&head);

			Assert::IsNull(head);
		}

#pragma endregion

#pragma region Length Tests

		TEST_METHOD(Length_Empty)
		{
			int expectedLength = 0;
			int length = DSLib::List::SinglyList::Length(nullptr);

			Assert::AreEqual(expectedLength, length);
		}

		TEST_METHOD(Length_OneNode)
		{
			int expectedLength = 1;
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			length = DSLib::List::SinglyList::Length(head);
			Assert::AreEqual(expectedLength, length);


			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(Length_TenNode)
		{
			int expectedLength = 10;
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			length = DSLib::List::SinglyList::Length(head);
			Assert::AreEqual(expectedLength, length);


			DSLib::List::SinglyList::Delete(&head);
		}

#pragma endregion

#pragma region GetNthNode Tests

		TEST_METHOD(GetNthNode_Nullptr)
		{
			DSLib::List::SinglyListNode* pExpected = DSLib::List::SinglyList::GetNthNode(nullptr, 5);
			Assert::IsNull(pExpected);
		}

		TEST_METHOD(GetNthNode_TenNodeList_GetFifthNode)
		{
			int expectedLength = 10;
			int position = 5;
			int expectedValue = 50;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;
			DSLib::List::SinglyListNode* pExpected = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			pExpected = DSLib::List::SinglyList::GetNthNode(head, position);
			Assert::IsNotNull(pExpected);

			Assert::AreEqual(expectedValue, pExpected->data);

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(GetNthNode_TenNodeList_GetEleventhNode)
		{
			int expectedLength = 10;
			int position = 11;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;
			DSLib::List::SinglyListNode* pExpected = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			pExpected = DSLib::List::SinglyList::GetNthNode(head, position);
			Assert::IsNull(pExpected);

			DSLib::List::SinglyList::Delete(&head);
		}


		TEST_METHOD(GetNthNode_TenNodeList_GetFirstNode)
		{
			int expectedLength = 10;
			int position = 1;
			int expectedValue = 10;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;
			DSLib::List::SinglyListNode* pExpected = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			pExpected = DSLib::List::SinglyList::GetNthNode(head, position);
			Assert::IsNotNull(pExpected);
			Assert::AreEqual(expectedValue, pExpected->data);

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(GetNthNode_TenNodeList_GetTenthNode)
		{
			int expectedLength = 10;
			int position = 10;
			int expectedValue = 100;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;
			DSLib::List::SinglyListNode* pExpected = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			pExpected = DSLib::List::SinglyList::GetNthNode(head, position);
			Assert::IsNotNull(pExpected);
			Assert::AreEqual(expectedValue, pExpected->data);

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(GetNthNode_TenNodeList_GetThirdNode)
		{
			int expectedLength = 10;
			int position = 3;
			int expectedValue = 30;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;
			DSLib::List::SinglyListNode* pExpected = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			pExpected = DSLib::List::SinglyList::GetNthNode(head, position);
			Assert::IsNotNull(pExpected);
			Assert::AreEqual(expectedValue, pExpected->data);

			DSLib::List::SinglyList::Delete(&head);
		}

#pragma endregion

#pragma region GetNthLastNode Tests

		TEST_METHOD(GetNthLastNode_Nullptr)
		{
			DSLib::List::SinglyListNode* pExpected = DSLib::List::SinglyList::GetNthLastNode(nullptr, 5);
			Assert::IsNull(pExpected);
		}

		TEST_METHOD(GetNthLastNode_TenNodeList_GetFifthNode)
		{
			int expectedLength = 10;
			int position = 5;
			int expectedValue = 60;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;
			DSLib::List::SinglyListNode* pExpected = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			pExpected = DSLib::List::SinglyList::GetNthLastNode(head, position);
			Assert::IsNotNull(pExpected);

			Assert::AreEqual(expectedValue, pExpected->data);

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(GetNthLastNode_TenNodeList_GetEleventhNode)
		{
			int expectedLength = 10;
			int position = 11;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;
			DSLib::List::SinglyListNode* pExpected = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			pExpected = DSLib::List::SinglyList::GetNthLastNode(head, position);
			Assert::IsNull(pExpected);

			DSLib::List::SinglyList::Delete(&head);
		}


		TEST_METHOD(GetNthLastNode_TenNodeList_GetFirstNode)
		{
			int expectedLength = 10;
			int position = 1;
			int expectedValue = 100;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;
			DSLib::List::SinglyListNode* pExpected = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			pExpected = DSLib::List::SinglyList::GetNthLastNode(head, position);
			Assert::IsNotNull(pExpected);
			Assert::AreEqual(expectedValue, pExpected->data);

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(GetNthLastNode_TenNodeList_GetTenthNode)
		{
			int expectedLength = 10;
			int position = 10;
			int expectedValue = 10;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;
			DSLib::List::SinglyListNode* pExpected = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			pExpected = DSLib::List::SinglyList::GetNthLastNode(head, position);
			Assert::IsNotNull(pExpected);
			Assert::AreEqual(expectedValue, pExpected->data);

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(GetNthLastNode_TenNodeList_GetThirdNode)
		{
			int expectedLength = 10;
			int position = 3;
			int expectedValue = 80;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;
			DSLib::List::SinglyListNode* pExpected = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			pExpected = DSLib::List::SinglyList::GetNthLastNode(head, position);
			Assert::IsNotNull(pExpected);
			Assert::AreEqual(expectedValue, pExpected->data);

			DSLib::List::SinglyList::Delete(&head);
		}

#pragma endregion

#pragma region GetValueAtNthNode Tests

		TEST_METHOD(GetValueAtNthNode_Nullptr)
		{
			int expectedValue = 0;
			int actualValue;
			bool bRet = DSLib::List::SinglyList::GetValueAtNthNode(nullptr, 5, &actualValue);
			Assert::IsFalse(bRet);
		}

		TEST_METHOD(GetValueAtNthNode_TenNodeList_GetFifthNode)
		{
			int actualValue;
			int expectedLength = 10;
			int position = 5;
			int expectedValue = 50;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			bool bRet = DSLib::List::SinglyList::GetValueAtNthNode(head, position, &actualValue);
			Assert::IsTrue(bRet);
			Assert::AreEqual(expectedValue, actualValue);

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(GetValueAtNthNode_TenNodeList_GetEleventhNode)
		{
			int actualValue;
			int expectedLength = 10;
			int position = 11;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			bool bRet = DSLib::List::SinglyList::GetValueAtNthNode(head, position, &actualValue);
			Assert::IsFalse(bRet);

			DSLib::List::SinglyList::Delete(&head);
		}


		TEST_METHOD(GetValueAtNthNode_TenNodeList_GetFirstNode)
		{
			int actualValue;
			int expectedLength = 10;
			int position = 1;
			int expectedValue = 10;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			bool bRet = DSLib::List::SinglyList::GetValueAtNthNode(head, position, &actualValue);
			Assert::IsTrue(bRet);
			Assert::AreEqual(expectedValue, actualValue);

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(GetValueAtNthNode_TenNodeList_GetTenthNode)
		{
			int actualValue;
			int expectedLength = 10;
			int position = 10;
			int expectedValue = 100;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			bool bRet = DSLib::List::SinglyList::GetValueAtNthNode(head, position, &actualValue);
			Assert::IsTrue(bRet);
			Assert::AreEqual(expectedValue, actualValue);

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(GetValueAtNthNode_TenNodeList_GetThirdNode)
		{
			int actualValue;
			int expectedLength = 10;
			int position = 3;
			int expectedValue = 30;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			bool bRet = DSLib::List::SinglyList::GetValueAtNthNode(head, position, &actualValue);
			Assert::IsTrue(bRet);
			Assert::AreEqual(expectedValue, actualValue);

			DSLib::List::SinglyList::Delete(&head);
		}

#pragma endregion


#pragma region GetValueAtNthLastNode Tests

		TEST_METHOD(GetValueAtNthLastNode_Nullptr)
		{
			int expectedValue = 0;
			int actualValue;
			bool bRet = DSLib::List::SinglyList::GetValueAtNthLastNode(nullptr, 5, &actualValue);
			Assert::IsFalse(bRet);
		}

		TEST_METHOD(GetValueAtNthLastNode_TenNodeList_GetFifthNode)
		{
			int actualValue;
			int expectedLength = 10;
			int position = 5;
			int expectedValue = 60;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			bool bRet = DSLib::List::SinglyList::GetValueAtNthLastNode(head, position, &actualValue);
			Assert::IsTrue(bRet);
			Assert::AreEqual(expectedValue, actualValue);

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(GetValueAtNthLastNode_TenNodeList_GetEleventhNode)
		{
			int actualValue;
			int expectedLength = 10;
			int position = 11;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			bool bRet = DSLib::List::SinglyList::GetValueAtNthLastNode(head, position, &actualValue);
			Assert::IsFalse(bRet);

			DSLib::List::SinglyList::Delete(&head);
		}


		TEST_METHOD(GetValueAtNthLastNode_TenNodeList_GetFirstNode)
		{
			int actualValue;
			int expectedLength = 10;
			int position = 1;
			int expectedValue = 100;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			bool bRet = DSLib::List::SinglyList::GetValueAtNthLastNode(head, position, &actualValue);
			Assert::IsTrue(bRet);
			Assert::AreEqual(expectedValue, actualValue);

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(GetValueAtNthLastNode_TenNodeList_GetTenthNode)
		{
			int actualValue;
			int expectedLength = 10;
			int position = 10;
			int expectedValue = 10;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			bool bRet = DSLib::List::SinglyList::GetValueAtNthLastNode(head, position, &actualValue);
			Assert::IsTrue(bRet);
			Assert::AreEqual(expectedValue, actualValue);

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(GetValueAtNthLastNode_TenNodeList_GetThirdNode)
		{
			int actualValue;
			int expectedLength = 10;
			int position = 3;
			int expectedValue = 80;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			bool bRet = DSLib::List::SinglyList::GetValueAtNthLastNode(head, position, &actualValue);
			Assert::IsTrue(bRet);
			Assert::AreEqual(expectedValue, actualValue);

			DSLib::List::SinglyList::Delete(&head);
		}

#pragma endregion


#pragma region Reverse Tests


		TEST_METHOD(Reverse_Nullptr)
		{
			int expectedLength = 1;
			DSLib::List::SinglyListNode* head = nullptr;
			int data[] = { 10 };

			DSLib::List::SinglyList::Reverse(&head);
			Assert::IsNull(head);
		}

		TEST_METHOD(Reverse_OneNodeList)
		{
			int expectedLength = 1;
			int data[] = { 10 };
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			DSLib::List::SinglyList::Reverse(&head);
			Assert::IsNotNull(head);

			DSLib::List::SinglyListNode* current = head;
			for (int i = expectedLength - 1; i >= 0 && current; i--, current = current->next)
			{
				Assert::AreEqual(data[i], current->data);
			}

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(Reverse_SevenNodeList)
		{
			int expectedLength = 7;
			int data[] = { 10, 20, 30, 40, 50, 60, 70 };
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			DSLib::List::SinglyList::Reverse(&head);
			Assert::IsNotNull(head);

			DSLib::List::SinglyListNode* current = head;
			for (int i = expectedLength - 1; i >= 0 && current; i--, current = current->next)
			{
				Assert::AreEqual(data[i], current->data);
			}

			DSLib::List::SinglyList::Delete(&head);
		}

		TEST_METHOD(Reverse_TenNodeList)
		{
			int expectedLength = 10;
			int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			DSLib::List::SinglyListNode* head = nullptr;

			int length = DSLib::List::SinglyList::Create(&head, data, expectedLength);

			Assert::IsNotNull(head);
			Assert::AreEqual(expectedLength, length);

			DSLib::List::SinglyList::Reverse(&head);
			Assert::IsNotNull(head);

			DSLib::List::SinglyListNode* current = head;
			for (int i = expectedLength - 1; i >= 0 && current; i--, current = current->next)
			{
				Assert::AreEqual(data[i], current->data);
			}
			
			DSLib::List::SinglyList::Delete(&head);
		}

#pragma endregion

	};
}

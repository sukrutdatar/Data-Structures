#include "pch.h"
#include "list.h"
#include "singly-list.h"

int DSLib::List::SinglyList::Create(SinglyListNode** head, int numberOfNodes)
{
	int length = 0;

	do
	{
		// input validation
		if ((!head) || (numberOfNodes <= 0))
		{
			break;
		}

		// create the first node
		(*head) = new (std::nothrow) SinglyListNode;

		// if memory allocation failed
		if (!(*head))
		{
			(*head) = nullptr;
			break;
		}

		length++;
		(*head)->data = 0;
		(*head)->next = nullptr;

		// create rest of the nodes
		SinglyListNode* current = (*head);
		for (int i = 1; i < numberOfNodes; i++)
		{
			current->next = new (std::nothrow) SinglyListNode;
			current = current->next;

			if (!current)
			{
				// if memory allocation fails, return whatever list is created till now
				current = nullptr;
				break;
			}

			length++;
			current->data = 0;
			current->next = nullptr;
		}

	} while (false);

	return length;
}

int DSLib::List::SinglyList::Create(SinglyListNode** head, int data[], int numberOfNodes)
{
	int length = 0;

	do
	{
		// input validation
		if ((!head) || (!data) || (numberOfNodes <= 0))
		{
			break;
		}

		// create the first node
		(*head) = new (std::nothrow) SinglyListNode;

		// if memory allocation failed
		if (!(*head))
		{
			(*head) = nullptr;
			break;
		}

		length++;
		(*head)->data = data[0];
		(*head)->next = nullptr;

		// create rest of the nodes
		SinglyListNode* current = (*head);
		for (int i = 1; i < numberOfNodes; i++)
		{
			current->next = new (std::nothrow) SinglyListNode;
			current = current->next;

			if (!current)
			{
				// if memory allocation fails, return whatever list is created till now
				current = nullptr;
				break;
			}

			length++;
			current->data = data[i];
			current->next = nullptr;
		}

	} while (false);

	return length;
}

void DSLib::List::SinglyList::Delete(SinglyListNode** head)
{
	do
	{
		// input validation
		if (!head || !(*head))
		{
			break;
		}

		SinglyListNode* current = (*head);
		SinglyListNode* previous = current;

		while (current)
		{
			previous = current;
			current = current->next;
			delete (previous);
		}

		(*head) = nullptr;

	} while (false);
}

int DSLib::List::SinglyList::Length(SinglyListNode* head)
{
	int length = 0;

	do
	{
		// input validation
		if (!head)
		{
			break;
		}

		SinglyListNode* current = head;

		while (current)
		{
			length++;
			current = current->next;
		}

	} while (false);

	return length;
}

DSLib::List::SinglyListNode* DSLib::List::SinglyList::GetNthNode(SinglyListNode* head, int position)
{
	SinglyListNode* pRet = nullptr;

	do
	{
		// input validation
		if (!head || position <= 0)
		{
			break;
		}

		SinglyListNode* current = head;
		int count = 1;

		while (current)
		{
			if (count == position)
			{
				pRet = current;
				break;
			}

			current = current->next;
			count++;
		}

	} while (false);

	return pRet;
}

bool DSLib::List::SinglyList::GetValueAtNthNode(SinglyListNode* head, int position, int* retVal)
{
	bool bRet = false;
	
	do
	{
		(*retVal) = 0;

		SinglyListNode* current = GetNthNode(head, position);
		if (current)
		{
			bRet = true;
			(*retVal) = current->data;
		}

	} while (false);

	return bRet;
}

DSLib::List::SinglyListNode* DSLib::List::SinglyList::GetNthLastNode(SinglyListNode* head, int position)
{
	SinglyListNode* pRet = nullptr;

	do
	{
		// input validation
		if (!head || position <= 0)
		{
			break;
		}

		SinglyListNode* current = head;
		pRet = head;
		int count = 1;

		while (current)
		{
			if (count > position)
			{
				pRet = pRet->next;
			}

			current = current->next;
			count++;
		}

		if (count <= position)
		{
			pRet = nullptr;
		}

	} while (false);

	return pRet;
}

bool DSLib::List::SinglyList::GetValueAtNthLastNode(SinglyListNode* head, int position, int* retVal)
{
	bool bRet = false;

	do
	{
		// input validation
		if (!head)
		{
			break;
		}

		SinglyListNode* current = GetNthLastNode(head, position);
		if (current)
		{
			bRet = true;
			(*retVal) = current->data;
		}

	} while (false);

	return bRet;
}

void DSLib::List::SinglyList::Reverse(SinglyListNode** head)
{
	do
	{
		// input validation
		if (!head || !(*head))
		{
			break;
		}

		SinglyListNode* current = (*head);
		SinglyListNode* temp = nullptr;
		SinglyListNode* nextNode = nullptr;

		while (current)
		{
			nextNode = current->next;
			current->next = temp;
			temp = current;
			current = nextNode;
		}

		(*head) = temp;

	} while (false);
}
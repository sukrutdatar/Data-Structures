#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

namespace DSLib
{
	namespace List
	{
		class SinglyList
		{
		public:
			static int Create(SinglyListNode** head, int numberOfNodes);
			static int Create(SinglyListNode** head, int data[], int numberOfNodes);
			static void Delete(SinglyListNode** head);
			static int Length(SinglyListNode* head);
			static SinglyListNode* GetNthNode(SinglyListNode* head, int position);
			static bool GetValueAtNthNode(SinglyListNode* head, int position, int* retVal);
			static SinglyListNode* GetNthLastNode(SinglyListNode* head, int position);
			static bool GetValueAtNthLastNode(SinglyListNode* head, int position, int* retVal);
			static void Reverse(SinglyListNode**head);
			static SinglyListNode* Reverse(SinglyListNode* head);
		};
	}
}
#endif

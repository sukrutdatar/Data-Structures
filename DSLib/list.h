#ifndef LIST_H
#define LIST_H

namespace DSLib
{
	namespace List
	{
		struct ListNode
		{
			int data;
			struct ListNode* next;
		};

		typedef ListNode SinglyListNode;

		struct DoublyListNode : public ListNode
		{
			struct DoublyListNode* previous;
		};
	}
}
#endif

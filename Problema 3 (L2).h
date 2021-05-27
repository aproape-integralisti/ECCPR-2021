#include "List.h"

template<class T>
int getCycleIndex(ForwardList<T> const &myList) {
	auto slow = myList.head, fast = myList.head;

	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			break;
		}
	}

	if (slow != fast) {
		return -1;
	}

	int index = 0;
	slow = myList.head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
		index++;
	}

	return index;
}
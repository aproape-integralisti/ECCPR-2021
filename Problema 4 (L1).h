#include "List.h"

template<class T>
void reverse(Node<T> *&first, Node<T> *last) {
	auto current = first;
	auto prev = last;

	while (current != last) {
		auto next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}
	first = prev;
}

template<class T>
void groupReverse(List<T> &myList, int groupSize) {
	auto it1 = myList.head;
	auto it2 = myList.head;
	auto prev = myList.head;

	while(it2 != nullptr){
		for(int i = 0; i < groupSize - 1 && it2 != nullptr; i++) {
			it2 = it2->next;
		}

		if(prev == myList.head){
			reverse(myList.head, it2->next);
		} else {
			prev = it1->next;

			if(it2 == nullptr){
				reverse(it1->next, it2);
			} else {
				reverse(it1->next, it2->next);
			}
		}

		it2 = prev->next;
		it1 = prev;
	}
}

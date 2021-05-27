#include "List.h"

template<class T, class Comparator>
void removeToSort(List<T> &myList, Comparator comparator){
	auto it = myList.head;

	while(it->next != myList.tail){
		if(comparator(it->data, it->next->data) == false){
			it->next = it->next->next;
			delete it->next->prev;
			it->next->prev = it;
		} else {
			it = it->next;
		}
	}
	
	if(comparator(it->data, it->next->data) == false){
		delete it->next;
		myList.tail = it;
	}
}
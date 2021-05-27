#include "List.h"

template<class T>
int size(List<T> const &myList) {
	int count = 0;

	for (auto itr = myList.head; itr; itr = itr->next) {
		count++;
	}

	return count;
}

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
bool isPalindrome(List<T> const &myList) {
	int middle = size(myList);
	middle = middle / 2 + middle % 2;

	auto it = myList.head;

	for(int i = 0; i < middle - 1; i++){
		it = it->next;
	}

	reverse(it->next, (Node<T> *) nullptr);

	auto it2 = it->next, it3 = it;
	it = myList.head;

	while (it2 != nullptr) {
		if (it->data != it2->data) {
			reverse(it3->next, (Node<T> *) nullptr);
			return false;
		}
		it = it->next;
		it2 = it2->next;
	}

	reverse(it3->next, (Node<T> *) nullptr);
	return true;
}

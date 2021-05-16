#include <bits/stdc++.h>

using namespace std;

template<class T>
struct Node{
	T data{};
	Node<T> *next{}, *prev{};

	Node(T const &data) : data(data) {}

	Node(T const &data, Node<T> *next, Node<T> *prev) : data(data), next(next), prev(prev) {}
};

template<class T>
struct List{
	Node<T> *head{}, *tail{};

	List() = default;

	void push_back(T const& e){
		if(head == nullptr){
			head = tail = new Node<T>(e);
		} else {
			tail->next = new Node<T>(e, nullptr, tail);
			tail = tail->next;
		}
	}

	void circular(){
		tail->next = head;
		head->prev = tail;
	}
};

int main(){
	int M, N, P;
	cin >> M >> N >> P;

	List<int> myIntList;
	for(int i = 1; i <= N; i++){
		myIntList.push_back(i);
	}

	myIntList.circular();

	auto it = myIntList.head;
	while(it->data != P){
		it = it->next;
	}

	while(it->next != it){
		for(auto i = 1; i < M; i++){
			it = it->next;
		}

		auto tmp = it->next;
		it->prev->next = it->next;
		it->next->prev = it->prev;
		delete it;
		it = tmp;
	}

	cout << it->data;
}

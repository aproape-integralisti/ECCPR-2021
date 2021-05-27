template <class T>
struct Node{
	T data{};
	Node<T> *next{}, *prev{};

	Node() = default;

	explicit Node(T data) : data(data) {}

	Node(T data, Node<T> *next) : data(data), next(next) {}

	Node(T data, Node<T> *prev, Node<T> *next) : data(data), prev(prev), next(next) {}

	virtual ~Node() = default;
};

template <class T>
class Deque {
private:
	int size{};
	Node<T> *head{}, *tail{}, *mid{};
public:
	Deque() = default;

	explicit Deque(Node<T> *head) : head(head) {}

	void push_back(T const &e) {
		if(tail == nullptr){
			tail = new Node<T> (e);
			size++;
			if(head == nullptr){
				head = tail;
				mid = tail;
			}
			return;
		}

		size++;
		tail->next = new Node<T> (e);
		tail->next->prev = tail;
		tail = tail->next;

		if(size % 2 == 0){
			mid = mid->next;
		}
	}

	void push_front(T const &e) {
		if(head == nullptr){
			head = new Node<T> (e);
			size++;
			if(tail == nullptr){
				tail = head;
				mid = head;
			}
			return;
		}

		size++;
		auto tmp = new Node<T> (e, head);
		head->prev = tmp;
		head = tmp;

		if(size % 2 != 0){
			mid = mid->prev;
		}
	}

	void pop_back() {
		auto tmp = tail;
		tail = tail->prev;
		tail->next = (Node<T> *) nullptr;
		delete tmp;
		size--;

		if(size % 2 != 0){
			mid = mid->prev;
		}
	}

	void pop_front() {
		auto tmp = head;
		head = head->next;
		head->prev = (Node<T> *) nullptr;
		delete tmp;
		size--;

		if(size % 2 == 0){
			mid = mid->next;
		}
	}

	T getMiddleElement() {
		return mid->data;
	}
};
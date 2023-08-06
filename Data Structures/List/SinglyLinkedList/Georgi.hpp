#include <iostream>

template<typename T>
class SinglyLinkedList {
private:
	struct Node {
		T value;
		Node* next;

		Node(const T& value, Node* next = nullptr)
			: value(value), next(next) { }
	};

	Node* head, * tail;

public:
	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList<T>&);
	SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>&);
	~SinglyLinkedList();

	void push_front(const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();
	void insert(const T&, size_t);
	void remove(size_t);
	bool contains(const T&) const;

	const T& front() const;
	const T& back() const;

	void print() const;

private:
	void copyFrom(const SinglyLinkedList<T>&);
	void free();
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
	head = tail = nullptr;
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other) {
	copyFrom(other);
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
	free();
}

template<typename T>
void SinglyLinkedList<T>::copyFrom(const SinglyLinkedList<T>& other) {
	Node* iter = other.head;

	while (iter) {
		push_back(iter->value);
		iter = iter->next;
	}
}

template<typename T>
void SinglyLinkedList<T>::free() {
	Node* iter = head;

	while (iter) {
		Node* next = iter->next;
		delete iter;
		iter = next;
	}

	head = tail = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::push_back(const T& value) {
	Node* newNode = new Node(value);

	if (!head) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = tail->next;
	}
}

template<typename T>
void SinglyLinkedList<T>::push_front(const T& value) {
	Node* newNode = new Node(value);

	if (!head) {
		head = tail = newNode;
	} 
	else {
		newNode->next = head;
		head = newNode;
	}
}

template<typename T>
void SinglyLinkedList<T>::pop_front() {
	if (!head) {
		throw std::length_error("List is empty");
	}

	Node* temp = head;
	head = head->next;
	delete temp;

	if (!head) {
		tail = nullptr;
	}
}

template<typename T>
void SinglyLinkedList<T>::pop_back() {
	if (!head)
		throw std::length_error("List is empty");

	Node* prev = nullptr;
	Node* iter = head;
	while (iter != tail) {
		prev = iter;
		iter = iter->next;
	}

	if (iter == head) {
		head = tail = nullptr;
	}
	else {
		prev->next = nullptr;
		tail = prev;
	}

	delete iter;
}

template<typename T>
void SinglyLinkedList<T>::insert(const T& value, size_t index) {
	if (index == 0) {
		push_front(value);
		return;
	}

	Node* prev = nullptr;
	Node* iter = head;
	for (size_t i = 0; i < index; i++) {
		if (!iter) {
			throw std::out_of_range("Invalid index");
		}

		prev = iter;
		iter = iter->next;
	}

	Node* newNode = new Node(value, iter);
	prev->next = newNode;
	if (tail == prev) {
		tail = newNode;
	}
}

// TODO: test
template<typename T>
void SinglyLinkedList<T>::remove(size_t index) {
	if (index == 0) {
		pop_front();
		return;
	}

	Node* prev = nullptr;
	Node* iter = head;

	for (size_t i = 0; i < index; i++) {
		if (!iter->next) {
			throw std::out_of_range("Invalid index");
		}

		prev = iter;
		iter = iter->next;
	}

	prev->next = iter->next;
	if (iter == tail) {
		tail = prev;
	}
	
	delete iter;
}

template<typename T>
bool SinglyLinkedList<T>::contains(const T& value) const {
	Node* iter = head;

	while (iter) {
		if (iter->value == value) {
			return true;
		}

		iter = iter->next;
	}

	return false;
}

template<typename T>
const T& SinglyLinkedList<T>::front() const {
	if (!head) {
		throw std::length_error("List is empty");
	}

	return head->value;
}
template<typename T>
const T& SinglyLinkedList<T>::back() const {
	if (!tail) {
		throw std::length_error("List is empty");
	}

	return tail->value;
}

template<typename T>
void SinglyLinkedList<T>::print() const {
	Node* iter = head;

	while (iter) {
		std::cout << iter->value << " ";
		iter = iter->next;
	}

	std::cout << "\n";
}
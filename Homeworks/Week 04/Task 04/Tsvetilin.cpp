#include <iostream>

struct Node
{
	Node* previous;
	Node* next;
	size_t data;
};

struct List
{
	Node* head = nullptr;
	Node* tail = nullptr;

	size_t count = 0;

	Node* push_front(size_t data)
	{
		Node* toAdd = new Node{ nullptr, head, data };

		if (head != nullptr) 
			head->previous = toAdd;

		if (tail == nullptr)
			tail = toAdd;

		head = toAdd;
		++count;

		return head;
	}

	void erase(Node* node)
	{
		--count;

		if (node == head)
		{
			Node* newHead = head->next;
			delete head;
			head = newHead;
			if (head == nullptr)
				tail = nullptr;

			return;
		}

		if (node == tail)
		{
			Node* newTail = tail->previous;
			delete tail;
			tail = newTail;
			return;
		}

		node->previous->next = node->next;
		node->next->previous = node->previous;
		delete node;
	}

	size_t erase_back()
	{
		if (tail != nullptr)
		{
			--count;

			size_t x = tail->data;
			Node* newTail = tail->previous;
			delete tail;
			tail = newTail;

			if (tail == nullptr)
				head = nullptr;
			else
				tail->next = nullptr;
                
			return x;
		}

		return -1;
	}

	void move_front(Node* node)
	{
		if (node == head)
			return;

		if (node == tail)
		{
			Node* newTail = tail->previous;
			newTail->next = nullptr;
			tail->next = head;
			tail->previous = nullptr;
			head->previous = tail;
			head = tail;
			tail = newTail;
			return;
		}

		node->previous->next = node->next;
		node->next->previous = node->previous;
		node->next = head;
		node->previous = nullptr;
		head->previous = node;
		head = node;
	}

};

const size_t MAX_SIZE = 1e5;
Node* arr[MAX_SIZE];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);


	size_t n, t;
	std::cin >> n >> t;

	List list;

	size_t x;

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> x;

		if (arr[x] != nullptr)
		{
			list.move_front(arr[x]);
			std::cout << "true\n";
		}
		else
		{
			if (list.count == t)
				arr[list.erase_back()] = nullptr;

			arr[x] = list.push_front(x);
			std::cout << "false\n";
		}

	}
}
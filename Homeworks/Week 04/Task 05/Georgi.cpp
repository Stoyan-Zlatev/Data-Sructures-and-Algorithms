#include <iostream>

const std::string GAME_OVER = "Game Over\n";

struct Ball {
	int color;
	size_t label;
};

bool operator==(const Ball& lhs, const Ball& rhs) {
	return lhs.color == rhs.color;
}

struct Node {
	Ball value;
	Node* next;
	Node* prev;

	Node(const Ball& value, Node* next = nullptr, Node* prev = nullptr) {
		this->value = value;
		this->next = next;
		this->prev = prev;
	}
};

class DoublyLinkedList {
private:
	Node* head, * tail;
	size_t length = 0;
public:
	DoublyLinkedList() {
		head = tail = nullptr;
	}

	size_t getLength() {
		return length;
	}

	Node* push_back(const Ball& value) {
		++length;
		Node* newNode = new Node(value);
		if (tail == nullptr) {
			head = tail = newNode;
			return tail;
		}

		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;

		return tail;
	}

	Node* insertAfter(const Ball& value, Node* nextTo) {
		++length;
		if (nextTo->next == nullptr) {
			nextTo->next = new Node(value, nullptr, nextTo);
			tail = nextTo->next;
			return nextTo->next;
		}

		Node* temp = nextTo->next;
		Node* newNode = new Node(value, temp, nextTo);
		nextTo->next = newNode;
		temp->prev = newNode;

		return newNode;
	}

	void removeRange(Node* start, Node* end) {
		if (start == nullptr) {
			start = head;
		}
		if (end == nullptr) {
			end = tail;
		}

		if (start == head) {
			head = end->next;

			if (head != nullptr)
				head->prev = nullptr;
		}
		else {
			start->prev->next = end->next;
		}

		if (end == tail) {
			tail = start->prev;

			if (tail != nullptr)
				tail->next = nullptr;
		}
		else {
			end->next->prev = start->prev;
		}

		int removed = 1;
		while (start != end) {
			Node* next = start->next;
			delete start;
			start = next;
			removed++;
		}

		delete end;
		length -= removed;
	}

	void print() {
		if (head == nullptr) {
			std::cout << -1;
			return;
		}

		Node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->value.color << " ";
			temp = temp->next;
		}
	}
};

int removeNodes(DoublyLinkedList& list, Node* node) {
	if (node == nullptr) {
		return 0;
	}

	Node* start = node->prev;
	Node* end = node->next;
	int difference = 1;

	while (start != nullptr && start->value == node->value) {
		difference++;
		start = start->prev;
	}

	if (start != nullptr) {
		start = start->next;
	}

	while (end != nullptr && end->value == node->value) {
		difference++;
		end = end->next;
	}

	if (end != nullptr) {
		end = end->prev;
	}

	if (difference < 3) {
		return 0;
	}

	Node* temp = nullptr;
	if (
		start != nullptr && start->prev != nullptr &&
		end != nullptr && end->next != nullptr &&
		start->prev->value == end->next->value
		)
	{
		temp = start->prev;
	}

	list.removeRange(start, end);
	return difference + removeNodes(list, temp);
}

Node* nodesContainer[200000];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int ballsCount, queries;
	DoublyLinkedList balls;

	std::cin >> ballsCount;
	size_t nextIndex = ballsCount;

	for (size_t i = 0; i < ballsCount; i++) {
		Ball ball;
		ball.label = i;
		std::cin >> ball.color;
		Node* newNode = balls.push_back(ball);
		nodesContainer[i] = newNode;
	}

	std::cin >> queries;

	for (size_t i = 0; i < queries; i++) {
		int shootAt;
		Ball ball;
		std::cin >> shootAt >> ball.color;
		ball.label = nextIndex;
		if (balls.getLength() == 0) {
			std::cout << GAME_OVER;
			continue;
		}

		Node* insertedNode = balls.insertAfter(ball, nodesContainer[shootAt]);
		nodesContainer[nextIndex++] = insertedNode;
		int removed = removeNodes(balls, insertedNode);
		std::cout << removed << '\n';
	}

	balls.print();
}
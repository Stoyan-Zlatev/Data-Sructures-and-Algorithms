#include <iostream>

struct Node;

const size_t MAX_SIZE = 1e5;
Node* originalBalls[MAX_SIZE]{};
Node* shootBalls[MAX_SIZE]{};

struct Node
{
	size_t color = 0;
	size_t number = 0;

	Node* previous = nullptr;
	Node* next = nullptr;

	static Node* of(size_t color, size_t number)
	{
		return new Node{ color, number };
	}
};

struct List
{
	Node* head = nullptr;
	Node* tail = nullptr;

	size_t count = 0;

	Node* push_after(Node* node, Node* after)
	{
		if (after == tail)
			return push_back(node);

		node->next = after->next;
		node->previous = after;
		after->next = node;
		node->next->previous = node;

		++count;

		return node;
	}

	Node* push_back(Node* node)
	{
		++count;

		if (count == 1)
		{
			head = tail = node;
			return node;
		}

		node->previous = tail;
		node->next = nullptr;
		tail->next = node;
		tail = node;

		return node;
	}

	// remove nodes between those; nullptr for head/tail removal
	void removeRange(Node* left, Node* right)
	{
		Node* current;

		if (!left)
			current = head;
		else
			current = left->next;

		while (current != right)
		{
			Node* temp = current->next;
			delete current;
			current = temp;
			--count;
		}

		if(!left && !right)
		{
			head = tail = nullptr;
		}

		if (!left && right)
		{
			head = right;
			head->previous = nullptr;
		}

		if (!right && left)
		{
			tail = left;
			tail->next = nullptr;
		}

		if (left && right)
		{
			left->next = right;
			right->previous = left;
		}
	}


	size_t pop_alike(Node* node, bool isMerged = false)
	{
		if (count == 0 || node == nullptr)
		{
			return 0;
		}

		Node* left = node;
		Node* right = node;

		long long leftCount = 0;
		long long rightCount = 0;

		bool tailContained = false;
		bool headContained = false;

		while (left->color == node->color)
		{
			++leftCount;

			if (left == head)
			{
				headContained = true;
				break;
			}

			left = left->previous;
		}

		while (right->color == node->color)
		{
			++rightCount;

			if (right == tail)
			{
				tailContained = true;
				break;
			}

			right = right->next;
		}

		--rightCount;

		if (((leftCount > 0 && rightCount > 0) || !isMerged) && leftCount + rightCount >= 3)
		{
			removeRange(headContained ? nullptr : left, tailContained ? nullptr : right);
			return leftCount + rightCount + (headContained || tailContained ? 0 : pop_alike(left, true));
		}

		return 0;
	}

	void print(std::ostream& stream)
	{
		Node* current = head;
		while (current != nullptr)
		{
			stream << current->color << " ";
			current = current->next;
		}
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t ballsCount;
	size_t requestCount;

	List balls;

	std::cin >> ballsCount;

	size_t ball, color;
	for (size_t i = 0; i < ballsCount; i++)
	{
		std::cin >> color;
		originalBalls[i] = balls.push_back(Node::of(color, i));
	}

	std::cin >> requestCount;
	Node* current;

	for (size_t i = 0; i < requestCount; i++)
	{
		std::cin >> ball >> color;

		if (balls.count == 0)
		{
			std::cout << "Game Over\n";
			continue;
		}

		if (ball < ballsCount)
			current = originalBalls[ball];
		else
			current = shootBalls[ball % ballsCount];

		shootBalls[i] = balls.push_after(Node::of(color, ballsCount + i), current);

		std::cout << balls.pop_alike(shootBalls[i]) << "\n";
	}

	if (balls.count == 0)
		std::cout << "-1\n";
	else
		balls.print(std::cout);
}
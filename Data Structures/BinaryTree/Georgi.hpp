#include <iostream>
#include <queue>

template <typename T>
struct Node {
	T value;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(const T& value) : value(value) { }

	Node(const Node<T>& other) {
		copyFrom(other);
	}

	Node& operator=(const Node<T>& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}

		return *this;
	}

	~Node() {
		free();
	}

private:
	void free() {
		delete left;
		delete right;
		left = right = nullptr;
	}

	void copyFrom(const Node<T>& other) {
		value = other.value;

		if (other.right) {
			right = new Node(*other.right);
		}

		if (other.left) {
			left = new Node(*other.left);
		}
	}
};

template <typename T>
class BinarySearchTree {
private:
	Node<T>* root;

	Node<T>* _insert(Node<T>* current, const T& value);
	bool _contains(const Node<T>* current, const T& value) const;
	Node<T>* _remove(Node<T>* current, const T& value);

	void _dfs(const Node<T>* current) const;
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<T>& other);
	BinarySearchTree<T>& operator=(const BinarySearchTree<T>& other);
	~BinarySearchTree();

	bool contains(const T&) const;
	void insert(const T&);
	void remove(const T&);

	void dfs() const;
	void bfs() const;

private:
	void copyFrom(const BinarySearchTree&);
	void free();
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
	root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other) {
	copyFrom(other);
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
	free();
}

template <typename T>
void BinarySearchTree<T>::copyFrom(const BinarySearchTree<T>& other) {
	root = new Node<T>(*other.root);
}

template <typename T>
void BinarySearchTree<T>::free() {
	delete root;
}

template <typename T>
Node<T>* BinarySearchTree<T>::_insert(Node<T>* current, const T& value) {
	if (!current) {
		return new Node<T>(value);
	}

	if (current->value < value) {
		current->right = _insert(current->right, value);
	}
	else if (value < current->value) {
		current->left = _insert(current->left, value);
	}

	return current;
}

template <typename T>
bool BinarySearchTree<T>::_contains(const Node<T>* current, const T& value) const {
	if (!current) {
		return false;
	}

	if (current->value == value) {
		return true;
	}

	return current->value > value ? contains(current->left, value) : contains(current->right, value);
}

template <typename T>
Node<T>* BinarySearchTree<T>::_remove(Node<T>* current, const T& value) {
	if (!current) {
		return nullptr;
	}

	if (value < current->value) {
		current->left = _remove(current->left, value);
	}
	else if (current->value < value) {
		current->right = _remove(current->right, value);
	}
	else {
		if (!current->left && !current->right) {
			return nullptr;
		}
		if (!current->left) {
			return current->right;
		}
		if (!current->right) {
			return current->left;
		}
		
		Node<T>* iter = current->right;

		while (iter->left) {
			iter = iter->left;
		}

		current->value = iter->value;
		current->right = _remove(current->right, current->value);
	}

	return current;
}

template <typename T>
bool BinarySearchTree<T>::contains(const T& value) const {
	return _contains(root, value);
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value) {
	root = _insert(root, value);
}

template <typename T>
void BinarySearchTree<T>::remove(const T& value) {
	root = _remove(root, value);
}

template <typename T>
void BinarySearchTree<T>::_dfs(const Node<T>* current) const {
	if (!current) {
		return;
	}

	_dfs(current->left);
	std::cout << current->value << " ";
	_dfs(current->right);
}

template <typename T>
void BinarySearchTree<T>::dfs() const {
	_dfs(root);
}

template <typename T>
void BinarySearchTree<T>::bfs() const {
	std::queue<Node<T>*> container;
	container.push(root);

	while (!container.empty()) {
		Node<T>* current = container.front();
		container.pop();

		if (current) {
			std::cout << current->value << " ";

			container.push(current->left);
			container.push(current->right);
		}
	}
}
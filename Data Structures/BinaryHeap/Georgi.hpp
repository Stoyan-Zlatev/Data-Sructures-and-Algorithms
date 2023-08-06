#include <vector>

template<typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
class Heap {
private:
	std::vector<T> dataContainer;

	size_t leftChild(size_t index) const { return index * 2 + 1; }
	size_t rightChild(size_t index) const { return index * 2 + 2; }
	size_t parent(size_t index) const { return (index - 1) / 2; }

	void siftUp(size_t index);
	void siftDown(size_t index);

public:
	void push(const T&);
	bool empty() const;
	const T& peek() const;
	void pop();
};

template<typename T>
void Heap<T>::siftUp(size_t index) {
	size_t parentIndex = parent(index);

	// The top value(dataContainer[0]) will be the max value
	while (dataContainer[parentIndex] < dataContainer[index]) {
		swap(dataContainer[parentIndex], dataContainer[index]);
		if (parentIndex == 0) {
			return;
		}

		index = parentIndex;
		parentIndex = parent(parentIndex);
	}
}

template<typename T>
void Heap<T>::siftDown(size_t index) {
	size_t leftChildIndex = leftChild(index);
	size_t rightChildIndex = rightChild(index);

    // if we have two children and atleast one of them
    // is bigger than current => swap
	if (leftChildIndex < dataContainer.size() && 
		rightChildIndex < dataContainer.size() &&
		(dataContainer[index] < dataContainer[leftChildIndex] || dataContainer[index] < dataContainer[rightChildIndex])) {
		size_t swapWithIndex = dataContainer[leftChildIndex] < dataContainer[rightChildIndex] ? rightChildIndex : leftChildIndex;
		swap(dataContainer[index], dataContainer[swapWithIndex]);
		siftDown(swapWithIndex);
	}
	// if we have only left child and is bigger than current
	// impossible to have only right
	else if(leftChildIndex < dataContainer.size() &&
		dataContainer[index] < dataContainer[leftChildIndex]) {
		swap(dataContainer[index], dataContainer[leftChildIndex]); // the left child has no more children
	}
}

template<typename T>
void Heap<T>::push(const T& data) {
	dataContainer.push_back(data);
	if (dataContainer.size() > 1) {
		siftUp(dataContainer.size() - 1);
	}
}

template<typename T>
bool Heap<T>::empty() const {
	return dataContainer.size() == 0;
}

template<typename T>
const T& Heap<T>::peek() const {
	return dataContainer[0];
}

template<typename T>
void Heap<T>::pop() {
	if (dataContainer.size() == 1) {
		dataContainer.pop_back();
		return;
	}

	swap(dataContainer[0], dataContainer[dataContainer.size() - 1]);
	dataContainer.pop_back();
	siftDown(0);
}
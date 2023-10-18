#include <iostream>
#include <queue>

struct record {
	size_t index;
	size_t startTime;
	size_t duration;

	record(size_t index, size_t startTime, size_t duration) :
		index(index),
		startTime(startTime),
		duration(duration) {}
};

struct OrderByStartTimeComparator {
	bool operator()(const record& first, const record& second) const {
		return first.startTime > second.startTime;
	}
};

struct OrderByDurationComparator {
	bool operator()(const record& first, const record& second) const {
		return first.duration != second.duration ? first.duration > second.duration : first.index > second.index;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::priority_queue<record, std::vector<record>, OrderByStartTimeComparator> placedOrders;
	std::priority_queue<record, std::vector<record>, OrderByDurationComparator> currentOrders;

	size_t n;
	std::cin >> n;

	size_t time, duration;
	for (size_t i = 0; i < n; i++) {
		std::cin >> time >> duration;
		placedOrders.push(record(i, time, duration));
	}

	size_t end = 0;
	while (true)
	{
		if (placedOrders.empty() && currentOrders.empty()) {
			break;
		}

		if (currentOrders.empty() && !placedOrders.empty())
		{
			currentOrders.push(placedOrders.top());
			placedOrders.pop();
			end = currentOrders.top().startTime;
		}

		std::cout << currentOrders.top().index << " ";
		end += currentOrders.top().duration;
		currentOrders.pop();

		while (!placedOrders.empty() && placedOrders.top().startTime <= end)
		{
			currentOrders.push(placedOrders.top());
			placedOrders.pop();
		}
	}

	return 0;
}

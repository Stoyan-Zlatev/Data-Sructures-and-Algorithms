#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

struct CustomOperatorStruct
{
    int x;

    bool operator<(const CustomOperatorStruct &other) const
    {
        return this->x > other.x;
    }
};

struct CustomComparatorStruct
{
    bool operator()(const CustomOperatorStruct &first, const CustomOperatorStruct &second) const
    {
        return first.x > second.x;
    }
};

int main()
{
    // auto - infers the type of the variable from the initializer
    auto x1 = 5;   // int
    auto x2 = 5.5; // double

    std::greater<CustomComparatorStruct>; // get the comparator (operator >) from the struct
    std::less<CustomComparatorStruct>;    // get the comparator (operator <) from the struct

    // array
    int *arr = new int[10]{}; // Initialize with 0s
    // Iterate using index
    for (int i = 0; i < 10; i++)
        arr[i];

    // vector
    auto vector = std::vector<int>(10, 0); // Initial size = 10, Initialize with 0s
    vector[0] = 1;                         // Access index
    vector.push_back(1);                   // Append new item
    vector.pop_back();                     // Remove last item
    vector.clear();                        // Remove all elements
    vector.resize(5);                      // Change size
    vector.reserve(10);                    // Change capacity
    vector[0];                             // Access index
    vector.at(1);                          // Access index == vec[2]
    vector.front();                        // First item == vec[0]
    vector.back();                         // Last item == vec[vec.size() - 1]
    vector.insert(vector.begin() + 2, 20); // Insert 42 at index 2
    vector.erase(vector.begin() + 2);      // Remove item at index 2

    // Iterate using index
    for (int i = 0; i < vector.size(); i++)
        vector[i];

    // Iterate using iterator
    for (auto it = vector.begin(); it != vector.end(); it++)
        *it;

    // Iterate using iterator
    for (int &element : vector)
        element;

    // Stack
    std::stack<int> stack;
    stack.push(1); // Add new element to top
    stack.top();   // View the top element
    stack.pop();   // Remove the top element
    stack.size();  // Get the size

    // Queue
    std::queue<int> queue;
    queue.push(1); // Add new element to the back
    queue.front(); // Get the front element
    queue.back();  // Get the back element
    queue.pop();   // Remove the front element
    queue.size();  // Get the size

    // Deque
    std::deque<int> deque;
    deque.push_back(1);  // Add element to back
    deque.push_front(0); // Add element to front
    deque.pop_back();    // Remove element from back
    deque.pop_front();   // Remove element from front
    deque.front();       // Get front element
    deque.back();        // Get back element
    deque.clear();       // Remove all elements

    // List
    std::list<int> list;
    list.push_back(1);  // Add element to back
    list.push_front(0); // Add element to front
    list.pop_back();    // Remove element from back
    list.pop_front();   // Remove element from front
    list.front();       // Get front element
    list.back();        // Get back element
    list.reverse();     // Reverse
    list.sort();        // Sort
    list.clear();       // Remove all elements

    auto iteratorList = list.begin(); // get iterator to first element
    std::advance(iteratorList, 1);    // move iterator to position 1 -> forward (according to current position)
    std::advance(iteratorList, -1);   // move iterator to position 0 -> backward (according to current position)
    std::prev(iteratorList);          // get previous iterator
    std::next(iteratorList);          // get next iterator

    // Insert element at position 1
    auto insertIndex = list.begin();
    std::advance(insertIndex, 1); // move iterator to position 1
    list.insert(insertIndex, 42);

    // Erase element at position 0
    auto removeIndex = list.begin();
    std::advance(removeIndex, 0); // move iterator to position 0
    list.erase(removeIndex);

    // Heap
    std::priority_queue<int> pq;                                                                                       // Default pq is max heap
    std::priority_queue<CustomOperatorStruct> pq_custom;                                                               // Use custom compare function implemented in struct
    std::priority_queue<CustomOperatorStruct, std::vector<CustomComparatorStruct>, CustomComparatorStruct> pq_custom2; // Use custom compare function
    pq.push(1);                                                                                                        // Add new element
    pq.top();                                                                                                          // Peek top
    pq.pop();                                                                                                          // Pop top
    pq.size();                                                                                                         // Get size

    // Set
    std::set<int> set;                                                                  // Default set is sorted ascending
    std::set<CustomComparatorStruct> set_custom;                                        // Use custom compare function
    std::set<CustomComparatorStruct, std::greater<CustomComparatorStruct>> set_custom2; // Use custom compare function
    set.insert(1);                                                                      // Add element
    set.begin();                                                                        // Get iterator to min element
    set.rbegin();                                                                       // Get iterator to max element
    set.size();                                                                         // Get the size
    set.erase(1);                                                                       // Remove element
    set.erase(set.begin());                                                             // Remove element
    set.count(20);                                                                      // Count occurrences, always 1 or 0
    set.find(20);                                                                       // Valid iterator to the element if found, otherwise st.end()
    set.lower_bound(20);                                                                // Iterator to the first element >= 42
    set.upper_bound(20);                                                                // Iterator to the first element > 42
    set.clear();                                                                        // Remove all elements

    // Iterate set
    for (auto &element : set)
        element;

    // map
    std::map<int, int> map;                    // Default map is sorted ascending by key
    map.insert(std::pair<int, int>(-1, -100)); // Insert or change with key-value pair
    map.insert({1, 100});                      // Insert or change with key-value pair
    map[999];                                  // Default value if key not found 0
    map[12] = 20;                              // Insert or change by key
    map.erase(-1);                             // Remove element by key
    map.count(20);                             // Count occurrences of key, always 1 or 0
    map.find(1);                               // Iterator to the element if found, mp.end() otherwise
    map.clear();                               // Remove all elements

    // Iterate map where element is (key,value)
    for (auto element : map)
        element;

    // multimap
    std::multimap<int, int> multimap;              // Default multimap is sorted ascending by key, order of values is not guaranteed
    multimap.insert(std::pair<int, int>(1, -100)); // Insert change with key-value pair
    multimap.insert(std::pair<int, int>(1, -100)); // Insert change with key-value pair
    multimap.insert({1, 300});                     // Insert change with key-value pair
    multimap.erase(1);                             // Removes all occurrences by key
    multimap.count(1);                             // Count occurrences of key
    multimap.find(1);                              // Iterator to the element if found, mp.end() otherwise
    multimap.clear();                              // Remove all elements

    // Iterate multimap where element is (key,value)
    for (auto element : multimap)
        element;

    // unordered_set
    std::unordered_set<int> hash_set;
    hash_set.insert(1);  // Add element
    hash_set.insert(-1); // Add element
    hash_set.erase(-1);  // Remove elemnt
    hash_set.count(1);   // Count occurrences, always 1 or 0
    hash_set.find(1);    // Iterator to the element if found, otherwise ust.end()
    hash_set.clear();    // Remove all elements

    // unordered_multiset
    std::unordered_multiset<int> unordered_multiset;
    unordered_multiset.insert(1);  // Add element
    unordered_multiset.insert(-1); // Add element
    unordered_multiset.erase(-1);  // Remove elemnt
    unordered_multiset.count(1);   // Count occurrences
    unordered_multiset.find(1);    // Iterator to the element if found, otherwise ust.end()
    unordered_multiset.clear();    // Remove all elements

    // unordered_map
    std::unordered_map<int, int> hash_map;
    hash_map.insert(std::pair<int, int>(-1, -100)); // Insert or change with key-value pair
    hash_map.insert({1, 100});                      // Insert or change with key-value pair
    hash_map[12] = 20;                              // Insert or change by key
    hash_map[999];                                  // Default value if key not found 0
    hash_map.erase(-1);                             // Remove element by key
    hash_map.count(2);                              // Count occurrences, always 1 or 0
    hash_map.find(2);                               // Iterator to the element if found, mp.end() otherwise
    hash_map.clear();                               // Remove all elements

    // algorithms
    std::max_element(vector.begin(), vector.end());                     // Get  iterator to max element
    std::min_element(vector.begin(), vector.end());                     // Get iterator to min element
    std::nth_element(vector.begin(), vector.begin() + 2, vector.end()); // Rearrange elements so nth is the pivot
    std::count(vector.begin(), vector.end(), 20);                       // Count the occurrences of 42
    std::find(vector.begin(), vector.end(), 20);                        // Iterator to the first occurrence of 42, vector.end() if not found
    std::lower_bound(vector.begin(), vector.end(), 20);                 // Iterator to the first element >= 42
    std::upper_bound(vector.begin(), vector.end(), 20);                 // Iterator to the first element > 42
    std::binary_search(vector.begin(), vector.end(), 20);               // True if 42 exists in the sorted collection

    std::sort(vector.begin(), vector.end());        // Sort
    std::stable_sort(vector.begin(), vector.end()); // Stable sort
    std::sort(vector.begin(), vector.end(),
              [](auto a, auto b)
              { return a > b; }); // Sort with custom function

    std::next_permutation(vector.begin(), vector.end()); // Get the next permutation
    std::replace(vector.begin(), vector.end(), 0, 20);   // Replace all occurrences of 0 with 42
    std::partition(vector.begin(), vector.end(),
                   [](auto a)
                   { return a < 10; }); // Partition and return iterator to pivot
}
# Task 3. Delete a Node (Easy) - [HackerRank](<https://www.hackerrank.com/contests/sda-hw-4-2022/challenges/delete-a-node-from-a-linked-list>)

## Statement:

Delete the node at a given position in a linked list and return a reference to the head node. The head is at position 0. The list may be empty after you delete the node. In that case, return a null value.


**Function Description**

Complete the **deleteNode** function in the editor below.

**deleteNode** has the following parameters:
- SinglyLinkedListNode pointer llist: a reference to the head node in the list
- int position: the position of the node to remove

**Returns**
- SinglyLinkedListNode pointer: a reference to the head of the modified list

**Input Format**

The first line of input contains an integer $n$, the number of elements in the linked list.
Each of the next $n$ lines contains an integer, the node data values in order.
The last line contains an integer, $position$, the position of the node to delete.

**Constraints**

$1 \le n \le 10^3$

$1 \le data \le 10^3$

---

**Sample Input 0**

```
8
20
6
2
19
7
4
15
9
3
```

**Sample Output 0**

```
20 6 2 7 4 15 9
```
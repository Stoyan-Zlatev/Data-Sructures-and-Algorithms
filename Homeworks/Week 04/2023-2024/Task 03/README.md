# Task: Insert a node at a specific position in a linked list (Easy) - [HackerRank](<https://www.hackerrank.com/contests/sda-hw-4-2023/challenges/insert-a-node-at-a-specific-position-in-a-linked-list>)


### Statement:

<sub>This challenge is part of a tutorial track by <a href="https://www.hackerrank.com/external_redirect?to=http://www.youtube.com/mycodeschool" target="_blank">MyCodeSchool</a> and is accompanied by a video lesson.</sub>

Given the pointer to the head node of a linked list and an integer to insert at a certain position, create a new node with the given integer as its $data$ attribute, insert this node at the desired position and return the head node.  

A position of 0 indicates head, a position of 1 indicates one node away from the head and so on. The head pointer given may be null meaning that the initial list is empty.  

**Example** 

$head$ refers to the first node in the list $1 ->2 ->3$ 
$data 4$ 
$position =2$  

Insert a node at position $2$ with $data=4$.  The new list is $1 -> 2 -> 4 ->3$

**Function Description**

Complete the function *insertNodeAtPosition* in the editor below.  It must return a reference to the head node of your finished list.

insertNodeAtPosition has the following parameters:

* $head$ a SinglyLinkedListNode pointer to the head of the list
* $data$ an integer value to insert as data in your new node
* $position$  an integer position to insert the new node, zero based indexing

**Returns**  
 * $SinglyLinkedListNode pointer:$ a reference to the head of the revised list

### Input format

The first line contains an integer $n$, the number of elements in the linked list. 

Each of the next $n$ lines contains an integer SinglyLinkedListNode[i].data. 

The next line contains an integer $data$, the data of the node that is to be inserted. 

The last line contains an integer $posiiton$.


### Constraints

$1\le n \le 1000$

$1\le SinglyLinkedListNode[i].data \le 1000$

$0\le position \le$


### Sample input

```
3
16
13
7
1
2
```

### Sample Output

```
16 13 1 7
```



#### Explanation
The initial linked list is $16 ->13 ->7$ Insert $1$ at the position $2$ which currently has $7$ in it. The updated linked list is $16 -> 13 ->1 ->7$

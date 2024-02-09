HackerRank Home
HackerRank
|
Prepare
Certify
Compete
Apply
Search
 
All Contests  СДА Домашно 4 2023-2024  Delete duplicate-value nodes from a sorted linked list
Delete duplicate-value nodes from a sorted linked listlocked
Problem
Submissions
Leaderboard
Discussions
Submitted 4 months ago • Score: 30.00Status: Accepted
 Test Case #0
 Test Case #1
 Test Case #2
 Test Case #3
 Test Case #4
 Test Case #5
 Test Case #6

Submitted Code
Language: C++14

 Open in editor
61
/*
62
 * Complete the 'removeDuplicates' function below.
63
 *
64
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
65
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
66
 */
67
​
68
/*
69
 * For your reference:
70
 *
71
 * SinglyLinkedListNode {
72
 *     int data;
73
 *     SinglyLinkedListNode* next;
74
 * };
75
 *
76
 */
77
​
78
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
79
    
80
    SinglyLinkedListNode* current = llist->next;
81
    SinglyLinkedListNode* prev = llist;
82
    
83
    while(current!=nullptr)
84
    {
85
        if(current->data == prev->data)
86
        {
87
            prev->next = current->next;
88
            current = prev->next;
89
        }else
90
        {
91
            prev = current;
92
            current = current->next;
93
        }
94
    }
95
    return llist;
96
}
Interview Prep | Blog | Scoring | Environment | FAQ | About Us | Support | Careers | Terms Of Service | Privacy Policy |


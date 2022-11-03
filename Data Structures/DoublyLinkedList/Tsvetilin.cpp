
struct Node
{
    size_t data;

    Node *previous = nullptr;
    Node *next = nullptr;
};

struct List
{
    Node *head = nullptr;
    Node *tail = nullptr;

    size_t count = 0;

    void push_front(Node *node)
    {
        if (head != nullptr)
            head->previous = node;

        if (tail == nullptr)
            tail = node;

        head = node;
        ++count;
    }

    void push_back(Node *node)
    {
        ++count;

        if (count == 1)
        {
            head = tail = node;
            return;
        }

        node->previous = tail;
        node->next = nullptr;
        tail->next = node;
        tail = node;
    }

    void pop_front()
    {
        if (head == nullptr)
            return;

        --count;

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node *newHead = head->next;
        delete head;
        head = newHead;
        head->previous = nullptr;
    }

    void pop_back()
    {
        if (tail == nullptr)
        {
            return;
        }

        --count;

        Node *newTail = tail->previous;
        delete tail;
        tail = newTail;

        if (tail == nullptr)
            head = nullptr;
        else
            tail->next = nullptr;
    }

    void insert(Node *node, size_t position)
    {
        if (position > count)
            return;
    }

    void insert_after(Node *node, Node *after)
    {
        if (after == tail)
            return push_back(node);

        node->next = after->next;
        node->previous = after;
        after->next = node;
        node->next->previous = node;

        ++count;
    }

    void erase(Node *node)
    {
        --count;

        if (node == head)
        {
            Node *newHead = head->next;
            delete head;
            head = newHead;
            if (head == nullptr)
                tail = nullptr;

            return;
        }

        if (node == tail)
        {
            Node *newTail = tail->previous;
            delete tail;
            tail = newTail;
            return;
        }

        node->previous->next = node->next;
        node->next->previous = node->previous;
        delete node;
    }

    // remove nodes between those; nullptr for head/tail removal
    void erase_range(Node *left, Node *right)
    {
        Node *current;

        if (!left)
            current = head;
        else
            current = left->next;

        while (current != right)
        {
            Node *temp = current->next;
            delete current;
            current = temp;
            --count;
        }

        if (!left && !right)
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

    void move_front(Node *node)
    {
        if (node == head)
            return;

        if (node == tail)
        {
            Node *newTail = tail->previous;
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
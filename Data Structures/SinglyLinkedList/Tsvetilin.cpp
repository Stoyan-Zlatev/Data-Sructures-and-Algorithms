
struct Node
{
    size_t data;

    Node *next = nullptr;
};

struct List
{
    Node *head = nullptr;
    Node *tail = nullptr;

    size_t count = 0;

    void push_front(Node *node)
    {
        if (tail == nullptr)
            tail = node;

        node->next = head;
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
    }

    void pop_back()
    {
        if (tail == nullptr)
        {
            return;
        }

        if (head == tail)
        {
            head = tail = nullptr;
            count = 0;
            return;
        }

        --count;

        Node *prev = nullptr;
        Node *current = head;
        while (current)
        {
            prev = current;
            current = current->next;
        }

        delete tail;
        tail = prev;
        prev->next = nullptr;
    }

    void insert(Node *node, size_t position)
    {
        if (position > count)
            return;

        size_t index = 0;
        Node *prev = nullptr;
        Node *current = head;
        while (current && index < position)
        {
            prev = current;
            current = current->next;
            ++index;
        }

        if (prev == nullptr)
        {
            push_front(node);
            return;
        }

        if (prev == tail)
        {
            push_back(node);
            return;
        }

        prev->next = node;
        node->next = current;
        ++count;
    }

    void erase(Node *node)
    {
        if (node == head)
        {
            pop_front();
            return;
        }

        if (node == tail)
        {
            pop_back();
            return;
        }

        --count;

        Node *prev = nullptr;
        Node *current = head;
        while (current != node)
        {
            prev = current;
            current = current->next;
        }

        prev->next = node->next;
        delete node;
    }
};
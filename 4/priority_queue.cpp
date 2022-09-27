#include <fstream>
#include <iostream>
#include <vector>

struct element {
    int value;
    int index;

    explicit element(int v, int n) : value(v), index(n) {}
    element() : value(0), index(0) {}

    bool operator< (const element& other) const
    {
        return this->value < other.value;
    }

    element& operator= (int other)
    {
        this->value = other;
        return *this;
    }

    bool operator== (int other) const
    {
        return this->index == other;
    }
};

template <typename T>
class priority_queue
{
    std::vector<T> heap;

    void sift_up(int i)
    {
        while (true)
        {
            int parent = i == 0 ? 0 : (i - 1) / 2;
            if (heap[i] < heap[parent])
            {
             std::   swap(heap[i], heap[parent]);
                i = parent;
            }
            else
                break;
        }
    }

    void sift_down(int i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < heap.size() && heap[l] < heap[i])
            smallest = l;

        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i)
        {
         std::   swap(heap[i], heap[smallest]);
            sift_down(smallest);
        }
    }

    int find(int key)
    {
        for (int i = 0; i < heap.size(); i++)
        {
            if (heap[i] == key)
            {
                return i;
            }
        }
    }

public:
    bool extract_min(T& min)
    {
        if (heap.empty())
            return false;
        min = heap[0];
       std:: swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        sift_down(0);
        return true;
    }

    void push(T elem)
    {
        heap.push_back(elem);
        sift_up(heap.size() - 1);
    }

    void decrease_key(int key, int new_value)
    {
        int i = find(key);
        heap[i] = new_value;
        sift_up(i);
    }
};

int main()
{
    std::ifstream input("priorityqueue.in");
    std::ofstream output("priorityqueue.out");

    priority_queue<element> queue;
    int line = 0;
    while (!input.eof())
    {
        line++;
        std::string command;
        input >> command;

        if (command == "push")
        {
            int key;
            input >> key;
            queue.push(element(key, line));
        }
        else if (command == "extract-min")
        {
            element min_key;
            if (queue.extract_min(min_key))
                output << min_key.value << '\n';
            else
                output << "*" << '\n';
        }
        else if (command == "decrease-key")
        {
            int index, new_value;
            input >> index >> new_value;
            queue.decrease_key(index, new_value);
        }
    }

    return 0;
}

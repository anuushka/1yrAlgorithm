#include <bits/stdc++.h>

struct queue
{
   std::vector<int> q;
    int l = 0;
    int r = 0;

    explicit queue(int size)
    {
        q.resize(size + 1);
    }

    void push(int value)
    {
        q[r++] = value;
    }

    int pop()
    {
        return q[l++];
    }
};

int main()
{
   std:: ifstream input("queue.in");

    int m = 0;
    input >> m;

    queue q(m);
    std:: ofstream output("queue.out");

    for (int i = 0; i < m; ++i)
    {
    	std:: string com;
        input >> com;
       
        if (com == "+")
        {
            int x = 0;
            input >> x;
            q.push(x);
        }
        else if (com == "-")
        {
            output << q.pop() << '\n';
        }
    }

    return 0;
}

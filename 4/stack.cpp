#include <bits/stdc++.h>

struct stack
{
   std:: vector<int> st;
    int size = 0;
 
    explicit stack(int m)
    {
        st.resize(m + 1);
    }
 
    void push(int N)
    {
        st[++size] = N;
    }
 
    int pop()
    {
        return st[size--];
    }
};
 
int main()
{
    std:: ifstream input("stack.in");
 
    int m = 0;
    input >> m;
 
    stack a(m);
    
	std:: ofstream output("stack.out");

    for (int i = 0; i < m; ++i)
    {
        std:: string com;
        input >> com;
 
        if (com == "+")
        {
            int c = 0;
            input >> c;
            a.push(c);
        }
        else if (com == "-")
        {
            output << a.pop() << '\n';
        }
    }
 
    return 0;
}

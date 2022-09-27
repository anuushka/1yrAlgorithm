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
    
    int evaluate(int a, char op, int b)
    {
    	if(op == '+')
    	return a + b;
    	
    	if(op == '-')
    	return a - b;
    	
    	if(op == '*')
    	return a*b;
	}    
 
int main()
{
    std:: ifstream input("postfix.in");  
	std:: ofstream output("postfix.out");

        std:: string exp;
        getline(input, exp);
        stack a(exp.size());

    for (auto & c : exp)
    {
        if (c == ' ')
            continue;
        if (isdigit(c))
            a.push(c - '0');
        else
            a.push(evaluate(a.pop(), c, a.pop()));
    }
    output << a.pop();

    return 0;
}

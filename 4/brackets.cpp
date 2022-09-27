#include<bits/stdc++.h> 
using namespace std; 
  
bool test_bracket(string seq) 
{ 
    stack<char> s; 
    char x; 
  
    for (int i=0; i<seq.length(); i++) 
    { 
        if (seq[i]=='('||seq[i]=='['||seq[i]=='{') 
        { 
            s.push(seq[i]); 
            continue; 
        } 
  
        if (s.empty()) 
           return false; 
  
        switch (seq[i]) 
        { 
        case ')': 
  
            x = s.top(); 
            s.pop(); 
            if (x=='{' || x=='[') 
                return false; 
            break; 
  
        case '}': 
  
            x = s.top(); 
            s.pop(); 
            if (x=='(' || x=='[') 
                return false; 
            break; 
  
        case ']': 
  
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{') 
                return false; 
            break; 
        } 
    } 
    return (s.empty()); 
} 
int main() 
{ 
    ifstream input("brackets.in");
    ofstream output("brackets.out");

    string sequence;
    while (getline(input, sequence))
    {
        output << (test_bracket(sequence) ? "YES" : "NO") << '\n';
    }

    return 0;
} 


#include <bits/stdc++.h> 
using namespace std;

void computeLPSArray(string pat, int M, int* lps); 
vector<int> ans;
  
vector<int> KMPSearch(string pat, string txt) 
{ 
    int M = pat.size(); 
    int N = txt.size();  
    int lps[M]; 
  
    computeLPSArray(pat, M, lps); 
  
    int i = 0; 
    int j = 0; 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
        	ans.push_back(i - j + 1);
            j = lps[j - 1]; 
        } 
  
        else if (i < N && pat[j] != txt[i]) {  
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
    return ans;
} 
  
void computeLPSArray(string pat, int M, int* lps) 
{ 
    int len = 0; 
    lps[0] = 0; 
  
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else 
        {  
            if (len != 0) { 
                len = lps[len - 1];  
            } 
            else 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 
  
int main() 
{ 
	ifstream fin("search2.in");
	ofstream fout("search2.out");
    string t, p;
    fin >> p >> t;
    KMPSearch(p, t); 
    fout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
	{
		fout << ans[i] << " ";
	}


    return 0; 
} 


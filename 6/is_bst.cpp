#include <bits/stdc++.h>

using namespace std;

struct Node{

    int key;
    Node* left;
    Node* right;
    Node(){
        key = NULL;
        left = nullptr;
        right = nullptr;
    }
};

bool check(Node* node, int min, int max){
    if (node == nullptr){
        return true;
    }

    if (node->key <= min || node->key >= max)
        return false;

    return (check(node->left, min, node->key) &&
            check(node->right, node->key , max));
}

int main() {
    ifstream input("check.in");
    ofstream output("check.out");
    int n, x, l, r;
    input >> n;
    if (n != 0)
	{
        vector<Node*> tree;
        tree.resize(n+1);
        for (int i = 0; i <= n; i++)
            tree[i] = new Node();

        for (int i = 1; i <= n; i++){
            input >> x >> l >> r;
            tree[i]->key = x;
            if (l != 0){
                tree[i]->left = tree[l];
            }
            if (r != 0){
                tree[i]->right = tree[r];
            }
        }
        output << ((check(tree[1], -1000000001, 1000000001)) ? "YES" : "NO") << endl;
    }
    else output << "YES" << endl;


    input.close();
    output.close();
    return 0;
}

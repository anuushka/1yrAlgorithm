#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    Node():key(0), left(nullptr), right(nullptr){}
    Node(int key):key(key), left(nullptr), right(nullptr){}
};

Node* insert(Node *tree, int x)
{
    if (tree == nullptr)
        tree = new Node(x);
    else if (x < tree->key)
        tree->left = insert(tree->left, x);
    else if (x > tree->key)
        tree->right = insert(tree->right, x);
    return tree;
}

bool exists(Node* tree, int x){
    if (tree->key == x)
        return true;
    if (x < tree->key && tree->left != nullptr)
        return exists(tree->left, x);
    if (x > tree->key && tree->right != nullptr)
        return exists(tree->right, x);
    return false;
}

Node* min(Node* node){
    if (node->left == nullptr)
        return node;
    return min(node->left);
}

Node* next(Node* node, int x){
    Node* nextNode = node;
    Node* answer = nullptr;
    while (nextNode != nullptr){
        if (x >= nextNode->key)
            nextNode = nextNode->right;
        else{
            answer = nextNode;
            nextNode = nextNode->left;
        }
    }
    return answer;
}

Node* prev(Node* node, int x){
    Node* prevNode = node;
    Node* answer = nullptr;
    while (prevNode != nullptr){
        if (x <= prevNode->key)
            prevNode = prevNode->left;
        else{
            answer = prevNode;
            prevNode = prevNode->right;
        }
    }
    return answer;
}

Node* deleteNode(Node* node, int x){
    if (node == nullptr)
        return node;
    if (x < node->key)
        node->left = deleteNode(node->left, x);
    else if (x > node->key)
        node->right = deleteNode(node->right, x);
    else if (node->left != nullptr && node->right != nullptr){
        node->key = min(node->right)->key;
        node->right = deleteNode(node->right, node->key);
    }else{
        if (node->left != nullptr)
            node = node->left;
        else
            node = node->right;
    }
    return node;
}

int main() {
    ifstream input("bstsimple.in");
    ofstream output("bstsimple.out");
    Node* tree = nullptr;
    
    while(!input.eof()){
        string str;
        int x;
        input >> str >> x;
        if (str == "insert")
            tree = insert(tree, x);
        if (str == "exists")
            output << (tree != nullptr && (exists(tree, x)) ? "true" : "false")  << endl;
        if (str == "next"){
            Node* n = nullptr;
            n = next(tree, x);
            if (n != nullptr)
                output << n->key << endl;
            else
                output << "none" << endl;
        }
        if (str == "prev"){
            Node* n = nullptr;
            n = prev(tree, x);
            if (n != nullptr)
                output << n->key << endl;
            else
                output << "none" <<  endl;
        }
        if (str == "delete"){
            tree = deleteNode(tree, x);
        }

    }

    input.close();
    output.close();
    return 0;
}

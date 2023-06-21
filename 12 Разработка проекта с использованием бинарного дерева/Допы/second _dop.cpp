#include <iostream>
#include <vector>

using namespace std;

struct Node 
{
    int value;
    Node* left;
    Node* right;

    Node(int value) 
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* buildTree(vector<int>& values, int index) 
{
    if (index >= values.size()) 
    {
        return nullptr;
    }

    Node* root = new Node(values[index]);

    root->left = buildTree(values, index + 1);

    if (root->left != nullptr) 
    {
        root->right = buildTree(values, index + 2);
    }

    return root;
}

void printTree(Node* root) 
{
    if (root == nullptr) 
    {
        return;
    }

    cout << root->value << " ";

    printTree(root->left);
    printTree(root->right);
}

int main() 
{
    vector<int> values = { 1, 2, 3, 4, 5 };

    Node* root = buildTree(values, 0);

    printTree(root);
}
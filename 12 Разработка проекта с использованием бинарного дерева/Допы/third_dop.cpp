#include <iostream>

using namespace std;

enum Color { RED, BLACK };

template <class T>
struct Node 
{
    T data;
    Color color;
    Node<T>* left, * right, * parent;
    Node(T data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

template <class T>
class RBTree 
{
private:
    Node<T>* root;

    void leftRotate(Node<T>* x)
    {
        Node<T>* y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node<T>* x)
    {
        Node<T>* y = x->left;
        x->left = y->right;
        if (y->right != nullptr)
            y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    void insertFixup(Node<T>* z) 
    {
        while (z->parent != nullptr && z->parent->color == RED)
        {
            if (z->parent == z->parent->parent->left) {
                Node<T>* y = z->parent->parent->right;
                if (y != nullptr && y->color == RED) 
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else 
                {
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            }
            else 
            {
                Node<T>* y = z->parent->parent->left;
                if (y != nullptr && y->color == RED) 
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->left) 
                    {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void transplant(Node<T>* u, Node<T>* v)
    {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
    }
public:
    RBTree() : root(nullptr) {}
    void insert(T data)
    {
        Node<T>* z = new Node<T>(data);
        Node<T>* y = nullptr;
        Node<T>* x = root;
        while (x != nullptr) 
        {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (y == nullptr)
            root = z;
        else if (z->data < y->data)
            y->left = z;
        else
            y->right = z;
        insertFixup(z);
    }

    Node<T>* getRoot()
    {
        return root;
    }

    Node<T>* minimum(Node<T>* x)
    {
        while (x->left != nullptr)
            x = x->left;
        return x;
    }

    Node<T>* maximum(Node<T>* x)
    {
        while (x->right != nullptr)
            x = x->right;
        return x;
    }

    Node<T>* successor(Node<T>* x) 
    {
        if (x->right != nullptr)
            return minimum(x->right);
        Node<T>* y = x->parent;
        while (y != nullptr && x == y->right)
        {
            x = y;
            y = y->parent;
        }
        return y;
    }

    Node<T>* predecessor(Node<T>* x) 
    {
        if (x->left != nullptr)
            return maximum(x->left);
        Node<T>* y = x->parent;
        while (y != nullptr && x == y->left)
        {
            x = y;
            y = y->parent;
        }
        return y;
    }

    void inorder(Node<T>* x) 
    {
        if (x != nullptr) 
        {
            inorder(x->left);
            cout << x->data << " ";
            inorder(x->right);
        }
    }

    Node<T>* findMinRedPath(Node<T>* x) 
    {
        int minRedCount = INT_MAX;
        Node<T>* minRedPathEnd = nullptr;
        int currentRedCount = 0;
        while (x != nullptr) {
            if (x->color == RED) 
            {
                currentRedCount++;
            }
            if (x->left == nullptr && x->right == nullptr && currentRedCount < minRedCount) 
            {
                minRedCount = currentRedCount;
                minRedPathEnd = x;
            }
            if (x->left != nullptr && (minRedPathEnd == nullptr || minRedCount > currentRedCount)) 
            {
                Node<T>* leftChild = x->left;
                if (leftChild->color == RED) {
                    leftChild->parent = x;
                    currentRedCount++;
                }
                x = leftChild;
                continue;
            }
            if (x->right != nullptr && (minRedPathEnd == nullptr || minRedCount > currentRedCount)) 
            {
                Node<T>* rightChild = x->right;
                if (rightChild->color == RED) 
                {
                    rightChild->parent = x;
                    currentRedCount++;
                }
                x = rightChild;
                continue;
            }
            Node<T>* successor = this->successor(x);
            if (successor != nullptr && successor->parent == x && (minRedPathEnd == nullptr || minRedCount > currentRedCount)) 
            {
                x = successor;
                continue;
            }
            currentRedCount--;
            x = x->parent;
        }
        return minRedPathEnd;
    }
};
int main()
{
    setlocale(LC_ALL, "rus");

    RBTree<int> tree;

    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    cout << "Вывод дерева: ";
    tree.inorder(tree.getRoot());
    cout << endl;

    Node<int>* minRedPathEnd = tree.findMinRedPath(tree.getRoot());

    if (minRedPathEnd != nullptr) 
    {
        cout << "Путь к листу с минимальным количеством красных вершин: ";
        while (minRedPathEnd != nullptr) 
        {
            cout << minRedPathEnd->data << " ";
            minRedPathEnd = minRedPathEnd->parent;
        }
        cout << endl;
    }
    else 
    {
        cout << "Путь не найден." << endl;
    }

    return 0;
}
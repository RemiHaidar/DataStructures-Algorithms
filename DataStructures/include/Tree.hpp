#include <iostream>

class Tree
{
private:
    struct Node
    {
        Node* left;
        Node* right;
        int value;
        Node(int);
    }; 
    Node* root;
    int levelWidth(Node*, int);
    int depthHeight(Node*, int, int);
public:
    Tree(int);
    ~Tree();
    void insert(int, Node* node = NULL);
    int height(Node* node = NULL);
    bool find(int value, Node* node = NULL);
    int depth(int);
    void preOrderPrint(Node* node = NULL);
    void postOrderPrint(Node* node = NULL);
    void inOrderPrint(Node* node = NULL);
};
#include "BinaryTree.hpp"

BinaryTree::Node::Node(int value)
{
    this->value = value;
    left = NULL;
    right = NULL;
}

int BinaryTree::levelWidth(Node* node, int level)
{
    if (node == NULL)
        return 0;

    if (level == 1)
        return 1;

    else if (level > 1)
        return levelWidth(node->left, level - 1) + levelWidth(node->right, level - 1);
}

int BinaryTree::depthHeight(Node* node, int value, int level)
{
    if(node == NULL) 
        return 0;

    if(node->value == value) 
        return level;
    
    int lowerLevel = depthHeight(node->left, value, level + 1);

    if(lowerLevel != 0) 
        return lowerLevel;

    lowerLevel = depthHeight(node->right, value, level + 1);
    
    return lowerLevel;
}

BinaryTree::BinaryTree(int root)
{
    this->root = new Node(root);
}

void BinaryTree::insert(int value, Node* node)
{
    if (node != NULL) {
        if (value < node->value) {
            if (node->left != NULL)
                insert(value, node->left);
            else
            {
                Node* n = new Node(value);
                node->left = n;
            }
        }
        else if (value > node->value) {
            if (node->right != NULL)
                insert(value, node->right);
            else
            {
                Node* n = new Node(value);
                node->right = n;
            }
        }
    }
    else {
        if (value < root->value) {
            if (root->left != NULL)
                insert(value, root->left);
            else
            {
                Node* n = new Node(value);
                root->left = n;
            }
                
        }
        else if (value > root->value) {
            if (root->right != NULL)
                insert(value, root->right);
            else
            {
                Node* n = new Node(value);
                root->right = n;
            }
        }
    }
}

int BinaryTree::height(Node* node)
{
    static bool recursionStarted = true;
    if (recursionStarted)
        node = root;
    recursionStarted = false;

    int h = 0;
    if (node != NULL)
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        int maxHeight = (leftHeight < rightHeight) ? rightHeight : leftHeight;
        h = maxHeight + 1;
    }
    return h;
}

bool BinaryTree::find(int value, Node* node)
{
    static bool recursionStarted = true;
    if (recursionStarted)
        node = root;
    recursionStarted = false;

    static bool found = false;

    if (node != NULL)
    {
        if (node->value != value)
        {
            find(value, node->left);
            find(value, node->right);
        }
        else
            found = true;   
    }
    return found;
}

void BinaryTree::preOrderPrint(Node* node)
{
    static bool recursionStarted = true;
    if (recursionStarted)
        node = root;
    recursionStarted = false;

    if (node != NULL)
    {
        std::cout << node->value << std::endl;
        preOrderPrint(node->left);
        preOrderPrint(node->right);
    }
}

void BinaryTree::postOrderPrint(Node* node)
{
    static bool recursionStarted = true;
    if (recursionStarted)
        node = root;
    recursionStarted = false;

    if (node != NULL)
    {
        postOrderPrint(node->left);
        std::cout << node->value << std::endl;
        postOrderPrint(node->right);
    }
}

void BinaryTree::inOrderPrint(Node* node)
{
    static bool recursionStarted = true;
    if (recursionStarted)
        node = root;
    recursionStarted = false;

    if (node != NULL)
    {
        inOrderPrint(node->left);
        inOrderPrint(node->right);
        std::cout << node->value << std::endl;
    }
}

int BinaryTree::depth(int value)
{
    return depthHeight(root, value, 0);
}
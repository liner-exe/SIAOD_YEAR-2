#ifndef RB_TREE
#define RB_TREE

#include <string>
#include <iostream>

enum Color
{
    RED,
    BLACK
};

struct Node
{
    std::string value;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(const std::string& v) : value(v), color(RED),
        left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree
{
public:
    RBTree() : root(nullptr) {}

    void insert(const std::string& value);
    void printPreorder();
    void printInorder();
    void printPostorder();

    int getHeight();
    int getPathLength(const std::string& value);
private:
    Node* root;

    void rotateLeft(Node* x);
    void rotateRight(Node* x);
    void fixInsert(Node* x);

    void preOrder(Node* n);
    void inOrder(Node* n);
    void postOrder(Node* n);

    int height(Node* n);
    int pathTo(Node* n, const std::string& target, int depth);
};

#endif // RB_TREE
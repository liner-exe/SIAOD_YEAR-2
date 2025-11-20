#include "RBTree.h"

void RBTree::rotateLeft(Node* x)
{
    Node* y = x->right;
    x->right = y->left;

    if (y-> left)
        y->left->parent = x;

    if (!x->parent)
    {
        root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else x->parent->right = y;
}

void RBTree::rotateRight(Node* x)
{
    Node* y = x->left;
    x->left = y->right;

    if (y->right)
        y->right->parent = x;

    y->parent = x->parent;

    if (!x->parent)
    {
        root = y;
    }
    else if (x == x->parent->right)
    {
        x->parent->right = y;
    }
    else x->parent->left = y;

    y->right = x;
    x->parent = y;
}

void RBTree::fixInsert(Node* x)
{
    while (x != root && x->parent->color == RED)
    {
        Node* parent = x->parent;
        Node* grandParent = parent->parent;

        if (parent == grandParent->left)
        {
            Node* uncle = grandParent->right;

            if (uncle && uncle->color == RED)
            {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandParent->color = RED;
                x = grandParent;
            }
            else
            {
                if (x == parent->right)
                {
                    x = parent;
                    rotateLeft(x);
                }

                parent->color = BLACK;
                grandParent->color = RED;
                rotateRight(grandParent);
            }
        }
        else
        {
            Node* uncle = grandParent->left;

            if (uncle && uncle->color == RED)
            {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandParent->color = RED;
                x = grandParent;
            }
            else
            {
                if (x == parent->left)
                {
                    x = parent;
                    rotateRight(x);
                }

                parent->color = BLACK;
                grandParent->color = RED;
                rotateLeft(grandParent);
            }
        }
    }

    root->color = BLACK;
}

void RBTree::insert(const std::string& value)
{
    Node* x = root;
    Node* y = nullptr;
    Node* z = new Node(value);

    while (x)
    {
        y = x;
        if (z->value < x->value)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    z->parent = y;
    if (!y) root = z;
    else if (z->value < y->value) y->left = z;
    else y->right = z;

    fixInsert(z);
}

void RBTree::preOrder(Node* n)
{
    if (!n) return;

    std::cout << n->value << " ";
    preOrder(n->left);
    preOrder(n->right);
}

void RBTree::inOrder(Node* n)
{
    if (!n) return;

    inOrder(n->left);
    std::cout << n->value << " ";
    inOrder(n->right);
}

void RBTree::postOrder(Node* n)
{
    if (!n) return;

    postOrder(n->left);
    postOrder(n->right);
    std::cout << n->value << " ";
}

void RBTree::printPreorder()
{
    preOrder(root);
    std::cout << std::endl;
}

void RBTree::printInorder()
{
    inOrder(root);
    std::cout << std::endl;
}

void RBTree::printPostorder()
{
    postOrder(root);
    std::cout << std::endl;
}

int RBTree::height(Node *n)
{
    if (!n) return 0;

    return 1 + std::max(height(n->left), height(n->right));
}

int RBTree::getHeight()
{
    return height(root);
}

int RBTree::pathTo(Node *n, const std::string &target, int depth)
{
    if (!n) return -1;
    if (n->value == target) return depth;

    if (target < n->value) return pathTo(n->left, target, depth + 1);
    return pathTo(n->right, target, depth + 1);
}

int RBTree::getPathLength(const std::string &value)
{
    return pathTo(root, value, 0);
}
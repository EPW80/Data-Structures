#pragma once
#include <iostream>

template <typename Key, typename Value>
class BinarySearchTree
{
public:
    BinarySearchTree() = default;
    BinarySearchTree(const BinarySearchTree &original);
    BinarySearchTree &operator=(BinarySearchTree rhs);
    ~BinarySearchTree();

    Value search(const Key &key) const;
    void insert(const Key &key, const Value &value);
    void remove(const Key &key);
    void printInorder() const;
    int getHeight() const;

    void clear();

private:
    struct Node;
    Node *root_ = nullptr;

    void clear(Node *node);
    void insertIterative(Node *node);
    void insertRecursive(Node *parent, Node *nodeToInsert);
    void remove(Node *node);
    void printInorder(Node *node) const;
    int getHeight(Node *node) const;

    Node *makeCopy(Node *node);

    Node *searchIterative(const Key &key) const;
    Node *searchRecursive(Node *node, const Key &key) const;

    bool replaceChild(Node *parent, Node *currentChild, Node *newChild);
};

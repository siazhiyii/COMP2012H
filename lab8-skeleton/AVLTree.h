#ifndef AVLTREE_H
#define AVLTREE_H

template<typename T>
class AVLNode {
public:
    T key;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(T k);
    ~AVLNode() { delete left; delete right; }
};

template<typename T>
class AVLTree {
private:
    AVLNode<T>* root;

    int height(AVLNode<T>* N);
    AVLNode<T>* minValueNode(AVLNode<T>* node);
    AVLNode<T>* rightRotate(AVLNode<T>* y);
    AVLNode<T>* leftRotate(AVLNode<T>* x);
    int getBalance(AVLNode<T>* N);
    AVLNode<T>* insert(AVLNode<T>* node, T key);
    AVLNode<T>* remove(AVLNode<T>* root, T key);
    void printHelper(AVLNode<T>* node, int depth) const;
    void preOrderTraversal(AVLNode<T>* node) const;

public:
    AVLTree();
    ~AVLTree() { delete root; }
    void insert(T key);
    void remove(T key);
    void print() const;
    void preOrder() const;
};

#include "AVLTree.tpp"
#endif // AVLTREE_H

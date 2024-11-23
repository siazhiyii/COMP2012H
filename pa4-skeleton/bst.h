#ifndef BST_H
#define BST_H

#include <vector>
#include <stdexcept>

template<typename T>
struct BSTNode {
    T data;
    BSTNode* left;
    BSTNode* right;
    
    explicit BSTNode(const T& item) : data(item), left(nullptr), right(nullptr) {}
};

template<typename T, typename Compare = std::less<T>>
class BSTree {
private:
    BSTNode<T>* root;
    Compare comp;
    size_t size{0};

    BSTNode<T>* insertHelper(BSTNode<T>* node, const T& data);
    BSTNode<T>* removeHelper(BSTNode<T>* node, const T& data);
    void inorderHelper(const BSTNode<T>* node, std::vector<T>& result) const;
    void deleteTree(BSTNode<T>* node);  // Helper for destructor
    int heightHelper(BSTNode<T>* node) const;  // Helper for getHeight

public:
    BSTree() : root(nullptr) {}
    ~BSTree() { deleteTree(root); }
    
    void insert(const T& data);
    bool remove(const T& data);
    T* find(const T& data) const;
    std::vector<T> inorderTraversal() const;
    size_t getSize() const { return size; }
    int getHeight() const { return heightHelper(root); }
};

#include "bst.tpp"

#endif
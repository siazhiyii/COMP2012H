template <typename T, typename Compare>
BSTNode<T> *BSTree<T, Compare>::insertHelper(BSTNode<T> *node, const T &data)
{
    // Please implement this function
    if (node == nullptr)
    {
        size++;
        return new BSTNode<T>(data);
    }
    if (comp(data, node->data))
    {
        node->left = insertHelper(node->left, data);
    }
    else if (comp(node->data, data))
    {
        node->right = insertHelper(node->right, data);
    }
    else
    {
        // Duplicate data, do not insert
        return node;
    }
    return node;
}

template <typename T, typename Compare>
void BSTree<T, Compare>::insert(const T &data)
{
    root = insertHelper(root, data);
}

template <typename T, typename Compare>
BSTNode<T> *BSTree<T, Compare>::removeHelper(BSTNode<T> *node, const T &data)
{
    // Please implement this function
    if (node == nullptr)
    {
        return node;
    }
    if (comp(data, node->data))
    {
        node->left = removeHelper(node->left, data);
    }
    else if (comp(node->data, data))
    {
        node->right = removeHelper(node->right, data);
    }
    else
    {
        if (node->left == nullptr)
        {
            BSTNode<T> *temp = node->right;
            delete node;
            size--;
            return temp;
        }
        else if (node->right == nullptr)
        {
            BSTNode<T> *temp = node->left;
            delete node;
            size--;
            return temp;
        }
        BSTNode<T> *temp = node->right;
        while (temp && temp->left != nullptr)
        {
            temp = temp->left;
        }
        node->data = temp->data;
        node->right = removeHelper(node->right, temp->data);
    }
    return node;
}

template <typename T, typename Compare>
bool BSTree<T, Compare>::remove(const T &data)
{
    size_t oldSize = size;
    root = removeHelper(root, data);
    return oldSize > size;
}

template <typename T, typename Compare>
T *BSTree<T, Compare>::find(const T &data) const
{
    // Please implement this function
    BSTNode<T> *current = root;
    while (current != nullptr)
    {
        if (comp(data, current->data))
        {
            current = current->left;
        }
        else if (comp(current->data, data))
        {
            current = current->right;
        }
        else
        {
            return &current->data;
        }
    }
    return nullptr;
}

template <typename T, typename Compare>
void BSTree<T, Compare>::inorderHelper(const BSTNode<T> *node, std::vector<T> &result) const
{
    // Please implement this function
    if (node != nullptr)
    {
        inorderHelper(node->left, result);
        result.push_back(node->data);
        inorderHelper(node->right, result);
    }
}

template <typename T, typename Compare>
std::vector<T> BSTree<T, Compare>::inorderTraversal() const
{
    std::vector<T> result;
    inorderHelper(root, result);
    return result;
}

template <typename T, typename Compare>
void BSTree<T, Compare>::deleteTree(BSTNode<T> *node)
{
    // Please implement this function
    if (node != nullptr)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

template <typename T, typename Compare>
int BSTree<T, Compare>::heightHelper(BSTNode<T> *node) const
{
    if (!node)
        return -1;
    return 1 + std::max(heightHelper(node->left), heightHelper(node->right));
}
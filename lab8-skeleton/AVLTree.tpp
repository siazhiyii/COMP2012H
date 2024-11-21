template <typename T>
AVLNode<T>::AVLNode(T k) : key(k), height(1), left(nullptr), right(nullptr) {}

template <typename T>
int AVLTree<T>::height(AVLNode<T> *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

template <typename T>
AVLNode<T> *AVLTree<T>::minValueNode(AVLNode<T> *node)
{
    AVLNode<T> *current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

template <typename T>
AVLNode<T> *AVLTree<T>::rightRotate(AVLNode<T> *y)
{
    //=========== TODO ===================================================

    // right rotate
    AVLNode<T> *x = y->left;
    AVLNode<T> *T2 = x->right;

    x->right = y;
    y->left = T2;

    // update height
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    //--------------------------------------------------------------------

    return x;
}

template <typename T>
AVLNode<T> *AVLTree<T>::leftRotate(AVLNode<T> *x)
{
    //=========== TODO ===================================================

    // left rotate
    AVLNode<T> *y = x->right;
    AVLNode<T> *T2 = y->left;
    y->left = x;
    x->right = T2;

    // update height
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    //--------------------------------------------------------------------
    return y;
}

template <typename T>
int AVLTree<T>::getBalance(AVLNode<T> *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

template <typename T>
AVLNode<T> *AVLTree<T>::insert(AVLNode<T> *node, T key)
{
    //=========== TODO ===================================================
    // 1. BST insert
    if (node == nullptr)
    {
        return new AVLNode<T>(key);
    }

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }

    // 2. update height
    node->height = 1 + std::max(height(node->left), height(node->right));

    // 3. check balance
    int balance = getBalance(node);

    // left-left
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    // right-right
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    // left-right
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // right-left
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    //--------------------------------------------------------------------

    return node;
}

template <typename T>
AVLNode<T> *AVLTree<T>::remove(AVLNode<T> *root, T key)
{
    //=========== TODO ===================================================
    // 1. BST remove
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = remove(root->left, key);
    else if (key > root->key)
        root->right = remove(root->right, key);
    else
    {
        if ((root->left == nullptr) || (root->right == nullptr))
        {
            AVLNode<T> *temp = root->left ? root->left : root->right;

            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;

            delete temp;
        }
        else
        {
            AVLNode<T> *temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = remove(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;
    // 2. update height
    root->height = 1 + std::max(height(root->left), height(root->right));

    // 3. check balance
    int balance = getBalance(root);

    // left-left
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    // left-right
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // right-right
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // right-left
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    //--------------------------------------------------------------------

    return root;
}

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <typename T>
void AVLTree<T>::insert(T key)
{
    root = insert(root, key);
}

template <typename T>
void AVLTree<T>::remove(T key)
{
    root = remove(root, key);
}

template <typename T>
void AVLTree<T>::printHelper(AVLNode<T> *node, int depth) const
{
    if (!node)
        return;
    printHelper(node->right, depth + 1);
    for (int i = 0; i < depth; ++i)
    {
        cout << "\t";
    }
    cout << node->key << "(" << node->height << ")" << endl;
    printHelper(node->left, depth + 1);
}

template <typename T>
void AVLTree<T>::print() const
{
    if (root == nullptr)
        return;
    printHelper(root, 0);
}

template <typename T>
void AVLTree<T>::preOrderTraversal(AVLNode<T> *node) const
{
    /*
    print the tree in pre-order, use a comma to separate between nodes
    For example, for the following tree:
          30
         /  \
       20   40
      /  \     \
     10  25    50
    the output should be: 30,20,10,25,40,50,
    */
    //=========== TODO ===================================================
    if (node != nullptr)
    {
        std::cout << node->key << ",";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    //--------------------------------------------------------------------
}

template <typename T>
void AVLTree<T>::preOrder() const
{
    if (root == nullptr)
        return;
    preOrderTraversal(root);
    cout << endl;
}
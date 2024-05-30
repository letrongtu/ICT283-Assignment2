#ifndef AVL_H
#define AVL_H

#include "Node.h"

/**
 * @brief Template class for AVL Tree
 * @tparam T Data type of the elements in AVL Tree
 */
template <class T>
class AVL {
public:
    using outputFunction = void (*)(const T& data);

    explicit AVL();
    AVL(const AVL<T>& avl);
    ~AVL();
    AVL<T>& operator=(const AVL<T>& avl);

    void insert(const T& data);
    bool search(const T& data) const;
    void inOrder(const outputFunction f) const;
    void preOrder(const outputFunction f) const;
    void postOrder(const outputFunction f) const;

private:
    Node<T>* root;

    Node<T>* copyHelper(const Node<T>* node);
    void clear(Node<T>*& node);
    Node<T>* insertHelper(Node<T>*& node, const T& data);
    bool searchHelper(const Node<T>* node, const T& data) const;
    void inOrderHelper(const Node<T>* node, const outputFunction f) const;
    void preOrderHelper(const Node<T>* node, const outputFunction f) const;
    void postOrderHelper(const Node<T>* node, const outputFunction f) const;

    // AVL-specific helper functions
    int height(const Node<T>* node) const;
    int getBalance(const Node<T>* node) const;
    Node<T>* rightRotate(Node<T>* y);
    Node<T>* leftRotate(Node<T>* x);
};

// Functions Implementations

template <class T>
AVL<T>::AVL() : root(nullptr) {}

template <class T>
AVL<T>::AVL(const AVL<T>& avl) : root(copyHelper(avl.root)) {}

template <class T>
Node<T>* AVL<T>::copyHelper(const Node<T>* node) {
    if (node == nullptr) {
        return nullptr;
    } else {
        Node<T>* copy = new Node<T>(node->data);
        copy->left = copyHelper(node->left);
        copy->right = copyHelper(node->right);
        return copy;
    }
}

template <class T>
AVL<T>& AVL<T>::operator=(const AVL<T>& avl) {
    if (this != &avl) {
        clear(this->root);
        this->root = copyHelper(avl.root);
    }
    return *this;
}

template <class T>
AVL<T>::~AVL() {
    clear(this->root);
    this->root = nullptr;
}

template <class T>
void AVL<T>::clear(Node<T>*& node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <class T>
void AVL<T>::insert(const T& data) {
    root = insertHelper(this->root, data);
}

template <class T>
Node<T>* AVL<T>::insertHelper(Node<T>*& node, const T& data) {
    if (node == nullptr) {
        return new Node<T>(data);
    }
    if (data < node->data) {
        node->left = insertHelper(node->left, data);
    } else if (data > node->data) {
        node->right = insertHelper(node->right, data);
    } else {
        return node; // Duplicate data is not allowed
    }

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template <class T>
bool AVL<T>::search(const T& data) const {
    return searchHelper(this->root, data);
}

template <class T>
bool AVL<T>::searchHelper(const Node<T>* node, const T& data) const {
    if (node == nullptr) {
        return false;
    }
    else if (data == node->data) {
        return true;
    }
    else if (data < node->data) {
        return searchHelper(node->left, data);
    }
    else {
        return searchHelper(node->right, data);
    }
}

template <class T>
void AVL<T>::inOrder(const outputFunction f) const {
    inOrderHelper(this->root, f);
}

template <class T>
void AVL<T>::inOrderHelper(const Node<T>* node, const outputFunction f) const {
    if (node != nullptr) {
        inOrderHelper(node->left, f);
        f(node->data);
        inOrderHelper(node->right, f);
    }
}

template <class T>
void AVL<T>::preOrder(const outputFunction f) const {
    preOrderHelper(this->root, f);
}

template <class T>
void AVL<T>::preOrderHelper(const Node<T>* node, const outputFunction f) const {
    if (node != nullptr) {
        f(node->data);
        preOrderHelper(node->left, f);
        preOrderHelper(node->right, f);
    }
}

template <class T>
void AVL<T>::postOrder(const outputFunction f) const {
    postOrderHelper(this->root, f);
}

template <class T>
void AVL<T>::postOrderHelper(const Node<T>* node, const outputFunction f) const {
    if (node != nullptr) {
        postOrderHelper(node->left, f);
        postOrderHelper(node->right, f);
        f(node->data);
    }
}

// AVL-specific helper functions

template <class T>
int AVL<T>::height(const Node<T>* node) const {
    return (node == nullptr) ? 0 : node->height;
}

template <class T>
int AVL<T>::getBalance(const Node<T>* node) const {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

template <class T>
Node<T>* AVL<T>::rightRotate(Node<T>* y) {
    Node<T>* x = y->left;
    Node<T>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

template <class T>
Node<T>* AVL<T>::leftRotate(Node<T>* x) {
    Node<T>* y = x->right;
    Node<T>* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

#endif // AVL_H

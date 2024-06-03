#ifndef AVL_H
#define AVL_H

#include "Node.h"

/**
 * @author Trong Tu Le
 * @version 1
 * turn BST to AVL tree
 * added function: height, getBalance, rightRotate, leftRotate, max
 * modified function: insertHelper
*/

//---------------------------------------------------------------------------------

/**
 * @class AVL
 * @brief Template class for an AVL Tree, which is a self-balancing Binary Search Tree.
 * @tparam T Data type of the elements in the AVL Tree.
 *
 * The AVL tree maintains its balance using rotations to ensure the heights of the subtrees
 * of any node differ by at most one.
 */
template <class T>
class AVL {
public:
    using funcPtr = void (*)(const T& data); /// Function pointer type for traversal operations.

    /**
     * @brief Default constructor for the AVL Tree.
     */
    explicit AVL();

    /**
     * @brief Deep copy constructor.
     * @param avl The AVL Tree to copy from.
     */
    AVL(const AVL<T>& avl);

    /**
     * @brief Destructor to clean up the tree.
     */
    ~AVL();

    /**
     * @brief Assignment operator to copy from another AVL Tree.
     * @param avl The AVL Tree to copy from.
     * @return Reference to the assigned AVL Tree.
     */
    AVL<T>& operator=(const AVL<T>& avl);

    /**
     * @brief Insert a data value into the AVL Tree.
     * @param data The data value to be inserted.
     */
    void insert(const T& data);

    /**
     * @brief Search for a data value in the AVL Tree.
     * @param data The data value to search for.
     * @return True if the data value is found, false otherwise.
     */
    bool search(const T& data) const;

    /**
     * @brief In-order traversal of the AVL Tree.
     * @param f Function pointer to be called on each node's data.
     */
    void inOrder(const funcPtr f) const;

    /**
     * @brief Pre-order traversal of the AVL Tree.
     * @param f Function pointer to be called on each node's data.
     */
    void preOrder(const funcPtr f) const;

    /**
     * @brief Post-order traversal of the AVL Tree.
     * @param f Function pointer to be called on each node's data.
     */
    void postOrder(const funcPtr f) const;

private:
    Node<T>* root; /// Root node of the AVL Tree.

    /**
     * @brief Helper function to recursively copy nodes.
     * @param node The node to copy from.
     * @return Pointer to the copied node.
     */
    Node<T>* copyHelper(const Node<T>* node);

    /**
     * @brief Utility to clear the tree starting from a node.
     * @param node The starting node to clear from.
     */
    void clear(Node<T>*& node);

    /**
     * @brief Helper function to recursively insert a node and balance the tree.
     * @param node Root node of the current subtree.
     * @param data Data value to be inserted.
     */
    void insertHelper(Node<T>*& node, const T& data);

    /**
     * @brief Helper function to recursively search for a data value.
     * @param node Root node of the current subtree.
     * @param data Data value to search for.
     * @return True if the data value is found, false otherwise.
     */
    bool searchHelper(const Node<T>* node, const T& data) const;

    /**
     * @brief Helper function for in-order traversal.
     * @param node Root node of the current subtree.
     * @param f Function pointer to be called on each node's data.
     */
    void inOrderHelper(const Node<T>* node, const funcPtr f) const;

    /**
     * @brief Helper function for pre-order traversal.
     * @param node Root node of the current subtree.
     * @param f Function pointer to be called on each node's data.
     */
    void preOrderHelper(const Node<T>* node, const funcPtr f) const;

    /**
     * @brief Helper function for post-order traversal.
     * @param node Root node of the current subtree.
     * @param f Function pointer to be called on each node's data.
     */
    void postOrderHelper(const Node<T>* node, const funcPtr f) const;

    // AVL helper functions
    /**
     * @brief Get the height of a node.
     * @param node Node to get the height of.
     * @return Height of the node.
     */
    int height(const Node<T>* node) const;

    /**
     * @brief Get the balance factor of a node.
     * @param node Node to get the balance factor of.
     * @return Balance factor of the node.
     */
    int getBalance(const Node<T>* node) const;

    /**
     * @brief Perform a right rotation on a subtree.
     * @param y Root of the subtree to rotate.
     */
    void rightRotate(Node<T>*& y);

    /**
     * @brief Perform a left rotation on a subtree.
     * @param x Root of the subtree to rotate.
     */
    void leftRotate(Node<T>*& x);

    /**
     * @brief Get the maximum of two integers.
     * @param a First integer.
     * @param b Second integer.
     * @return The maximum of the two integers.
     */
    int max(int a, int b) const;
};

//-------------------------------------------------------------------------------------------
// Functions Implementations

// Constructor for the AVL
template <class T>
AVL<T>::AVL() : root(nullptr) {
}

//-------------------------------------------------------------------------------------------

// Deep copy constructor
template <class T>
AVL<T>::AVL(const AVL<T>& avl) : root(copyHelper(avl.root)) {
}

//-------------------------------------------------------------------------------------------

// Helper function to copy the data and its child from a node
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

//-------------------------------------------------------------------------------------------

// Assign Operator to copy avl
template <class T>
AVL<T>& AVL<T>::operator=(const AVL<T>& avl) {
    if (this != &avl) {
        clear(this->root);
        this->root = copyHelper(avl.root);
    }
    return *this;
}

//-------------------------------------------------------------------------------------------

// Destructor to clean up the tree
template <class T>
AVL<T>::~AVL() {
    clear(this->root);
    this->root = nullptr;
}

//-------------------------------------------------------------------------------------------

// Function to clear the tree starting from a node.
template <class T>
void AVL<T>::clear(Node<T>*& node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

//-------------------------------------------------------------------------------------------

// Insert a node into the AVL.
template <class T>
void AVL<T>::insert(const T& data) {
    insertHelper(this->root, data);
}

//-------------------------------------------------------------------------------------------

// Helper function to recursively insert a node and balance the tree if needed.
template <class T>
void AVL<T>::insertHelper(Node<T>*& node, const T& data) {
    if (node == nullptr) {
        node = new Node<T>(data);
    }
    else if (data < node->data) {
        insertHelper(node->left, data);
    }
    else if (data > node->data) {
        insertHelper(node->right, data);
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data) {
        rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && data > node->right->data) {
        leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        leftRotate(node->left);
        rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        rightRotate(node->right);
        leftRotate(node);
    }
}

//-------------------------------------------------------------------------------------------

// Search for a data value in the AVL.
template <class T>
bool AVL<T>::search(const T& data) const {
    return searchHelper(this->root, data);
}

//-------------------------------------------------------------------------------------------

// Helper function to recursively search for a data value.
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

//-------------------------------------------------------------------------------------------

// In-order traversal of the AVL.
template <class T>
void AVL<T>::inOrder(const funcPtr f) const {
    inOrderHelper(this->root, f);
}

//-------------------------------------------------------------------------------------------

// Helper function for in-order traversal.
template <class T>
void AVL<T>::inOrderHelper(const Node<T>* node, const funcPtr f) const {
    if (node != nullptr) {
        inOrderHelper(node->left, f);
        f(node->data);
        inOrderHelper(node->right, f);
    }
}

//-------------------------------------------------------------------------------------------

// Pre-order traversal of the AVL.
template <class T>
void AVL<T>::preOrder(const funcPtr f) const {
    preOrderHelper(this->root, f);
}

//-------------------------------------------------------------------------------------------

// Helper function for pre-order traversal.
template <class T>
void AVL<T>::preOrderHelper(const Node<T>* node, const funcPtr f) const {
    if (node != nullptr) {
        f(node->data);
        preOrderHelper(node->left, f);
        preOrderHelper(node->right, f);
    }
}

//-------------------------------------------------------------------------------------------

// Post-order traversal of the AVL.
template <class T>
void AVL<T>::postOrder(const funcPtr f) const {
    postOrderHelper(this->root, f);
}

//-------------------------------------------------------------------------------------------

// Helper function for post-order traversal.
template <class T>
void AVL<T>::postOrderHelper(const Node<T>* node, const funcPtr f) const {
    if (node != nullptr) {
        postOrderHelper(node->left, f);
        postOrderHelper(node->right, f);
        f(node->data);
    }
}

//-------------------------------------------------------------------------------------------
// AVL helper functions

// Get the height of a node.
template <class T>
int AVL<T>::height(const Node<T>* node) const {
    return (node == nullptr) ? 0 : node->height;
}

//-------------------------------------------------------------------------------------------

// Get the balance factor of a node.
template <class T>
int AVL<T>::getBalance(const Node<T>* node) const {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

//-------------------------------------------------------------------------------------------

// Perform a right rotation on a subtree.
template <class T>
void AVL<T>::rightRotate(Node<T>*& y) {
    Node<T>* x = y->left;
    Node<T>* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    y = x;
}

//-------------------------------------------------------------------------------------------

// Perform a left rotation on a subtree.
template <class T>
void AVL<T>::leftRotate(Node<T>*& x) {
    Node<T>* y = x->right;
    Node<T>* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    x = y;
}

//-------------------------------------------------------------------------------------------

// Function to get the maximum of two integers.
template <class T>
int AVL<T>::max(int a, int b) const {
    return (a > b) ? a : b;
}
//-------------------------------------------------------------------------------------------

#endif

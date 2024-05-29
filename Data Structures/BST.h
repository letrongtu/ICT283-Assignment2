#ifndef BST_H
#define BST_H

//-------------------------------------------------------------------------------------------
#include "Node.h"
#include "vector.h"
//-------------------------------------------------------------------------------------------

/**
 * @brief Template class for Binary Search Tree
 * @tparam T Data type of the elements in BST
 */
template <class T>
class BST{
public:

    /**
     * @brief Function pointer
     * */
    using outputFunction = void (*)(const T& data);

    /**
     * @brief Constructor for the BST
     * @param root Initial root node of the BST (default is nullptr)
     */
    explicit BST();

    /**
     * @brief Deep copy constructor
     * @param bst The BST to copy from
     */
    BST(const BST<T>& bst);

    /**
     * @brief Destructor to clean up the tree
     */
    ~BST();

    /**
     * @brief Assign Operator to copy bst
     * @param bst The BST to copy from
     */
    BST<T>& operator=(const BST<T>& bst);

    /**
     * @brief Insert a node into the BST.
     * @param data Data value to be inserted
     * @return void
     */
    void insert(const T& data);

    /**
     * @brief Search for a data value in the BST.
     * @param data Data to search for
     * @return True if data is found, false otherwise
     */
    bool search(const T& data) const;

    /** @brief In-order traversal of the BST.
     *  @param f Function pointer to be called on each node's data.
     *  @return void
    */
    void inOrder(const outputFunction f) const;

    /** @brief Pre-order traversal of the BST.
     *  @param f Function pointer to be called on each node's data.
     *  @return void
    */
    void preOrder(const outputFunction f) const;

    /** @brief Post-order traversal of the BST.
     *  @param f Function pointer to be called on each node's data.
     *  @return void
    */
    void postOrder(const outputFunction f) const;

private:
    Node<T>* root; /// Root node of the tree
    /**
     * @brief Helper function to copy the data and its child from a node
     * @param node The node to copy from
     * @return void
     */
    Node<T>* copyHelper(const Node<T>* node);

    /**
     * @brief Utility to clear the tree starting from a node.
     * @param node The starting node to clear from
     * @return void
     */
    void clear(Node<T>*& node);

    /**
     * @brief Helper function to recursively insert a node.
     * @param node Root node of the current subtree.
     * @param data Data value to be inserted.
     * @return New root of the subtree.
     */
    void insertHelper(Node<T>*& node, const T& data);

    /**
     * @brief Helper function to recursively search for a data value.
     * @param node Root node of the current subtree.
     * @param data Data value to search for.
     * @return True if data is found, false otherwise.
     */
    bool searchHelper(const Node<T>* node, const T& data) const;

    /**
     * @brief Helper function for in-order traversal.
     * @param node Root node of the current subtree.
     * @param f Function pointer to be called on each node's data.
     * @return void
     */
    void inOrderHelper(const Node<T>* node,  const outputFunction f) const;

    /**
     * @brief Helper function for pre-order traversal.
     * @param node Root node of the current subtree.
     * @param f Function pointer to be called on each node's data.
     * @return void
     */
    void preOrderHelper(const Node<T>* node, const outputFunction f) const;

    /**
     * @brief Helper function for post-order traversal.
     * @param node Root node of the current subtree.
     * @param f Function pointer to be called on each node's data.
     * @return void
     */
    void postOrderHelper(const Node<T>* node, const outputFunction f) const;
};

//-------------------------------------------------------------------------------------------
//Functions Implementations

// Constructor for the BST
template <class T>
BST<T>::BST() : root(nullptr) {
}

//-------------------------------------------------------------------------------------------

// Deep copy constructor
template <class T>
BST<T>::BST(const BST<T>& bst) : root(copyHelper(bst.root)) {
}

//-------------------------------------------------------------------------------------------

// Helper function to copy the data and its child from a node
template <class T>
Node<T>* BST<T>::copyHelper(const Node<T>* node){
    if(node == nullptr){
        return nullptr;
    }
    else{
        Node<T>* copy = new Node<T>();
        copy->data = node->data;
        copy->left = copyHelper(node->left);
        copy->right = copyHelper(node->right);
        return copy;
    }
}

//-------------------------------------------------------------------------------------------

// Assign Operator to copy bst
template <class T>
BST<T>& BST<T>::operator=(const BST<T>& bst){
    if(this->root != bst.root){
        this->root = copyHelper(bst.root);
    }

    return *this;
}

//-------------------------------------------------------------------------------------------

// Destructor to clean up the tree
template <class T>
BST<T>::~BST() {
    clear(this->root);
    this->root = nullptr;
}

//-------------------------------------------------------------------------------------------

// Utility to clear the tree starting from a node.
template <class T>
void BST<T>::clear(Node<T>*& node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

//-------------------------------------------------------------------------------------------

//Insert a node into the BST.
template <class T>
void BST<T>::insert(const T& data){
    insertHelper(this->root, data);
}

//-------------------------------------------------------------------------------------------

// Helper function to recursively insert a node.
template <class T>
void BST<T>::insertHelper(Node<T>*& node, const T& data){
    if (node == nullptr) {
        node = new Node<T>(data);
    }
    else if (data < node->data) {
        insertHelper(node->left, data);
    }
    else {
        insertHelper(node->right, data);
    }
}

//-------------------------------------------------------------------------------------------

// Search for a data value in the BST.
template <class T>
bool BST<T>::search(const T& data) const{
    return searchHelper(this->root, data);
}

//-------------------------------------------------------------------------------------------

// Helper function to recursively search for a data value.
template <class T>
bool BST<T>::searchHelper(const Node<T>* node, const T& data) const{
    if(node == nullptr){
        return false;
    }
    else if (data == node->data){
        return true;
    }
    else if(data < node->data){
        return searchHelper(node->left, data);
    }
    else{
        return searchHelper(node->right, data);
    }
}

//-------------------------------------------------------------------------------------------

// In-order traversal of the BST.
template <class T>
void BST<T>::inOrder(const outputFunction f) const{
    inOrderHelper(this->root, f);
}

//-------------------------------------------------------------------------------------------

// Helper function for in-order traversal.
template <class T>
void BST<T>::inOrderHelper(const Node<T>* node, const outputFunction f) const{
    if(node != nullptr){
        inOrderHelper(node->left, f);
        f(node->data);
        inOrderHelper(node->right, f);
    }
}

//-------------------------------------------------------------------------------------------

// Pre-order traversal of the BST.
template <class T>
void BST<T>::preOrder(const outputFunction f) const{
    preOrderHelper(this->root, f);
}

//-------------------------------------------------------------------------------------------

// Helper function for pre-order traversal.
template <class T>
void BST<T>::preOrderHelper(const Node<T>* node, const outputFunction f) const{
     if(node != nullptr){
        f(node->data);
        preOrderHelper(node->left, f);
        preOrderHelper(node->right, f);
    }
}

//-------------------------------------------------------------------------------------------

// Post-order traversal of the BST.
template <class T>
void BST<T>::postOrder(const outputFunction f) const{
    postOrderHelper(this->root, f);
}

//-------------------------------------------------------------------------------------------

// Helper function for post-order traversal.
template <class T>
void BST<T>::postOrderHelper(const Node<T>* node, const outputFunction f) const{
    if(node != nullptr){
        postOrderHelper(node->left, f);
        postOrderHelper(node->right, f);
        f(node->data);
    }
}

//-------------------------------------------------------------------------------------------

#endif

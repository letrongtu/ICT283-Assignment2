#ifndef NODE_H
#define NODE_H

/**
 * @brief Template struct for the node used in the Binary Search Tree.
 *
 * This structure defines a node in a binary search tree, holding a value of any type,
 * and pointers to its left and right children.
 *
 * @tparam T Data type of the elements stored in the node.
 */
template <class T>
struct Node {
    T data;       /// Data value
    Node* left;   /// Pointer to the left child
    Node* right;  /// Pointer to the right child
    int height;   /// Height of the node in the tree

    /**
     * @brief Constructor to initialize a node with a value and optional children pointers.
     *
     * @param value The value to be stored in the node.
     * @param leftChild Pointer to the left child node (default is nullptr).
     * @param rightChild Pointer to the right child node (default is nullptr).
     * @param hei Height of the node in the tree
     */
    explicit Node(const T& value = T(), Node* leftChild = nullptr, Node* rightChild = nullptr, int hei = 1);
};

//---------------------------------------------------------------------------------

// Constructor to initialize a node with a value and optional children pointers.
template <class T>
Node<T>::Node(const T& value, Node* leftChild, Node* rightChild, int hei)
    : data(value), left(leftChild), right(rightChild), height(hei){
}

#endif

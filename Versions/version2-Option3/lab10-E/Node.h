#ifndef NODE_H
#define NODE_H

/**
 * @brief Template struct for the node used in the Binary Search Tree.
 * @tparam T Data type of the elements stored in the node.
 */
template <class T>
struct Node {
    T data; /// Data value
    Node* left; /// Left child
    Node* right; /// Right child

    explicit Node(T value = 0, Node* leftChild = nullptr, Node* rightChild = nullptr);
};

template <class T>
Node<T>::Node(T value, Node* leftChild, Node* rightChild) : data(value), left(leftChild), right(rightChild){
}
#endif


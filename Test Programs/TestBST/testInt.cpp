#include <iostream>
#include "../../Data Structures/BST.h"

using namespace std;

template<class T>
void outputFunction(const T& data){
    cout << data << endl;
}
template<class T>
void result(T expected, T actual, const string& testMessage) {
    cout << testMessage << ": ";
    if (expected == actual) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << "\n    Expected: " << expected << " but got: " << actual << endl;
    }
}

template<class T>
void resultPtr(const T* expected, const T* actual, const string& testMessage) {
    cout << testMessage << ": ";
    if (expected == actual) {
        cout << "PASSED" << endl;
    } else {
        cerr << "FAILED" << "\n    Expected pointer: " << static_cast<const void*>(expected) << " but got pointer: " << static_cast<const void*>(actual) << endl;
    }
}

void testInsertSearch() {
    cout << "Test 1: Testing Insert and Search Functions" << endl;
    BST<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);

    result(true, tree.search(10), "1.1 Search for existing value 10");
    result(true, tree.search(20), "1.2 Search for existing value 20");
    result(false, tree.search(1), "1.3 Search for non-existing value 1");
    cout << "-----------------------------------------" << endl;
}

void testTraversal() {
    cout << "Test 2: Testing Traversals" << endl;
    BST<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order Traversal (Should be 20, 30, 40, 50, 60, 70, 80): \n";
    tree.inOrder(outputFunction);
    cout << "Pre-order Traversal (Should be 50, 30, 20, 40, 70, 60, 80): \n";
    tree.preOrder(outputFunction);
    cout << "Post-order Traversal (Should be 20, 40, 30, 60, 80, 70, 50): \n";
    tree.postOrder(outputFunction);
    cout << "-----------------------------------------" << endl;
}

void testCopyConstructor(){
    cout << "Test 3: Testing Copy Constructor" << endl;
    BST<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);

    BST<int> other(tree);
    other.insert(20);

    cout << "In-order Traversal (Should be 20, 30, 50, 70): \n";
    other.inOrder(outputFunction);
    cout << "-----------------------------------------" << endl;
}

void testAssignOperator(){
    cout << "Test 4: Testing Assign Operator" << endl;
    BST<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);

    BST<int> other;
    other = tree;
    other.insert(20);

    cout << "In-order Traversal (Should be 20, 30, 50, 70): \n";
    other.inOrder(outputFunction);
    cout << "-----------------------------------------" << endl;
}

void testDestructor(){
    cout << "Test 5: Testing Assign Operator" << endl;
    BST<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);

    tree.~BST();
    cout << "<<In-order Traversal should not print anything>>\n";
    cout << "Tree: ";
    tree.inOrder(outputFunction);
    cout << endl;
    cout << "-----------------------------------------" << endl;
}

BST<int> testReturnByValue(){
    cout << "Test 6: Testing Return By Value" << endl;
    BST<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);

    cout << "The tree will be tested on Test 7" << endl;
    cout << "-----------------------------------------" << endl;
    return tree;
}

void testPassByReference(BST<int>& tree){
    cout << "Test 7: Testing Pass By Reference" << endl;
    tree.insert(20);

    cout << "In-order Traversal (Should be 20, 30, 50, 70): \n";
    tree.inOrder(outputFunction);
    cout << "-----------------------------------------" << endl;
}

void testPassByConstReference(const BST<int>& tree){
    cout << "Test 8: Testing Pass By Const Reference" << endl;
     result(true, tree.search(70), "8. Testing Pass By Const Reference");
    cout << "-----------------------------------------" << endl;
}

void testPassByValue(BST<int> tree){
    cout << "Test 8: Testing Pass By Value" << endl;
    tree.insert(100);

    cout << "In-order Traversal (Should be 20, 30, 50, 70, 100): \n";
    tree.inOrder(outputFunction);
    cout << "-----------------------------------------" << endl;
}

int main() {
    testInsertSearch();
    testTraversal();
    testCopyConstructor();
    testAssignOperator();
    testDestructor();
    BST<int> tree = testReturnByValue();
    testPassByReference(tree);
    testPassByConstReference(tree);
    testPassByValue(tree);

    cout << "All tests completed." << endl;
    return 0;
}

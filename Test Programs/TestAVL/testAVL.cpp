#include <iostream>
#include "../../Data Structures/AVL.h"

using namespace std;

template<class T>
void outputFunction(const T& data) {
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

void testInsertSearch() {
    cout << "Test 1: Testing Insert and Search Functions" << endl;
    AVL<int> tree;
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
    AVL<int> tree;
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

void testCopyConstructor() {
    cout << "Test 3: Testing Copy Constructor" << endl;
    AVL<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);

    AVL<int> other(tree);
    other.insert(20);

    cout << "In-order Traversal (Should be 20, 30, 50, 70): \n";
    other.inOrder(outputFunction);
    cout << "-----------------------------------------" << endl;
}

void testAssignOperator() {
    cout << "Test 4: Testing Assign Operator" << endl;
    AVL<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);

    AVL<int> other;
    other = tree;
    other.insert(20);

    cout << "In-order Traversal (Should be 20, 30, 50, 70): \n";
    other.inOrder(outputFunction);
    cout << "-----------------------------------------" << endl;
}

void testDestructor() {
    cout << "Test 5: Testing Destructor" << endl;
    AVL<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);

    tree.~AVL();
    cout << "<<In-order Traversal should not print anything>>\n";
    cout << "Tree: ";
    tree.inOrder(outputFunction);
    cout << endl;
    cout << "-----------------------------------------" << endl;
}

AVL<int> testReturnByValue() {
    cout << "Test 6: Testing Return By Value" << endl;
    AVL<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);

    cout << "The tree will be tested on Test 7" << endl;
    cout << "-----------------------------------------" << endl;
    return tree;
}

void testPassByReference(AVL<int>& tree) {
    cout << "Test 7: Testing Pass By Reference" << endl;
    tree.insert(20);

    cout << "In-order Traversal (Should be 20, 30, 50, 70): \n";
    tree.inOrder(outputFunction);
    cout << "-----------------------------------------" << endl;
}

void testPassByConstReference(const AVL<int>& tree) {
    cout << "Test 8: Testing Pass By Const Reference" << endl;
    result(true, tree.search(70), "8. Testing Pass By Const Reference");
    cout << "-----------------------------------------" << endl;
}

void testPassByValue(AVL<int> tree) {
    cout << "Test 9: Testing Pass By Value" << endl;
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
    AVL<int> tree = testReturnByValue();
    testPassByReference(tree);
    testPassByConstReference(tree);
    testPassByValue(tree);

    cout << "All tests completed." << endl;
    return 0;
}

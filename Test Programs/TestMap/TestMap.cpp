#include <iostream>
#include "../../Data Structures/Map.h"

using namespace std;

template<class T>
void result(T expected, T actual, const string& testMessage) {
    cout << testMessage << ": ";
    if (expected == actual) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << "\n    Expected: " << expected << " but got: " << actual << endl;
    }
}

void testInsertAndAccess() {
    cout << "Test 1: Testing Insert and Access Functions" << endl;
    Map<int, string> map;
    map.insert(1, "one");
    map.insert(2, "two");
    map.insert(3, "three");

    result(string("one"), map[1], "1.1 Access element with key 1");
    result(string("two"), map[2], "1.2 Access element with key 2");
    result(string("three"), map[3], "1.3 Access element with key 3");
    cout << "-----------------------------------------" << endl;
}

void testContainsAndAt() {
    cout << "Test 2: Testing Contains and At Functions" << endl;
    Map<int, string> map;
    map.insert(1, "one");
    map.insert(2, "two");

    result(true, map.contains(1), "2.1 Contains key 1");
    result(false, map.contains(3), "2.2 Does not contain key 3");

    try {
        string value = map.at(1);
        result(string("one"), value, "2.3 At function for key 1");
    } catch (const std::out_of_range& e) {
        cout << "2.3 At function for key 1: FAILED" << "\n    Exception: " << e.what() << endl;
    }

    try {
        map.at(3);
        cout << "Map at 3: " << map.at(3) << endl;
        cout << "2.4 At function for key 3: FAILED" << "\n    Expected an exception but got none" << endl;
    } catch (const std::out_of_range& e) {
        cout << "2.4 At function for key 3: PASSED" << endl;
    }
    cout << "-----------------------------------------" << endl;
}

void testClearAndEmpty() {
    cout << "Test 3: Testing Clear and Empty Functions" << endl;
    Map<int, string> map;
    result(true, map.empty(), "3.1 Map is initially empty");

    map.insert(1, "one");
    result(false, map.empty(), "3.2 Map is not empty after insert");

    map.clear();
    result(true, map.empty(), "3.3 Map is empty after clear");
    cout << "-----------------------------------------" << endl;
}

void testIterators() {
    cout << "Test 4: Testing Iterators" << endl;
    Map<int, string> map;
    map.insert(1, "one");
    map.insert(2, "two");
    map.insert(3, "three");

    cout << "4.1 Iterating through map:" << endl;
    for (auto it = map.begin(); it != map.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
    cout << "-----------------------------------------" << endl;
}

void testCopyConstructor() {
    cout << "Test 5: Testing Copy Constructor" << endl;
    Map<int, string> map;
    map.insert(1, "one");
    map.insert(2, "two");

    Map<int, string> copy(map);
    result(string("one"), copy[1], "5.1 Copy contains key 1");
    result(string("two"), copy[2], "5.2 Copy contains key 2");
    cout << "-----------------------------------------" << endl;
}

void testAssignmentOperator() {
    cout << "Test 6: Testing Assignment Operator" << endl;
    Map<int, string> map;
    map.insert(1, "one");
    map.insert(2, "two");

    Map<int, string> assigned;
    assigned = map;
    result(string("one"), assigned[1], "6.1 Assignment contains key 1");
    result(string("two"), assigned[2], "6.2 Assignment contains key 2");
    cout << "-----------------------------------------" << endl;
}

int main() {
    testInsertAndAccess();
    testContainsAndAt();
    testClearAndEmpty();
    testIterators();
    testCopyConstructor();
    testAssignmentOperator();

    cout << "All tests completed." << endl;
    return 0;
}

#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
//---------------------------------------------------------------------------------

using namespace std;
using LongInt = long long int;
//---------------------------------------------------------------------------------

/**
 * @class Vector
 * @brief Vector class representing a dynamic array.
 *
 * @author Trong Tu Le
 * @version 1
 *
 * @version 2
 * remove setElementAtIndex function
 * add operator to set the element at specified index
 * add 1 more Constructor
 * adjust the name of the variables of the class, and rename getSize() to size()
 * adjust ~Vector Destructor  (setting the capacity and size to 0)
 * add operator =
 * change int -> LongInt (long long int) for a larger range
 *
 * @version 3
 * add Clear function
 *
 * @version 4
 * adjust the name of private variables of the class, and rename the size() function
 *
 * @version 5
 * fix the parameterized constructor to handle the case when cap is negative number
 *
 * @version 6
 * remove grow function, 2 constructors, and 2 members of the class
 * modify the class so it encapsulates std::vector
 *
 * @version 7
 * add copy constructor
 * add assign operator
 */

/**
 * @brief Template class representing a dynamic array.
 *
 * @tparam T - The type of elements to be stored in the array.
 */
template <class T>
class Vector {
    public:
        /**
         * @brief Default Constructor
         *
         */
        Vector();

        /**
         * @brief Copy Constructor
         *
         * @param other - The other Vector to copy from
         */
        Vector(const Vector<T>& other);


        /**
         * @brief Destructor to release dynamically allocated memory.
         */
        ~Vector();

        /**
         * @brief Assignment operator
         *
         * @param other - The other Vector to assign from
         * @return Reference to this Vector
         */
        Vector<T>& operator=(const Vector<T>& other);

        /**
         * @brief add the element at the end of the array
         *
         * @param element - the element
         *
         * @return void
        */
        void add(const T& element);

        /**
         * @brief function to return the number of element stored in the array
         *
         * @return  the number of elements stored in the array
        */
        LongInt Size() const;

        /**
         * @brief operator to access the element at the specified index.
         *
         * @param index - The specified index
         *
         * @return the element at the specified index
        */
        const T& operator[](LongInt index) const;

        /**
         * @brief operator to set the element at the specified index
         *
         * @param index - the specified index
         *
         * return the element at the specified index
        */
        T& operator[](LongInt index);

        /**
         *  @brief Function to delete all elements in the vector
         *
         *  @return void
        */
        void Clear();

    private:
        vector<T> vec; /// vector
};

//---------------------------------------------------------------------------------

// Default Constructor
template <class T>
Vector<T>::Vector() : vec(){
}

//---------------------------------------------------------------------------------

// Copy Constructor
template <class T>
Vector<T>::Vector(const Vector<T>& other) : vec(other.vec){
}

//---------------------------------------------------------------------------------

// Deconstructor to release dynamically allocated memory
template <class T>
Vector<T>::~Vector(){
    vec.clear();
    vec.shrink_to_fit();
}

//---------------------------------------------------------------------------------

// Assignment operator
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        vec = other.vec;
    }
    return *this;
}

//---------------------------------------------------------------------------------

// Method to add an element
template <class T>
void Vector<T>::add(const T& element){
    vec.push_back(element);
}

//---------------------------------------------------------------------------------

// Getter for size
template <class T>
LongInt Vector<T>::Size() const{
    return vec.size();
}

//---------------------------------------------------------------------------------

// Operator to access the element at specified index
template <class T>
const T& Vector<T>::operator[](LongInt index) const{
    return vec[index];
}

//---------------------------------------------------------------------------------

// Operator to set the element at the specified index
template <class T>
T& Vector<T>::operator[](LongInt index){
    return vec[index];
}

//---------------------------------------------------------------------------------

// Function to delete all elements in the vector
template <class T>
void Vector<T>::Clear(){
    vec.clear();
}

//---------------------------------------------------------------------------------

#endif

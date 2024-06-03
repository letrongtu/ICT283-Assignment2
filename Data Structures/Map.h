#ifndef MAP_H
#define MAP_H

//---------------------------------------------------------------------------------
#include <map>
//---------------------------------------------------------------------------------

/**
 * @brief A templated map class that wraps around std::map.
 *
 * @tparam K Key type.
 * @tparam V Value type.
 */
template<class K, class V>
class Map {

public:
    /**
     * @brief Type alias for the iterator.
     *
     * This alias provides an iterator type for iterating over elements of the map.
     */
    using iterator = typename std::map<K, V>::iterator;

    /**
     * @brief Type alias for the constant iterator.
     *
     * This alias provides a constant iterator type for iterating over elements of the map.
     * It ensures that the elements cannot be modified while iterating.
     */
    using const_iterator = typename std::map<K, V>::const_iterator;

    /**
     * @brief Default constructor
     */
    Map();

    /**
     * @brief Copy constructor
     *
     * @param other The map to copy from
     */
    Map(const Map<K, V>& other);

    /**
     * @brief Destructor.
     */
    ~Map();

    /**
     * @brief Assignment operator
     *
     * @param other The map to assign from
     * @return Reference to this map
     */
    Map<K, V>& operator=(const Map<K, V>& other);

    /**
     * @brief Operator to access or modify elements
     *
     * @param key The key of the element to access
     * @return Reference to the value corresponding to the key
     */
    V& operator[](const K& key);

    /**
     * @brief Inserts a key-value pair into the map
     *
     * @param key The key to insert
     * @param value The value to insert
     */
    void insert(const K& key, const V& value);

    /**
     * @brief Retrieves the value corresponding to a key
     *
     * @param key The key of the value to retrieve
     * @return Constant reference to the value
     */
    const V& at(const K& key) const;

    /**
     * @brief Checks if the map contains a key
     *
     * @param key The key to check
     * @return True if the key is found, false otherwise
     */
    bool contains(const K& key) const;

    /**
     * @brief Checks if the map is empty
     *
     * @return True if the map is empty, false otherwise
     */
    bool empty() const;

    /**
     * @brief Clears the map.
     */
    void clear();

    /**
     * @brief Returns an iterator to the beginning.
     *
     * @return Iterator to the beginning.
     */
    iterator begin();

    /**
     * @brief Returns an iterator to the end.
     *
     * @return Iterator to the end.
     */
    iterator end();

    /**
     * @brief Returns a constant iterator to the beginning.
     *
     * @return Constant iterator to the beginning.
     */
    const_iterator begin() const;

    /**
     * @brief Returns a constant iterator to the end.
     *
     * @return Constant iterator to the end.
     */
    const_iterator end() const;

private:
    std::map<K, V> map; /// Internal map to store key-value pairs.
};

//---------------------------------------------------------------------------------

// Default constructor
template <class K, class V>
Map<K, V>::Map() : map(){
}

//---------------------------------------------------------------------------------

// Copy constructor
template <class K, class V>
Map<K, V>::Map(const Map<K, V>& other) : map(other.map){
}

//---------------------------------------------------------------------------------

// Destructor
template <class K, class V>
Map<K, V>::~Map(){
}

//---------------------------------------------------------------------------------

// Assignment operator
template <class K, class V>
Map<K, V>& Map<K, V>::operator=(const Map<K, V> &other){
    if (this != &other) {
        map = other.map;
    }

    return *this;
}

//---------------------------------------------------------------------------------

// Operator to access or modify elements
template <class K, class V>
V& Map<K, V>::operator[](const K& key) {
    return map[key];
}

//---------------------------------------------------------------------------------

// Function to insert a key-value pair into the map
template<class K, class V>
void Map<K, V>::insert(const K& key, const V& value) {
    map[key] = value;
}

//---------------------------------------------------------------------------------

// Function to retrieve the value corresponding to a key
template<class K, class V>
const V& Map<K, V>::at(const K& key) const {
    auto it = map.find(key);
    return it->second;
}

//---------------------------------------------------------------------------------

// Function to check if the map contains a key
template <class K, class V>
bool Map<K, V>::contains(const K &key) const{
    return map.find(key) != map.end();
}

//---------------------------------------------------------------------------------

// Function to check if the map is empty
template <class K, class V>
bool Map<K, V>::empty() const{
    return map.empty();
}

//---------------------------------------------------------------------------------

// Function to clear the map
template <class K, class V>
void Map<K, V>::clear(){
    map.clear();
}

//---------------------------------------------------------------------------------

// Function to return an iterator to the beginning
template <class K, class V>
typename Map<K, V>::iterator Map<K, V>::begin(){
    return map.begin();
}

//---------------------------------------------------------------------------------

// Function to return an iterator to the end
template <class K, class V>
typename Map<K, V>::iterator Map<K, V>::end() {
    return map.end();
}

//---------------------------------------------------------------------------------

// Function to return a constant iterator to the beginning
template <class K, class V>
typename Map<K, V>::const_iterator Map<K, V>::begin() const {
    return map.begin();
}

//---------------------------------------------------------------------------------

// Function to return a constant iterator to the end
template <class K, class V>
typename Map<K, V>::const_iterator Map<K, V>::end() const {
    return map.end();
}

//---------------------------------------------------------------------------------

#endif

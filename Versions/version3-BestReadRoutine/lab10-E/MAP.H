#ifndef MAP_H
#define MAP_H

//---------------------------------------------------------------------------------

#include <map>
using namespace std;

//---------------------------------------------------------------------------------

/**
 * @brief A templated map class that wraps around std::map.
 *
 * @tparam K Key type.
 * @tparam V Value type.
 */
template<typename K, typename V>
class Map {

public:
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
     * @brief Removes a key-value pair from the map
     *
     * @param key The key of the element to remove
     */
    void remove(const K& key);

    /**
     * @brief Clears the map.
     */
    void clear();

private:
    map<K, V> map; /// Internal map to store key-value pairs.
};

//---------------------------------------------------------------------------------

// Default constructor
template <typename K, typename V>
Map<K, V>::Map() : map(){
}

//---------------------------------------------------------------------------------

// Copy constructor
template <typename K, typename V>
Map<K, V>::Map(const Map<K, V>& other) : map(other.map){
}

//---------------------------------------------------------------------------------

// Destructor
template <typename K, typename V>
Map<K, V>::~Map(){
}

//---------------------------------------------------------------------------------

// Assignment operator
template <typename K, typename V>
Map<K, V>& Map<K, V>::operator=(const Map<K, V> &other)
{
    if (this != &other) {
        map = other.map;
    }

    return *this;
}

//---------------------------------------------------------------------------------

// Operator to access or modify elements
template <typename K, typename V>
V& Map<K, V>::operator[](const K& key) {
        return map[key];
}

//---------------------------------------------------------------------------------

// Function to insert a key-value pair into the map
template<typename K, typename V>
void Map<K, V>::insert(const K& key, const V& value) {
    map[key] = value;
}

//---------------------------------------------------------------------------------

// Function to retrieve the value corresponding to a key
template<typename K, typename V>
const V& Map<K, V>::at(const K& key) const {
    auto it = map.find(key);
    return it->second;
}

//---------------------------------------------------------------------------------

// Function to check if the map contains a key
template <typename K, typename V>
bool Map<K, V>::contains(const K &key) const{
    return map.find(key) != map.end();
}

//---------------------------------------------------------------------------------

// Function to remove a key-value pair from the map
template <typename K, typename V>
bool Map<K, V>::empty() const{
    return map.empty();
}

//---------------------------------------------------------------------------------

// Function to check if the map is empty
template<typename K, typename V>
void Map<K, V>::remove(const K& key) {
    map.erase(key);
}

//---------------------------------------------------------------------------------

// Function to clear the map
template <typename K, typename V>
void Map<K, V>::clear(){
    map.clear();
}

//---------------------------------------------------------------------------------

#endif

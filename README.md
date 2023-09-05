# HashMap
A user defined hash map

This is a simple implementation of a hash map (also known as a hash table) in C++. It is a user-defined hash map that allows you to store key-value pairs, where keys are integers, and values are of any data type.

## Features

- Hashing function for efficient storage and retrieval of key-value pairs.
- Automatic resizing (rehashing) when the hash map is full.
- Support for inserting, searching, and removing key-value pairs.
- Keeps track of the size and capacity of the hash map.

## Usage

To use this HashMap in your C++ program:

1. Include the `HashMap` header file in your source code:
     ```cpp
    #include "HashMap.h"
2. Include the `HashMap` header file in your source code:

    HashMap<std::string> myMap;
3. Use the provided functions to insert, search, and remove key-value pairs:

    myMap.insert(42, "Hello");
    std::string value = myMap.search(42);
    bool removed = myMap.remove(42);

4. You can also check the size and capacity of the hash map:

     int size = myMap.size();
     int capacity = myMap.capacity();

   
Contributing

Feel free to contribute to this project by submitting bug reports, feature requests, or pull requests.

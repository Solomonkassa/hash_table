Introduction:
A hash table is a data structure that maps keys to values by using a hash function to compute an index into an array of buckets, from which the correct value can be found. Hash tables provide constant-time average-case performance for insertion, deletion, and lookup operations.

Implementation:
The hash table implementation consists of two main classes: HashTable and HashNode.

    HashTable:
    The HashTable class contains the implementation of the hash table itself. It maintains an array of HashNodes as buckets, with each HashNode representing a key-value pair. The hash table supports the following operations:
    a. Insertion of a key-value pair: insert(key, value)
    b. Deletion of a key: delete(key)
    c. Lookup of a key: get(key)

    HashNode:
    The HashNode class contains the implementation of each key-value pair. Each HashNode has a key and value, and a reference to the next HashNode in the same bucket.

Hash Function:
The hash function is used to compute the index into the bucket array for each key-value pair. A good hash function should distribute the keys uniformly across the array to minimize the number of collisions. In this implementation, we are using the modulo operator with a prime number to generate the hash value.

Collision Resolution:
Collisions occur when two or more keys hash to the same index in the array. To resolve collisions, we are using chaining, which means that each bucket contains a linked list of HashNodes that have collided.

Usage:
To use the hash table implementation, you need to create an instance of the HashTable class and call the required methods. Here is an example:

lua

hash_table = HashTable()
hash_table.insert('key1', 'value1')
hash_table.insert('key2', 'value2')
hash_table.get('key1')
hash_table.delete('key2')

Conclusion:
The hash table is an efficient data structure for key-value storage and retrieval. This implementation provides a basic understanding of how hash tables work and can be used as a starting point for building more complex hash tables with additional features.

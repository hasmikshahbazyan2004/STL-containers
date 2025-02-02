#include <iostream>
#include "unordered_set.hpp"
using namespace std;
using namespace MyHash;


template <typename Key, typename Hash, typename KeyEqual, typename Allocator>
unordered_set<Key, Hash, KeyEqual, Allocator>::unordered_set(): unordered_set(16){cout << "default\n";}

template <typename Key, typename Hash, typename KeyEqual, typename Allocator>
unordered_set<Key, Hash, KeyEqual, Allocator>::unordered_set(size_t bucket, 
                                                                    const Hash& hash,
                                                            const key_equal& equal,
                                                                    const Allocator& alloc): buckets(bucket){cout << "Parametrized\n";}

template <typename Key, typename Hash, typename KeyEqual, typename Allocator>
unordered_set<Key, Hash, KeyEqual, Allocator>::unordered_set(const Allocator& alloc): buckets(16), 
                                                hash_function(Hash()), 
                                                equal_function(KeyEqual()), 
                                                allocator(Allocator()),
                                                element_count(0){}



/* insert_return_type<iterator, node_type<value_type, allocator_type>> insert(const value_type& value) {
    size_t bucket_index = bucket(value);
    auto& bucket = buckets[bucket_index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (*it == value) {
            // Value already exists, return node and false
            node_type<value_type, allocator_type> node(value, allocator_type());
            return {iterator(it), false, node};
        }
    } */

/* node_type<value_type, allocator_type> extract(const key_type& key) {
    size_t bucket_index = bucket(key);
    auto& bucket = buckets[bucket_index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (*it == key) {
            node_type<value_type, allocator_type> node(*it, allocator_type());
            bucket.erase(it);
            return node;
        }
    }
    return node_type<value_type, allocator_type>();
}*/
 
#include <iostream>
#include "unordered_set.hpp"

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
}
 */
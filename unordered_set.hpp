#ifndef MY_UNORDERED_SET_H
#define MY_UNORDERED_SET_H

#include <vector>
#include <list>
#include <functional> //we use std::hash from this library

//Creating your own namespace is useful for avoiding name collisions
namespace MyHash{
    template <class Key,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator<Key>
    >
    class unordered_set{
    public:
        using key_type = Key;
        using value_type = Key;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using hasher = Hash;
        using key_equal = KeyEqual;
        using allocator_type = Allocator;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = std::allocator_traits<Allocator>::pointer;
        using const_pointer = std::allocator_traits<Allocator>::const_pointer;
        using iterator = typename std::list<value_type>::const_iterator;
        using const_iterator = typename std::list<value_type>::const_iterator;
        using local_iterator = typename std::list<value_type>::iterator;
        using const_local_iterator = typename std::list<value_type>::cons_iterator;
        iterator begin() const;/*{ return data.cbegin();} */
        iterator end() const; /* {return data.cend();} */
        local_iterator begin(size_t bucket); /* {return buckets[bucket].begin();} */
        local_iterator end(size_t bucket); /* {return buckets[bucket].end();} */
        const_local_iterator begin(size_t bucket) const; /* {return buckets[bucket].cend();} */
        const_local_iterator end(size_t bucket) const; /* {return buckets[bucket].cend();} */


        template <typename ValueType, typename Allocator>
        class node_type{
        public:
            using allocator_type = Allocator;

            node_type(): allocated(false){}
            node_type(const ValueType& val, const Allocator& alloc): value(val), allocator(alloc), allocated(true){}

            bool empty() const noexceptxcept;
            void swap(node_type& other) noexcept;
            ValueType& value() noexcept;
            const ValueType& value() const noexcept;

        private:
            ValueType value;
            Allocator allocator;
            bool allocated;
            //std::vector<std::list<value_type>> buckets{10}; //*** for begin, end..operations
            //std::list<value_type> data; // Used for global iteration
            
        };

        node_type<value_type, allocator_type> extract(const key_type& key);

        template <typename Iterator, typename NodeType>
        struct insert_return_type{
            Iterator position;
            bool inserted;
            NodeType node;
        };

        insert_return_type<iterator, node_type<value_type, allocator_type>> insert(const value_type& value);


    private:
        //std::vector<std::list<value_type>> buckets{10};

    };

}
#endif
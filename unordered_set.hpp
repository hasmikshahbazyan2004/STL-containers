#ifndef MY_UNORDERED_SET_H
#define MY_UNORDERED_SET_H

#include <vector>
#include <list>
#include <functional> //we use std::hash from this library
using namespace std;

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
        using const_local_iterator = typename std::list<value_type>::const_iterator;
        iterator begin() const;/*{ return data.cbegin();} */
        iterator end() const; /* {return data.cend();} */
        local_iterator begin(size_t bucket); /* {return buckets[bucket].begin();} */
        local_iterator end(size_t bucket); /* {return buckets[bucket].end();} */
        const_local_iterator begin(size_t bucket) const; /* {return buckets[bucket].cend();} */
        const_local_iterator end(size_t bucket) const; /* {return buckets[bucket].cend();} */


        template <typename ValueType, typename _Allocator>
        class node_type{
        public:
            using allocator_type = _Allocator;

            node_type(): _allocated(false){}
            node_type(const ValueType& val, const _Allocator& alloc): _value(val), _allocator(alloc), _allocated(true){}

            bool empty() const noexcept;
            void swap(node_type& other) noexcept;
            ValueType& value() noexcept;
            const ValueType& value() const noexcept;

        private:
            ValueType _value;
            Allocator _allocator;
            bool _allocated;
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

        unordered_set();
        explicit unordered_set(size_type bucket_count,
                                const Hash& hash = Hash(),
                                const key_equal& equal = key_equal(),
                                const Allocator& alloc = Allocator() );

        unordered_set(size_type bucket_count,
                        const Allocator& alloc): unordered_set(bucket_count, Hash(), key_equal(), alloc){cout << "bucket size, allocator\n";}

        explicit unordered_set(const Allocator& alloc);

        template <class InputIt>
        unordered_set(InputIt first, InputIt last, 
                        size_type bucket_count, 
                        const Allocator& alloc): unordered_set(first, last, 
                                                                bucket_count, 
                                                                Hash(), 
                                                                key_equal(), 
                                                                alloc) {}
        template <typename InputIt>
        unordered_set(InputIt first, InputIt last, 
                        size_type bucket_count,
                        const Hash& hash,
                        const Allocator& alloc): unordered_set(first, last,
                                                                bucket_count,
                                                                hash,
                                                                key_equal(),
                                                                alloc){}
        

        insert_return_type<iterator, node_type<value_type, allocator_type>> insert(const value_type& value);


    private:
        std::vector<std::list<Key>> buckets; // Hash table
        size_type bucket_count; //Number of buckets
        size_type element_count; //Total number of elements
        hasher hash_function; //Hash function
        key_equal equal_function; // Comparator(Equality comparsion)
        allocator_type allocator; // Allocator for memory management

    };

}
#endif
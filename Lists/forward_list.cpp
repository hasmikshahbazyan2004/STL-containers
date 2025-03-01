#include <iostream>

template <typename T>
class forward_list{
 private:
        struct Node{
            T m_data;
            Node* m_next;
            Node(T data) : m_data(data), m_next(nullptr){std::cout << "Node ctor\n";}
        };
            Node* m_head;
public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = T&;
    using const_reference = const T&;
    using  pointer = T*;
    using const_pointer = const T*;

    forward_list() : m_head(nullptr){std::cout << "list ctor\n";}
    forward_list(size_type count){
        Node* node = new Node(0);
        m_head = node;
        Node* current = m_head;
        while(current && count - 1){
            current -> m_next = new Node(0);
            current = current -> m_next;
            --count;
        }
    }

    forward_list(value_type data, size_type count){
        Node* node = new Node(data);
        m_head = node;
        Node* current = m_head;
        while(current && count - 1){
            current -> m_next = new Node(data);
            current = current -> m_next;
            --count;
        }
    }

    forward_list& operator=(const forward_list& rhs){
        if (this != &rhs){
            Node* current = m_head;
            Node* rhs_current = rhs.m_head;

            while (current){
                Node* tmp = current -> m_next;
                delete current;
                current = tmp;
            }

            m_head = new Node (rhs.m_head -> m_data);
            current = m_head;
            while (rhs_current -> m_next){
                current -> m_next = new Node(rhs_current -> m_next -> m_data);
                current = current -> m_next;
                rhs_current = rhs_current -> m_next;
            }
        }
            return *this;
    }

    ~forward_list(){
        std::cout << "list dtor\n";
        Node* current = m_head;
        while(current){
            Node* m_next = current -> m_next;
            delete current;
            current = m_next;
        }
    }



    void print(){
        Node* current = m_head;
        while(current){
            std::cout << current -> m_data << ' ';
            current = current -> m_next;
        }
            std::cout << std::endl;
    }
    
    class iterator {
    public:
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using difference_type = std::ptrdiff_t;

        iterator(Node* node) : m_current(node){}

        reference operator*(){
            return m_current -> m_data;
        }

        pointer operator->(){
            return &(m_current->m_data);
        }

        iterator& operator++(){
            if (m_current){
                m_current = m_current -> m_next;
            }
            return *this;
        }

        iterator& operator++(int){
            iterator tmp = *this;
            m_current = m_current -> m_next;
            return tmp;
        }

        bool operator!=(iterator& other) const{
            return m_current != other.m_current;
        }

        bool operator==(iterator& other)const{
            return m_current == other.m_current;
        }
        
    
    private:
        Node* m_current;
    };

    iterator begin() const{
            return iterator(m_head);
        }

    iterator end() const{
        return iterator(nullptr);
    }

};

template <typename T>
bool operator!=(const forward_list<T>& lhs, const forward_list<T>& rhs){
    auto it1 = lhs.begin();
    auto it2 = rhs.begin();
    auto it1_end = lhs.end();
    auto it2_end = lhs.end();

    while (it1 != it1_end && it2 != it2_end) {
        if (*it1 != *it2) {
            return true;  
        }
        ++it1;
        ++it2;
    }

        return (it1 != it1_end || it2 != it2_end);
}

template <typename T>
bool operator==(const forward_list<T>& lhs, const forward_list<T>& rhs){
    auto it1 = lhs.begin();
    auto it2 = rhs.begin();
    auto it1_end = lhs.end();
    auto it2_end = lhs.end();

    while (it1 != it1_end && it2 != it2_end) {
        if (*it1 == *it2) {
            return true;  
        }
        ++it1;
        ++it2;
    }

        return (it1 == it1_end || it2 == it2_end);
}

template <typename T>
bool operator >(const forward_list<T>& lhs, const forward_list<T>& rhs){
    auto it1 = lhs.begin();
    auto it2 = rhs.begin();
    auto it1_end = lhs.end();
    auto it2_end = lhs.end();

    while (it1 != it1_end && it2 != it2_end) {
        if (*it1 > *it2) {
            return true;  
        }
        ++it1;
        ++it2;
    }
        return false;
}

template <typename T>
bool operator >=(const forward_list<T>& lhs, const forward_list<T>& rhs){
    auto it1 = lhs.begin();
    auto it2 = rhs.begin();
    auto it1_end = lhs.end();
    auto it2_end = lhs.end();

    while (it1 != it1_end && it2 != it2_end) {
        if (*it1 >= *it2) {
            return true;  
        }
        ++it1;
        ++it2;
    }
        return false;
}

template <typename T>
bool operator <(const forward_list<T>& lhs, const forward_list<T>& rhs){
    auto it1 = lhs.begin();
    auto it2 = rhs.begin();
    auto it1_end = lhs.end();
    auto it2_end = lhs.end();

    while (it1 != it1_end && it2 != it2_end) {
        if (*it1 < *it2) {
            return true;  
        }
        ++it1;
        ++it2;
    }
        return false;
}

template <typename T>
bool operator <=(const forward_list<T>& lhs, const forward_list<T>& rhs){
    auto it1 = lhs.begin();
    auto it2 = rhs.begin();
    auto it1_end = lhs.end();
    auto it2_end = lhs.end();

    while (it1 != it1_end && it2 != it2_end) {
        if (*it1 <= *it2) {
            return true;  
        }
        ++it1;
        ++it2;
    }
        return false;
}


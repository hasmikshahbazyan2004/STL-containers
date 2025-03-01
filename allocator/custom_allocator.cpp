#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template <typename T>
class CustomAllocator{
public:
    using value_type = T;

    CustomAllocator() = default;

    T* allocate(std::size_t n){
        cout << "Allocating " << n << " elements.\n";
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t n){
        cout << "Allocating " << n << " elements.\n";
        ::operator delete(p);
    }

    template <typename U, typename... Args>
    void construct(U* p, Args&&... args){
        ::new((void*)p) U(std::forward<Args>(args)...);
    }

    template <typename U>
    void destroy(U* p){
        p -> ~U();
    }
};

int main(){
    vector<int, CustomAllocator<int>> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    for (const auto& v : vec){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}

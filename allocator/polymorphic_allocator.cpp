#include <iostream>
#include <vector>
#include <memory_resource>

int main(){
    char buffer[1024];
    std::pmr::monotonic_buffer_resource pool{buffer, sizeof(buffer)};
    std::pmr::vector<int> vec{&pool};

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    for (const auto& val : vec){
        std::cout << val << " ";
    }

    std::cout << std::endl;

    return 0;
}
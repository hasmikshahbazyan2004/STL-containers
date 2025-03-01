#include "unordered_set.cpp"
using namespace MyHash;

int main(){
    unordered_set<int> set1;
    unordered_set<int> set2;
    set2(std::move(set1));
    return 0;
}
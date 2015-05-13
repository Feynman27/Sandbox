#include <unordered_set>
#include <iostream>

template <typename T>
void DisplayContents(const T& input){
    std::cout << "Number of elements, size() = " << input.size() << std::endl;
    std::cout << "Max bucket count = " << input.max_bucket_count() << std::endl;
    std::cout << "Load factor: " << input.load_factor() << std::endl;
    std::cout << "Max load factor = " << input.max_load_factor() << std::endl;
    std::cout << "Unordered set contains: " << std::endl;

    for(typename T::const_iterator i=input.begin(); i!=input.end(); ++i){

        std::cout << *i << ' ';
    }//i
    std::cout << std::endl;
}

int main(){
    
    std::unordered_set<int> usetInts;
    usetInts.insert(1000);
    usetInts.insert(-3);
    usetInts.insert(2011);
    usetInts.insert(300);
    usetInts.insert(-1000);
    usetInts.insert(989);
    usetInts.insert(-300);
    usetInts.insert(111);
    DisplayContents(usetInts);
    usetInts.insert(999);
    DisplayContents(usetInts);

    std::cout << "Enter integer to search for: " << std::endl;
    int Key=0;
    std::cin >> Key;

    std::unordered_set<int>::iterator iter;
    iter=usetInts.find(Key);

    if(iter!=usetInts.end()){
        std::cout << *iter << " found in set" << std::endl;
    }
    else std::cout << Key << " not found." << std::endl;

    return 0;
}

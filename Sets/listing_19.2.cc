#include <set>
#include <iostream>

template <typename T>
void DisplayContents(const T& input){
    for(typename T::const_iterator iElement = input.begin(); iElement!=input.end(); ++iElement) 
        std::cout << *iElement << ' ' << std::endl;
}

int main(){

    std::set<int> setIntegers;
    std::multiset<int> msetIntegers;

    setIntegers.insert(60);
    setIntegers.insert(-1);
    setIntegers.insert(3000);
    std::cout << "Writing the contents of the set to the screen" << std::endl;
    DisplayContents(setIntegers);
    
    msetIntegers.insert(setIntegers.begin(),setIntegers.end());
    msetIntegers.insert(3000);

    std::cout << "Number of instances of 3000 in the multiset are: " << msetIntegers.count(3000) << std::endl;

    return 0;
}

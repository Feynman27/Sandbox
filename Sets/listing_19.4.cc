#include <set>
#include <iostream>

template <typename T>
void DisplayContents(const T& input){
    for(typename T::const_iterator i = input.begin(); i!=input.end(); ++i){
        std::cout << *i << ' ';
    }//i
        std::cout << std::endl;
}

int main(){
    std::multiset<int> msetInts;

    msetInts.insert(43);
    msetInts.insert(78);
    msetInts.insert(78);
    msetInts.insert(-1);
    msetInts.insert(124);

    std::cout << "Multiset contains " << msetInts.size() << " elements." << std::endl;
    std::cout << "These are: " << std::endl;

    DisplayContents(msetInts);

    std::cout << "Enter number to erase : " << std::endl;
    int nNumberToErase;
    std::cin >> nNumberToErase;

    std::cout << "Erasing " << msetInts.count(nNumberToErase) << " instances of value " << nNumberToErase << std::endl;

    std::multiset<int>::iterator iter;
    iter=msetInts.find(nNumberToErase);
    if(iter!=msetInts.end())
        msetInts.erase(msetInts.begin(),iter);
    else std::cout << "Element " << nNumberToErase << " not found." << std::endl;

    std::cout << "Multiset contains " << msetInts.size() << " elements." << std::endl;
    std::cout << "These are: " << std::endl;

    DisplayContents(msetInts);
    
    return 0;
}

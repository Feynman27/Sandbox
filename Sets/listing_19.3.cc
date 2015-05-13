#include <set>
#include <iostream>

int main(){
    
    std::set<int> setInts;

    setInts.insert(43);
    setInts.insert(78);
    setInts.insert(-1);
    setInts.insert(124);

    for(std::set<int>::const_iterator iter = setInts.begin();
            iter!=setInts.end(); ++iter){
        
        std::cout << *iter << ' ' << std::endl;
    }//iter

    std::set<int>::iterator iter = setInts.find(-1);
    if(iter!=setInts.end()) std::cout << "Element " << *iter << " found!" << std::endl;
    else std::cout << "Element not found in set!" << std::endl;

    iter=setInts.find(1902);
    if(iter!=setInts.end()) std::cout << "Element " << *iter << " found!" << std::endl;
    else std::cout << "Element not found in set!" << std::endl;

    return 0;
}

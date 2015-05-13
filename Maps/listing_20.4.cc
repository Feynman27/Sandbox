
#include <iostream>
#include <map>

template <typename T>
void DisplayContents(const T& input){
    
    for(typename T::const_iterator it=input.begin(); it!=input.end(); ++it){
        std::cout << it->first << "-->" << it->second << std::endl;
    }
}

int main(){

    std::multimap<int,std::string> mmap;

    mmap.insert(std::pair<int,std::string>(3,"Three") );
    mmap.insert(std::pair<int,std::string>(45,"Forty Five") );
    mmap.insert(std::pair<int,std::string>(-1,"Minus One") );
    mmap.insert(std::pair<int,std::string>(1000,"One Thousand") );

    mmap.insert(std::pair<int,std::string>(-1,"Minus One") );
    mmap.insert(std::pair<int,std::string>(1000,"One Thousand") );

    std::cout << "Multimap contains " << mmap.size() << " elements." << std::endl;
    std::cout << "Key-Value pairs: " << std::endl;
    DisplayContents(mmap);

    std::cout << "Erasing " << mmap.erase(-1) << " elements from map" << std::endl;
//    mmap.erase(-1);

    std::multimap<int,std::string>::iterator iter = mmap.find(45);
    if(iter!=mmap.end()){
        mmap.erase(45);
        std::cout << "Erased pair with key: 45" << std::endl; 
    }

    std::cout << "Erasing range of pairs with 1000 as the key." << std::endl;
    mmap.erase(mmap.lower_bound(3),mmap.upper_bound(1000));

    std::cout << "Map now contains: " << mmap.size() << " pairs." << std::endl;
    DisplayContents(mmap);

    
    return 0;
}

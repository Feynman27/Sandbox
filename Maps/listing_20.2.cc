#include <iostream>
#include <map>

template <typename T>
void DisplayContents(const T& input){
    
    for(typename T::const_iterator it=input.begin(); it!=input.end(); ++it){
        std::cout << it->first << "-->" << it->second << std::endl;
    }
}

int main(){

    std::map<int,std::string> mapIntToString;

    mapIntToString.insert(std::map<int,std::string>::value_type (3,"Three") );

    mapIntToString.insert(std::make_pair(-1,"Minus one") );

    mapIntToString.insert(std::pair<int,std::string>(1000,"One thousand") ) ;

    mapIntToString[1000000]="One Million";

    std::cout << "The map contains " << mapIntToString.size() << " elements." << std::endl;
    std::cout << "Key-Value pairs: " << std::endl;
    DisplayContents(mapIntToString);

    std::multimap<int,std::string> mmapIntToString(mapIntToString.begin(),mapIntToString.end());
    mmapIntToString.insert(std::pair<int,std::string>(1000,"One thousand") ) ;

    std::cout << "The multi-map contains " << mmapIntToString.size() << " elements." << std::endl;
    std::cout << "Key-Value pairs: " << std::endl;
    DisplayContents(mmapIntToString);

    std::cout << "The number of pairs in the multimap with 1000 as their key: " << mmapIntToString.count(1000) << std::endl;


    return 0;
}

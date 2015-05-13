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
    
    mapIntToString.insert(std::pair<int,std::string>(3,"Three") );
    mapIntToString.insert(std::pair<int,std::string>(45,"Forty Five") );
    mapIntToString.insert(std::pair<int,std::string>(-1,"Minus One") );
    mapIntToString.insert(std::pair<int,std::string>(1000,"One Thousand") );

    std::cout << "Map contains " << mapIntToString.size() << " elements." << std::endl;
    DisplayContents(mapIntToString);
    
    std::cout << "Enter key you wish to locate: " << std::endl;
    int Key=0;
    std::cin >> Key;

    std::map<int,std::string>::iterator iter = mapIntToString.find(Key);
    if(iter!= mapIntToString.end()) std::cout << "Key " << iter->first << " -->" << iter->second << std::endl;
    else std::cout << "Key cannot be located in map. " << std::endl;

    return 0;
}

#include<map>
#include<iostream>

template <typename KeyType>
struct ReverseSort{
    bool operator()(const KeyType& key1, const KeyType& key2){
        return (key1 > key2);
    }
};

int main(){

    std::map<int,std::string> mapIntToString1;
    std::multimap<int,std::string> mmapIntToString1;

    std::map<int,std::string> mapIntToString2(mapIntToString1);
    std::multimap<int,std::string> mmapIntToString2(mmapIntToString1);
    
    std::map<int,std::string> mapIntToString3(mapIntToString1.begin(),mapIntToString1.end());
    std::multimap<int,std::string> mmapIntToString3(mmapIntToString1.begin(),mmapIntToString1.end());

    std::map<int,std::string,ReverseSort<int> > mapIntToString4(mapIntToString1.begin(),mapIntToString1.end());
    std::multimap<int,std::string,ReverseSort<int> > mmapIntToString4(mmapIntToString1.begin(),mmapIntToString1.end());

    return 0;
}

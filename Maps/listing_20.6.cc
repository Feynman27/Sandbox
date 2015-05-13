#include<iostream>
#include<string>
#include<unordered_map>

template <typename T1, typename T2>
void DisplayUnorderedMap(std::unordered_map<T1,T2>& input){
    std::cout << "Number of pairs: " << input.size() << std::endl;
    std::cout << "Max bucket count = " << input.max_bucket_count() << std::endl;
    std::cout << "Load factor: " << input.load_factor() << std::endl;
    std::cout << "Max load factor: " << input.max_load_factor() << std::endl;
    std::cout << "Unordered map contains: " << std::endl;

    for(auto it=input.begin(); it!=input.end(); ++it){
        std::cout << it->first << " --> " << it->second << std::endl;
    }
}

int main(){

    std::unordered_map<int,std::string> umap;
    umap.insert(std::make_pair(1,"one") );
    umap.insert(std::make_pair(45,"forty-five") );
    umap.insert(std::make_pair(1001,"thousand one") );
    umap.insert(std::make_pair(-2,"minus two") );
    umap.insert(std::make_pair(-1000,"minus one thousand") );
    umap.insert(std::make_pair(100,"one hundred") );
    umap.insert(std::make_pair(12,"twelve") );
    umap.insert(std::make_pair(-100,"minus one hundred") );

    DisplayUnorderedMap(umap);

    std::cout << "Inserting one more element." << std::endl;
    umap.insert(std::make_pair(300,"three hundred") ) ;

    DisplayUnorderedMap(umap);

    std::cout << "Enter key to find: ";
    int Key=0;
    std::cin >> Key;

    auto iter=umap.find(Key);
    if(iter!=umap.end()) std::cout << "Found key-value pair. " << iter->first << " --> " << iter->second << std::endl;
    else std::cout << "Cannot locate key-value pair." << std::endl;

    return 0;
}

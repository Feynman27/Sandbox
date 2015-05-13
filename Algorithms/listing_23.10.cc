#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

template<typename T>
void DisplayContents(const T& input){
    for(typename T::const_iterator it=input.begin(); it!=input.end(); ++it)
           std::cout << *it << std::endl;
}

int main(){

    std::vector<std::string> vec;
    vec.push_back("John Doe");
    vec.push_back("Jack Nicholson");
    vec.push_back("Sean Penn");
    vec.push_back("Anna Hoover");
    
    vec.push_back("Jack Nicholson");

    std::cout << "The initial contents of the vector are: " << std::endl;
    DisplayContents(vec);

    std::cout << "The sorted vector contains names in the order: " << std::endl;
    std::sort(vec.begin(),vec.end());
    DisplayContents(vec);

    std::cout << "Search for \"John Doe\" using binary_search:" << std::endl;
    bool bElementFound = std::binary_search(vec.begin(),vec.end(),"John Doe");

    if(bElementFound) std::cout << "Result: \"John Doe\" was found." << std::endl;
    else std::cout << "Cannot locate element." << std::endl;

    auto iNewEnd = std::unique(vec.begin(),vec.end());
    vec.erase(iNewEnd,vec.end());

    std::cout << "Vector contents after using 'unique':" << std::endl;
    DisplayContents(vec);

    return 0;
}

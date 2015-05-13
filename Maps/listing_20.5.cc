#include<map>
#include<algorithm>
#include<string>
#include<iostream>

template <typename T>
void DisplayContents(const T& input){
    for(typename T::const_iterator it=input.begin(); it!=input.end(); ++it){
        std::cout << it->first << " -->" << it->second << std::endl;
    }
}

struct PredIgnoreCase{

    bool operator()(const std::string& str1, const std::string& str2){
        std::string str1NoCase(str1), str2NoCase(str2);
        std::transform(str1.begin(),str1.end(),str1NoCase.begin(),tolower);
        std::transform(str2.begin(),str2.end(),str2NoCase.begin(),tolower);

        return (str1NoCase<str2NoCase);
    }
};

int main(){

    std::map<std::string,std::string,PredIgnoreCase> dirCaseInsensitive;

    dirCaseInsensitive.insert(std::make_pair("John","23456") );
    dirCaseInsensitive.insert(std::make_pair("JOHN","23456") );
    dirCaseInsensitive.insert(std::make_pair("Sara","15656") );
    dirCaseInsensitive.insert(std::make_pair("Jack","58654") );

    std::cout << "Case insensitive: " << std::endl;
    DisplayContents(dirCaseInsensitive);

    std::map<std::string,std::string> dirCaseSensitive(dirCaseInsensitive.begin(),dirCaseInsensitive.end());

    std::cout << "Case sensitive: " << std::endl;
    DisplayContents(dirCaseSensitive);

    std::cout << "Enter name to search: " << std::endl;
    std::string strNameInput;
    std::cin >> strNameInput;

    std::map<std::string,std::string,PredIgnoreCase>::iterator iter = dirCaseInsensitive.find(strNameInput);
    if(iter!=dirCaseInsensitive.end()) {
        std::cout << iter->first << " -->" << iter->second << std::endl;
    }
    else std::cout << strNameInput << " cannot be found in directory." << std::endl;

    std::map<std::string,std::string>::iterator iter2 = dirCaseSensitive.find(strNameInput);
    if(iter2!=dirCaseSensitive.end()) {
        std::cout << iter2->first << " -->" << iter2->second << std::endl;
    }
    else std::cout << strNameInput << " cannot be found in directory." << std::endl;

    return 0;
}

#include <vector>
#include<utility>
#include<string>
#include<iostream>
#include<algorithm>

struct Container{

    Container(int c): _c(c){}
    int _c;
};

struct comp{
    comp(std::string const& s) : _s(s){}
    bool operator() (std::pair<std::string, Container> const& p){
        return (p.first == _s);
    }

    std::string _s;
};

int main(){

    std::vector<std::pair<std::string,Container> > v;
    v.push_back(std::make_pair("Hello", Container(42) ) );
    v.push_back(std::make_pair("World", Container(1729) ) );
    
    std::vector<std::pair<std::string,Container> >::iterator 
        it = find_if(v.begin(),v.end(),comp("World"));

    if(it!=v.end()){
        Container& c = it->second;
        std::cout << c._c << std::endl;;
    }

    return 0;
}

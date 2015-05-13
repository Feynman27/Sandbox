#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

template <typename T>
void DisplayContents(const T& input){
    for(auto it=input.begin(); it!=input.end(); ++it)
        std::cout << *it << std::endl;
}

int main(){
    
    vector<string> vec;

    vec.push_back("John Doe");
    vec.push_back("Brad Pitt");
    vec.push_back("Jack Nicholson");
    vec.push_back("Sean Penn");
    vec.push_back("Anna Hoover");

    sort(vec.begin(),vec.end());
    //vec.sort();
    DisplayContents(vec);

    std::cout << "Lowest index where \"Thomas Balestri\" may be inserted: " ;
    auto iMinInsertPos = lower_bound(vec.begin(),vec.end(),"Thomas Balestri");
    cout << distance(vec.begin(),iMinInsertPos) << endl;

    std::cout << "Highest index where \"Thomas Balestri\" may be inserted: " ;
    auto iMaxInsertPos = upper_bound(vec.begin(),vec.end(),"Thomas Balestri");
    cout << distance(vec.begin(),iMaxInsertPos) << endl;
    cout<<endl;

    //auto pos = vec.begin() + 2;
    auto pos = find(vec.begin(),vec.end(),vec.at(3));
    cout << "After inserting new element." << endl;
    //vec.insert(iMinInsertPos,"Thomas Balestri");
    vec.insert(pos,"Thomas Balestri");
    DisplayContents(vec);
    sort(vec.begin(),vec.end());
    std::cout<<std::endl;
    DisplayContents(vec);
    
    return 0;
}

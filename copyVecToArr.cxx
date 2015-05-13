// copy algorithm
#include <iostream>
#include <algorithm>
#include <vector>

int main(){

    std::vector<int> myvector;
    myvector.reserve(3);
    myvector.push_back(71);
    myvector.push_back(16);
    myvector.push_back(11);
    const int size = myvector.size();
    std::cout << "My vector contains " << size << " elements." << std::endl;
    int myint[size];
    std::copy(myvector.begin(),myvector.end(), myint);
    for(int i=0; i<myvector.size(); ++i){

        std::cout << "My vector contains " << myvector.at(i) << std::endl;
        std::cout << "My array contains " << myint[i] << std::endl;
    }
}

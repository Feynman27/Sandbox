#include<vector>
#include <iostream>
using namespace std;

int main(){
    
    vector<bool> vecBoolFlags(3);
    vecBoolFlags[0]=true;
    vecBoolFlags[1]=true;
    vecBoolFlags[2]=false;

    vecBoolFlags.push_back(true);

    cout << "The contents of the vector are: " << endl;
    for(size_t i = 0; i<vecBoolFlags.size(); ++i){

        cout << vecBoolFlags[i] << ' ';
    }//i

    cout << endl;

    vecBoolFlags.flip();
    cout << "The contents of the inverted vector are: " << endl;
    for(size_t i = 0; i<vecBoolFlags.size(); ++i){

        cout << vecBoolFlags[i] << ' ';
    }//i

    cout << endl;

    vector<bool> vecBoolFlags2(vecBoolFlags);
    vecBoolFlags2.flip();

    for(size_t i = 0; i<vecBoolFlags.size(); ++i){

        cout << (vecBoolFlags[i] | vecBoolFlags2[i]) << ' ';
    }//i

    cout << endl;

    
    return 0;
}

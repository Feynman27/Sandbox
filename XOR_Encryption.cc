#include<iostream>

int main(){
    
    char string[11] = "A nice cat";
    char key[11]    = "ABCDEFGHIJ";

    for(int x=0; x<10; ++x){

        string[x] = string[x]^key[x];
        std::cout << string[x] ;


    }//x
    std::cout << std::endl;

    return 0;
}

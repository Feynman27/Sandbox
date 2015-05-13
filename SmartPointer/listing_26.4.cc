#include<iostream>
#include<memory> // to use std::unique_ptr

using namespace std;

class Fish{
    public:
        Fish(){cout << "Fish: Ctor." << endl;}
        ~Fish(){cout << "Fish: Dtor." << endl;}
        void Swim() const {cout << "Fish swims in the water." << endl;}

};

void MakeFishSwim(const unique_ptr<Fish>& inFish){
    inFish->Swim();
}

int main(){
    unique_ptr<Fish> smartFish(new Fish);

    smartFish->Swim();
    MakeFishSwim(smartFish); // passed by reference

    unique_ptr<Fish> copySmartFish;
//    copySmartFish = smartFish; // error: operator= is private
    return 0;
}

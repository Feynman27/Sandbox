#include <iostream>
#include <algorithm>
#include <vector>

bool IsEven(int i){

    return ( (i % 2) == 0);
}

int main(){

    using namespace std;
    vector<int> vecIntegers;

    for(int SampleValue=-9; SampleValue<10; ++SampleValue){
        vecIntegers.push_back(SampleValue);
    }//SampleValue

    std::cout << "Enter number to find in collection: " ;
    int NumToFind=0;
    std::cin >> NumToFind;

    std::vector<int>::iterator iElementFound;
    iElementFound = find( vecIntegers.begin(), vecIntegers.end(), NumToFind);

    if(iElementFound!=vecIntegers.end()) std::cout << "Result: Value " << *iElementFound << " found!" << std::endl;
    else std::cout << "Result: No element contains value " << NumToFind << std::endl;

    std::cout << "Finding the first event number using find_if: " << std::endl;

    std::vector<int>::iterator iEvenNumber = std::find_if(vecIntegers.begin(), vecIntegers.end(), IsEven);

    if(iEvenNumber != vecIntegers.end()){
        std::cout << "Number " << *iEvenNumber << " found at position [";
        std::cout << distance (vecIntegers.begin(), iEvenNumber);
        std::cout << "]" << std::endl;
    }

    return 0;
}

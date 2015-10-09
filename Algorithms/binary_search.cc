#include <iostream>
#include <cstdlib>

int binary_search(int array[], int first, int last, int search_key){

    int index;

    if(first>last) index=-1;
    else{ 
        // find the median index
        int med = (first+last)/2;
        if(search_key==array[med]) index = med;
        else if(search_key<array[med]) index = binary_search(array,first,med-1,search_key);
        else index = binary_search(array,med+1,last,search_key);
    }
    return index;
}//binary

int main(){

    // generate an array
    int sequence[10];
    std::cout << "Number of elements: " << sizeof(sequence)/sizeof(int) << std::endl;
    int n_elements = sizeof(sequence)/sizeof(int);
    for(int i=0; i<11; ++i){
        sequence[i] = 2*i+1;
    }//i
    int search_key;
    std::cout << "Enter an integer." << std::endl;
    std::cin >> search_key;
    int index = -1;
    index = binary_search(sequence,0,n_elements-1,search_key) ;
    if(index == -1) std::cout << "This integer is not in the sequence." << std::endl;
    else std::cout << "Found integer " << search_key << " at position index " << index << std::endl;

    return 0;
}  // main

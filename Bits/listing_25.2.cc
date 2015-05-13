#include<bitset>
#include<string>
#include<iostream>

int main(){
    using namespace std;
    bitset<8> inputBits;
    cout << "Enter an 8-bit sequence: " ;
    cin >> inputBits;

    cout << "Number of 1s you supplied: " << inputBits.count() << endl;
    cout << "Number of 0s: " << inputBits.size()-inputBits.count() << endl;

    bitset<8> inputFlipped(inputBits);
    inputFlipped.flip();
    cout << "Flipped version is: " << inputFlipped << endl;

    cout << "Result of AND,OR,and XOR between the two:" << endl;
    cout << inputBits << " & " << inputFlipped << " = " ;
    cout << (inputBits & inputFlipped) << endl;

    cout << inputBits << " | " << inputFlipped << " = ";
    cout << (inputBits | inputFlipped) << endl;

    cout << inputBits << " ^ " << inputFlipped << " = ";
    cout << (inputBits ^ inputFlipped) << endl;
    return 0;
}

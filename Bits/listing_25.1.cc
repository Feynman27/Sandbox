#include <bitset>
#include <iostream>
#include <string>
using namespace std;
int main(){
    bitset<4> fourBits;
    cout << "Initial contents of fourBits: " << fourBits << std::endl;

    bitset<5> fiveBits("10101");
    cout << "Initial contents of fiveBits: " << fiveBits << std::endl;

    bitset<8> eightBits(255);
    cout << "Initial contents of eightBits: " << eightBits << std::endl;

    bitset<8> eightBitsCopy(eightBits);

    return 0;
}

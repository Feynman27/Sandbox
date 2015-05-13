#include <vector>

int main(){
    using namespace std;
    vector<bool> vecBool1;
    vector<bool> vecBool2(10,true);
    vector<bool> vecBool2_c(vecBool2);

    return 0;
}

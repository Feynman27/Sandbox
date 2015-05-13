#include <set>

template <typename T>
struct SortDescending{
    bool operator()(const T& lhs, const T& rhs) const{
        return (lhs > rhs);
    }
};

int main(){
    using namespace std;

    std::set<int> setIntegers1;
    std::multiset<int> msetIntegers1;

    std::set<int, SortDescending<int> > setIntegers2;
    std::multiset<int, SortDescending<int> > msetIntegers2;

    std::set<int> setIntegers3(setIntegers1);
    std::multiset<int> msetIntegers3(setIntegers1.begin(),setIntegers2.end());

    return 0;
}

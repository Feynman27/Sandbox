#include<iostream>
#include<sstream>
#include<string>
#include<memory>

using namespace std;

template <typename T>
class smart_pointer{
    private:
        T* m_pRawPointer;
    public:
        smart_pointer(T* pData):m_pRawPointer(pData){}
        ~smart_pointer(){delete m_pRawPointer;}

        T& operator* () const{
            return *(m_pRawPointer);
        }

        T* operator-> () const{
            return m_pRawPointer;
        }
};

class Date{

    private:
        int Day;
        int Month;
        int Year;
        string DateInString;
    public:
        Date(int day,int month, int year):Day(day), Month(month), Year(year){;}

        Date& operator ++(){
            ++Day;
            return *this;
        }

        Date& operator -- (){
            --Day;
            return *this;
        }

        operator const char* (){
            ostringstream formattedDate;
            formattedDate << Day << "/" << Month << "/" << Year;

            DateInString = formattedDate.str();
            return DateInString.c_str();
        }

        void DisplayDate(){
            cout << Day << "/" << Month << "/" << Year << endl;
        }
};

int main(){
    
    smart_pointer<int> pDynamicInt(new int(42)); 
    cout << "Integer: " << *pDynamicInt << endl;

    smart_pointer<Date> pHoliday(new Date(25,12,2014) );
    cout << "New instance contains: " ;
    pHoliday->DisplayDate();
    return 0;
}

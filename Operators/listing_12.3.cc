#include<iostream>
#include<sstream>
#include<string>
#include<memory>

class Date{

    private:
        int Day;
        int Month;
        int Year;
        std::string DateInString;
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
            std::ostringstream formattedDate;
            formattedDate << Day << "/" << Month << "/" << Year;

            DateInString = formattedDate.str();
            return DateInString.c_str();
        }

        void DisplayDate(){
            std::cout << Day << "/" << Month << "/" << Year << std::endl;
        }
};

int main(){
    
    std::unique_ptr<int> pDynamicAllocInteger(new int); 
    *pDynamicAllocInteger=42;

    std::cout << "Integer: " << *pDynamicAllocInteger << std::endl;

    std::unique_ptr<Date> pHoliday(new Date(25,12,2014) );
    std::cout << "New instance contains: " ;
    pHoliday->DisplayDate();
    return 0;
}

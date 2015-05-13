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

        Date operator + (int DaysToAdd){
            Date newDate(Day+DaysToAdd,Month,Year);
            return newDate;
        }
        Date operator - (int DaysToAdd){
            Date newDate(Day-DaysToAdd,Month,Year);
            return newDate;
        }

        void DisplayDate(){
            std::cout << Day << "/" << Month << "/" << Year << std::endl;
        }
};

int main(){
    
    Date Holiday(25,12,2014);
    std::cout << "Holiday on : " ;
    Holiday.DisplayDate();

    Date PrevHoliday(Holiday-19);
    std::cout << "Previous holiday was on:";
    PrevHoliday.DisplayDate();

    Date NextHoliday = Holiday+6;
    std::cout << "Next holiday is on:";
    NextHoliday.DisplayDate();

    return 0;
}

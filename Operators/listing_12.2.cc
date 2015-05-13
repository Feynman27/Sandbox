#include<iostream>
#include<sstream>
#include<string>

class Date{

    private:
        int Day;
        int Month;
        int Year;
        std::string DateInString;
    public:
        Date(int day,int month, int year):Day(day), Month(month), Year(year){
        }

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
    
    Date Holiday(25,12,2014);

    std::cout << "The date is initialized to: " ;
    Holiday.DisplayDate();

    ++Holiday;

    std::cout << "Tomorrow is: ";
    Holiday.DisplayDate();

    std::cout << "Yesterday was: " ;
    --Holiday;
    --Holiday;
    Holiday.DisplayDate();
    
    std::cout << Holiday << std::endl;
}

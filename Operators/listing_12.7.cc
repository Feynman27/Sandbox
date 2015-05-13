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

        void operator += (int DaysToAdd){
            Day+=DaysToAdd;
        }

        void operator -= (int DaysToSub){
            Day-=DaysToSub;
        }

        bool operator == (const Date& compareTo){

            return ( (Day==compareTo.Day) && (Month == compareTo.Month) && (Year==compareTo.Year) );
        }

        bool operator != (const Date& compareTo){
            return !(this->operator==(compareTo));
        }

        bool operator < (const Date& compareTo){
            if(Year < compareTo.Year) 
                return true;
            else if(Year > compareTo.Year) 
                return false;
            // same year, different month
            if (Month < compareTo.Month)
                return true;
            else if(Month > compareTo.Month)
                return false;
            // same month and year, different day
            if (Day < compareTo.Day)
                return true;
            else if (Day > compareTo.Day)
                return false;
            // same date
            return false;
        }

        bool operator <= (const Date& compareTo){
            if(this->operator==(compareTo)) return true;
            else return this->operator<(compareTo);
        }

        bool operator > (const Date& compareTo){
            return !(this->operator<=(compareTo)) ;
        }

        bool operator >=(const Date& compareTo){
            if(this->operator==(compareTo)) return true;
            else return this->operator>(compareTo);
        }

        void DisplayDate(){
            std::cout << Day << "/" << Month << "/" << Year << std::endl;
        }
};

int main(){
    
    Date Holiday(29,1,2015);
    Date Holiday2(27,1,2015);
    Holiday.DisplayDate();
    Holiday2.DisplayDate();

    if(Holiday!=Holiday2) std::cout << Holiday << " is not on " << Holiday2 << std::endl;
    if(Holiday<Holiday2) std::cout << Holiday << " is b/4 " << Holiday2 << std::endl;
    else if(Holiday>Holiday2) std::cout << Holiday << " is after " << Holiday2 << std::endl;
    else if(Holiday<=Holiday2 && Holiday>=Holiday2) std::cout << Holiday << " is on " << Holiday2 << std::endl;
    return 0;
}

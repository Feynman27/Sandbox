#include<iostream>

class Date{

    private:
        int Day;
        int Month;
        int Year;
    public:
        Date(int day,int month, int year):Day(day), Month(month), Year(year){
            ;
        }

        Date& operator ++(){
            ++Day;
            return *this;
        }

        Date& operator -- (){
            --Day;
            return *this;
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

}

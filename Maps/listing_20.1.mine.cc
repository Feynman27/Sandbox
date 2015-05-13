#include<map>
#include<set>
#include<iostream>
#include<sstream>

template <typename KeyType>
struct ReverseSort{
    bool operator()(const KeyType& key1, const KeyType& key2){
        return (key1 > key2);
    }
};

template <typename T>
void DisplayContents(const T& input){
    
    for(typename T::const_iterator it=input.begin(); it!=input.end(); ++it){
        std::cout << it->first << "-->" << it->second << std::endl;
    }
}



class Date{

    private:
        int Day;
        int Month;
        int Year;
        std::string DateInString;
    public:
        Date(int day,int month, int year):Day(day), Month(month), Year(year){
            DateInString = (std::to_string(Day)+"/"+std::to_string(Month)+"/"+std::to_string(Year));
        }

        Date& operator ++() {
            ++Day;
            return *this;
        }

        Date& operator -- () {
            --Day;
            return *this;
        }

        operator const char*() const{
            return DateInString.c_str();
        }

        Date operator + (int DaysToAdd) const{
            Date newDate(Day+DaysToAdd,Month,Year);
            return newDate;
        }

        Date operator - (int DaysToAdd) const{
            Date newDate(Day-DaysToAdd,Month,Year);
            return newDate;
        }

        void operator += (int DaysToAdd) {
            Day+=DaysToAdd;
        }

        void operator -= (int DaysToSub) {
            Day-=DaysToSub;
        }

        bool operator == (const Date& compareTo) const{

            return ( (Day==compareTo.Day) && (Month == compareTo.Month) && (Year==compareTo.Year) );
        }

        bool operator != (const Date& compareTo) const{
            return !(this->operator==(compareTo));
        }

        bool operator < (const Date& compareTo) const {
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

        bool operator <= (const Date& compareTo) const{
            if(this->operator==(compareTo)) return true;
            else return this->operator<(compareTo);
        }

        bool operator > (const Date& compareTo) const{
            return !(this->operator<=(compareTo)) ;
        }

        bool operator >=(const Date& compareTo) const{
            if(this->operator==(compareTo)) return true;
            else return this->operator>(compareTo);
        }

        void DisplayDate() const{
            std::cout << Day << "/" << Month << "/" << Year << std::endl;
        }
};

int main(){

    std::map<Date,std::string> mapIntToString;
//    std::set<Date> setIntToString;

//    setIntToString.insert(Date(3,9,1783));
    mapIntToString.insert(std::make_pair(Date(3,9,1783), "Revolution War Ends") );
    mapIntToString.insert(std::make_pair(Date(16,12,1774),"Boston Tea Party") );
    mapIntToString.insert(std::make_pair(Date(27,4,1987), "My Birthday") );
    DisplayContents(mapIntToString);
    /*for(std::map<Date,std::string>::const_iterator it=mapIntToString.begin(); it!=mapIntToString.end(); ++it){
        std::cout << it->first << "-->" << it->second << std::endl;
    }
    */
    return 0;
}

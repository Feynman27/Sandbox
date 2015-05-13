#include<map>
#include<vector>
#include<set>
#include<iostream>
#include<sstream>
#include<utility>
#include<tuple>
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


class citizen{
    private:
        std::string m_name;
        std::vector<std::string> m_countriesVisited;
        std::vector<std::string> m_nationality;
        bool m_isSuspect;
        std::string m_suspect;
        std::string m_not_suspect;
        void fillNationality(std::string str){m_nationality.push_back(str);}
    public:
        citizen(std::string name):m_name(name){
            m_isSuspect=false;
            m_suspect="Suspect";
            m_not_suspect="Clean";
        }
        ~citizen(){;}


        operator const char*() const{
            return m_name.c_str();  
        }

        bool operator == (const citizen& compareTo) const{
            return(m_name==compareTo.m_name);
        }

        bool operator < (const citizen& compareTo) const{
            return(m_name < compareTo.m_name);
        }

        std::vector<std::string> nationality() const{
            return m_nationality;
        }
        std::vector<std::string> countriesVisited() const{
            return m_countriesVisited;
        }
        std::string Suspect() const{
            if(m_isSuspect) return m_suspect;
            else return m_not_suspect;
        }
        bool isSuspect() const{
            return m_isSuspect;
        }

        void AddNationality(std::string str) const { 
            fillNationality(str);
        }
};

struct SortByNationality{
    bool operator() (const citizen& compareTo1, const citizen& compareTo2) const{
        return (compareTo1.isSuspect()<compareTo2.isSuspect());
    }
};

//typedef std::map<citizen, std::tuple<std::vector<std::string>,std::vector<std::string>,std::string> > MAPNAMETOATTR;
int main(){

//    citizen c("Thomas Balestri");
//    std::vector<std::string> nationality = c.nationality();
//    nationality.push_back("US");
//    std::cout << nationality[0] << ": " << c.isSuspect() << std::endl;
    
    /*std::map<citizen, std::tuple<std::vector<std::string>,std::vector<std::string>,std::string> > mCitizens;
    mCitizens.insert(std::make_pair(citizen("Thomas Balestri"),std::tuple<std::vector<std::string>,std::vector<std::string>,std::string>(0,0,"")) );
    mCitizens.insert(std::make_pair(citizen("Barack Obama"),std::tuple<std::vector<std::string>,std::vector<std::string>,std::string>(0,0,"")) );

    std::map<citizen, std::tuple<std::vector<std::string>,std::vector<std::string>,std::string> >::iterator it;
    */
/*    for(it=mCitizens.begin(); it!=mCitizens.end(); ++it){
        std::get<0>(it->second) = (it->first).nationality();
        std::cout << it->first << ": " << std::endl;
    }
*/
    std::set<citizen> setCitizens;
    setCitizens.insert(citizen("Thomas Balestri"));
    auto iCitizenFound = setCitizens.find(citizen("Thomas Balestri"));
    if(iCitizenFound!=setCitizens.end()){
        std::cout << *iCitizenFound << ": " << iCitizenFound->Suspect() << std::endl;
        std::string str = "US";
        iCitizenFound->AddNationality(str);
    }
    else std::cout << "ERROR: Cannot find contact." << std::endl;
    setCitizens.insert(citizen("Barack Obama"));


/*    mCitizens.insert( std::make_pair<std::string, std::tuple<std::string, std::vector<std::string>, bool > >("Thomas Balestri", std::make_tuple("",) ) );  
    mCitizens.insert( std::make_pair<std::string, std::tuple<std::string, std::vector<std::string>, bool > >("Barack Obama") );  
    mCitizens.insert( std::make_pair<std::string, std::tuple<std::string, std::vector<std::string>, bool > >("Ayman al-Zawahiri") );  
    mCitizens.insert( std::make_pair<std::string, std::tuple<std::string, std::vector<std::string>, bool > >("Abu Bakr al-Baghdadi") );  
    mCitizens.insert( std::make_pair<std::string, std::tuple<std::string, std::vector<std::string>, bool > >("Alex Mwai") );  
*/
    //std::get<std::vector<std::string> >( mCitizens["Thomas Balestri"] );
//    mCitizens["Thomas Balestri"]->make_tuple();
    return 0;
}

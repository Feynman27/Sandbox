#include <set>
#include <iostream>

template <typename T>
void DisplayContents(const T& input){
    for(typename T::const_iterator i = input.begin(); i!=input.end(); ++i){
        std::cout << *i << ' ' << std::endl;
    }//i
}

struct ContactItem{

    std::string sContactsName;
    std::string sPhoneNumber;
    std::string sNationality;
    std::string sDisplayRepresentation;

    ContactItem(const std::string& sName, const std::string& sNumber, const std::string& sNationality ):
        sContactsName(sName),sPhoneNumber(sNumber),sNationality(sNationality){

        sDisplayRepresentation = (sContactsName+": "+sPhoneNumber+" : "+sNationality);
    }

    bool operator == (const ContactItem& itemToCompare) const{
        return (this->sContactsName == itemToCompare.sContactsName);
        //return ( itemToCompare.sContactsName == this->sContactsName);
    }

    bool operator < (const ContactItem& itemToCompare) const{
        return (this->sContactsName < itemToCompare.sContactsName);
    }

    operator const char*() const{
        return sDisplayRepresentation.c_str();
    }
};

int main(){

    std::set<ContactItem> setContacts;
    setContacts.insert(ContactItem("Welsch, Jack","+1 7889 879 879", "US") );
    setContacts.insert(ContactItem("Gates, Bill","+1 97 7897 8799 8", "US") );
    setContacts.insert(ContactItem("Merkel, Angela","+49 23456 5466" ,"Germany") );
    setContacts.insert(ContactItem("Putin, Vladimir","+7 6645 4564 797","Russia") );
    setContacts.insert(ContactItem("Modi, Narendra","+91 234 4564 789","India") );
    setContacts.insert(ContactItem("Obama, Barack","+1 745 641 314","US") );

    DisplayContents(setContacts);

    std::cout << "Enter a person who you wish to delete: " ;
    std::string nameInput;
    getline(std::cin,nameInput);

    std::set<ContactItem>::iterator iContactFound = setContacts.find(ContactItem(nameInput,"",""));
    if(iContactFound!=setContacts.end()){
        setContacts.erase(iContactFound);
        std::cout << nameInput << " has been erased. " << std::endl;
        DisplayContents(setContacts);
    }
    else std::cout << "Contact not found." << std::endl;

    return 0;
}

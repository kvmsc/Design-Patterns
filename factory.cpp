/*
    Example for Factory Design Pattern in C++:
        Country Validation Factory for different country validators
*/
#include <bits/stdc++.h>
using namespace std;


class Address{
    string number;
    string street;
    string city;
    string country;
    
    public:
        Address(string _number,string _street, string _city, string _country){
            number = _number;
            street = _street;
            city = _city;
            country = _country;
        }

        void viewAddress(){
            cout<<number<<endl
                <<street<<endl
                <<city<<endl
                <<country<<endl;
        }

        string getCountry(){
            return country;
        }
};

class AddressValidator{
    public:
        virtual bool Validate(Address&) = 0;
};

class INValidator : public AddressValidator{
    public:
        bool Validate(Address& add){
            add.viewAddress();
            cout<<"INDIA Validated!"<<endl;
            return true;
        }
};

class USValidator : public AddressValidator{
    public:
        bool Validate(Address& add){
            add.viewAddress();
            cout<<"US Validated!"<<endl;
            return true;
        }
};

class UKValidator : public AddressValidator{
    public:
        bool Validate(Address& add){
            add.viewAddress();
            cout<<"UK Validated!"<<endl;
            return true;
        }
};

class AddressValidatorFactory{
    private:
        inline static AddressValidatorFactory* valids = NULL;
        inline static unordered_map<string, AddressValidator*> validators;
        AddressValidatorFactory(){
            validators["IN"] = new INValidator();
            validators["UK"] = new UKValidator();
            validators["US"] = new USValidator();
        }
    public:
        static AddressValidatorFactory* getInstance(){
            if(valids==NULL)
                valids = new AddressValidatorFactory;
            return valids;
        }

        static AddressValidator* getValidator(string cnt){
            if(validators.find(cnt)==validators.end())
                throw "Validator for the country not available.";
            return validators[cnt];
        }

};

//Instead used inline feater from C++17
//Initializing static variables
//AddressValidatorFactory* AddressValidatorFactory::valids = NULL;
//unordered_map<string, AddressValidator*> AddressValidatorFactory::validators = unordered_map<string, AddressValidator*>();


int main(void){
    Address user1("1234","Oakstreet","Newark","US");
    AddressValidatorFactory::getInstance()->getValidator(user1.getCountry())->Validate(user1);
}

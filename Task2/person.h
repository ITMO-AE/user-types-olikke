#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <map>
#include <algorithm>

struct FullName
{
    std::string FirstName;
    std::string LastName;
    FullName(std::string firstName, std::string lastName): FirstName(firstName), LastName(lastName) {}
};

class Person
{
 private:
    std::map <int,FullName> Map;
 //   std::map <int, std::pair<std::string,std::string>> Map;
    int BirthYear;
public:
    Person(std::string FirstName, std::string LastName, int BirthYear);
    void ChangeFirstName(int Year, std::string FirstName);
    void ChangeLastName(int Year, std::string LastName);
    std::string GetFullName(int Year) const;
    void PrintAll() const;
    std::string GetFullNameWithHistory(int Year) const;
};

#endif // PERSON_H

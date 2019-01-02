#include <iostream>
#include "person.h"

using namespace std;

int main()
{
    Person person("Olik","Krolik",1981);
    person.ChangeFirstName(1985,"Vasya");
    person.ChangeFirstName(1996,"Masha");
    person.ChangeLastName(1999,"Bird");
    person.ChangeFirstName(1985,"Natasha");
    person.ChangeLastName(1996,"BlaBlaBla");

    cout<<"Get Full Name\n";
    for (int year : {1980,1982,1985,1986,1996,2000})
    {
        cout << year<<" "<< person.GetFullName(year) << endl;
    }

    cout<<"Get Full Name With History\n";
    cout << person.GetFullNameWithHistory(2000)<<endl;
    return 0;
}

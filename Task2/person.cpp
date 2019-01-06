#include "person.h"

Person::Person(std::string FirstName, std::string LastName, int BirthYear)
{
    Map.insert(std::make_pair(BirthYear,FullName(FirstName,LastName)));
    this->BirthYear=BirthYear;
};

void Person::ChangeFirstName(int Year, std::string FirstName)
{
    if ((Year<BirthYear) || (FirstName.empty())) return;
    //C++17 try_emplace :( без лишнего конструктора
    auto result=Map.emplace(std::make_pair(Year,FullName(FirstName,""))); //auto [iterator1, succeed1]
    if (!result.second)
    {
        result.first->second.FirstName=FirstName;
    }
};

void Person::PrintAll() const
{
    for (const auto& c:Map)
        std::cout<<c.first<<" "<<c.second.FirstName<<" "<<c.second.LastName<<std::endl;
}

void Person::ChangeLastName(int Year, std::string LastName)
{
    if ((Year<BirthYear) || (LastName.empty())) return;
    auto result=Map.emplace(std::make_pair(Year,FullName("",LastName)));
    if (!result.second)
    {
        result.first->second.LastName=LastName;
    }
};

std::string Person::GetFullName(int Year) const
{
    if (Year<BirthYear) return "No Person";
    auto result=Map.upper_bound(Year);
    result--;
    std::string FN=result->second.FirstName;
    std::string LN=result->second.LastName;
    if (LN.empty())
    {
        auto searchN=std::find_if(std::make_reverse_iterator(result),Map.rend(), [](const auto &it){return !it.second.LastName.empty();});
        LN=searchN->second.LastName;
        return FN+" "+LN;
    }
    if (FN.empty())
    {
        auto searchN=std::find_if(std::make_reverse_iterator(result),Map.rend(), [](const auto &it){return !it.second.FirstName.empty();});
        FN=searchN->second.FirstName;
        return FN+" "+LN;
    }
    return FN+" "+LN;
}

std::string Person::GetFullNameWithHistory(int Year) const
{
    if (Year<BirthYear) return "No Person";
    auto result=Map.upper_bound(Year);
    result--;
    std::string FN=result->second.FirstName;
    std::string LN=result->second.LastName;
    while (1)
    {
        auto FL=[](const auto &it)
                    { return (!it.second.LastName.empty() || !it.second.FirstName.empty());};
        auto searchN=std::find_if(std::make_reverse_iterator(result--),Map.rend(),FL);
        if (searchN->second.LastName!="")
        {
            if (!LN.empty()) LN+=" ("+searchN->second.LastName+")"; else LN=searchN->second.LastName;
        }
        if (searchN->second.FirstName!="")
        {
            if (!FN.empty()) FN+=" ("+searchN->second.FirstName+")"; else FN=searchN->second.FirstName;
        }
        if (result->first==BirthYear) break;
    }
    return FN+" "+LN;
}

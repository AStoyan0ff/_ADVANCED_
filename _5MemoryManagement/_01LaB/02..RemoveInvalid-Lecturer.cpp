#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;

void * readCompany(istream & in) {

    string number, name;

    cin >> number;
    if (number == "end")
        return nullptr;

    int id = stol(number);
    cin >> name;

    char * company = new char[sizeof(int) + name.length()+1];

    int * idPtr = reinterpret_cast<int *>(company);
    *idPtr = id;

    strcpy(company + sizeof(int), name.c_str());

    return company;
}

bool isValidCompanyId(void * companyData) {
    int * id = static_cast<int *>(companyData);

    return *id >= 0;
}

void printCompany(void * companyData) {
    int * id = static_cast<int *>(companyData);
    const char * name = reinterpret_cast<const char *>(id+1);

    cout << *id << ' ' << name << endl;
}

int main()
{
    vector<void *> data;

    while(true) {

        void * newCompany = readCompany(cin);

        if (newCompany == nullptr)
            // we reached "end"
                break;

        data.push_back(newCompany);
    }

    for(void * curr : data) {
        if (isValidCompanyId(curr))
            printCompany(curr);
    }


    for( void * curr : data)
        delete [] static_cast<char*>(curr);
    data.clear();

    return 0;
}
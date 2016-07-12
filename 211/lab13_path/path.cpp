#include"location.h"
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector < Location * > location;
    double latitude;
    double longitude;

    while (cin >> latitude)
    {
        cin >> longitude;
        location.push_back(new Location(latitude,longitude));
    }

    for (unsigned int i = 0; i < location.size(); i++)
    {
        location[i]->print(cout);
        cout << endl;
    }
}

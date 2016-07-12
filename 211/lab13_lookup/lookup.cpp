#include"location.h"
#include<vector>
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
    map < string, Location * > my_map;
    vector < string > place_holder;
    Location *location;
    double latitude;
    double longitude;
    string place;

    while (cin >> latitude)
    {
        if (latitude == 0)
            break;
        cin >> longitude;
        cin >> place;
        location = new Location(latitude,longitude);
        my_map[place] = location;
    }

    while (cin >> place)
    {
        map <string, Location * > :: iterator iter;
        iter = my_map.find(place);
        
        if (iter == my_map.end())
        {
            my_map[place] = NULL;
        }
        place_holder.push_back(place);

    }
      
    for (unsigned int i = 0; i < place_holder.size(); i++)
    {
        map < string, Location * > :: iterator iters;
        iters = my_map.find(place_holder[i]);
        if (iters->second != NULL)
        {
            cout << iters->first << " is at ";
            iters->second->print(cout);
            cout << endl;
        }
        else
        {
            cout << iters->first << " not in database" << endl;
        }
            
    }
    
}

//main.cpp
//Valdivia, Pedro
//pvaldivia1

#include<iostream>
#include"vlist.h" 
#include"video.h"
#include<string>
#include<regex>

using namespace std;

int main()
{
//DECLARATION OF VARIABLES
    Vlist list;
    string function;
    string title;
    string url;
    string comment;
    double length;
    int rating;
//START OF WHILE LOOP
    while (getline(cin,function))
    {
        if (function == "insert") //CALLS THE INSERT FUNCTION FROM CLASS VLIST IF FUNCTION = "insert"
        {
            getline(cin,title);
            if (list.title_exists(title) == false) // DETERMINES IF THE INPUTED TITLE EXISTS IN THE CURRENT LINKED LIST 
            {
                getline(cin,url);
                getline(cin,comment);
                cin >> length;
                cin >> rating;
                cin.ignore();
                Video *video = new Video(title,url,comment,length,rating);
                list.insert_sorted(video);
            }
            else //TITLE ALREADY EXISTS SO DISPLAY ERROR MESSAGE
            {
                cerr << "Could not insert <" << title << ">, already in list.\n";
            }
        }
        else if (function == "lookup") //CALLS THE LOOKUP FUNCTION FROM CLASS VLIST IF FUNCTION = "lookup"
        {
            string temp_title;
            getline(cin,temp_title);
            if (list.title_exists(temp_title) == true) //DETERMINES IF THE INPUTED TITLE EXISTS IN THE CURRENT LINKED LIST
            {
                list.lookup(temp_title);
            }
            else //TITLE DOES NOT EXIST IN LINKED LIST SO DISPLAY ERROR MESSAGE
            {
                cerr << "Title <" << temp_title << "> not in list.\n";
            }
        }
        else if (function == "print") //CALLS PRINT FUNCTION FROM CLASS VLIST IF FUNCTION = "print"
        {
            list.print();
        }
        else if (function == "remove") //CALLS REMOVE FUNCTION FROM CLASS VLIST IF FUNCTION = 
        {
            string temp_title2;
            getline(cin,temp_title2);
            if (list.title_exists(temp_title2) == true)
            {
                list.remove(temp_title2);
            }
            else
            {
                cerr << "Title <" << temp_title2 << "> not in list, could not delete.\n";
            }
        }
        else if (function == "length")
        {
            cout << list.length() << endl;
        }
        else if (function == "print_by_length")
        {
            if (list.is_empty() == false)
            {
                list.print_by_length();
            }
        }
        else if (function == "print_by_rating")
        {
            if (list.is_empty() == false)
            {
                list.print_by_rating();
            }
        }
        else if (function == "lookup_expression")
        {
            string e;
            getline(cin,e);
            list.print_by_expression(e);
        }
        else
        {
            cerr << "<" << function << "> is not a legal command, giving up.\n";
            return 1;
            exit(EXIT_FAILURE);

        }
    }
    cin.ignore();

    
    

}

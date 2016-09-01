/**
 * @file playlist.cpp   Implementation of a Playlist for music.
 *
 * @brief
 *    Implementation of a Playlist for music. A doubly linked list is
 *    used to store the song names.
 *
 *    Note: main() is in this file.
 *
 * @author Judy Challinger & <put your name here!>
 * @date 2016
 */

#include <iostream>
#include <string>
#include <sstream>

#include "playlist.h"
#include "doublylinkedlist.h"

using std::ws;
using std::string;
using std::cin;
using std::cout;
using std::endl;

void print(vector<string*>);

// you may add more private functions for functional decomposition

/**
 * Process a playlist command.
 *
 * Gets an entire line from std::cin, extracts the first word as the command,
 * and calls the appropriate processing function. Invalid commands are
 * ignored.
 *
 * @return false if command is "quit", otherwise true
 */
bool Playlist::processCommand() {

    string command;
    string data;
    cin >> command;
  
    if (command == "appendSong")
    {
	cin >> ws;
	getline(cin,data);
	dll.append(data);
    }
    if (command == "nextSong")
    {
	dll.next();
    } 
    if (command == "prevSong")
    {
	dll.prev();
    }
    if (command == "gotoFirstSong")
    {
	dll.begin();
    }
    if (command == "gotoLastSong")
    {
	dll.end();
    }
    if (command == "playCurrent")
    {
	cout << endl;
        if (dll.empty())
	{
        cout << "playing current:";
	}
	else
	{
	    cout << "playing current: " << dll.getData();
	}
    }
    if (command == "quit")
    {
        return false;
    }
    if (command == "playFoward")
    {
	cout << endl;
	cout << "playing foward:" << endl;
	if (dll.empty() == false)
	{
	    cout << dll.getData() << endl;
	    while (dll.next())
	    cout << dll.getData() << endl;
	}
        
    }
    if (command == "playReverse")
    {
	cout << endl;
	cout << "playing reverse:" << endl;
	if (dll.empty() == false)
	{
	    cout << dll.getData() << endl;
	    while (dll.prev())
	    cout << dll.getData() << endl;
	}
    }
    if (command == "insertBefore")
    {
	cin >> ws;
	getline(cin,data);
	dll.insertBefore(data);
    }
    if (command == "insertAfter")
    {
	cin >> ws;
    	getline(cin,data);
	dll.insertAfter(data);
    }
    if (command == "removeSong")
    {
	cin >> ws;
	getline(cin,data);
	dll.remove(data);
    }
    if (command == "gotoSong")
    {
	cin >> ws;
	getline(cin,data);
	dll.find(data);
    }
    
    return true;
}

/**
 * The Playlist main loop will process command lines until finished.
 */
void Playlist::mainLoop() {
   while (processCommand());         // process all commands
}

void print(vector<string*> temp_playlist)
{
    for (unsigned int i = 0; i < temp_playlist.size(); i++)
    {
	cout << *(temp_playlist[i]) << endl;
    }
}

/**
 * The main entry point for the program.
 */
int main()
{
   Playlist myPlaylist;
   myPlaylist.mainLoop();
   return 0;
}


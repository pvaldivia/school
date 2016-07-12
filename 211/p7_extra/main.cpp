//main.cpp
//Valdivia, Pedro
//pvaldivia1

#include"bst.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

void print_vector(vector<string>);
using namespace std;

int main()
{
    BST tree;
    string command;
    string input_string;
    while (cin >> command)
    {
        if (command == "insert")
        {
            //READS IN ALL THE WHITE SPACE UNTIL THERE IS A CHARACTER 
            cin >> ws;
            bool insert;
            getline(cin,input_string);
            //TREE.INSERT INPUTS THE STRING INTO THE BINARY SEARCH TREE
            insert = tree.insert(input_string);
            //IF INSERT FAILED WRITE TO STANDARD ERROR
            if (insert == false)
            cerr << "insert <" << input_string << "> failed. String already in tree." << endl;
        }
        else if (command == "size")
        {
            int tree_size;
            //RETURN THE NUMBER OF ELEMENTS IN THE BINARY SEARCH TREE
            tree_size = tree.count_nodes();
            cout << tree_size << endl;
        }
        else if (command == "echo")
        {
            cin >> ws;
            getline(cin,input_string);
            //OUTPUTS THE INPUT TO STANDARD OUTPUT
            cout << input_string << endl;
        }
        else if (command == "find")
        {
            cin >> ws;
            bool find;
            getline(cin,input_string);
            //RETURNS IF INPUT_STRING IS/IS'NT IN THE TREE
            find = tree.find(input_string);
            if (find == true)
            {
                cout << "<" << input_string << ">" << " is in tree." << endl;
            }
            else
            {
                cout << "<" << input_string << ">" << " is not in tree." << endl;
            }
        }
        else if (command == "breadth")
        {
            vector<string> strings;
            tree.breadth(strings);
            print_vector(strings);
        }
        else if (command == "distance")
        {
            cout << "Average distance of nodes to root = " << tree.distance() << endl;
        }
        else if (command == "balanced")
        {
            int balanced = tree.balanced();
            if (balanced == -1)
            {
                cout << "Tree is not balanced." << endl;
            }
            else 
            {
                cout << "Tree is balanced." << endl;
            }
        }
        else if (command == "rebalance")
        {
            vector<string> strings;
            tree.print(strings);
            tree.delete_tree();
            tree.insert_from_vector(strings);
        }
        else if (command == "print")
        {
            vector<string> strings;
            tree.print(strings);
            print_vector(strings);
        }
        else if (command == "delete")
        {
            tree.delete_tree();
        }
        else if (command == "remove")
        {
            cin >> ws;
            getline(cin,input_string);
            if (tree.find(input_string))
            tree.delete_node(input_string);
            else
            cerr << "<" << input_string << "> " << "is not in the tree and cannot be removed.\n";
        }
        else 
        {
            string garbage;
            getline(cin,garbage);
            cerr << "Illegal command <" << command << ">." << endl;
            
        }
    }

    return 0;
}

void print_vector(vector<string> values)
{
    cout << "{";
    for (unsigned int i = 0; i < values.size(); i++)
    {
        cout << values[i];
        if (values.size() - 1 == i) continue;
        cout << ", ";
    }
    cout << "}" << endl;
}

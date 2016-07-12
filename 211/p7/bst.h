//bst.h
//Valdivia, Pedro
//pvaldivia1

#ifndef BST_H_
#define BST_H_

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class BST
{
    public:
        BST();
        bool insert(string);
        bool find(string);
        double distance();
        int count_nodes();
        int balanced();
        void breadth(vector<string>&);
        void print(vector<string> &);
        void delete_tree();
        void insert_from_vector(vector<string>&);

    private:
        class Node
        {
            public:
                Node(string string_input, Node* root, Node* right = NULL, Node *left = NULL)
                {m_string = string_input; m_right = right; m_left = left;}
                Node *m_left;
                Node *m_right;
                string m_string;
            
        };
        bool insert(string, Node*&);
        bool find(string, Node *);
        void delete_tree(Node*&);
        void print(vector<string> &, Node *);
        void insert_from_vector(vector<string>&,int,int);
        void breadth(vector<string> &, Node *);
        int is_balanced(Node*);
        int count_nodes(Node*);
        double distance(Node*,double);
        Node *m_root;
        
};

#endif

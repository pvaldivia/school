//vlist.h
//Valdivia, Pedro
//pvaldivia1

#ifndef VLIST_H_
#define VILIST_H_

#include<string> 
#include"video.h"
#include<regex>

using namespace std;

class Vlist
{
    public:
        Vlist();
        void remove(string);
        void insert(string,string,string,double,int);
        void insert_sorted(Video*);
        void lookup(string);
        int length();
        void print();
        bool title_exists(string);
        void print_by_length();
        void print_by_rating();
        void print_by_expression(string);
        bool is_empty();
        void fix_list();
        
    private:
        class Node
        {
            public:
                Node (Video *video,Node *next)
                {vlist_next = next; vlist_video  = video;}
                Node *vlist_next;
                Video *vlist_video;

        };
        Node *vlist_head;
};

#endif

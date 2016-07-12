//cust.h
//Valdivia, Pedro
//pvaldivia1

#ifndef CUST_H_
#define CUST_H_
#include<iostream>

using namespace std;

class Cust
{
    public:
        Cust(string,bool,int,int);
        int get_num_items();
        int get_arrival_time();
        bool is_robber();
        void print(ostream &);
        void print_entered(ostream &,int);
        void print_done_shopping(ostream &,int);
        void print_start_checkout(ostream &,int,int);
        void print_done_checkout(ostream &,int,int,int);
    private:
        string m_name;
        int m_arrival_time;
        int m_num_items;
        bool m_isRobber;
        
};

#endif

//sim.cpp
//Valdivia, Pedro
//pvaldivia1

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<assert.h>
#include<string>
#include"cust.h"
#include"pqueue.h"


using namespace std;

struct Checker
{
    Pqueue queue;
    double checker_money;
    int time_cust_done;
    int checker_break_time;
    Cust *ptr_cust;
};

int shortest_checker_queue(Checker [],int);
bool legal_int(char *);
void run_simulation(Pqueue &,int,int,ostream &);

Pqueue arrival_queue;
Pqueue shopping_queue;
Pqueue checker_queue;

int main(int argc, char *argv[])
{
    if (argc < 5 || argc > 5)
    {
        cerr << "Error: invalid number of command line arguments." << endl;
        exit(1);
    }

    ifstream my_ifile(argv[3], ios::in);
    ofstream my_ofile(argv[4], ios::out);

    if (!my_ifile)
    {
        cerr << "Error: could not open input file <" << argv[3] << ">." << endl;
        exit(1);
    }
    if (!my_ofile)
    {
        cerr << "Error: could not open output file <" << argv[4] << ">." << endl;
        exit(1);
    }
    if (!legal_int(argv[1]) || atoi(argv[1]) < 1)
    {
        cerr << "Error: invalid number of checkers specified." << endl;
        exit(1);
    }
    if (!legal_int(argv[2]) || atoi(argv[2]) < 0)
    {
        cerr << "Error: invalid checker break duration specified." << endl;
        exit(1);
    }

    string input;
    string name;
    string shopper_status;
    bool isShopper;
    int num_items;
    int arrival_time;
    
    while (my_ifile >> name)
    {
        my_ifile >> shopper_status;
        if (shopper_status == "shopper")
        {
            isShopper = true;
        }
        else
        {
            isShopper = false;
        }

        my_ifile >> arrival_time;
        my_ifile >> num_items;
        arrival_queue.enqueue(new Cust(name,isShopper,arrival_time,num_items),arrival_time);
            
    }

    run_simulation(arrival_queue,atoi(argv[1]),atoi(argv[2]),my_ofile);
    
    return 0;
}

void run_simulation(Pqueue &arrival_queue, int num_checkers, int checker_break_duration, ostream &os)
{
    int end_time = 0;
    int done_shopping_time;
    int shortest_checker;
    int num_customers = arrival_queue.length();
    Checker *checkers = new Checker[num_checkers];
 
    for (int i = 0; i < num_checkers; i++)
    {
        checkers[i].checker_money = 250;
        checkers[i].checker_break_time = 0;
        checkers[i].ptr_cust = NULL;
    }

    for (int clock = 1; num_customers > 0; clock++)
    {
        while (arrival_queue.first_priority() == clock)
        {
            Cust *removed_cust = arrival_queue.dequeue();
            removed_cust->print_entered(os,clock);
            done_shopping_time = removed_cust->get_arrival_time() + removed_cust->get_num_items()*3;
            shopping_queue.enqueue(removed_cust, done_shopping_time);
        }
        while (shopping_queue.first_priority() == clock)
        {
            Cust *removed_cust = shopping_queue.dequeue();
            shortest_checker = shortest_checker_queue(checkers,num_checkers);
            removed_cust->print_done_shopping(os,clock,shortest_checker);
            checkers[shortest_checker].queue.enqueue(removed_cust,0);
        }
        for (int i = 0; i < num_checkers; i++)
        {
            if (checkers[i].ptr_cust != NULL && clock == checkers[i].time_cust_done)
            {
                if (checkers[i].ptr_cust->is_robber())
                {
                    checkers[i].ptr_cust->print_done_checkout(os,clock,i,checkers[i].checker_money);
                    checkers[i].checker_money = 0;
                    checkers[i].checker_break_time = checker_break_duration;
                }
                else
                {
                    checkers[i].ptr_cust->print_done_checkout(os,clock,i,checkers[i].checker_money);
                    checkers[i].checker_money = checkers[i].checker_money + checkers[i].ptr_cust->get_num_items()*2;
                }
                delete checkers[i].ptr_cust;
                num_customers--;
                checkers[i].ptr_cust = NULL;
            }
        }
        for (int i = 0; i < num_checkers; i++)
        {
            while (checkers[i].ptr_cust == NULL && checkers[i].checker_break_time == 0 && checkers[i].queue.length() > 0)
            {
                Cust *removed_cust = checkers[i].queue.dequeue();
                checkers[i].ptr_cust = removed_cust;
                if (checkers[i].ptr_cust->is_robber())
                {
                    checkers[i].time_cust_done = clock + 7;
                }
                else
                {
                    checkers[i].time_cust_done = clock + checkers[i].ptr_cust->get_num_items()*2;
                }
                checkers[i].ptr_cust->print_start_checkout(os,clock,i);
            }
        }
        for (int i = 0; i < num_checkers; i++)
        {
            if (checkers[i].checker_break_time > 0)
            {
                checkers[i].checker_break_time--;    
            }
        }
        end_time++;
    }
    for (int i = 0; i < num_checkers; i++)
    {
        os << "registers[" << i << "] = $" << checkers[i].checker_money << endl;
    }
    os << "time = " << end_time + 1 << endl;
}

bool legal_int(char *str)
{
    while (*str != 0)
    {
        if (!isdigit(*str))
        return false;

        str++;
    }
    return true;
}

int shortest_checker_queue(Checker checkers[],int num_checkers)
{
    int shortest_line = 0;
    int smallest = 0;
    if (checkers[0].ptr_cust != NULL)
    {
        smallest = checkers[0].queue.length() + 1;
    }
    else
    {
        smallest = checkers[0].queue.length();
    }

    for (int i = 1; i < num_checkers; i++)
    {
        if (checkers[i].ptr_cust == NULL)
        {
            if (checkers[i].queue.length() < smallest)
            {
                smallest = checkers[i].queue.length();
                shortest_line = i;
            }
        }
        else
        {
            if (checkers[i].queue.length() + 1 < smallest)
            {
                smallest = checkers[i].queue.length() + 1;
                shortest_line = i;
            }

        }
    }
    return shortest_line;
}

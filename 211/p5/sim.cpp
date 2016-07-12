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
    double checker_money;
    int time_cust_done;
    int checker_break_time;
    Cust *ptr_cust;
};

bool legal_int(char *);
bool is_checker_available(Checker [],int,int&);
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

    //READING INPUT FROM INPUT FILE
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
        //INSERTING NEW CUSTOMER OBJECT INTO THE ARRIVAL QUEUE
        arrival_queue.enqueue(new Cust(name,isShopper,arrival_time,num_items),arrival_time);
            
    }
    //BEGINS THE SIMULATION
    run_simulation(arrival_queue,atoi(argv[1]),atoi(argv[2]),my_ofile);
    
    return 0;
}

void run_simulation(Pqueue &arrival_queue, int num_checkers, int checker_break_duration, ostream &os)
{
    int end_time = 0;
    int done_shopping_time;
    int num_customers = arrival_queue.length();
    Checker *checkers = new Checker[num_checkers];
    //INITIALIZING EACH CHECKER
    for (int i = 0; i < num_checkers; i++)
    {
        checkers[i].checker_money = 250;
        checkers[i].checker_break_time = 0;
        checkers[i].ptr_cust = NULL;
    }
    //FOR LOOP THAT CONINUES UNTIL THERE ARE NO CUSTOMERS LEFT
    for (int clock = 1; num_customers > 0; clock++)
    {
        //CHECKS TO SEE IF CUSTOMER HAS ARRIVED AT THE STORE
        while (arrival_queue.first_priority() == clock)
        {
            Cust *removed_cust = arrival_queue.dequeue();
            removed_cust->print_entered(os,clock);
            done_shopping_time = removed_cust->get_arrival_time() + removed_cust->get_num_items()*3;
            shopping_queue.enqueue(removed_cust, done_shopping_time);
        }
        //CHECKS TO SEE IF CUSTOMER HAS FINISHED SHOPPING FOR THEIR ITEMS
        while (shopping_queue.first_priority() == clock)
        {
            Cust *removed_cust = shopping_queue.dequeue();
            removed_cust->print_done_shopping(os,clock);
            checker_queue.enqueue(removed_cust,0);
        }
        //GOES THROUGH EACH CHECKER
        for (int i = 0; i < num_checkers; i++)
        {
            //CHECKS IF CHECKER IS SERVING A CUSTOMER AND IF THE CHECKER HAS RINGED UP ALL OF THE CUSTOMERS ITEMS
            if (checkers[i].ptr_cust != NULL && clock == checkers[i].time_cust_done)
            {
                //CHECKS IF CUSTOMER IS A ROBBER
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
        int checker_available = 0;
        //CHECKS IF THERE IS A CHECKER AVAILABLE AND IF THE CHECKER QUEUE IS HOLDING AT LEAST ONE CUSTOMER
        while (is_checker_available(checkers,num_checkers,checker_available) && checker_queue.length() > 0)
        {
            Cust *removed_cust = checker_queue.dequeue();
            checkers[checker_available].ptr_cust = removed_cust;
            //CHECKS IF CUSTOMER IS A ROBBER
            if (checkers[checker_available].ptr_cust->is_robber())
            {
                checkers[checker_available].time_cust_done = clock + 7;
            }
            else
            {
                checkers[checker_available].time_cust_done = clock + checkers[checker_available].ptr_cust->get_num_items()*2;
            }
            checkers[checker_available].ptr_cust->print_start_checkout(os,clock,checker_available);

        }
        //FOR LOOP THAT DECREMENTS CHECKERS BREAK TIME IF ITS GREATER THAN 0
        for (int i = 0; i < num_checkers; i++)
        {
            if (checkers[i].checker_break_time > 0)
            {
                checkers[i].checker_break_time--;    
            }
        }
        end_time++;
    }
    //PRINTS OUT EACH OF THE CHECKERS MONEY IN THE REGISTER
    for (int i = 0; i < num_checkers; i++)
    {
        os << "registers[" << i << "] = $" << checkers[i].checker_money << endl;
    }
    //PRINTS OUT THE ENDING TIME
    os << "time = " << end_time + 1 << endl;
}

bool is_checker_available(Checker checkers[],int num_checkers,int &checker_available)
{
    
    for (int i = 0; i < num_checkers; i++)
    {
        if (checkers[i].ptr_cust == NULL && checkers[i].checker_break_time == 0)
        {
            checker_available = i;
            return true;
        }
    }
    return false;
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

//cust.cpp
//Valdivia, Pedro
//pvaldivia1

#include"cust.h"
#include<assert.h>

Cust::Cust(string name,bool isRobber,int arrival_time,int num_items)
{
    m_name = name;
    m_isRobber = isRobber;
    m_arrival_time = arrival_time;
    m_num_items = num_items;
}

void Cust::print(ostream &os)
{
    os << m_name << " ";
    if (m_isRobber)
    os << "shopper ";
    else 
    os << "robber ";
    os << m_arrival_time << " ";
    os << m_num_items << endl;
}

int Cust::get_num_items()
{
    return m_num_items;
}

int Cust::get_arrival_time()
{
    return m_arrival_time;
}

bool Cust::is_robber()
{
    if(m_isRobber)
    return false;
    else
    return true;
}

void Cust::print_entered(ostream &os,int clock)
{
    assert (clock == m_arrival_time);
    os << clock << ": " << m_name << " entered store" << endl;
}

void Cust::print_done_shopping(ostream &os,int clock)
{
    assert (clock == m_arrival_time + m_num_items * 3);
    os << clock << ": " << m_name << " done shopping" << endl;
}

void Cust::print_start_checkout(ostream &os,int clock,int num_checker)
{
    os << clock << ": " << m_name << " started checkout with checker " << num_checker << endl; 
}

void Cust:: print_done_checkout(ostream &os,int clock,int num_checker,int checker_money)
{
    if (m_isRobber == false)
    {
        os << clock << ": " << m_name << " stole $" << checker_money << " and " 
        << m_num_items;
        if (m_num_items == 1)
        os << " item ";
        else
        os << " items ";
        os << "from checker " << num_checker << endl;
    }
    else
    {
        os << clock << ": " << m_name << " paid $" << m_num_items*2 << " for " << m_num_items;
        if (m_num_items == 1)
        os << " item ";
        else
        os << " items ";
        os << "to checker " << num_checker << endl;

    }
}

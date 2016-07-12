//vlist.cpp
//Valdivia, Pedro
//pvaldivia1

#include"video.h"
#include"vlist.h"
#include<regex>

Vlist::Vlist()
{
    vlist_head = NULL;
}

int Vlist::length()
{
    int num_nodes = 0;
    Node *ptr = vlist_head;
    while (ptr != NULL)
    {
        ptr = ptr->vlist_next;
        num_nodes++;
    }
    return num_nodes;
    
}

bool Vlist::title_exists(string title)
{
    Node *ptr = vlist_head;
    if (ptr == NULL)
    {
        return false;
    }
    else
    {
        while (ptr != NULL && ptr->vlist_video->get_title() != title)
        {
            ptr = ptr->vlist_next;
        }
        if (ptr == NULL)
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
}


void Vlist::insert_sorted(Video *video)
{
        Node *ptr = vlist_head;
 
        if (ptr == NULL || video->get_title() < ptr->vlist_video->get_title())
        {
            vlist_head = new Node (video,vlist_head);    
        }
        else
        {
            while (ptr->vlist_next != NULL && video->get_title() > ptr->vlist_next->vlist_video->get_title())
            {
                ptr = ptr->vlist_next;

            }
            ptr->vlist_next = new Node (video,ptr->vlist_next);

        }

}

void Vlist::print()
{
    Node *ptr = vlist_head;
        while (ptr != NULL)
        {
            ptr->vlist_video->print();
            ptr = ptr->vlist_next;
        }
}

void Vlist::lookup(string title)
{
    Node *ptr = vlist_head;
        while (ptr != NULL && ptr->vlist_video->get_title() != title)
        {
            ptr = ptr->vlist_next;
        }
            ptr->vlist_video->print();
}

void Vlist::remove(string title)
{
    Node *ptr = vlist_head;
    Node *previous_ptr = vlist_head;

        if (title == ptr->vlist_video->get_title())
        {
            vlist_head = vlist_head->vlist_next;
            delete ptr;
        }
        else
        {
            while (ptr->vlist_next != NULL && ptr->vlist_video->get_title() != title)
            {
                previous_ptr = ptr;
                ptr = ptr->vlist_next;

            }
            if (ptr->vlist_next == NULL && ptr->vlist_video->get_title() == title)
            {
                previous_ptr->vlist_next = ptr->vlist_next;
                previous_ptr = ptr;
                delete previous_ptr->vlist_video;
                delete previous_ptr;
            }
            else
            {
                previous_ptr->vlist_next = ptr->vlist_next;
                delete ptr->vlist_video;
                delete ptr;
            }
        }
}

void Vlist::print_by_rating()
{
    Node *ptr = vlist_head;
    Node *temp = vlist_head;

    for (int loops = length(); loops > 0; loops--)
    {
    for (int current = 0; current < loops; current++)
    {
        ptr = vlist_head;
        temp = vlist_head;
        while (ptr->vlist_next != NULL && ptr->vlist_video->get_rating() >= ptr->vlist_next->vlist_video->get_rating())
        {
            temp = ptr;
            ptr = ptr->vlist_next;
        }
        if (ptr == vlist_head)
        {
            vlist_head = vlist_head->vlist_next;
            ptr->vlist_next = vlist_head->vlist_next;
            vlist_head->vlist_next = ptr;
        }
        else if (ptr->vlist_next != NULL)
        {
            temp->vlist_next = ptr->vlist_next;
            ptr->vlist_next = ptr->vlist_next->vlist_next;
            temp->vlist_next->vlist_next = ptr;

        }
    }
    }
    print();
    fix_list();

}

void Vlist::print_by_length()
{
    Node *ptr = vlist_head;
    Node *temp = vlist_head;
    double temp_smallest;
    double smallest_length;
    for (int i = 0; i < length(); i++)
    {
    while (ptr != NULL)
    {
        smallest_length = ptr->vlist_video->get_length();
        if (smallest_length < ptr->vlist_next->vlist_video->get_length() && smallest_length > temp_smallest )
        {
            ptr = ptr->vlist_next;
        }
        else
        {
            smallest_length = ptr->vlist_next->vlist_video->get_length();
            ptr = ptr->vlist_next;
        }
    }
    
    temp_smallest = smallest_length;
    while (ptr != NULL)
    {
        if (temp_smallest == ptr->vlist_video->get_length())
        {
            ptr->vlist_video->print();
        }
        ptr = ptr->vlist_next;
    }
    }


   /* for (int loops = length(); loops > 0; loops--)
    {
    for (int current = 0; current < loops; current++)
    {
        ptr = vlist_head;
        temp = vlist_head;
        while (ptr->vlist_next != NULL && ptr->vlist_video->get_length() < ptr->vlist_next->vlist_video->get_length())
        {
            temp = ptr;
            ptr = ptr->vlist_next;
        }
        if (ptr == vlist_head)
        {
            vlist_head = vlist_head->vlist_next;
            ptr->vlist_next = vlist_head->vlist_next;
            vlist_head->vlist_next = ptr;
        }
        else if (ptr->vlist_next != NULL)
        {
            temp->vlist_next = ptr->vlist_next;
            ptr->vlist_next = ptr->vlist_next->vlist_next;
            temp->vlist_next->vlist_next = ptr;

        }
    }
    }
    print();
    fix_list();*/
}

void Vlist::fix_list()
{
    Node *ptr = vlist_head;
    Node *temp = vlist_head;

    for (int loops = length(); loops > 0; loops--)
    {
        for (int current = 0; current < loops; current++)
        {
            ptr = vlist_head;
            temp = vlist_head;
            while (ptr->vlist_next != NULL && ptr->vlist_video->get_title() < ptr->vlist_next->vlist_video->get_title())
            {
                temp = ptr;
                ptr = ptr->vlist_next;
            }
            if (ptr == vlist_head)
            {
                vlist_head = vlist_head->vlist_next;
                ptr->vlist_next = vlist_head->vlist_next;
                vlist_head->vlist_next = ptr;
            }
            else if (ptr->vlist_next != NULL)
            {
                temp->vlist_next = ptr->vlist_next;
                ptr->vlist_next = ptr->vlist_next->vlist_next;
                temp->vlist_next->vlist_next = ptr;
            }
        }
    }
    
}

bool Vlist::is_empty()
{
    Node *ptr = vlist_head;
    return (ptr == NULL);
}

void Vlist::print_by_expression(string expression)
{
    Node *ptr = vlist_head;
    while (ptr != NULL)
    {
        if (regex_match (ptr->vlist_video->get_title(),regex(expression)))
        {
            ptr->vlist_video->print();
        }
        ptr = ptr->vlist_next;
    }
}

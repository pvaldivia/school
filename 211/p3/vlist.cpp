//vlist.cpp
//Valdivia, Pedro
//pvaldivia1

#include"video.h"
#include"vlist.h"

Vlist::Vlist()
{
    vlist_head = NULL;
}

Vlist::~Vlist()
{
    Node *ptr = vlist_head;
    while (ptr != NULL)
    {
        Node *temp;
        temp = ptr;
        ptr = ptr->vlist_next;
        delete temp->vlist_video;
        delete temp;
    }
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

    while (ptr != NULL && ptr->vlist_video->get_title() != title)
    {
        ptr = ptr->vlist_next;
    }
    return (ptr != NULL);
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


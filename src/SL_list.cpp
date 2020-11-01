#include <iostream>
#include "SL_list.h"

using namespace std;


SL_list::SL_list()
{
    root = NULL;
}

SL_list::~SL_list()
{
    //dtor
}

void SL_list::append(int val=0)
{
    List_node *new_node = new List_node(val);
    append(new_node);
}

void SL_list::append(List_node *new_node)
{
    if(root == NULL)
    {
        root = new_node;
    }
    else
    {
        get_last_node()->next = new_node;
    }
}
void SL_list::print()
{
    List_node *node = root;
    while(node != NULL)
    {
        cout << node->value << " -> ";
        node = node->next;
    }
    cout<<endl;
}
int SL_list::get_size()
{
    int list_size = 0;
    List_node *node = root;
    while(node != NULL)
    {
        list_size++;
        node = node->next;
    }
    return list_size;
}

List_node* SL_list::get_node_by_index(int index)
{
    int current_index = 0;
    List_node *node = root;
    if(index >= get_size())
    {
        return NULL;
    }
    while(current_index != index)
    {
        current_index++;
        node = node->next;
    }
    return node;
}

void SL_list::reverse_list()
{
    int list_size = get_size();
    for(int i = 1; i < get_size(); i++)
    {
        for(int index = 1; index < list_size; index++)
        {
            List_node *a = get_node_by_index(index-1);
            List_node *b = get_node_by_index(index);
            List_node *c = get_node_by_index(index+1);
            a->next = c;
            b->next = a;
            if(index >= 2)
            {
                List_node *d = get_node_by_index(index-2);
                d->next = b;
            }
            else
            {
                root = b;
            }
        }
        list_size--;
    }
}

SL_list* SL_list::merge_two_lists(SL_list *to_merge_list)
{
    SL_list* merged_list = new SL_list();

    List_node *first = root;
    List_node *second = to_merge_list->root;

    while(first != NULL && second != NULL)
    {
        if(first->value < second->value)
        {
            root = first->next;
            merged_list->append(first);
            first->next = NULL;
            first = root;
        }
        else
        {
            to_merge_list->root = second->next;
            merged_list->append(second);
            second->next = NULL;
            second = to_merge_list->root;
        }
    }
    if(first != NULL)
    {
        merged_list->append(first);
        root = NULL;
    }
    if(second != NULL)
    {
        merged_list->append(second);
        to_merge_list->root = NULL;
    }
    return merged_list;
}

List_node* SL_list::get_last_node()
{
    List_node *last_node = root;
    while(last_node->next != NULL)
    {
        last_node = last_node->next;
    }
    return last_node;
}

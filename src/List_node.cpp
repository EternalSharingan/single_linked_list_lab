#include <iostream>
#include "List_node.h"


List_node::List_node(int val)
{
    value = val;
    next = NULL;
}

List_node::~List_node()
{
    //dtor
}

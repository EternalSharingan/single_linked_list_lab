#ifndef LIST_NODE_H
#define LIST_NODE_H


class List_node
{
    public:
        int value;
        List_node *next;
        List_node(int);
        ~List_node();
};

#endif // LIST_NODE_H

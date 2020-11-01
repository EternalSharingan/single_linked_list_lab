#ifndef SL_LIST_H
#define SL_LIST_H
#include <List_node.h>

class SL_list
{
    public:
        List_node *root;
        SL_list();
        ~SL_list();
        void append(int val);
        void append(List_node *);
        void print();
        int get_size();
        List_node* get_node_by_index(int);
        void reverse_list();
        SL_list* merge_two_lists(SL_list *);

    private:
        List_node* get_last_node();
};

#endif // SL_LIST_H

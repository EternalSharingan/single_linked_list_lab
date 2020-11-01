#include <iostream>
#include <SL_list.h>

using namespace std;

int main()
{
    cout << "Reversing list:" << endl;
    SL_list *my_list_0 = new SL_list();
    my_list_0->append(1);
    my_list_0->append(2);
    my_list_0->append(3);
    my_list_0->append(4);
    my_list_0->append(5);
    my_list_0->print();
    my_list_0->reverse_list();
    my_list_0->print();

    cout << endl << "Merging two lists:" << endl;
    SL_list *mylist_1 = new SL_list();
    mylist_1->append(3);
    mylist_1->append(5);
    mylist_1->append(9);
    mylist_1->append(12);
    mylist_1->print();

    SL_list *mylist_2 = new SL_list();
    mylist_2->append(1);
    mylist_2->append(4);
    mylist_2->append(6);
    mylist_2->append(7);
    mylist_2->append(13);
    mylist_2->print();

    SL_list *mylist_3 = mylist_1->merge_two_lists(mylist_2);
    mylist_3->print();
    mylist_1->print();
    mylist_2->print();
    return 0;
}

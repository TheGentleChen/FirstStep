#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

void printLists(const list<int> &l1, const list<int> &l2)
{
    cout << "list1:";
    copy(l1.begin(), l1.end(), ostream_iterator<int>(cout, " "));
    cout << endl << "list2:";
    copy(l2.begin(), l2.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
}

int main()
{
    list<int> list1, list2;

    for (int i = 0;i < 6;++i)
    {
        list1.push_back(i);
        list2.push_front(i);
    }

    printLists(list1, list2);

    //insert all elements of list1 before the first element with value 3 of list 2
    //-find() returns an iterator to the element with value 3
    list2.splice(find(list2.begin(), list2.end(),   //destination position
                      3),
                list1); //source list
    printLists(list1, list2);

    //move first element to the end
    list2.splice(list2.end(),
                 list2,
                 list2.begin());
    printLists(list1, list2);

    //sort second list, assign to list1 and remove duplicates
    list2.sort();
    list1 = list2;
    list2.unique();
    printLists(list1, list2);

    //merge both sorted lists into the first list
    list1.merge(list2);
    printLists(list1, list2);

    return 0;
}

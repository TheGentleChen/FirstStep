#include <iostream>
#include <set>
#include "print.h"

using namespace std;

template <class T>
class RuntimeCmp
{
public:
    enum cmp_mode {normal, reverse};
private:
    cmp_mode mode;
public:
    RuntimeCmp(cmp_mode m = normal):mode(m){}
    bool operator()(const T & t1, const T & t2)const
    {
        return mode == normal ? t1 < t2 : t2 < t1;
    }
    bool operator==(const RuntimeCmp & rc)
    {
        return mode == rc.mode;
    }
};

typedef set<int, RuntimeCmp<int> > Intset;
void fill(IntSet & set);

int main()
{
    Inset coll1;
    fill(coll1);
    PRINT_ELEMENTS(coll1, "coll1: ");

    RuntimeCmp<int> reverse_order(RuntimeCmp<int>::reverse);

    Inset coll2(reverse_order);
    fill(coll2);
    PRINT_ELEMENTS(coll2, "coll2: ");

    if (coll1.value_comp() == coll2.value_comp())
    {
        cout << "coll1 and coll2 have same sorting criterion"
        << endl;
    }
    else
    {
        cout << "coll1 and coll2 have different sorting criterion"
        << endl;
    }

    return 0;
}

void fill(Intset & set)
{
    set.insert(4);
    set.insert(7);
    set.insert(5);
    set.insert(1);
    set.insert(6);
    set.insert(2);
    set.insert(5);
}

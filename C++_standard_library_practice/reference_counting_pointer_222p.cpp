#include <iostream>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

//class for counted reference semantics
//- deletes the object to which it refers when the last CountedPtr
//that refers to it is destroyed
template<class T>
class CountedPtr
{
private:
    T *ptr;         //pointer to the values
    long *count;    //shared number of owners

public:
    explicit CountedPtr(T *p = 0)
    :ptr(p),count(new long(1)){}

    CountedPtr (const CountedPtr<T> &p) throw()
    :ptr(p.ptr), count(p.count)
    {
     ++*count;
    }

    //destructor (delete value if this was the last owner)
    ~CountedPtr() throw()
    {
        dispose();
    }

    CountedPtr<T> & operator=(const CountedPtr<T> &p) throw()
    {
        if (this != &p)
        {
        dispose();
        count = p.count;
        ptr = p.ptr;
        ++*count;
        }
        return *this;
    }

    T &operator*() const throw()
    {
        return *ptr;
    }

    T *operator->() const throw()
    {
        return ptr;
    }

private:
    void dispose()
    {
        if (--*count == 0)
        {
            delete count;
            delete ptr;
        }
    }
};

inline void printCountedPtr(CountedPtr<int> elem)
{
    cout << *elem << ' ';
}

int main()
{
    static int values[] = {3, 5, 9, 1, 6, 4};

    typedef CountedPtr<int> IntPtr;
    deque<IntPtr> coll1;
    list<IntPtr> coll2;

    for (int i = 0;i < sizeof(values) / sizeof(values[0]);++i)
    {
        IntPtr ptr(new int(values[i]));
        coll1.push_back(ptr);
        coll2.push_front(ptr);
    }

    for_each(coll1.begin(), coll1.end(),
             printCountedPtr);
    cout << endl;
    for_each(coll2.begin(), coll2.end(),
             printCountedPtr);
    cout << endl << endl;

    *coll1[2] *= *coll1[2];
    (**coll1.begin()) *= -1;
    (**coll2.begin()) = 0;

    for_each(coll1.begin(), coll1.end(),
             printCountedPtr);
    cout << endl;
    for_each(coll2.begin(), coll2.end(),
             printCountedPtr);
    cout << endl << endl;

    return 0;
}

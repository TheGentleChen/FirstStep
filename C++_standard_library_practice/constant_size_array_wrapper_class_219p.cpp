#include <iostream>
#include <cstddef>
#include <algorithm>
#include <functional>

using namespace std;

template<class T, std::size_t thesize>
class carray
{
private:
    T v[thesize];

public:
    typedef T value_type;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef T& reference;
    typedef const T& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

    iterator begin() {return v;}
    const_iterator begin()const {return v;}
    iterator end() {return v + thesize;}
    const_iterator end()const {return v + thesize;}

    reference operator[](std::size_t i) {return v[i];}
    const_reference operator[](std::size_t i)const {return v[i];}

    size_type size()const {return thesize;}
    size_type max_size()const {return thesize;}

    T* as_array() {return v;}
};

int main()
{
    carray<int, 10> a;

    for (unsigned i = 0;i < a.size();++i)
    {
        a[i] = i + 1;
    }

    carray<int, 10>::iterator pos;
    for (pos = a.begin();pos != a.end();++pos)
    {
        cout << *pos << " ";
    }
    cout << endl;

    reverse(a.begin(), a.end());
    for (pos = a.begin();pos != a.end();++pos)
    {
        cout << *pos << " ";
    }
    cout << endl;

    transform(a.begin(), a.end(),
              a.begin(),
              negate<int>());
    for (pos = a.begin();pos != a.end();++pos)
    {
        cout << *pos << " ";
    }
    cout << endl;

    return 0;
}

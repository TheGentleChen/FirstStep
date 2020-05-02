#include <iostream>
#include "algostuff.hpp"

using namespace std;
//1.
void print (int elem)
{
    cout << elem << ' ';
}
//2.
template <class T>
class AddValue
{
private:
    T theValue;
public:
    AddValue(const T & v):theValue(v){}
    void operator()(T & elem)const
    {
        elem += theValue;
    }
};
//3.
class MeanValue
{
private:
    long num;
    long sum;
public:
    MeanValue():num(0),sum(0){}
    void operator()(int elem)
    {
        num++;
        sum += elem;
    }

    operator double()
    {
        return static_cast<double>(sum) / static_cast<double>(num);
    }
};

//4.
bool isEven(int elem)
{
    return elem % 2 == 0;
}

int main()
{
    //for_each()
//    1.
//    vector<int> coll;
//    INSERT_ELEMENTS(coll, 1, 9);
//
//    for_each(coll.begin(), coll.end(),
//             print);
//    cout << endl;

//    2.
//    vector<int> coll;
//    INSERT_ELEMENTS(coll, 1, 9);
//
//    for_each(coll.begin(), coll.end(),
//             AddValue<int>(10));
//
//    PRINT_ELEMENTS(coll);
//    for_each(coll.begin(), coll.end(),
//             AddValue<int>(*coll.begin()));
//    PRINT_ELEMENTS(coll);

//    3.
//    vector<int> coll;
//    INSERT_ELEMENTS(coll, 1, 8);
//    double mv = for_each(coll.begin(), coll.end(),
//                         MeanValue());
//    cout << "mean value: " << mv << endl;

//    count(), count_if()
//    4.
//    vector<int> coll;
//    int num;
//    INSERT_ELEMENTS(coll, 1, 9);
//    PRINT_ELEMENTS(coll, "coll: ");
//
//    num = count(coll.begin(), coll.end(),
//                4);
//    cout << "number of elements equal to 4: " << num << endl;
//
//    num = count_if(coll.begin(), coll.end(),
//                   isEven);
//    cout << "number of elements with even value: " << num << endl;
//
//    num = count_if(coll.begin(), coll.end(),
//                   bind2nd(greater<int>(), 4));
//    cout << "number of elements greater than 4: " << num << endl;
    return 0;
}

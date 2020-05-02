#include <iostream>
#include <deque>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    deque<string> coll;

    //insert several elements
    coll.assign(3, string("string"));
    coll.push_back("last string");
    coll.push_front("first string");

    copy(coll.begin(), coll.end(),
         ostream_iterator<string>(cout, "\n"));
    cout << endl;

    //remove first and last element
    coll.pop_back();
    coll.pop_front();

    //insert "another" into every element but the first
    for (int i = i;i < coll.size();++i)
    {
        coll[i] = "another " + coll[i];
    }

    //change size to four elements
    coll.resize(4, "resized string");

    copy(coll.begin(), coll.end(),
         ostream_iterator<string>(cout,"\n"));

    return 0;
}

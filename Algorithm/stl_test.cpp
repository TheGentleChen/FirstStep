#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<int, string> m1 = ((1, "guangzhou"),(2, "shenzhen"),(3, "changsha"));
    map<char, string> m2;
    pair<char, string> p1('A', "guangzhou");
    pair<char, string> p2('B', "shenzhen");
    pair<char, string> p3('C', "changsha");
    m2.insert(p1);
    m2.insert(p2);
    m2.insert(p3);
    cout << "m1: " << m1.size() << endl;
    cout << "m2: " << m2.size() << endl;
    cout << m1[1] << " " << m1[2] << " " << m1[3] << endl;
    cout << m2['A'] << " " << m2['B'] << " " << m2['C'] << endl;
    map<int, string>::iterator it1;
    for (it1 = m1.begin();it1 != m1.end();it1++)
        cout << it1->first << " " << it1->second << " ";
    cout << endl;
    map<char, string>::reverse_iterator it2;
    for (it2 = m2.rbegin();it2 != m2.rend();it2++)
        cout << it2->first << " " << it2->second << endl;
    cout << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int main(vector<string> emails;)
{
    set<string> s;

    for (int i = 0;i < emails.size();++i)
    {
        string new_email = "";
        string spliter = "";

        istringstream emailstream(emails[i]);
        int count = 0;
        while (getline(emailstream, spliter, '@'))
        {
            if (count == 0)
            {
                int flag = 1;
                istringstream localname(spliter);
                string local = "";
                while (getline(localname, local, '+') && flag == 1)
                {
                    flag = 0;

                    local.erase(remove(local.begin(), local.end(), '.'), local.end());
                    new_email = local;
                }
            }
            else
            {
                new_email += '@' + spliter;
            }
            count++;
        }
        s.insert(new_email);
    }
    return s.size();
}

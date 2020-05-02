#include <iostream>
using namespace std;
#include "text.h"
const int MAX = 10;
void showClassType();
int main()
{
	abstr_emp * pc[MAX];
	cout << "This program show the file of class Empoyee, input the data name to continue.\n";
	cout << "Enter the target file: ";
	char filename[MAX];
	cin.getline(filename,MAX);
	ifstream fin;
	if (!fin.is_open())
	{
		cerr << "Sorry, can't open " << filename << endl;
		exit(EXIT_FAILURE);
	}
	char ch;
	int i = 0;
	int classtype;
	while (fin >> classtype)
	{
		switch(classtype)
		{
		case Employee:pc[i] = new employee;break;
		case Manager:pc[i] = new manager;break;
		case Fink:pc[i] = new fink;break;
		case Highfink:pc[i] = new highfink;break;
		}
		pc[i]->getall(fin);
		pc[i]->ShowAll();
		i++;
	}
	fin.close();
	ofstream fou;
	fou.open(filename,ios_base::out | ios_base::app);
	int idex = 0;
	showClassType();
	while (cin >> ch && ch != 'q' && idex < MAX)
	{
		cin.get();
		switch(ch)
		{
		case 'a':pc[idex] = new employee;
			pc[idex]->SetAll();
			break;
		case 'b':pc[idex] = new manager;
			pc[idex]->SetAll();break;
		case 'c':pc[idex] = new fink;
			pc[idex]->SetAll();break;
		case 'd':pc[idex] = new highfink;
			pc[idex]->SetAll();break;
		default:cout << "Error type!\n";break;
		}
		idex++;
		showClassType();
	}
	for (i = 0;i < idex;i++)
	{
		pc[i]->writeall(fou);
	}
	fou.close();
	fin.close();
	fin.clear();
	fin.open(filename);
	cout << "Here is the redice file:\n";
	while ((fin >> classtype).get(ch))
	{
		switch (classtype)
		{
		case Employee:pc[i] = new employee;break;
		case Manager:pc[i] = new manager;break;
		case Fink:pc[i] = new fink;break;
		case Highfink:pc[i] = new highfink;break;
		}
		pc[i]->getall(fin);
		pc[i]->ShowAll();
		i++;
	}
	fin.close();
	cout << "Bye!\n";
	return 0;
}

void showClassType()
{
	cout << "What class type do you want to creat:\n "
		"a)Employee  b)Manage  c)Fink  d)Highfink  q)quit\n";
}
#include "text.h"

void abstr_emp::ShowAll()const
{
	cout << "\t\t" << lname << "," << fname << "\t"
		<< job;
}

void abstr_emp::SetAll()
{
	cout << "Enter first name: ";
	getline(cin,fname);
	cout << "Enter last name: ";
	getline(cin,lname);
	cout << "Job: ";
	getline(cin,job);
}

void abstr_emp::writeall(ofstream & fo)
{
	fo << lname << endl << fname << endl << job << endl;
}

void abstr_emp::getall(ifstream & fi)
{
	getline(fi,lname);
	getline(fi,fname);
	getline(fi,job);
}

ostream & operator <<(ostream & os,const abstr_emp & e)
{
	os << "Name: " << e.lname << "," << e.fname;
	return os;
}

void employee::writeall(ofstream & fo)
{
	fo << Employee;
	abstr_emp::writeall(fo);
}

void employee::getall(ifstream & fi)
{
	abstr_emp::getall(fi);
}

manager::manager(const manager & m):abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll()const
{
	cout << endl;
	abstr_emp::ShowAll();
	cout << "\t" << inchargeof;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter the inchangeof count: ";
	cin >> inchargeof;
	while (cin.get() != '\n')
		continue;
}

void manager::writeall(ofstream & fo)
{
	fo << Manager;
	abstr_emp::writeall(fo);
	fo << inchargeof << endl;
}

void manager::getall(ifstream & fi)
{
	abstr_emp::getall(fi);
	fi >> inchargeof;
}

fink::fink(const fink & f):abstr_emp(f)
{
	reportsto = f.reportsto;
}

void fink::ShowAll()const
{
	cout << endl;
	abstr_emp::ShowAll();
	cout << "\t" << reportsto;
}

void fink::SetAll()
{
	cout << "Enter the reportsto: ";
	getline(cin,reportsto);
	while (cin.get() != '\n')
		continue;
}

void fink::writeall(ofstream & fo)
{
	fo << Fink;
	abstr_emp::writeall(fo);
	fo << reportsto << endl;
}

void fink::getall(ifstream & fi)
{
	abstr_emp::getall(fi);
	getline(fi,reportsto);
}

void highfink::ShowAll()const
{
	cout << endl;
	abstr_emp::ShowAll();
	cout << "\t" << manager::InChargeOf();
	cout << "\t" << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	string temp;
	int tem;
	cout << "Enter the inchangeof count: ";
	cin >> tem;
	cin.get();
	cout << "Enter the reportsto: ";
	getline(cin,temp);
}

void highfink::writeall(ofstream & fo)
{
	fo << Highfink;
	abstr_emp::writeall(fo);
	manager::FileChangeOf(fo);
	fink::FileReportsTo(fo);
}

void highfink::getall(ifstream & fi)
{
	abstr_emp::getall(fi);
	manager::FileChangeOf(fi);
	fink::FileReportsTo(fi);
}
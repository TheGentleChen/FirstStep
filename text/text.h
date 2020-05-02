#ifndef TEXT_H_
#define TEXT_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
enum classkin{Employee,Manager,Fink,Highfink};
class abstr_emp
{
private:
	string fname;
	string lname;
	string job;
public:
	abstr_emp():fname("No name"),lname("no name"),job("no job"){}
	abstr_emp(const string & fn,const string & ln,const string & j):fname(fn)
		,lname(ln),job(j){}
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void writeall(ofstream & fo);
	virtual void getall(ifstream & fi);
	friend ostream & operator <<(ostream & os,const abstr_emp & e);
	virtual ~abstr_emp() = 0{}
};
class employee:public abstr_emp
{
public:
	employee(const string & fn,const string & ln,const string & j):abstr_emp(fn,ln,j){};
	employee():abstr_emp(){}
	virtual void ShowAll()const{abstr_emp::ShowAll();}
	virtual void SetAll(){abstr_emp::SetAll();}
	void writeall(ofstream & fo);
	void getall(ifstream & fi);
};
class manager:virtual public abstr_emp
{
public:
	manager():abstr_emp(),inchargeof(0){}
	manager(const string & fn,const string & ln,
		const string & j,int ico = 0):abstr_emp(fn,ln,j),inchargeof(ico){}
	manager(const abstr_emp & e,int ico):abstr_emp(e),inchargeof(ico){}
	manager(const manager & m);
	virtual void ShowAll()const;
	virtual void SetAll();
	void writeall(ofstream & fo);
	void getall(ifstream & fi);
protected:
	int InChargeOf()const{return inchargeof;}
	int & InChargeOf(){return inchargeof;}
	void FileChangeOf(ofstream & fou)const{fou << inchargeof << "\t";}
	void FileChangeOf(ifstream & fin){fin >> inchargeof;}
private:
	int inchargeof;
};
class fink:virtual public abstr_emp
{
private:
	string reportsto;
protected:
	const string ReportsTo()const{return reportsto;}
	string & RoportsTo(){return reportsto;}
	void FileReportsTo(ofstream & fou){fou << reportsto;}
	void FileReportsTo(ifstream & fin){fin >> reportsto;}
public:
	fink():abstr_emp(),reportsto("null"){};
	fink(const string & fn,const string &ln,
		const string & j,const string & rpo):abstr_emp(fn,ln,j),reportsto(rpo){}
	fink(const abstr_emp & e,const string & rpo):abstr_emp(e),reportsto(rpo){}
	fink(const fink & f);
	virtual void ShowAll()const;
	virtual void SetAll();
	void writeall(ofstream & fo);
	void getall(ifstream & fi);
};
class highfink:public manager,public fink
{
public:
	highfink(){}
	highfink(const string & fn,const string & ln,
		const string & j,const string & rpo,int ico)
		:abstr_emp(fn,ln,j),fink(fn,ln,j,rpo),manager(fn,ln,j,ico){}
	highfink(const abstr_emp & e,const string & rpo,int ico)
		:abstr_emp(e),fink(e,rpo),manager(e,ico){}
	highfink(const fink & f,int ico)
		:abstr_emp(f),fink(f),manager(f,ico){}
	highfink(const manager & m,const string & rpo)
		:abstr_emp(m),fink(m,rpo),manager(m){}
	highfink(const highfink & h)
		:abstr_emp(h),manager(h),fink(h){}
	virtual void ShowAll()const;
	virtual void SetAll();
	void writeall(ofstream & fo);
	void getall(ifstream & fi);
};

#endif
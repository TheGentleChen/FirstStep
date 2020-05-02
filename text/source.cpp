#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
void ShowStr(const std::string & s){std::cout << s << std::endl;}
void GetStrs(std::ifstream & fi,vector<std::string> & s);
class Store
{
private:
	std::ofstream & fou;
public:
	Store(std::ofstream & os):fou(os){};
	void operator()(const std::string & s)
	{
		size_t len = s.size(); //size�ķ�������,len�洢�ַ����ĳ���
		fou.write((char *)&len,sizeof(std::size_t));//�ȴ洢���ȣ����ϵ����������  
			//����д���Ȱ��ַ����ĳ���len������Ϣ���Ƶ���������ļ���  
		fou.write(s.data(),len);//������ָ���ַ������ַ����������ַ���������'\0'д���ļ�
	}
};
int main()
{
	using namespace std;
	vector<string>vostr;
	string temp;
	cout << "Enter strings(empty line to quit):\n";
	while (getline(cin,temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(),vostr.end(),ShowStr);
	ofstream fout("string.dat",ios_base::out | ios_base::binary);
	for_each(vostr.begin(),vostr.end(),Store(fout));
	fout.close();
	vector<string>vistr;
	ifstream fin("string.dat",ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin,vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vostr.begin(),vostr.end(),ShowStr);
	return 0;
}

void GetStrs(std::ifstream & fi,vector<std::string> & s)
{
	size_t len;//ʹ��read����ȡ���ȣ������������
	while (fi.read((char *)&len,sizeof(size_t)))
	{ //����Ҫ֪��ѭ�����������ַ���
		char * st = new char[len];//len���ҵ�������ÿ���ַ���ռ�ݵĶ�����λ��
		st[len + 1] = '\0';//����û�д洢���ַ�������������Ϊ��
		ve.push_back(st);
	}
}
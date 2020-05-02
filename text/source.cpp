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
		size_t len = s.size(); //size的返回类型,len存储字符串的长度
		fou.write((char *)&len,sizeof(std::size_t));//先存储长度，书上的用意很明显  
			//这样写是先把字符串的长度len长度信息复制到相关联的文件中  
		fou.write(s.data(),len);//这里是指定字符串的字符数，把字字符串不包括'\0'写入文件
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
	size_t len;//使用read来获取长度，这个方法很赞
	while (fi.read((char *)&len,sizeof(size_t)))
	{ //这里要知道循环条件就是字符数
		char * st = new char[len];//len按我的理解就是每个字符所占据的二进制位数
		st[len + 1] = '\0';//由于没有存储空字符，所以这里人为加
		ve.push_back(st);
	}
}
#include<iostream>//Ԥ��������
using namespace std;//ʹ�������ռ�
class student//����һ����
{
private://����Ϊ���˽�в���
    int num;//˽�б���num
    int score;//˽�б���score
public://����Ϊ��Ĺ��в���
    void setdata()//���幫�ú���setdata
    {
        cin>>num;//����num
        cin>>score;//����score
    }
    void display()//���幫�ú���display
    {
        cout<<"num="<<num<<endl;//���num
        cout<<"score="<<score<<endl;//���score
    };
};//�����������
student stud1,stud2;//����stud1��stud2��stude��ı�������Ϊ����
int main()//�������ײ�
{
    stud1.setdata();//���ö���stud1��setdata����
    stud2.setdata();//���ö���stud2��setdata����
    stud1.display();//���ö���stud1��display����
    stud2.display();//���ö���stud2��display����
    return 0;
}

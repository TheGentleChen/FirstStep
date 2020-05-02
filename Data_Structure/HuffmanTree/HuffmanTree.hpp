#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
class HuffmanTree
{
private:
    typedef struct HTNode
    {
        int weight;
        int parent, lChild, rChild;
    }* Node;
    Node HT;
    char* book;
    string* HC;
    int n;

    void select(int k, int& s1, int& s2);
    int select(char item);
    void creatHuffmanCode();
    void setNum(int num);
public:
    HuffmanTree();
    void initial();
    void setNum();
    void codeDisplay();
    void encode(string s);
    void decode(string code);
};

#endif // HUFFMANTREE_H_

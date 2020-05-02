#include "HuffmanTree.hpp"

HuffmanTree::HuffmanTree()
{
    setNum(27);
    if (n > 1)
    {
        int m = 2 * n - 1;
        HT = new HTNode[m + 1];
        for (int i = 1;i <= m;++i)
            HT[i].parent = HT[i].lChild = HT[i].rChild = 0;
        for (int i = 1;i <= n;++i)
            cin >> HT[i].weight;
        for (int i = n+1;i <= m;++i)
        {
            int s1, s2;
            select(i - 1, s1, s2);
            HT[s1].parent = HT[s2].parent = i;
            HT[i].lChild = s1;HT[i].rChild = s2;
            HT[i].weight = HT[s1].weight + HT[s2].weight;
        }
        creatHuffmanCode();
    }
}

void HuffmanTree::initial()
{
    book = new char[n+2];
    book[n+2] = '\0';
    getchar();
    gets(book+1);
}

void HuffmanTree::setNum(int num)
{
    n = num;
}

void HuffmanTree::codeDisplay()
{
    for (int i = 1;i <= n;++i)
    {
        cout << book[i] << "\t\t" << HC[i] << endl;
    }
}

void HuffmanTree::select(int k, int& s1, int& s2)
{
    int min = 1000000;
    for (int i = 1;i <= k;++i)
    {
        if (HT[i].parent == 0 && HT[i].weight < min)
        {
            min = HT[i].weight;
            s1 = i;
        }
    }
    min = 1000000;
    for (int i = 1;i <= k;++i)
    {
        if (HT[i].parent == 0 && HT[i].weight < min && i != s1)
        {
            min = HT[i].weight;
            s2 = i;
        }
    }
}

void HuffmanTree::creatHuffmanCode()
{
    HC = new string[n+1];
    char* cd = new char[n];
    cd[n-1] = '\0';
    for (int i = 1;i <= n;++i)
    {
        int start = n-1;
        int c = i, p = HT[c].parent;
        while (p != 0)
        {
            --start;
            if (HT[p].lChild == c)  cd[start] = '0';
            else cd[start] = '1';
            c = p;p = HT[p].parent;
        }
        for (int j = start;j < n-1;++j)
        {
            HC[i] += cd[j];
        }
    }
    delete cd;
}

int HuffmanTree::select(char item)
{
    for (int i = 1;i <= n;++i)
    {
        if (book[i] == item)
            return i;
    }
}

void HuffmanTree::encode(string s)
{
    for (int i = 0;i < s.length();++i)
    {
        int index = select(s[i]);
        cout << HC[index];
    }
    cout << endl;
}

void HuffmanTree::decode(string code)
{
    for (int i = 0;i < code.length();++i)
    {
        int m = n * 2 - 1;
        while (HT[m].lChild != 0)
        {
            if (code[i] == '0') m = HT[m].lChild;
            else m = HT[m].rChild;
            ++i;
        }
        i--;
        cout << book[m];
    }
    cout << endl;
}

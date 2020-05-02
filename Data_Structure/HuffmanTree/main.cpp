#include "HuffmanTree.hpp"
#include <windows.h>
int main()
{
    HuffmanTree* test1;
    int chance = 1;
    while (true)
    {
        cout << "Author:1710243231陈恒勋\n"
        "1----输入HuffmanTree的参数\n"
        "2----初始化HuffmanTree的参数.（含26个字母和空格）\n"
        "3----输出编码表\n"
        "4----输入编码并翻译为字符\n"
        "5----输入字符并实现转码\n"
        "\t退出，输入一个负数\n"
        "请输入HuffmanTree1的操作代码：";
        cin >> chance;
        if (chance < 0) break;
        int n;
        string s;
        switch (chance)
        {
        case 1:
            cout << "请输入HuffmanTree的参数：";
            test1 = new HuffmanTree();
            break;
        case 2:
            cout << "初始化HuffmanTree参数.（含26个字母及空格）：";
            test1->initial();
            cout << endl;
            break;
        case 3:
            cout << "输出编码表：";
            test1->codeDisplay();
            cout << endl;
            break;
        case 4:
            cout << "输入编码：";
            getchar();
            getline(cin, s);
            cout << "翻译成的字符为：";
            test1->decode(s);
            break;
        case 5:
            cout << "输入字符：";
            getchar();
            getline(cin, s);
            cout << "翻译成的编码为：";
            test1->encode(s);
            break;
        default:
            cout << "输入有误，请重新输入..." << endl;
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

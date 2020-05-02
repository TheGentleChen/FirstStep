#include <iostream>
#include "gotoxy.hpp"
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

char direction_a, direction_b;
int scores, num, fool_x, fool_y, speed = 100;
bool END;
struct node
{
    int x, y;
    node *next;
}*head = nullptr, *p, *tail;

void init();
void start();
void init_snake();
void delete_snake();
void control();
void move();
void limit();
void panduan();
void fool();
void isEND();
void zhuangwei();
void zhuangqiang();

int main()
{
    srand(time(0));
    init();
    cin >> direction_a;
    if (direction_a != 'y' && direction_a != 'Y')
        return 0;
    do
    {
        system("cls");
        END = false;
        start();
        delete_snake();
        init_snake();
        scores = 0;
        num = 0;
        fool_x = (rand() % 78) + 2;
        fool_y = (rand() % 21) + 2;
        gotoxy(fool_x, fool_y);
        cout << "0";
        direction_a = getch();
        while(direction_a != 'd' && direction_a != 'w' && direction_a != 's')
            direction_a = getch();
        while(true)
        {
            if (direction_a != 'd' && direction_a != 's' && direction_a != 'w' && direction_a != 'a')
            {
                direction_a = direction_b;
            }
            control();
            fool();
            Sleep(speed);
            if (kbhit())
            {
                direction_a = getch();
                limit();
            }
            panduan();
            num = 1;
            zhuangqiang();
            zhuangwei();
            if (END)    break;
        }
    }while(direction_a == 'y' || direction_a == 'Y');
    return 0;
}

void init()
{
    gotoxy(35, 8);
    cout << "*贪吃蛇*";
    gotoxy(36, 10);
    cout << "开始请输入y: ";
}

void start()
{
    for (int i = 0; i <= 79; ++i)
    {
        Sleep(10);
        cout << "*";
        gotoxy(i+1, 24);
        cout << "*";
        gotoxy(i+2, 1);
    }

    gotoxy(1, 2);

    for (int i = 0; i <= 21; ++i)
    {
        Sleep(20);
        cout << "*";
        for (int j = 0; j <= 77; ++j)
            cout << " ";
        cout << "*";
        gotoxy(1, i + 3);
    }
}

void init_snake()
{
    int n = 3;
    head = new node;
    tail = head;
    head->x = 40;
    head->y = 12;
    while(n--)
    {
        p = new node;
        tail->next = p;
        p->x = tail->x - 1;
        p->y = tail->y;
        tail = p;
    }
    tail->next = nullptr;
    node *q = head->next;
    gotoxy(head->x, head->y);
    cout << "#";
    while (q != nullptr)
    {
        gotoxy(q->x, q->y);
        cout << "*";
        q = q->next;
    }
}

void delete_snake()
{
    while (head != nullptr)
    {
        node *q = head;
        head = q->next;
        delete q;
    }
}

void move()
{
    gotoxy(tail->x, tail->y);
    cout << " ";
    gotoxy(head->next->x, head->next->y);
    cout << "*";
    gotoxy(head->x, head->y);
    cout << "#";
    node *q = tail;
    tail = head;
    while(tail->next != q)
    {
        tail = tail->next;
    }
    tail->next = nullptr;
    delete q;
}

void control()
{
    node *q = new node;
    q->next = head;
    q->x = head->x;
    q->y = head->y;
    head = q;
    switch(direction_a)
    {
        case 'w':   head->y--;break;
        case 's':   head->y++;break;
        case 'a':   head->x--;break;
        case 'd':   head->x++;break;
        default:    break;
    }
    move();
}

void limit()
{
    if (direction_b == 's' && direction_a == 'w')
        direction_a = 's';
    if (direction_b == 'w' && direction_a == 's')
        direction_a == 'w';
    if (direction_b == 'a' && direction_a == 'd')
        direction_a = 'a';
    if (direction_b == 'd' && direction_a == 'a')
        direction_a == 'd';
}

void panduan()
{
    if (direction_a == 's') direction_b = 's';
    if (direction_a == 'w') direction_b = 'w';
    if (direction_a == 'd') direction_b = 'd';
    if (direction_a == 'a') direction_b = 'a';
}

void fool()
{
    node *q;
    if (head->x == fool_x && head->y == fool_y)
    {
        fool_x = (rand() % 78) + 2;
        fool_y = (rand() % 21) + 2;
        gotoxy(fool_x, fool_y);
        cout << "0";
        num = 0;
        scores++;
        node *q = new node;
        q->x = tail->x;
        q->y = tail->y;
        tail->next = q;
        tail = q;
        tail->next = nullptr;
    }
    q = head;
    while (q != nullptr)
    {
        if (q->x == fool_x && q->y == fool_y)
        {
            fool_x = (rand() % 78) + 2;
            fool_y = (rand() % 21) + 2;
            gotoxy(fool_x, fool_y);
            cout << "*";
            q = head;
            continue;
        }
        q = q->next;
    }
}

void isEND()
{
    END = true;
    Sleep(600);
    system("cls");
    gotoxy(35, 8);
    cout << "您 输 啦~";
    gotoxy(33, 10);
    cout << "您的分数为: " << scores;
    gotoxy(31, 12);
    cout << "重新开始请输入y: ";
    cin >> direction_a;
}

void zhuangwei()
{
    node *q = head->next;
    while (q != nullptr)
    {
        if (head->x == q->x && head->y == q->y)
        {
            isEND();
            break;
        }
        q = q->next;
    }
}

void zhuangqiang()
{
    if (head->x == 80 || head->x == 1 || head->y == 24 || head->y == 1)
        isEND();
}

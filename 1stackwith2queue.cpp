#include<iostream>
using namespace std;

struct qe{
    int m[5];
    int maxx;
    bool root;
};
// stack la cho vao cuoi thi lay ra dau tien
// queue la cho vao dau thi lay ra dau tien
// 1 2 3
//

qe a;

qe b;


void push(int x)
{
    if (a.root == true)
    {
        a.m[a.maxx] = x;
        a.maxx++;
    }
    else if (b.root == true)
    {
        b.m[b.maxx] = x;
        b.maxx++;
    }

}

void pop()
{
    if (a.root == true)
    {
        for(int i=0;i<a.maxx;i++)
        {
            b.m[i] = a.m[i];
        }
        b.maxx = a.maxx -1;
        a.maxx = 0;
        a.root = false;
        b.root = true;
    }
    else if(b.root = true)
    {
        for(int i=0;i<b.maxx;i++)
        {
            a.m[i] = b.m[i];
        }
        a.maxx = b.maxx -1;
        b.maxx = 0;
        b.root = false;
        a.root = true;
    }
}

int main()
{
    a.maxx = 0;
    a.root = true;
    b.maxx = 0;
    b.root = false;
    push(1);
    push(2);
    push(3);
    pop();
    push(4);
    push(5);
    pop();
    pop();
    if (a.root == true)
    {
        for (int i=0;i<a.maxx;i++)
        {
            cout << a.m[i] << " ";
        }
    }
    else if(b.root == true)
    {
        for (int i=0;i<b.maxx;i++)
        {
            cout << b.m[i] << " ";
        }
    }
}

#include<iostream>
using namespace std;
struct stackk{
    int m[5];
    int maxx;
};

stackk st1;
stackk st2;

void enqueue(int x)
{
    st1.m[st1.maxx]=x;
    st1.maxx++;
}

void dequeue()
{
    for(int i=0;i<st1.maxx-1;i++)
    {
        st2.m[i] = st1.m[st1.maxx-1-i];
    }
    st2.maxx = st1.maxx-1;
    st1.maxx = 0;
    for (int i=0;i<st2.maxx;i++)
    {
        st1.m[i] = st2.m[st2.maxx-1-i];
    }
    st1.maxx = st2.maxx;
    st2.maxx = 0;
}



int main()
{
    st1.maxx = 0;
    st2.maxx = 0;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    for (int i=0;i<st1.maxx;i++)
    {
        cout << st1.m[i] << " ";
    }
}

#include<iostream>
#include<vector>
using namespace std;
// cai dat max heap
void swapp(int &a,int &b)
{
    int c = a;
    a= b;
    b= c;
}
void swimUp(vector<int> &tree,int k)
{
    if (k!=0)
    {
        int t = (k-1)/2;
        if (tree[k]>tree[t])
        {
            swapp(tree[k],tree[t]);
            swimUp(tree,t);
        }
    }

}
void sinkDown(vector<int> &tree,int k)
{
    int n = tree.size()-1;
    int left = k*2 +1;
    int right = k*2 +2;
    if (left<n&&tree[k]<tree[left])
    {
        swapp(tree[k],tree[left]);
        sinkDown(tree,left);
    }
    else if (right<n&&tree[k]<tree[right])
    {
        swapp(tree[k],tree[right]);
        sinkDown(tree,right);
    }

}

void insertNode(vector<int> &tree,int data)
{
    tree.push_back(data);
    int k = tree.size()-1;
    swimUp(tree,k);
}

void deleteNode(vector<int> &tree,int data)
{
    int n = tree.size();
    int dex = -1;
    for(int i=0;i<n;i++)
    {
        if (tree[i]==data)
        {
            dex = i;
            break;
        }
    }
    if (dex == -1)
    {
        return;
    }
    int lastDex = n-1;
    tree[dex]= tree[lastDex];
    tree.pop_back();
    sinkDown(tree,dex);
}

void print(vector<int> tree)
{
    for (int i=0;i<tree.size();i++)
    {
        cout << tree[i] << " ";
    }
}



int main()
{
    vector<int> tree;
    insertNode(tree,2);
    insertNode(tree,1);
    insertNode(tree,10);
    insertNode(tree,6);
    insertNode(tree,3);
    insertNode(tree,8);
    insertNode(tree,7);
    insertNode(tree,13);
    insertNode(tree,20);
    deleteNode(tree,13);
    print(tree);
    return 0;

}

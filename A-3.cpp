#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int a[n][n];
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        if(x>y){
            a[y][x]++;
        }
        else{a[x][y]++;}
    }
    int ans = 0;
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]>1&&i!=j){
                ans += a[i][j];
            }
        }
    }
    cout << ans;
}

#include<iostream>
using namespace std;
int main()
{
    string a,b;
    cin >> a >> b;
    int m = a.size();
    int n = b.size();
    int x[m+1][n+1];
    for (int i=0;i<=n;i++)
    {
        x[0][i]=0;
    }
    for (int i=0;i<=m;i++)
    {
        x[i][0]=0;
    }
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1])
            {
                x[i][j] = x[i-1][j-1]+1;
            }
            else
            {
                x[i][j] = max(x[i-1][j],x[i][j-1]);
            }
        }
    }
    cout << x[m][n];


}

#include<iostream>
#include<vector>

using namespace std;

void takeinput(int a[2][2], int size)
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            int k;
            cin>>k;
            a[i][j]=k;
        }
        //cout<<endl;
    }

}

int main()
{
    static int n=2;
    int a[2][2];

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            int k;
            cin>>k;
            a[i][j]=k;
        }
        //cout<<endl;
    }

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }


    return 0;
}
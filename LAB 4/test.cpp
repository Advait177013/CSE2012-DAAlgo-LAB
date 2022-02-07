#include<iostream>
#include<vector>

using namespace std;

void takeinput(vector<vector<int>> a, int n)
{
    int k;
    for (int i=0; i<n; i++)
    {
        vector<int> row;
        for(int j=0; j<n; j++)
        {
            cin>>k;
            row.push_back(k);
        }
        a.push_back(row);
    }
}

void multimat(vector<vector<int>> a, vector<vector<int>> b, vector<vector<int>> c, int ar, int ac, int br, int bc, int size)
{
    cout<<"test1\n";
    if(size==1)
    {
        c[ar][bc]+=a[ar][ac]*b[br][bc];   
        cout<<"what\n";
    }
    else
    {
        cout<<"working";
        int k=size/2;
        multimat(a, b, c, ar, ac, br, bc, k);
        multimat(a, b, c, ar, ac+k, br+k, bc, k);
        
        multimat(a, b, c, ar, ac, br, bc+k, k);
        multimat(a, b, c, ar, ac+k, br+k, bc+k, k);
        
        multimat(a, b, c, ar+k, ac, br, bc, k);
        multimat(a, b, c, ar+k, ac+k, br+k, bc, k);
        
        multimat(a, b, c, ar+k, ac, br+k, bc, k);
        multimat(a, b, c, ar+k, ac+k, br+k, bc+k, k);
    }
}

void print_matrix(vector<vector<int> > mat)
{
    int n=mat.size(),i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
}


int main()
{
    int size;
    cin>>size;
    vector<vector<int>> a, b;
    vector<vector<int>> c;
    
    
    for(int i=0; i<size; i++)
    {
        vector<int> test;
        for(int j=0; j<size; j++)
        {
            test.push_back(0);
        }
        c.push_back(test);
    }

    takeinput(a, size);
    takeinput(b, size);
    
    //multimat(a, b, c, 0, 0, 0, 0, size);
    
    /*for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            //cout<<c[i][j]<<" ";
            cout<<a[i][j]<<" ";
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }*/

    print_matrix(a);
    print_matrix(b);
    print_matrix(c);
    

    
    return 0;
}
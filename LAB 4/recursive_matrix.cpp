#include<iostream>
using namespace std;
#include <cstdlib> 
#include <ctime> 
#include<vector>
void read_matrix(vector<vector<int> >&mat,int n)
{
    int i,j,ele,x;
    for(i=0;i<n;i++)
    {
        vector<int> row;
        
        for(int j=0; j<n; j++)
	  {
	  x=std::rand();
	  x=x%400;
	  row.push_back(x);
	  }
        
        mat.push_back(row);
    }
}
void print_matrix(vector<vector<int> > &mat)
{
    int n=mat.size(),i,j;
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
}

void square_matrix_multiply_recursive(vector<vector<int> > &mat1,vector<vector<int> > &mat2, vector<vector<int> > &mat3, int top1, int left1, int top2, int left2, int size)
{       
    if (size==1)
    {
        mat3[top1][left2] += mat1[top1][left1] * mat2[top2][left2];
    }
    else
    {
        // 11 - top, left
        // 12 - top, left+n/2
        // 21 - top+n/2, left
        // 22 - top+n/2, left+n/2
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1,left1,top2,left2,size/2);
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1,left1+size/2,top2+size/2,left2,size/2);
        
        
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1,left1,top2,left2+size/2,size/2);
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1,left1+size/2,top2+size/2,left2+size/2,size/2);
        
        
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1+size/2,left1,top2,left2,size/2);
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1+size/2,left1+size/2,top2+size/2,left2,size/2);
        
        
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1+size/2,left1,top2,left2+size/2,size/2);
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1+size/2,left1+size/2,top2+size/2,left2+size/2,size/2);
        
    }
}
int main()
{
    vector<vector<int> > mat1,mat2;
    
    vector<double> time1;
    int i,j,n;
    
    for(int i=2; i<1025; i=i*2)
    {
     read_matrix(mat1,i);
     //print_matrix(mat1);
     read_matrix(mat2,i);
     //print_matrix(mat2);
    // Create resultant matrix of size nxn and intialize all elements to 0
    vector< vector<int> > mat3(i, vector<int>(i,0));  
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    clock_t tStart = clock();  
    square_matrix_multiply_recursive(mat1,mat2,mat3,0,0,0,0,i);
    double time=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    time1.push_back(time);
    //print_matrix(mat3);
    mat1.clear();
    mat2.clear();
    mat3.clear();
   }
   n=time1.size();
   for(int i=0; i<n; i++)
   {
     printf("\n%f",time1[i]);
   }
}

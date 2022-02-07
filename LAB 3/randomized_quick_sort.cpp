#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include<vector>
using namespace std;
int party( vector<int> &v, int low, int high)

	{
	    
	    int temp,num;
	
	    
	    
	    num = (std::rand() % (-low+ high +1)) + low;
	    
	    
	    
	    temp=v[high];
	    v[high]=v[num];
	    v[num]=temp;
	    
	    int pivot=v[high];
	    
	    int i=low-1, j;
	    
	    
	    for(j=low; j<high; j++)
	    {
		if (v[j]<=pivot)
		{
			i=i+1;
			temp=v[j];
			v[j]=v[i];
			v[i]=temp;
		}
	     }
	     
	     temp=v[i+1];
	     v[i+1]=v[high];
	     v[high]=temp;
	     
	     return (i+1);
	 }
			

void quick_sort(vector<int> &v, int low, int high)

	{
	   if (low>=high)
	   return;
	   
	   int p=party(v,low,high);
	   quick_sort(v,low, p-1);
	   quick_sort(v,p,high);
	   
	}
int main()

	{
	   int n,i,x;
	  vector<int> v;
	  cin >> n;
	  std::srand(static_cast<unsigned int>(std::time(nullptr))); 
	  
	  for(int i=0; i<n; i++)
	  {
	  x=std::rand();
	  x=x%100;
	  v.push_back(x);
	  } 
	   clock_t tStart = clock();
	   quick_sort(v,0,n-1);
	   
	   for(int i=0; i<n; i++)
	   {
	      printf("%d ", v[i]);
	   }
	   printf("Time taken: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	   return 0;
	   
	 }

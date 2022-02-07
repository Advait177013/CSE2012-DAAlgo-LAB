#include<iostream>
#include<vector>
#include<chrono>
#include<time.h>
#include<ctime>

using namespace std;
using namespace std::chrono;

void merge(vector <int> &ar, int start, int middle, int end)
{
    //cout<<"merge called\n";
    vector <int> r(end-middle);
    vector <int> l(middle - start+1);
    //setting sorted elements
    for(int i=0; i<r.size(); i++)
    {
        r[i]=ar[middle+i+1];
    }
    for(int i=0; i<l.size(); i++)
    {
        l[i]=ar[start+i];
    }
    //cout<<"elements placed\n";
    int lcount =0, rcount=0;
    int starter=start;
    
    //actual merge
    while(rcount<r.size() && lcount<l.size())
    {
        if(l[lcount]<r[rcount])
        {
            ar[starter]=l[lcount];
            lcount++;
        }
        else
        {
            ar[starter]=r[rcount];
            rcount++;
        }
        starter++;
    }
    //cout<<"double merge\n";
    while(lcount<l.size())
    {
        ar[starter]=l[lcount];
        lcount++;
        starter++;
    }
    //cout<<"lmerge\n";
    while(rcount<r.size())
    {
        ar[starter]=r[rcount];
        rcount++;
        starter++;
    }
    //cout<<"rmerge\n";
    //cout<<"merged\n";

}

void merge_sort(vector<int> &ar, int start, int end)
{
    //cout<<"nmergesort called\n";
    if(start<end)
    {
        int m=(start+end)/2;
        merge_sort(ar, start, m);
        merge_sort(ar, m+1, end);
        merge(ar, start, m, end);
    }
    if(start>=end)
    {
        return;
    }
}

int partition(vector<int> &ar, int low, int high)
{
    int temp,num;
	num = (std::rand() % (-low+ high +1)) + low;

	temp=ar[high];
	ar[high]=ar[num];
	ar[num]=temp;
	    
	int pivot=ar[high];
	    
	int i=low-1, j;
	    
	    
	for(j=low; j<high; j++)
	{
        if (ar[j]<=pivot)
	    {
            i=i+1;
            temp=ar[j];
            ar[j]=ar[i];
            ar[i]=temp;
	    }
	}
	     
	temp=ar[i+1];
	ar[i+1]=ar[high];
	ar[high]=temp;
	     
	return (i+1);
    
}

void quick_sort(vector<int> &v, int low, int high)
{
    if (low>=high)
	   return;
	   
	int p=partition(v,low,high);
	quick_sort(v,low, p-1);
	quick_sort(v,p,high);
}
int main()
{
    srand(time(0));
    int size;
    vector <int> arr, arr1;
    //cout<<"Advait Deochakke 20bCE1143\nEnter size of array/vector\n";
    for(int j=500; j<5001; j=j+500)
    {        
        size=j;
        long long u=0;
        for(int k=0; k<100; k++)
        {
            for(int i=0; i<size; i++)
            {
                int k=rand()%100;
                //cout<<k<<" ";
                arr.push_back(k);
                arr1.push_back(k);
                //cout<<"entered"<<i<<endl;
            }
            //cout<<endl;
            


            clock_t tStart = clock();
            auto start=high_resolution_clock::now();

            quick_sort(arr1, 0, size-1);

            auto end=high_resolution_clock::now();

            //for(int i=0; i<size; i++)
            {
                //cout<<arr1[i]<<" ";
            }

            auto duration = duration_cast<microseconds>(end-start).count();
            //cout<<"quick sort duration: "<<duration<<endl;

            //printf("Time taken: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
            u=u+duration;

        }
        cout<<"for input size "<<j<<": "<<u/100<<endl;

    }
   
            

    
    return 0;
}
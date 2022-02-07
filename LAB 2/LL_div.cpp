#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void display(list <int> l)
{
    list <int> :: iterator it;
    for(it=l.begin(); it!=l.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}


void multiply(list <int> l1, list <int> l2, list <int> l3)
{

    list <int> :: iterator it1;
    int l2size=l2.size();
    int carry=0;
    int val=0;
    int add=0;
    for(int i=0; i<l2size; i++)
    {
        int current=l2.back();
        //cout<<current<<endl;
        val=0;
        //cout<<i<<endl;
        for(it1=l1.begin(); it1!=l1.end(); it1++)
        {
            int t=*it1;
            val=val*10+(t*current);
            //cout<<t<<"*"<<current<<"="<<val;
            //cout<<"smal for\n"<<t;
            //cout<<t<<endl;
        }
        val=val+carry;
        l2.pop_back();
        add=val%10;
        carry=(val-add)/10;
        l3.push_back(add);
        //cout<<"big for\n";
    }
    //cout<<"start while\n";
    int f=val%10;
    val=(val-f)/10;
    while(val!=0)
    {
        l3.push_back(val%10);
        val=val/10;
        //cout<<"while\n";
    }
    //cout<<"display\n";
    l3.reverse();
    display(l3);
}


int main()
{
    list <int> n1, n2, n3;
    cout<<"Advait Deochakke 20BCE1143\n";
    cout<<"Enter no. of numbers in n1\n";
    int n1o, n2o;
    cin>>n1o;
    cout<<"Enter no. of numbers in n2\n";
    cin>>n2o;

    cout<<"Enter numbers in n1\n";
    for(int i=0; i<n1o; i++)
    {
        int k=0;
        cin>>k;
        n1.push_back(k);
    }

    cout<<"Enter numbers in n2\n";
    for(int i=0; i<n2o; i++)
    {
        int k=0;
        cin>>k;
        n2.push_back(k);
    }
    
    cout<<"List 1 is : "<<endl;
    display(n1);
    cout<<"List 2 is : "<<endl;
    display(n2);

    /*list <int> :: iterator it1;
    list <int> :: iterator it2;
    int carry;
    for(it2=n1.end(); it2!=n1.begin(); it2--)
    {
        cout<<*it2<<endl;
    }*/

    multiply(n1, n2, n3);


    cout<<"Test";
    return 0;
}
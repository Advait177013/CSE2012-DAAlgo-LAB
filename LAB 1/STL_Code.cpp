#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

void stlar()
{
    array<int, 5> stlar = {0, 1, 2, 3, 4};
    int size=stlar.size();
    for(int i=0; i<size; i++)
        cout<<stlar[i]<<" ";
    
    cout<<"\nElement at 3rd place - "<<stlar.at(2);
    cout<<"\nElement at 3rd index - "<<stlar.at(3);
    cout<<"\nEmpty or not-> "<<stlar.empty();
    cout<<"\nFirst Element-> "<<stlar.front();
    cout<<"\nLast Element-> "<<stlar.back();
}

void stlvector()
{
    vector<int> stlv1;
    vector<int> stlv2(5, 1);
    vector<int> last(stlv2);
  
    cout<<"print last"<<endl;
    for(int i:last) {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Capacity-> "<<stlv1.capacity()<<endl;

    stlv1.push_back(1);
    cout<<"Capacity-> "<<stlv1.capacity()<<endl;

    stlv1.push_back(2);
    cout<<"Capacity-> "<<stlv1.capacity()<<endl;

    stlv1.push_back(3);
    cout<<"Capacity-> "<<stlv1.capacity()<<endl;
    cout<<"Size-> "<<stlv1.size()<<endl;

    cout<<"Elemetn at 2nd Index" <<stlv1.at(2)<<endl;

    cout<<"front " <<stlv1.front()<<endl;
    cout<<"back " <<stlv1.back()<<endl;

    cout<<"before pop"<<endl;
    for(int i:stlv1) 
    {
        cout<<i<<" ";
    }
    cout<<endl;

    stlv1.pop_back();

    cout<<"after pop"<<endl;
    for(int i:stlv1) 
    {
        cout<<i<<" ";
    }

    cout<<"before clear size "<<stlv1.size()<<endl;
    stlv1.clear();
    cout<<"after clear size "<<stlv1.size()<<endl;
}

void stldq()
{
    deque<int> d;

    d.push_back(1);
    d.push_front(2);
    d.push_front(3);

    d.pop_front();
    cout<<endl;

    cout<<"Print First INdex Element-> "<<d.at(1)<<endl;

    cout<<"front "<<d.front()<<endl;
    cout<<"back "<<d.back()<<endl;

    cout<<"Empty or not" <<d.empty()<<endl;

    cout<<"before erase" <<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);
    cout<<"after erase" <<d.size()<<endl;
    for(int i:d)
    {
    cout<<i<<endl;
    }
}

void stllist()
{
    list<int> l;

    list<int> n(5,100);
    cout<<"Printing n"<<endl;
    for(int i:n) 
    {
        cout<<i<<" ";
    }
    cout<<endl;

    l.push_back(1);
    l.push_front(2);

    for(int i:l) 
    {
        cout<<i<<" ";
    }
    cout<<endl;
    l.erase(l.begin());
    cout<<"after erase"<<endl;

    for(int i:l) 
    {
        cout<<i<<" ";
    }

    cout<<"size of list"<<l.size()<<endl;
}

void stlstack()
{
    stack<string> s;

    s.push("Test");
    s.push("STL");
    s.push("CSE2012");

    cout<<"Top Element-> "<<s.top()<<endl;

    s.pop();
    cout<<"Top Element-> "<<s.top()<<endl;

    cout<<"size of stack"<<s.size()<<endl;

    cout<<"Empty or not "<<s.empty()<<endl;
}

void stlq()
{
    queue<string> q;

    q.push("Test");
    q.push("STL");
    q.push("CSE2012");

    cout<<"Size before pop" <<q.size()<<endl;
    
    cout<<"First Element "<<q.front()<<endl;
    q.pop();
    cout<<"First Element "<<q.front()<<endl;

    cout<<"Size after pop" <<q.size()<<endl;

}

void stlpq()
{
    //max heap
    priority_queue<int> maxi;

    //min - heap
    priority_queue<int,vector<int> , greater<int> > mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
    cout<<"size-> "<<maxi.size()<<endl;
    int n = maxi.size();
    for(int i=0;i<n;i++) 
    {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;

    mini.push(5);
    mini.push(1);
    mini.push(0);
    mini.push(4);
    mini.push(3);

    int m = mini.size();
    for(int i=0;i<m;i++) 
    {
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;

    cout<<"Empty -> "<<mini.empty()<<endl;
}

void stlset()
{
    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0);

    for(auto i : s) 
    {
        cout<<i<<endl;
    }
    cout<<endl;

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);

    for(auto i : s) 
    {
        cout<<i<<endl;
    }
    cout<<endl;
    cout<<"-5 is present or not -> "<<s.count(-5)<<endl;

    set<int>::iterator itr = s.find(5);

    for(auto it=itr;it!=s.end();it++) 
    {
    cout<<*it<<" ";
    }
    cout<<endl;
}

void stlmap()
{
    map<int,string> m;

    m[1]= "Test";
    m[13]="STL";
    m[2]="CSE2012";

    m.insert( {5,"Algorithm"});

    cout<<"before erase"<<endl; 
    for(auto i:m) 
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"finding -13 -> " <<m.count(-13)<<endl;

    // m.erase(13);
    cout<<"after erase"<<endl;
    for(auto i:m) 
    {
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl<<endl;

    auto it = m.find(5);

    for(auto i=it;i!=m.end();i++) 
    {
        cout<<(*i).first<<endl;
    }
}

void stlalgo()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"Finding 6-> "<<binary_search(v.begin(),v.end(),6)<<endl;

    cout<<"lower bound-> "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
    cout<<"Uppper bound-> "<<upper_bound(v.begin(),v.end(),4)-v.begin()<<endl;

    int a =3;
    int b =5;

    cout<<"max -> "<<max(a,b);

    cout<<"min -> "<<min(a,b);

    swap(a,b);
    cout<<endl<<"a-> "<<a<<endl;

    string abcd = "abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<"string-> "<<abcd<<endl;

    rotate(v.begin(),v.begin()+1,v.end());
    cout<<"after rotate"<<endl;
    for(int i:v)
    {
        cout<<i<<" ";
    }

    sort(v.begin(),v.end());
    cout<<"after sorting"<<endl;
    for(int i:v)
    {
        cout<<i<<" ";
    }
}

int main()
{
    cout<<"Advait Deochakke\n20BCE1143\n";
    cout<<"select a number from 0 to 9\n";
    cout<<"0 - array\n";
    cout<<"1 - vector\n";
    cout<<"2 - deque\n";
    cout<<"3 - list\n";
    cout<<"4 - stack\n";
    cout<<"5 - queue\n";
    cout<<"6 - priority queue\n";
    cout<<"7 - set\n";
    cout<<"8 - map\n";
    cout<<"9 - algo\n";

    int test;
    cin>>test;

    switch (test)
    {
    case 0:
        stlar();
        cout<<"\n";
        break;

    case 1:
        stlvector();
        cout<<"\n";
        break;
    
    case 2:
        stldq();
        cout<<"\n";
        break;

    case 3:
        stllist();
        cout<<"\n";
        break;

    case 4:
        stlstack();
        cout<<"\n";
        break;

    case 5:
        stlq();
        cout<<"\n";
        break;

    case 6:
        stlpq();
        cout<<"\n";
        break;

    case 7:
        stlset();
        cout<<"\n";
        break;

    case 8:
        stlmap();
        cout<<"\n";
        break;
    
    case 9:
        stlalgo();
        cout<<"\n";
        break;
    
    default:
        cout<<"Illegal value entered.\n";
        break;
    }
    
    return 0;
}
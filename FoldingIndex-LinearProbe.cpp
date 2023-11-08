// You are using GCC
#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int h[10];
    for(i=0;i<n;i++)
        h[i] =-1;
    for(i=0;i<n;i++)
    {
        int key;
        //pass key, and find mid square
        cin>>key;
        int index=key*key;
        while(index>=n)
        {
            index/=10; //discard from right
            if(index>=n)
            {
                int t;
                if(index>1000)
                    t=1000;
                else if(index>100)
                    t=100;
                else
                    t=10;
                // int t= floor(log10(index) +1)
                index%=t; //discard from left
            }
        }
        if(h[index]==-1) //no collision
        {
            h[index]= key;
        }
        else
        {
            int j=1;
            int hh=index;
            while(h[index]!=-1)
            {
                index=hh+j*j;
                if(index>n)
                {
                    index%=n;
                }
                j++;
            }
            h[index]=key;
        }
        cout<<"Index "<<index<<"th of key: "<<key<<endl;
    }
    for(i=0;i<n;i++)
    {
        cout<<h[i]<<" ";
    }
}
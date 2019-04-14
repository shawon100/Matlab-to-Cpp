#include <bits/stdc++.h>
using namespace std;

vector<double> movMeanFilter(vector<double>y , double window_size)
{
    vector<double>result;
    double ws,val,fws,ss;
    int first,last,win;
    int wSize;
    if(y.size()>window_size)
    {
         assert(y.size()>0);
         double s=0;
         int check;
         win=window_size-1;
         last=win/2;
         first=win-last;

         //result.push_back(val);

         for(int i=0;i<y.size()-(window_size-1);i++)
         {
             double sum=0;
             ws=i+window_size;
             for(int j=i;j<ws;j++)
             {
                 sum=sum+y[j];


             }


             val=sum/window_size;
                   //cout<<val<<endl;
              //cout<<y[i+1]<<endl;
              result.push_back(val);

         }
         int sz=result.size()-1;
         double lv=result[sz];
         double fv=result[0];
         wSize=window_size-1;
         int st2=y.size()-(window_size);
         int st1=(window_size)-3;

         for(int i=1;i<=last;i++)
         {
             ss=0.0;
             for(int j=st2+i;j<=y.size()-1;j++)
             {
                 ss=ss+y[j];
                 //cout<<y[j]<<" ";
             }
             //cout<<endl;

             val=ss/wSize;
             wSize--;
             result.push_back(val);
         }
         wSize=window_size-1;
         st1=st1+1;
         for(int i=1;i<=first;i++)
         {
             double ss=0.0;
             for(int j=st1;j>=0;j--)
             {
                 ss=ss+y[j];
                 //cout<<y[j]<<" ";
             }
             st1--;
             //cout<<endl;
             //result.push_back(fv);
             val=ss/wSize;
             wSize--;
             result.insert(result.begin(),val);
         }
         //sort(result.begin(),result.end());


    }
    else
    {
        cout<<"Change Window Size to smaller than array"<<endl;
    }
    return result;


}
int main()
{

    vector<double>yy={1892.77,1900.99,1902.77,1700.88,1600.88,1900.7,1600};
    //vector<double>yy={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vector<double>yz;
    yz=movMeanFilter(yy,5.0);
    for(int i=0;i<yz.size();i++)
    {
        cout<<yz[i]<<endl;
    }
    return 0;
}

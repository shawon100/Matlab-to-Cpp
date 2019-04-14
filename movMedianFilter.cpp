#include <bits/stdc++.h>
using namespace std;

vector<double> movMedianFilter(vector<double>nums,int k)
{
    multiset<double> mSet(nums.begin(),nums.begin()+k);
    vector<double> retVec;
    auto mid = next(mSet.begin(),k/2);
    for(int i = k;;i++)
    {
        retVec.push_back((double)((double)*mid +(double)*prev(mid,1-k%2))/2);
        if(i==nums.size())
        {
             return retVec;
        }

        mSet.insert(nums[i]);
        if(nums[i]<*mid)
            mid--;
        if(nums[i-k]<=*mid)
            mid++;
        mSet.erase(mSet.lower_bound(nums[i-k]));
    }


}

vector<double> movmedian(vector<double>y,vector<double>result,double window_size)
{
     vector<double>tail;
     vector<double>head;
     vector<double>temp;
     double val;
     int sz=result.size()-1;
     double lv=result[sz];
     double fv=result[0];
     double wSize=window_size-1;
     int st2=y.size()-(window_size);
     int st1=(window_size)-3;

     //number of tail elements
     int win=window_size-1;
     int last=win/2;
     //number of head elements
     int first=win-last;


     for(int i=1;i<=last;i++)
     {
         tail.clear();
         for(int j=st2+i;j<=y.size()-1;j++)
         {
             tail.push_back(y[j]);
             //cout<<y[j]<<" ";
         }

         temp=movMedianFilter(tail,(int)wSize);
         val=temp[0];
         wSize--;
         result.push_back(val);
     }

     wSize=window_size-1;
     st1=st1+1;
     for(int i=1;i<=first;i++)
     {
         head.clear();
         for(int j=st1;j>=0;j--)
         {
             head.push_back(y[j]);
             //cout<<y[j]<<" ";
         }
         st1--;
         temp=movMedianFilter(head,(int)wSize);
         val=temp[0];
         wSize--;
         result.insert(result.begin(),val);
     }

     return result;
}


int main()
{
    //vector<double>y{5, 15, 10, 20, 3};
    vector<double>y={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vector<double>result;
    vector<double>tempY;
    tempY=y;

    double window_size=5;
    result=movMedianFilter(y,(int)window_size);
    result=movmedian(tempY,result,window_size);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }

    return 0;
}

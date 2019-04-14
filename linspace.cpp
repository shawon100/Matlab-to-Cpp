#include <bits/stdc++.h>
using namespace std;


vector<double> linspace(double min, double max, int n)
{
    vector<double> result;
     // vector iterator
    int iterator = 0;

    for (int i = 0; i <= n-2; i++)
    {
         double temp = min + i*(max-min)/(floor((double)n) - 1);
         //cout<<min + i*(max-min)<<endl;
         //cout<<(floor((double)n) - 1)<<endl;
         //cout<<min + i*(max-min)/(floor((double)n) - 1)<<endl;
         result.insert(result.begin() + iterator, temp);
         iterator += 1;
    }

    //iterator += 1;

    result.insert(result.begin() + iterator, max);
    return result;

}

int main()
{
    double a=1,b=10,c=5;
    vector<double>r;
    r=linspace(a,b,c);
    for(int i=0;i<r.size();i++)
    {
        cout<<r[i]<<" ";
    }

    return 0;
}

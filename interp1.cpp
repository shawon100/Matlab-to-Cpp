#include <bits/stdc++.h>
using namespace std;

vector<double>interpolateYvector(vector<double>xData, vector<double>yData, vector<double>xx,bool extrapolate)
{
     vector<double> y_int;
      for ( double x:xx){

            int size = xData.size();

            int i = 0;                                                                  // find left end of interval for interpolation
            if ( x >= xData[size - 2] ){                                                 // special case: beyond right end
                i = size - 2;
            }
            else{
                while ( x > xData[i+1] ) i++;
            }
            double xL = xData[i], yL = yData[i], xR = xData[i+1], yR = yData[i+1];      // points on either side (unless beyond ends)
            if ( !extrapolate ){                                                         // if beyond ends of array and not extrapolating
                if ( x < xL ) yR = yL;
                if ( x > xR ) yL = yR;
            }

            double dydx = ( yR - yL ) / ( xR - xL );                                    // gradient

            y_int.push_back(yL + dydx * ( x - xL ));
            //cout << y_int.back() << endl;
            }

        return y_int;
}


int main()
{
    vector<double>ynew;
    vector<double>x{ 1.0000,4.5000,8.0000,11.5000,15.0000};
    vector<double>y{1.0000,5.7500,10.5000,15.2500,20.0000};
    vector<double>z{ 1.0000,3.2500,5.5000,7.7500,10.0000};
    ynew=interpolateYvector(x,y,z,true);
    for(int i=0;i<ynew.size();i++)
    {
        cout<<ynew[i]<<" ";
    }
    cout<<endl;
    return 0;

}




#include <bits/stdc++.h> 

double multiply(int num,int x)

{

  double ans=1;

  for(int i=1;i<=x;i++)

  {

    ans=ans*num;

  }

  return ans;

}

int NthRoot(int n, int m) {

  // Write your code here.

  double low=1,high=m,eps=1e-6;

  while((high-low)>eps)

  {

    double mid=(low+high)/2;

    double res=multiply(mid,n);

    if(res==m)

    {

      return mid;

    }

    else if(res<m)

    {

      low=mid;

    }

    else

    {

      high=mid;

    }

  }

  return -1;

 

}
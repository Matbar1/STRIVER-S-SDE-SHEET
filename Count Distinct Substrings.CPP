#include <bits/stdc++.h>

#include<unordered_map>

int countDistinctSubstrings(string &s)

{

    unordered_map<string,int> mp;

    int n=s.length();

    for(int i=0;i<n;i++){

        string str="";

        for (int j = i; j <n; j++) {

          str = str + s[j];

        //   cout<<str.size()<<endl;

          mp[str]++;

        }

    }

    return mp.size()+1;

}
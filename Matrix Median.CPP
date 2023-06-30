int Solution::findMedian(vector<vector<int> > &A) {
    int l = 0, r = INT_MAX;
    int mid, req = (int)A.size() * (int)A[0].size();
    assert(A.size()*A[0].size()<=1000000);
    assert(req % 2);
    while(r - l > 1){
        mid = l + (r - l) / 2;
        int cnt = 0;
        for(auto &i: A){ 
            //using upper bound in a sorted array to count number of elements smaller than mid
            int p = upper_bound(i.begin(), i.end(), mid) - i.begin();
            cnt += p;
        }
        if(cnt >= (req/2 +1)) r = mid;
        else l = mid;
    }   
    return r;
}


// int Solution::findMedian(vector<vector<int> > &A) {

    
//         vector<int> v;
//         for(int i=0;i<A.size();i++)
//         {
//             for(int j=0;j<A[0].size();j++)
//             {
//                 v.push_back(A[i][j]);
//             }
//         }
        
//         sort(v.begin(), v.end());
//         return v[v.size()/2];
// }

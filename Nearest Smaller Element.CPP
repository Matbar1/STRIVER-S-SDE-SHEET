/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* prevSmaller(int* A, int n1, int *len1) {
    *len1 = n1;
    int i,j,arr[n1];
    int stac[n1];
    int idx = 0;
    arr[0] = -1;
    for(i=1;i<n1;i++)
    {
        j = i - 1;
        if(A[i] > A[j])
        {
            arr[i] = A[j];
            if(idx > 0)
            {
                idx --;
                while(stac[idx] > A[j] && idx > 0)
                {
                    idx--;
                }
                idx++;
            }
            stac[idx] = A[j];
            idx++;
        }
        else
        {
            if(idx==0)
            {
                arr[i] = -1;
                stac[idx] = A[j];
                idx++;
            }
            else
            {
                idx--;
                while(stac[idx]>=A[i] && idx >= 0)
                {
                    idx--;
                }
                if(idx<0)
                {
                    arr[i] = -1;
                }
                else
                {
                    arr[i] = stac[idx];
                }
                idx++;
                stac[idx] = A[j];
                idx++;
            }
        }
    }
    for(i=0;i<n1;i++)
    {
        A[i] = arr[i];
    }
    return A;
}


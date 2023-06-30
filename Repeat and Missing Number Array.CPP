void finalin(int arr[], int n, int *x, int *y)
{
  int xor1; 
  int set_bit_no; 
  int i;
  *x = 0;
  *y = 0;
 
  xor1 = arr[0];
 
  
  for(i = 1; i < n; i++)
     xor1 = xor1^arr[i];
 
 
  for(i = 1; i <= n; i++)
     xor1 = xor1^i;
 
  
  set_bit_no = xor1 & ~(xor1-1);
 
  
  for(i = 0; i < n; i++)
  {
    if(arr[i] & set_bit_no)
     *x = *x ^ arr[i]; 
    else
     *y = *y ^ arr[i]; 
  }
  for(i = 1; i <= n; i++)
  {
    if(i & set_bit_no)
     *x = *x ^ i; 
    else
     *y = *y ^ i; 
  }
 for(i = 0; i < n; i++)
  {
    if(*y==arr[i]) {
        return;
    } 
  }
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
 
}

int* repeatedNumber(const int* A, int n1, int *length_of_array) {
	// SAMPLE CODE
        
          *length_of_array = 2; // length of result array
          int *result = (int *) malloc(*length_of_array * sizeof(int));
          // DO STUFF HERE
          int *x=(int*)malloc(sizeof(int));
          int *y=(int*)malloc(sizeof(int));
          finalin(A,n1,x,y);
          result[0]=*y;
          result[1]=*x;
          return result;
         
}
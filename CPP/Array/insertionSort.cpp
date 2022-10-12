
#include<iostream>
using namespace std; 

void inSort(int a[], int n)
{  
    int i,j, k;  
    for (i = 1; i < n; i++) 
    {  
        k = a[i];  
        j = i - 1;  
        
        while (j >= 0 && a[j] > k) 
        {  
            a[j + 1] = a[j];  
            j = j - 1;  
        }  
        a[j + 1] = k;  
    }  
}  

void print(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << a[i] << " ";  
    cout << endl; 
}  
  

int main()  
{  
    int a[] = { 5,2,8,7,3,5,4,1 };  
    int n = sizeof(a) / sizeof(a[0]);  
    inSort(a, n);  
    print(a, n);  
    return 0;  
}  
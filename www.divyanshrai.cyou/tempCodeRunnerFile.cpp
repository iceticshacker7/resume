#include <stdio.h>
void counting_sort(int A[], int k, int n)
{
    int i, j;
    int B[10], C[10]={0};
    //for (i = 0; i <= k; i++)
        //C[i] = 0;
    for (j = 0; j < n; j++) // n = 5    A{5,2,7,9,1}
        C[A[j]] = C[A[j]] + 1; // C -> count of data 

    for (i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1]; // C[2] = C[2] + C[1] 

    for (j = n-1; j >= 0; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    printf("The Sorted array is : ");
    for (i = 1; i <= n; i++)
        printf("%d ", B[i]);
}

int main()
{
    int n=5, k = 9, A[5]={5,2,7,9,1};
    counting_sort(A, k, n);
    printf("\n");
    return 0;
}
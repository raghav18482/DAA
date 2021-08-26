#include<stdio.h>

void quickSort(int arr[], int low, int heigh)
{
    if(low < heigh)
    {
        int pIndex = partition(arr, low, heigh);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex+1, heigh);
    }
}

int partition(int arr[], int low, int heigh)
{
    int pIndex = low;
    int pivot = arr[heigh];
    int i;
    for(i = low; i < heigh; i++)
    {
        if(arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }
    int t = arr[heigh];
    arr[heigh] = arr[pIndex];
    arr[pIndex] = t;
    return pIndex;
}




int main()
{
    int n,i;

    printf("Enter Array Size\n");
    scanf("%d",&n);

    int arr[n];

    printf("Enter Array Elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    quickSort(arr,0,n-1);

    printf("After the QuickSort\n");

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;
}


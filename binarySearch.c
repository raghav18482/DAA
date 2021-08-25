#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int bottom, top, mid, n;
void bubble_sort(int a[]);
int binary_search(int a[], int l, int r, int key);
void main()
{
    int i, a[50], key;
    int result;
    double clk;
    clock_t starttime, endtime;
    printf("Enter the number of products\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        a[i] = rand() % 1000;
    printf("\nThe Product IDs are: \n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    bubble_sort(a);
    printf("\n\nSorted Product IDs are: \n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n\nEnter the ISBN to be searched: \n");
    scanf("%d", &key);
    starttime = clock();
    result = binary_search(a,0,n-1,key);
    endtime = clock();
    if (result == 1)
    {
        printf("\nProduct found!!\n");
        printf("\n\n Product ID %d found in position: %d\n", key, mid + 1);
    }
    else
        printf("\n Out of stock\nproduct ID %d not found\n", key);
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nTime taken for searching %f seconds\n", clk);
}
int binary_search(int a[], int l, int r, int key)
{
    if(r>=l)
    {
        int mid = (l +(r-l))/2;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return binary_search(a,l, mid-1, key);
        else
            return binary_search(a,mid+1, r, key);
    }
}
void bubble_sort(int a[])
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
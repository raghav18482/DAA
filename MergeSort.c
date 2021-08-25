#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int a[55];
int count=0,c=0;
void merge(int, int, int);
void merge_sort(int low, int high)
{
    int mid;
    c++;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
    
}
void merge(int low, int mid, int high)
{
    int h, i, j, b[55], k;
    h = low;
    i = low;
    j = mid + 1;
    while ((h <= mid) && (j <= high))   
    {
        if (a[h] <= a[j])
        {
            b[i] = a[h];
            h++;
        }
        else
        {
            b[i] = a[j];
            j++;
        }
        i++;
        count++;
        
    }
    if (h > mid)
    {
        for (k = j; k <= high; k++)
        {
            
            b[i] = a[k];
            i++;
        }
    }
    else
    {
        for (k = h; k <= mid; k++)
        {
            
            b[i] = a[k];
            i++;
        }
    }
    for (k = low; k <= high; k++)
        a[k] = b[k];
}
int main()
{
    int n, i;
    double clk;
    
    clock_t starttime, endtime;
    printf("MERGE SORT\n");
    printf("Enter the number of employee records:\n ");
    scanf("%d", &n);
    // char name[n][30];
    // printf("Please enter %d names \n",n);
    // for(int i=0;i<n;i++){
    //     scanf("%s",&name[i]);
    // }
    for (i = 0; i < n; i++)
        // scanf("%d",&a[i]);
        a[i] = rand() % 100; //to get 2 digit number
    printf("Their respective Employee IDs are:\n");
    for (i = 0; i < n; i++){
        // printf("%s\t",name[i]);
        printf("%d\n", a[i]);
    }
    
    starttime = clock();
    merge_sort(0, n - 1);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nTheir sorted Employee IDs are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\ntotal no of comparision is %d", count);
    printf("\ntotal no of recursive call is %d", c);
    printf("\nThe run time is %f seconds. \n", clk);
}
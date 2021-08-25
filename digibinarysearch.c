
#include <stdio.h>
#include <time.h>
int bin_ser(int A[], int n, int key)
{
    int l, r, m = 0;
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (key == A[m])
            return m;
        else if (key < A[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}
int main()
{
    int i, n, key, result;
    clock_t starttime, endtime;
    double clk;
    printf("\t\tDIGISHOP\n");
    printf("Enter the value for n\n");
    scanf("%d", &n);
    int prod_id[n];
    printf("Enter the product ID to be searched\n");
    scanf("%d", &key);
    printf("Enter the product IDs of available products\n");
    for (i = 0; i < n; i++)
        scanf("%d", &prod_id[i]);
    starttime = clock();
    result = bin_ser(prod_id, n, key);
    endtime = clock();
    if (result == -1)
        printf("Product not available\n");
    else
        printf("Product with product ID %d found at position %d", key, result);
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("Time taken =%f\n", clk);
}
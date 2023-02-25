#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int b[high + 1];
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= high)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    if (j > mid)
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (k = low; k <= high; k++)
    {
        a[k] = b[k];
    }
}

void Msort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        Msort(a, low, mid);
        Msort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    Msort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
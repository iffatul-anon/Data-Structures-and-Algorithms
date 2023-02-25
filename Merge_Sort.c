#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low;     // left array index
    int j = mid + 1; // right array index
    int k = low;     // merged array index
    int b[high + 1];
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= high)
    {
        b[k++] = a[j++];
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
        int mid = low + (high - low) / 2;
        Msort(a, low, mid);       // left subarray
        Msort(a, mid + 1, high);  // right subarray
        merge(a, low, mid, high); // merged array
    }
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
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
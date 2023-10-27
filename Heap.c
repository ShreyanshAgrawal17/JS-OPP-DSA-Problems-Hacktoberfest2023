#include <stdio.h>
#include <stdlib.h>

void insert(int A[], int n)
{
    int temp;
    int i = 0;
    i = n;
    temp = A[n];
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

void create(int A[], int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        insert(A, i);
    }
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int delete(int A[], int n)
{
    int x, i, j;
    x = A[1];
    A[1] = A[n];
    A[n] = x;
    i = 1;
    j = 2 * i;
    while (j < n - 1)
    {
        if (A[j + 1] > A[j])
        {
            j = j + 1;
        }
        if (A[i] < A[j])
        {
            swap(&A[i], &A[j]);
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
    A[n] = x;
    return x;
}

int check(int A[], int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (A[i] > A[2 * i] && A[i] > A[2 * i + 1])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void sort(int A[], int n)
{
    int i;
    for (i = n; i >= 2; i--)
    {
        int x = delete (A, i);
        A[i] = x;
    }
}

void heapify(int A[], int n, int i) // find max of node and its 2 children
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l < n && A[l] > A[largest])
        largest = l;

    if (r < n && A[r] > A[largest])
        largest = r;

    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        heapify(A, n, largest);
    }
}

int main()
{
    int *A;
    int i, n;
    int choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("\n");
    A = malloc((n + 1) * sizeof(int));
    while (1)
    {
        printf("******MAIN MENU******");
        printf("\n1.Insert");
        printf("\n2.Display");
        printf("\n3.Delete");
        printf("\n4.Check max heap or not");
        printf("\n5.Heap Sort");
        printf("\n6.Heapify");
        printf("\n7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (i = 1; i <= n; i++)
            {
                printf("Enter %dth element: ", i);
                scanf("%d", &A[i]);
            }
            create(A, n);
            break;
        case 2:
            for (i = 1; i <= n; i++)
            {
                printf("%d ", A[i]);
            }
            printf("\n");
            break;
        case 3:
            delete (A, n);
            n = n - 1;
            break;
        case 4:
            if (check(A, n))
            {
                printf("Max Heap\n");
            }
            else
            {
                printf("Not a max heap\n");
            }
            break;
        case 5:
            sort(A, n);
            for (i = 1; i <= n; i++)
            {
                printf("%d ", A[i]);
            }
            printf("\n");
            break;
        case 6:
            for (i = 1; i <= n; i++)
            {
                printf("Enter %dth element: ", i);
                scanf("%d", &A[i]);
            }
            for (i = n / 2 - 1; i >= 0; i--)
            {
                heapify(A, n, i);
            }
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("Wrong choice,enter different choice\n");
            break;
        }
    }
    return 0;
}

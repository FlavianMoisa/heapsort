#include <iostream>
using namespace std;

int max_heapify(int *a, int i, int n)
{
    int fiu, tata;
    tata = a[fiu];
    fiu= 2*i;
    while (fiu <= n)
    {
        if (fiu < n && a[fiu+1] > a[fiu])
            fiu = fiu+1;
        if (tata> a[fiu])
            break;
        else if (tata <= a[fiu])
        {
            a[fiu/2] = a[fiu];
            fiu = 2*fiu;
        }
    }
    a[fiu/2] = tata;
}
int heapsort(int *a, int n)
{
    int i, tata;
    for (i = n; i >= 2; i--)
    {
        tata = a[i];
        a[i] = a[1];
        a[1] = tata;
        max_heapify(a, 1, i - 1);
    }
}
int build_maxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}
int main()
{
    int n, i, x;
    cout<<" nr.de elemente ";
    cin>>n;
    int a[20];
    for (i = 1; i <= n; i++)
    {
        cout<<"introdu elementul "<<(i)<<endl;
        cin>>a[i];
    }
    build_maxheap(a,n);
    heapsort(a, n);
    cout<<"elemente sortate\n";
    for (i = 1; i <= n; i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}


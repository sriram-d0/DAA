#include <stdio.h>
void
swap (int a[], int i, int j)
{
  int temp;
  temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

int partition (int a[], int l, int h)
{
  int temp, piv, i, j;
  piv = a[l];
  i = l;
  j = h + 1;
  do
    {
      do
	{
	  i++;
	}
      while (a[i] < piv && i < j);
      do
	{
	  j--;
	}
      while (a[j] > piv);
      if (i < j)
	swap (a, i, j);
    }
  while (i < j);
  swap (a, l, j);
  return j;
}

void quicksort (int a[], int l, int h)
{
  int j;
  if (l < h)
    {
      j = partition (a, l, h);
      quicksort (a, l, j - 1);
      quicksort (a, j + 1, h);
    }
}

int ksmall(int a[], int l, int h, int k) {
  int i, j;
  if (l <= h) {
    j = partition(a, l, h);
    if (j == k)
      return a[j];
    else if (k < j)
      return ksmall(a, l, j - 1, k);
    else
      return ksmall(a, j + 1, h, k); 
}
}
int main ()
{
  int ks,k, n, a[20], i;
  printf ("Enter range of array : ");
  scanf ("%d", &n);
  printf ("Enter Elements into array\n");
  for (i = 0; i < n; i++)
    {
      printf ("Enter element %d: ", i + 1);
      scanf ("%d", &a[i]);
    }
  printf ("Before Sorting\n");
  for (i = 0; i < n; i++)
    printf ("a[%d] : %d  ", i, a[i]);
  quicksort (a, 0, n - 1);
  printf ("\nAfter Sorting\n");
  for (i = 0; i < n; i++)
    printf ("a[%d] : %d  ", i, a[i]);   
    printf("\nEnter K(0-%d) ",n-1);
    scanf("%d",&k);
  ks = ksmall (a, 0, n - 1,k);
  printf("%d is %d the smallest element  ",ks,k);
}



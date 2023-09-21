#include<stdio.h>
#include<stdlib.h>
int p[100], w[100], jo[100], n, c = 0;
float pw[100], x[100];
void knapsack (int m, int n)
{
  float t1, profit = 0;
  int i, j, t3, u;
  for (i = 0; i < n; i++)
    {
      pw[i] = (float) p[i] / w[i];
    }
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	{
	  if (pw[i] > pw[j])
	    {
	      t1 = pw[i];
	      pw[i] = pw[j];
	      pw[j] = t1;
	      t3 = p[i];
	      p[i] = p[j];
	      p[j] = t3;
	      t3 = w[i];
	      w[i] = w[j];
	      w[j] = t3;
	      t3 = jo[i];
	      jo[i] = jo[j];
	      jo[j] = t3;
	    }
	}
    }
  for (i = 0; i < n; i++)
    {
      x[i] = 0;
      u = m;
      for (j = 0; j < n; j++)
	{
	  if (w[j] > u)
	    break;
	  x[j] = 1;
	  u = u - w[j];
	}
      if (j < n)
	{
	  x[j] = (float) u / w[j];
	  u = u - w[i];
	}
  }
  printf("Sequence : ");
  for (i = 0; i < n; i++)
    {
      profit += p[i] * x[i];
      printf ("%d  ", jo[i]);
    }
  printf ("\nProfit=%f\n", profit);
}

int main ()
{
  int i, j, n, m, u;
  system ("clear");
  printf ("Enter no of objects(n): ");
  scanf ("%d", &n);
  printf("Enter profits & weights\n");
  for (i = 0; i < n; i++)
    {
      printf ("Enter P%d: ", i + 1);
      scanf ("%d", &p[i]);
      printf ("Enter W%d: ", i + 1);
      scanf ("%d", &w[i]);
      jo[i] = i + 1;
    }
  printf ("Enter Knapsack Capacity(m):");
  scanf ("%d", &m);
  knapsack (m, n);
}

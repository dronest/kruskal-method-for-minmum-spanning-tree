#include<stdio.h>
#define inf 99999

void  initialize(int* ptr,int n)
{
  int i,j;
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  *(ptr+i*n+j)=0;
	}
    }
}

int minimum(int a,int b)
{
  if(a<b)
    return(a);
  else
    return(b);
}

void print(int *ptr,int n)
{
  int i,j;
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  printf("%d \t",*(ptr+i*n+j));
	}
      printf("\n");
    }  
}

void kruskals(int* ptr_ar,int n)
{
  int i,j,i_temp,j_temp,k;
  int min_val,val,v,max;
  int ord[n];
  for(i=0;i<n;i++)
    {
      ord[i]=i;
      //printf("%d \t",ord[i]);
      }
  //printf("\n");
  for(k=0;k<n-1;k++)
    {
      min_val=inf;
      for(i=0;i<n;i++)
	{
	  for(j=0;j<n;j++)
	    {
	      val=*(ptr_ar+n*i+j);
	      if(val<min_val && val>0 && ord[i]!=ord[j])
		{
		  min_val=val;
		  i_temp=i;
		  j_temp=j;
		}
	    }
	}
      v=minimum(ord[i_temp],ord[j_temp]);
      max=ord[i_temp]+ord[j_temp]-v;
      for(i=0;i<n;i++)
	{
	  if(ord[i]==max)
	    ord[i]=v;
	}
      printf("%d \t %d",i_temp+1,j_temp+1);
      /*for(i=0;i<n;i++)
	{
	  printf("%d \t",ord[i]);
	  } */  
      printf("\n");
    } 
}

int main()
{
  int i,j,n;
  printf("enter the number of vertex: ");
  scanf("%d",&n);
  int ar[n][n];
  printf("enter the weight values \n");
  initialize(&(ar[0][0]),n);
  /*print(&(ar[0][0]),n);
  printf("%p \n",&ar[0]);
  printf("%p \n",&ar[0][0]);*/
  for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
	{
	  printf("enter value of weight between %d and %d:",i+1,j+1);
	  scanf("%d",&ar[i][j]);
	  ar[j][i]=ar[i][j];
	}
    }
  printf("entered matrix \n");
  print(&(ar[0][0]),n);
  printf("connections \n");
  kruskals(&(ar[0][0]),n);
  int weights[n][n];
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  weights[i][j]=ar[i][j];
	}
    }
  return(0);
}

#include<stdio.h>
#define size 10

struct sparse
{
   int nrows;
   int ncols;
   int nz;
   int row[size];
   int col[size];
   int value[size];
};
typedef struct sparse Sparse;

//Convert normal matrix into sparse  
void convert_to_Sparse(Sparse* x)
{
   int i,j,a,m,n;
   printf("Enter number of rows and column of matrix\n");
   scanf("%d%d",&x->nrows,&x->ncols);
   printf("Enter elements of matrix (row by row):\n");
   m=0;
   for(i=0;i<x->nrows;i++)
   {
      for(j=0;j<x->ncols;j++)
      {
         scanf("%d",&a);
         if(a!=0)
         {
            x->row[m]=i;
            x->col[m]=j;
            x->value[m]=a;
            m++;
         }
      }
   }
   x->nz=m;
}

void Display_Sparse(Sparse e)
{  int i;
   printf("Row\tcol\tvalue\n");
   for(i = 0; i< e.nz; i++)
   { 
         printf("%d\t%d\t%d\n", e.row[i],e.col[i],e.value[i]);   
   }
}

Sparse Transpose(Sparse a)
{
   Sparse b;
   b.ncols=a.nrows;
   b.nrows=a.ncols;
   b.nz=a.nz;
   int c[a.ncols];
   int t[a.ncols];
   int i;
   for(i=0;i<a.nz;i++)
   {
      c[i]=0;
   }
   for(i=0;i<a.nz;i++)
   {
      c[a.col[i]]=c[a.col[i]]+1;
   }
   t[0]=0;
   for(i=1;i<a.ncols;i++)
   {
      t[i]=t[i-1]+c[i-1];
   }
   for(i=0;i<a.nz;i++)
   {
      b.row[t[a.col[i]]]=a.col[i];
      b.col[t[a.col[i]]]=a.row[i];
      b.value[t[a.col[i]]]=a.value[i];
      t[a.col[i]]=t[a.col[i]]+1;
   }
   return b;
}

Sparse Multiply(Sparse a, Sparse b)
{
   Sparse c;
   if(a.nrows!=b.ncols)
   {
      c.nz=0;
      return c;
   }
   c.nrows=a.nrows;
   c.ncols=b.ncols;
   b=Transpose(b);
   int k=0,i=0,j,sum=0;
   while(i<a.nz)
   {
      int rn = a.row[i];
      j=0;
      while(j<b.nz)
      {
         int cn = b.row[j];
         
         int sa = i;
         int sb = j;
         sum = 0; 
         while(sa<a.nz && a.row[sa]==rn && b.row[sb]==cn)
         {
            if(a.col[sa]<b.col[sb])
            {
               sa++;
            }
            else if(a.col[sa]>b.col[sb])
            {
               sb++;
            }
            else
            {
               sum += a.value[sa] * b.value[sb];
               sa++;
               sb++;
            }
         }
         
         if(sum!=0)
         {
            c.row[k] = rn;
            c.col[k] = cn;
            c.value[k] = sum;
            k++;
         }
         while(j<b.nz && b.row[j]==cn)
         {
            j++;
         }
      }
      while(i<a.nz && a.row[i]==rn)
      {
            i++;
      }
   }
   c.nz = k;
   return c;

}

int main()
{
   Sparse a,b,c;
   printf("For 1st matrix:\n");
   convert_to_Sparse(&a);
   printf("For 2nd matrix:\n");
   convert_to_Sparse(&b);
   c=Multiply(a,b);
   printf("Matrix A :\n");
   Display_Sparse(a);
   printf("Matrix B :\n");
   Display_Sparse(b);
   printf("Product of A and B :\n");
   Display_Sparse(c);
   return 0;
}
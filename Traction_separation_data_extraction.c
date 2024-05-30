// Author: Praveenkumar Hiremath (TU Bergakademie Freiberg, Germany)
#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
#include<string.h> 
#include<float.h> 


int main()
{

int n=100;
//printf("enter number of values\n");
//scanf("%d",&n);
FILE *out=fopen("OUT","w");
FILE *input;
//input=fopen("new.txt","r");
input=fopen("TS_Law.OUT","r");
double dis[n],eps[n],lx[n],ly[n],lz[n],vol[n],delE[n],del_eps[n],temp[n],stress[n],E[n],N_dis[n]; 
int i;
double a[n],b[n];

/*for(i=0;i<n;i++)
 {
 
 
  fscanf(input, "%lf \t %lf \n",&dis[i],&eps[i]);                           
printf("dis[%lf]= %lf \t eps[%lf]= %lf \n",i,dis[i],i,eps[i]);
  }
*/
for(i=0;i<n;i++)
 {
  //fscanf(input, "%lf \t %lf \n",&a[i],&b[i]);           
  fscanf(input, "\t %lf \t %lf \t %lf \t %lf \t %lf \t %lf\n",&dis[i],&eps[i],&E[i],&lx[i],&ly[i],&lz[i]);                                            
printf("a= %lf\t b= %lf c= %lf\t d= %lf\t e= %lf\t f= %lf\n",dis[i],eps[i],E[i],lx[i],ly[i],lz[i]);
}

for(i=0;i<n;i++)
{
vol[i]=lx[i+1]*ly[i+1]*lz[i+1];
delE[i]=E[i+1]-E[i];
del_eps[i]=eps[i+1]-eps[i];
temp[i]=delE[i]/del_eps[i];
stress[i]=temp[i]/vol[i];
N_dis[i]=dis[i+1]-dis[i];
}

for(i=0;i<n;i++)
{

fprintf(out,"%lf \t %lf \n",dis[i],stress[i]);
//printf("E[%lf]= %lf \n",i,E[i]);

}

return 0;
}

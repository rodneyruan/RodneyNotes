```
Description

Problems involving the computation of exact values of very large magnitude and precision are common. For example, the computation of the national debt is a taxing experience for many computer systems.

This problem requires that you write a program to compute the exact value of Rn where R is a real number ( 0.0 < R < 99.999 ) and n is an integer such that 0 < n <= 25.
Input

The input will consist of a set of pairs of values for R and n. The R value will occupy columns 1 through 6, and the n value will be in columns 8 and 9.
Output

The output will consist of one line for each line of input giving the exact value of R^n. Leading zeros should be suppressed in the output. Insignificant trailing zeros must not be printed. Don't print the decimal point if the result is an integer.
Sample Input

95.123 12
0.4321 20
5.1234 15
6.7592  9
98.999 10
1.0100 12
Sample Output

548815620517731830194541.899025343415715973535967221869852721
.00000005148554641076956121994511276767154838481760200726351203835429763013462401
43992025569.928573701266488041146654993318703707511666295476720493953024
29448126.764121021618164430206909037173276672
90429072743629540498.107596019456651774561044010001
1.126825030131969720661201
```
```
#include<stdio.h>
#include<string.h>

int result[9999];
int len_result;

int point_result;//how many digits on the right side of the point?
void multiply(int* a, int len_a, int point_a,int*b,int len_b, int point_b)
{
   int i,j,k,temp,carry,move;
   int each_round[9999];


   for(i=len_b-1;i>=0;i--)
   {
      k =0;
      carry =0;
      for(j=len_a -1;j>=0;j--)
      {
         temp = a[j]*a[i]+carry;
         each_round[k++] = temp%10;
         carry = temp/10;

         if( (j==0) && (carry!=0) )
         {
            each_round[k++] = carry;
         }
      }
      for(j=0;j<k;j++)

      move= len_b-1 -i;

      carry =0;
      for(j=0;j<k;j++)
      {
         temp = each_round[j]+result[j+move]+carry;
         result[j+move]=temp%10;
         len_result = j+move+1;

         carry = temp/10;

         if( (j==k-1) && ( carry != 0))
         {
            result[j+move+1]=carry;
            len_result =j+move+2;
         }
      }
   }

   point_result =  point_a+point_b;
   for(i=0;i<len_result/2;i++)
   {
           temp = result[i];
           result[i] =result[len_result-i-1];
           result[len_result-i -1] = temp;
   }
}

int main()
{
   char s[10];
   int n=0;
   int r[10];
   int i=0,point=0;
   int len=0;
   while(scanf("%s%d",s,&n)!=EOF)
   {
      i=0;
      memset(r,0,sizeof(r));
      len=0;
      point = 0;

      while(s[i]!='\0')
      {
         if( s[i] == '.')
         {
            point = 0;
         //   printf("point = %d\n",point);
         }
         else if( ( s[i]>='0') && ( s[i]<='9') )
         {
            r[len] = s[i] - '0' ;
           // printf("adding %d ",r[number_of_digits]);
            len++;
            point++;
         }
         i++;
      }

              for(i=0;i<len;i++)
              {
                   result[i] = r[i];
              }
              len_result = len;
              point_result = point;
      for(i=0;i<n-1;i++)
      {
               multiply(r,len,point,r,len,point);
      }

      for(i=0;i<len_result;i++)
      {
              printf("%d",result[i]);
              if(i== len_result-point_result-1)
                      printf(".");
      }
      printf("\n");
   }
   return 0;
}
```

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
0.0
0
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

int result[999];
int len_result;

int point_result;//how many digits on the right side of the point?
void multiply(int* a, int len_a, int point_a,int*b,int len_b, int point_b)
{
   int i,j,k,temp,carry,move,len_sum=0;
   int each_round[999]={0};
   int sum[999]={0};

   for(i=len_b-1;i>=0;i--)
   {
      memset(each_round,0,sizeof(each_round));
      k =0;
      carry =0;
      for(j=len_a -1;j>=0;j--)
      {
         temp = a[j]*b[i]+carry;
         each_round[k++] = temp%10;
//       printf("each_round[%d]=%d ",k-1,each_round[k-1]);
         carry = temp/10;

         if( (j==0) && (carry!=0) )
         {
            each_round[k++] = carry;
         }
      }

      move= len_b-1 -i;

      carry =0;
      for(j=0;j<k;j++)
      {
         temp = each_round[j]+sum[j+move]+carry;
//       printf("#%d, for %d, each_round[j] =%d, sum[j+move] = %d",move,j,each_round[j],sum[j+move]);
         sum[j+move]=temp%10;
         len_sum = j+move+1;

         /*Debug*/
//        printf("#%d, for %d, Moving %d to %d, \n",move, j, sum[j+move],j+move);
         carry = temp/10;

         if( (j==k-1) && ( carry != 0))
         {
            sum[j+move+1]=carry;
            len_sum =j+move+2;
         }
      }
   }

   for(i=0;i<len_sum;i++)
   {
           result[i] = sum[len_sum-1-i];
   }

   point_result =  point_a+point_b;
   len_result = len_sum;
}

int main()
{
   char s[10];
   int n=0;
   int r[10];
   int i=0,j=0,point=0,point_found=0;
   int len=0;
   while(scanf("%s%d",s,&n)!=EOF)
   {
      i=0;
      memset(r,0,sizeof(r));
      len=0;
      point = 0;
      point_found =0;
      while(s[i]!='\0')
      {
         if( s[i] == '.')
         {
            point_found = 1;
         //   printf("point = %d\n",point);
         }
         else if( ( s[i]>='0') && ( s[i]<='9') )
         {
            r[len] = s[i] - '0' ;
           // printf("adding %d ",r[number_of_digits]);
            len++;
            if(point_found) point++;
         }
         i++;
      }

 //printf("len %d, point %d",len,point);

   for(i=len-1;i>=0;i--)
   {
         if(r[i] !=0)
                 break;
         if( i< (len - point))
                        break;
      //   printf("Remvoing tailing 0 @ %d ", i);
         len --;
         point --;

   }


              for(i=0;i<len;i++)
              {
                   result[i] = r[i];
              }
              len_result = len;
              point_result = point;
      for(i=0;i<n-1;i++)
      {
               multiply(result,len_result,point_result,r,len,point);
               /*printf("\n After One round \n");
               for(j=0;j<len_result ;j++)
               {
                       printf("%d",result[j]);
               }
               printf("\n");*/
      }

   //   printf(": len %d",len_result);
      for(i=0;i<len_result;i++)
      {
              if( (len_result ==1) && i ==0)
                      printf("%d",result[i]);
              else if ( !( (i==0) && (result[i] == 0 )))
              {
                  printf("%d",result[i]);
              }
              if( (point_result!= 0) && (i== len_result-point_result-1) )
                      printf(".");
      }
      printf("\n");
   }
   return 0;
}    
                                           
```

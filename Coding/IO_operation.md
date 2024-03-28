## Read IO from file
```
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
```
### C++ IO
```
#include <iostream>        
using namespace std;
int main()
{
   // s is a string, n is an integer.
   while(cin>>s>>n)
   {
      ...
   }
}
```
###  Read in C
```
while(scanf("%s%d",s,&n)==2) //to  see if the scanf read in as many items as you want
/*while(scanf(%s%d",s,&n)!=EOF) //this also work    */

{

...

}
```

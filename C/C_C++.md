### Writ a program to tell big Endian or little endian.
```
Little endian 也叫主机序， 低字节保存的是低字节 
联合体union的存放顺序是所有成员都从低地址开始存放， 
联合体所分配内存空间的大小为联合体中所占字节最大成员的大小。 

在ARM体系中，每个字单元包含4个字节单元或者两个半字单元。在字单元中，4个字节哪一个是高位字节，哪一个是低位字节则有两种不同的格式：big-endian和little-endian格式。在小端模式中，低位字节放在低地址，高位字节放在高地址；在大端模式中，低位字节放在高地址，高位字节放在低地址。 
在C语言中，不同于结构体，共用体（联合体）中的几种不同类型的变量存放在同一段内存单元中。利用这一特点，可以用联合体变量判断ARM或x86环境下，存储系统是是大端还是小端模式。 

#include "stdio.h" 
int main() 
{ 
  union w 
{ 
  int a;  //4 bytes 
  char b; //1 byte 
} c; 
  c.a=1; 
  if (c.b==1) 
  printf("It is Little_endian!/n");
  else 
  printf("It is Big_endian!/n"); 
  return 1; 
} 

说明： 

1  在c中，联合体（共用体）的数据成员都是从低地址开始存放。 
2  若是小端模式，由低地址到高地址c.a存放为0x01 00 00 00，c.b被赋值为0x01；
```
```
#include <stdio.h>

int main() {
    // Use an integer (4 bytes) and check byte order
    unsigned int num = 0x12345678;
    
    // Cast to a char pointer to inspect individual bytes
    unsigned char *ptr = (unsigned char *)&num;

    // Check the first byte in memory
    if (*ptr == 0x12) {
        printf("System is Big-Endian\n");
    } else if (*ptr == 0x78) {
        printf("System is Little-Endian\n");
    } else {
        printf("Unexpected byte order!\n");
    }

    // Optional: Print all bytes for clarity
    printf("Byte order: ");
    for (int i = 0; i < sizeof(num); i++) {
        printf("%02x ", ptr[i]);
    }
    printf("\n");

    return 0;
}
```
### Issue that causes Linecard issue
It has different result on ARM and ATOM  
```
#include <stdio.h>
void main()
{
    char a;
    a = 0xff;

    printf("%d %d\n", (a==0xff), a);
    return;
}
```
### iterate over a series.
```
    // Handle prefixes "Green", "Blue", and "Red"
    const char *prefixes[] = {"Green", "Blue",  "Red"};
    for (int i = 0; i < sizeof(prefixes) / sizeof(prefixes[0]); ++i)
    {
         ....
    }
```

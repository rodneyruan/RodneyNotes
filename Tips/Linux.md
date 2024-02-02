 ### 查看版本号
  cat /proc/version   
  uname －a
### 查看网络状态
netstat -nlutp

### 查看硬盘信息
```
    du --max-depth=1 | sort -n
    du -sh xmldb/ 
    du -sm * | sort -n //统计当前目录大小 并安大小 排序 
    du -sk * | sort -n 
    du -sk * | grep guojf //看一个人的大小 
    du -m | cut -d "/" -f 2 //看第二个/ 字符前的文字 
    查看此文件夹有多少文件 /*/*/* 有多少文件 
    du xmldb/ 
    du xmldb/*/*/* |wc -l 
du -sh  文件夹名 
 统计总数大小 
```

### 找出大于2M的文件 
find ./ -type f -size +2M | xargs ls -Slh 

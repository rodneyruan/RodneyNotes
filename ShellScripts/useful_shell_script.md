
#### 读取每一行作为命令的参数
cat output.txt | while read line; do cp /export/rruan/2022/URX/1.19.ab/arris-source/arris-source_private/arm/voice_overlay/$line $line ; done   
#### for loop
for i in {1..10}; do echo "(${RANDOM:0:3}) ${RANDOM:0:3}-${RANDOM:0:4}" >>rodney.txt; done    
for i in {1..10}; do echo "rodney" >> rodney.txt; done    
for i in {1..5}; do echo $i; done    
### 数字计算 Arithmetic Operation
```
a=5;b=3;echo $((a+b))
echo $(expr 5 + 7)
result=$(echo "5 + 7" | bc); echo $result
```
### 计算总和
cat  foo.txt |grep "BUY Order Filled at" | cut -d " " -f 10 |cut -d "," -f 1 |while read line; do a=$sum; sum=$(echo "$a + $line" | bc); echo $sum;done
### If statement
```
if [ "$model" = "aaa" ] && [ "$cust_index" != "22" ]; then
    echo a
elif [ "$model" = "3452" ]; then
    echo 3452
else
    echo b
fi
```

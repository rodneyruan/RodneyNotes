
#### 读取每一行作为命令的参数
cat output.txt | while read line; do cp /export/rruan/2022/URX/1.19.ab/arris-source/arris-source_private/arm/voice_overlay/$line $line ; done   
#### for 循环
for i in {1..10}; do echo "(${RANDOM:0:3}) ${RANDOM:0:3}-${RANDOM:0:4}" >>rodney.txt; done    
for i in {1..10}; do echo "rodney" >> rodney.txt; done    
for i in {1..5}; do echo $i; done    


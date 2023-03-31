### Server

https://www.ovhcloud.com/asia/  
sshpass -p XXXXXXXXXXXXX ssh  ubuntu@51.79.254.14  

### Official guide
https://github.com/stratosnet/sds

### How-to 
https://stratosmining.info/howto-install-stratos-sds-node/

### Check reward
OVH-1:
https://rest-tropos.thestratos.org/pot/rewards/wallet/st1vxyse40va5kwgt866zlja47cyghh6tk0zf7ntx  
OVH-2
https://rest-tropos.thestratos.org/pot/rewards/wallet/st1kja3c74qlx8eschpt3harjn9zhvhj6jvjxh3g9  
Veggie
https://rest-tropos.thestratos.org/pot/rewards/wallet/st1d4ek5q2le00l5vlyqzmajfvxcureqhwutfdrpf 

### What to do if node is suspended
updateStake 1stos 0.01stos 1  
startmining 
### Script to upload files

screen -S upload

#!/bin/bash  
while true;  
do /usr/bin/head -c 25M /dev/urandom > "$HOME/upload/test-$(date '+%Y%m%d%H%M')" ; ppd terminal exec put "$HOME/upload/test-$(date '+%Y%m%d%H%M')";  
sleep 900;  
/usr/bin/rm -rf "$HOME/upload/test*";  
sleep 1;  
done  

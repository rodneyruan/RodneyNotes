# MUON Testnet 
### 奖励
```
2月27号前，所有加入的节点，瓜分 20%的奖励
2月27号后，至少跑60天，90%的uptime，80%的奖励
奖励的方式是 $PION币
```
### 官方文档
```bash
https://docs.muon.net/muon-network/muon-nodes/joining-the-testnet-alice/faq-for-alice
```
### 安装docker 和docker-compose
```
 curl -fsSL https://get.docker.com | bash -s docker
 sudo systemctl daemon-reload
 sudo systemctl restart docker
 sudo apt-get install -y docker-compose
 ``` 

### 下载配置文件：
```
 curl -o docker-compose.yml https://raw.githubusercontent.com/muon-protocol/muon-node-js/testnet/docker-compose-pull.yml
```
### 启动：
```
docker compose up -d
```
### 添加节点：
- http://**172.245.86.246**:8000/status
- https://alice.muon.net/join/
BSC测试链，连接家里电脑的小狐狸钱包

### 重启节点
``` 
 添加节点后必须重启节点才能看到更新的状态。
 注意， 不能用 docker compose down 来重启， 这样会导致原来的节点丢失。
 必须执行这个： docker restart muon-node
```
### backup 备份
```＞＞＞＞＞＞＞注意，　每次重启都会生成新的节点， 所以　每次都需要restore 这个back.json文件
docker exec -it muon-node ./node_modules/.bin/ts-node ./src/cmd keys backup > backup.json
然后查看文件：
cat backup.json
这个信息非常重要，需要备份
```
### 还原 restore
```
创建一个名为 backup.json的文件， 然后输入你之前保存的内容：
执行命令 cat > backup.json 
粘贴保存的信息
敲回车
在键盘上按Ctrl+D 保存退出

执行这个命令查看内容 cat  backup.json 

docker exec -it muon-node ./node_modules/.bin/ts-node ./src/cmd keys restore "$(cat backup.json)"
docker restart muon-node

```

### 更新节点
```
docker cp muon-node:/usr/src/muon-node-js/.env ./backup.env
docker-compose down --rmi all
docker-compose pull
docker-compose up -d

docker cp backup.env muon-node:/usr/src/muon-node-js/backup.env
docker exec -it muon-node ./node_modules/.bin/ts-node ./src/cmd keys restore backup.env
docker restart muon-node

```
### 查看每天的收益：
```
https://alice.muon.net/join/
点击右上角的SWITCH NETWORK，切换到BSC测试链，并连接小狐狸钱包
```
### 删除节点
```
docker stop muon-node redis mongo  
docker rm muon-node redis mongo  
docker image prune   
```

### Install 安装节点
docker run --rm --tty --interactive --network host --volume <home-directory>/.ironfish:/root/.ironfish ghcr.io/iron-fish/ironfish:latest
  
### 使用钱包生成地址并导出私钥
docker docker exec -it node  0c48045a3abe -c "ironfish wallet:balances"   
docker exec -it 0c48045a3abe bash -c "ironfish wallet:create "  
docker exec -it 0c48045a3abe bash -c "ironfish wallet:use 115563936"  
docker exec -it 0c48045a3abe bash -c "ironfish wallet:address"  
docker exec -it 0c48045a3abe bash -c "ironfish wallet:export"  
### 领取空投
  https://testnet.ironfish.network/dashboard/rewards   
### 查积分  
  https://testnet.ironfish.network/users/458114   
  https://testnet.ironfish.network/users/311656   
  https://testnet.ironfish.network/users/313807   

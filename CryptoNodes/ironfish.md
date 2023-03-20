### Install 安装节点
docker run --rm --tty --interactive --network host --volume <home-directory>/.ironfish:/root/.ironfish ghcr.io/iron-fish/ironfish:latest
  
### 使用钱包
docker docker exec -it node  0c48045a3abe -c "ironfish wallet:balances"
docker exec -it 0c48045a3abe bash -c "ironfish wallet:create "
docker exec -it 0c48045a3abe bash -c "ironfish wallet:use 115563936"
docker exec -it 0c48045a3abe bash -c "ironfish wallet:address"
docker exec -it 0c48045a3abe bash -c "ironfish wallet:export"

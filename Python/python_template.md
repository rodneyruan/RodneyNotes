### 读取文件每一行，并处理其中数据 Read a file line-by-line by iterating.
> 数据如下
> ```
> AA 100 32.20
> IBM 50 91.10
> ```
```python
# pcost.py

total_cost = 0.0

with open('Data/portfolio.dat', 'r') as f:
    for line in f:
        fields = line.split()
        nshares = int(fields[1])
        price = float(fields[2])
        total_cost = total_cost + nshares * price

print(total_cost)
```
### 读取文件一次性处理数据 Read an entire file all at once as a string.

```python
with open('foo.txt', 'rt') as file:
    data = file.read()
    # `data` is a string with all the text in `foo.txt`
```

### 条件语句 conditional with if statement
> if 后可以不用括号， 是elif 不是 elseif   
> Check for multi conditions by adding extra checks using elif    
```python
if a > b:
    print("A")
elif a == b:
    print("B")
else:
    print("C")
```

### 用户输入 user input
```python
name = input('What is your name? ')
print('Hello ' + name)
``` 

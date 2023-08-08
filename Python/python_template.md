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

### 定义函数， 错误处理
```python
def portfolio_cost(filename):
    total_cost = 0.0
    with open(filename) as f:
        for line in f:
            fields = line.split()
            try:
                nshares = int(fields[1])
                price = float(fields[2])
                total_cost = total_cost + nshares*price

            # This catches errors in int() and float() conversions above
            except ValueError as e:
                print("Couldn't parse:", repr(line))
                print("Reason:", e)
    return total_cost

print(portfolio_cost('Data/portfolio3.dat'))
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

### list comprehension (expression) for (variable_name) in (sequence) if (condition)
  

```python
>>> a = [1, -5, 4, 2, -2, 10]
>>> b = [2*x for x in a if x > 0 ]
>>> b
[2, 8, 4, 20]
>>>
```


### Tuples vs. Lists

Tuples look like read-only lists. However, tuples are most often used for a single item consisting of multiple parts.    
Lists are usually a collection of distinct items, usually all of the same type.   
Tuple 像是数据库的一行， 由不同的数据类型组成， List 通常是同一种数据类型， ordered, 体现的是 sequence   

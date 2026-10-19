# Agent项目重搭建
## Stage 1: basic command-line interaction loop
### 实现功能

1. 输入字符串，返回输入内容，格式如下：
```
You> hello world!
Agent> received hello wolrd!
```
2. 退出符`/exit`;
3. 处理空白输入：当无输入内容时，跳过返回;
4. 处理输入异常：用
```cpp
std::cin.getline()
```
的bool返回值检查是否有输入异常。

### 功能抽象
将接受返回值功能抽象为`get_response`函数。接受`std::string input`输入，返回`received: " + input

### 语法
1. do...while... 替换 while，至少执行一次；
2. 由于退出循环体条件优先级不同，在循环体内完成退出条件判断，while条件写为true;
3. 函数参数接受：`const std::string&`，注意const头和&的选择使用。

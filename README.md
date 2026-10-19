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

## Stage 2: feat: add Agent class with input history
### 实现功能
1. 将每次的有效输入存入inputs;
2. 返回history_size;

### 功能抽象
抽象为Agent类，类内有属性（inputs为历史对话）以及对属性的操作（接受输入，存入历史，返回history_size）

### 语法
1. 私有成员在main函数域内不可见，只能通过的类内的公开函数，让Agent操作他；
2. const修饰不修改任何成员的函数。

## Stage 3: support pluggable models with ownership validation
### 实现功能
1. 希望历史记录能够区分“谁的回复“ -- 设计`struct Message`，记录role和content。其中，role的类型为`enum class Role`;
2. `Model`类实现的功能：`generate_reply`函数，提取`history`的最后一条记录生成回答。
3. 我们有很多不一样的model，使用什么model由用户指定。因此要先让用户传入模型选择，再转交给`Agent`。此处使用

### 功能抽象
1. 分离头文件和实现文件。当main函数在调用的时候，只需要看头文件中的接口/功能描述即可，无需到cpp文件里查看函数实现。
2. 拆分功能：`Agent`负责管理对话的历史，进行与显示; `Model`负责为对话产生回答，并回传给`Agent`.
3. 继承与多态：创建`Model`基类。我们可能有很多不同的model，但他们本质上都是model类，当agent要调用这个模型时，接口也应该是一样的。因此提取Model基类。

### 语法
1. enum class 与 enum, std::string的区别;
2. 虚函数是基类为继承类提供的接口，有语法`virtual = 0/default`。
    `override` -- 告诉编译器"这个函数是在重写基类的虚函数";
3. **基类指针或引用**提供统一的调用方式，实际对象决定执行哪份虚函数实现。不能对基类创建对象；
4. 智能指针`std::unique_ptr`：独占所有权的智能指针，同一时刻只有一个 unique_ptr 拥有某个对象，离开作用域时自动 delete。使用时头文件应包含`<memory>`
    创建智能指针，使用`std::make_unique<数据类型>`创建。

    结合“独占”，引入功能`std::move`，把传入的智能指针转交给成员，此时，模型没有被复制，也没有创建第二个模型，只是“转交”，所以转交后，再对之前的指针进行操作是没有意义的。使用时头文件应包含`<utility>`；
5. 异常抛出。注意检查传入指针是否为空指针。若是，用`throw`完成报错与程序截断。使用时，头文件包含`<stdexcept>`。并初步学习使用了`try/catch`。
```cpp
try {
    // 可能抛出异常的操作
} catch (const std::exception& e) {
    // 发生异常后的处理
    std::cerr << e.what() << '\n';
}
```


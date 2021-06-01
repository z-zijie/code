Compile & Run
---
Use `g++`  
```sh
g++ -o prog1 prog1.cc 
```
`-o` means the filename of the executable file is `prog1`  
根据使用的GNU编译器的版本，可能需要指定`-std=c++0x`参数来打开对C++11的支持.

Input & Output
---
使用`<iostream>`标准输入输出

Comments
---
- 单行注释  
   使用`//`，注释从`//` 开始到换行符结束。
- 界定符对注释  
    使用`/*` `*/`，在这两个组合之间的被注释。  
    注释界定符不能嵌套。

Control Flow
---
- while
```sh 
while (condition)
    statement
```
- for
```sh 
for (init-statement; condition; expression)
    statement
``` 
The vals in _init-statement_ only works in the loop, and only executed one time.
- if
```sh 
if (condition)
    statement

if (condition)
    statement
else
    statement

if (condition)
    statement
else if (condition)
    statement

...
```

Class
---
We need to define a `data structure` to represent some special data.  
For example, if we have defined a `class` named `Sales_item` in the head file `Sales_item.h`.  
The `Sales_item` class is used to represents the total sales, number of copies sold, and average selling price of a book. But now, we don't care about how to store or calculate these data, we only need to care about what operations this class objects can perform. The following statement
```cpp 
Sales_item item;
```
means `item` is a object of the class `Sales_item`.  

#### Member function
If we want to know the ISBN of one `Sales_item` object. We can use `item.isbn()` to get it.
Here the `isbn()` is a `member function` of `Sales_item` class.

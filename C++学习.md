# C++学习

## 继承

子类继承了父类，子类包含父类时，父类先构造先析构

子类再构造在析构

### 继承同名成员处理方式

子类与父类出现同名成员时，直接访问时访问子类，访问父类中的同名的成员在成员名前加一个父类的作用域，例如s.base::变量名
如果子类出现与父类同名的函数，会自动隐藏父类中的函数，需要加上作用域

### 继承同名的静态成员成员处理方式（static）

##### 通过对象访问

 静态成员类内声明，类外初始化，所有对象共享同一份数据

类外初始化，例如：int base：：m_A=200

同样方位父类中的静态成员要加上作用域 

##### 通过类名访问

例如：

```c++
cout<<son::m_A<<endl;
```

通过子类继承的访问父类下的静态成员

例如：

```c++
cout<<son::base::m_A;
```

同时函数也可以这样调用

### 多继承语法

语法：class 子类：继承方式：父类，继承方式：父类

不太建议使用多继承

### 菱形继承

#### （一个大类有两个子类，同时这两个子类有同一个子类）virtual来解决这个问题

两个派生类继承同一个类，又有某个类同事继承，叫菱形继承也叫钻石继承

利用虚继承解决菱形继承的问题，加上关键字virtual，虚继承，最大的类叫虚基类

cl /d1 singlecalssXXX "路径"

nullprt空指针

## 多态

### 多态的基本概念

静态多态：函数重载和运算符重载都属于动态重载

动态多态：派生类和虚函数实现运行时多态

##### 静态和动态的区别

静态多态的函数地址早绑定，编译阶段确定函数地址

动态多态的函数地址晚绑定，运行阶段确定函数地址

如果引用的是父类中的同名函数，但是想实现子类中的函数，再父类的同名函数前加上virtual，可实现父类中的函数变成虚函数，同时指针晚绑定可以运行子类中自己的

动态多态的条件：要有继承关系，子类要重写父类中的虚函数，需要父类变成虚函数父类的指针或者引用指向子类函数

例如父类的func函数前面加上virtual这样继承的子类中的同名函数调用时就是子类中的同名函数

<img src="C:\Users\86150\AppData\Roaming\Typora\typora-user-images\image-20231124231023983.png" alt="image-20231124231023983" style="zoom:150%;" />



vfptr是虚函数的指针，虚函数只会占1的空间，一个指针占4个字节空间

例如一个父类的引用指向一个子类的对象实例，然后调用父类的中的虚函数，此时不会实现父类中的函数，因为指针已经指向了子类中的函数地址，**这是动态实现多态**。子类继承了父类之后，就算就是空类也会有空间，因为汇集成父类中的指针。

### 纯虚函数和抽象类

#### 纯虚函数用法：virtual 返回值类型 函数名 （参数列表） =0

例如：

```
virtual void func（）=0；
```

当类中有了纯虚函数这个类也变成了抽象类 

**抽象类：无法发实例化对象**

子类必须重写抽象类中的纯虚函数，要不然子类也是抽象类

#### 总结：父类指针指向子类的对象，实现的是子类中重载的虚函数。

### 虚析构和纯虚析构

多态使用时，如果子类中有属性开辟到堆区，那么父指针在释放时无法调用到子类的析构函数代码

解决方法：将父类中的虚构函数改为**虚析构**和**纯虚析构*

虚析构和纯虚析构的共性：

- 可以解决父类指针释放子类对象
- 都需要具体的函数体现

虚析构和纯虚析构区别：

- 如果是纯虚析构，该类属于抽象类，无法实例化对象

 父类指针在指向 子类式，创建在堆区的数据用子类中的析构释放时，不能够完全释放，此时要把父类中的析构编程虚析构才可以释放完父类指针中的数据，在父类析构函数前加上virtual

虚析构和纯虚析构只有一个

纯虚析构virtual~类名 （）=0；

此时在类中只存在声明，不能够直接运行应该在全局区写一个纯虚析构函数的实现内容

**例如animal：：~animal（）{实现内容}**

使用条件总结：前提有继承，而且父类与子类中有同名的重写函数，子类中有 堆区数据，用父类指针new一个子类的数据 

有纯虚析构的类也属于抽象类。

## 文件操作

程序运行是产生的数据都属于临时文件，从程序一旦运行 结束都会被释放

通过**文件可以将数据持久化**

c++中对文件操作需要包含头文件`****<fstream>****`

文件类型分为两种：

1. 文本文件：文件以ASCLL码形式存储在计算机中
2. 二进制文件：文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂他们

操作文件的三大类

1. ofstream：写操作
2. ifstream：读操作
3. fstream：读写操作

### 文本文件

### 写文件

步骤：

1. 包含头文件
   
   ```
   #include<fstream>
   ```
   
   
   
2. 创建流对象
   ofstream ofs
   
3. 打开文件
   
   ```
   ofs.open（“文件路径”，打开方式）；
   ```
   
   
   
4. 写数据
   ofs<<"写入的数据"；ofs相当于cout，cout输出在屏幕，ofs输出屏幕
   
5. 关闭文件
   
   ```
   ofs.close（）；
   ```
   
   

文件打开方式：

![image-20231128161503634](C:\Users\86150\AppData\Roaming\Typora\typora-user-images\image-20231128161503634.png)

### 读文件

#### 1.右移方法

1. 包含头文件
   
   ```c++
   1. #include<fstream>
   2. 
   ```
   
   创建流对象
   
   ```c++
   ifstream ifs
   ```
   
   
   
2. ifs.if_open()是否成果打开文件是一个bool类型返回值的函数

4. 打开文件
   
   ```c++
   1. ifs.open（“文件路径”，打开方式）；
   2. 
   ```
   
   写数据
   ifs<<"写入的数据"；ifs中的i是in的意思，意思就是从程序中输入文件中的数据
   
6. 关闭文件
   
   ```c++
   ifs.close（）；
   ```
   
   

in就是从文件中输入进程序中

out就是从程序中输出到文件中

读文件使用循环代码while（ifs >>  buf）

buf是一个数组；要把文件中的数据读进buf这个数组中 来就需要一行一行录入，右移允许算符相当于读取运算符，知道读到最后一个字符变成空的时候才结束进行

#### 2.ifstream.getline（）

同样可以 使用getline函数读取数据getline函数中包含两个数据

例如getline（读取的数组，需要读取的长度），如果需要将数组填满则需要第二个长度与数组大小相同。

#### 3.string buf，使用全局区的getline

使用全局函数下的getline（）函数里面的参数是初始化的ifstream输入流对象

getline（输入流对象，buf），前提初始化一个string类型的对象

#### 4.char 个字符

初始化一个char  C;

while（(C != ifs.get()) != EOF）//EOF是文档尾部，这样也可以读取整个文档内容

### 二进制文件呢ios::binary

创建一下ofstream类型对象

```c++
// *创建一个写二进制的独享*

*void* test06()

{

  ofstream write;

  write.open("*person.txt*", ios::out *|* ios::binary);

  person p = {"*张三*", 18};

  write.write((*const* *char* *)&p, *sizeof*(person));

  write.close();

}

// *读二进制的文件*

*void* test07()

{

  ifstream read;

  read.open("*person.txt*", ios::in *|* ios::binary);

  *if* (!read.is_open())

  {

​    cout *<<* "*打开失败*" *<<* endl;

  }

  person p;

  read.read((*char* *)&p, *sizeof*(p));

  // *读取文件的内容相当于存进初始化的p*

  // *打印输出的时候输出p.name和p.age*

  cout *<<* p.m_Name *<<* p.m_Age *<<* endl;

  //*最后一步关闭文件*

  read.close();

}
```

写入文件（从代码写入到文本文件呢）是out，输出代码中的对象内容到文件中

读取文件（从文本文件读取到代码中） 是in，读取文本文件的内容到代码中的对象中

其中的write函数中包含的应该是常量*数据类型 和数据占有的内存大小

read函数中包含的是数据类型*，和应该 写入数据类型的大小。







## 模板

### 泛型编程，主要利用技术就是模板

#### 语法：

```c++
template<typename T>
```

template --声明创建模板

typename --模板名称



模板中有两种用法一个是**自动类型推导**和**显示指定类型**

自动类型推到例如：

```c++
mySwap（a，b）
```

显示指定类型：

```c++
 mySwap<int>（a，b）
```

模板函数调用规则：如果有符合的非模板函数，先调用非模板函数，如果没有则编译器自己调用模板函数自己推导

### 模板的局限性

无法对特定类型的数据进行推导，有些特定的数据类型需要具体方式做特殊实现

利用具体化的模板，可以解决自定义类型的通用化相当于重载

### 类模板

```c++
template<typename T>
```

class

紧接着一个类说明要写一个类模板

### 类模板与函数模板的区别

类模板中不能用自动类型推导，函树模板两个都可以

### 类模板与继承

继承的时候要明确继承的类型，如果不告诉继承的

类外实现 例子：

```c++
template<class T 1,class T2>

void   person<T1,T2>::person(T1 t,T2 t)
```



### 类模板模块化

份文件编写语法不会报错，但是模板无法连接在一起包含文件源文件.cpp不会生成错误，编译器是在编译阶段才会推导数据类型。

## STL

STL六大组件：**容器、算法、迭代器、仿函数、适配器、空间配置器**

1. 容器：各种数据结构：vector、list、deque、set、map
2. 算法：各种常用算法：sort、find、copy、for_each
3. 迭代器：扮演了容器与算法之间的胶合剂
4. 仿函数：行为类似函数，可作为算法的某种策略

### STL中的容器（Containers）、算法（Algorithms）、迭代器（iterators）

要包含头文件#include<vector>

#include<algorithms>

想要遍历容器中的数据需要包含算法头文件调用函数for_each

初始化一个容器

```c++
vector<int>  v
```

v中包含v.begin和v.end分别认为是指向容器数据中的第一个数据和最后一个数据的后一个数据的指针

for_each(v.begin；v.end；调用的函数)

解释： for_each中第一个参数与第二个参数不相等则调用第三个参数中的函数，然后进行第一个参数的++运算

同时遍历元素可以用到for循环

```c++
for（vector<int> :: iterators it=v.begin;it != v.end;i++）
```

在for循环中初始化一个iterators迭代器

```c++
for(auto i = v.bigen; i < v.end; i++)
```

<u>次遍历方法中输出的应该是*it 因为迭代器本身是一个指针形式的数据，不能直接输出</u>

**在C++中，auto关键字可以用于声明变量时根据变量的初始值自动推导变量的类型**

```c++
#include <vector>
#include <algorithm>
int myprint(int v)
{
    cout << v << endl;
}
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    // 通过迭代器访问容器中的数据
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        //迭代器是指针
        cout << *it << endl;
    }
    // for_each中第一个参数与第二个参数不相等则调用第三个参数中的函数，然后进行第一个参数的++运算
    for_each(v.begin(),v.end(), myprint);
    // 以上链各个方法都可以遍历容器中的数据
    for (auto i = v.begin(); i < v.end(); i++)
    {
       cout<<*i<<endl;//迭代器只是一个指针，如果直接打印输出只会打印出地址
    }
    for(auto &x : v)
    {   
        cout<<x<<" ";
    }
}
```

**新方法for（auto x：v）同时适用于普通遍历**

##### vector嵌套容器

```c++
vector<vector<int>>  v
```

嵌套容器循环需要嵌套循环才能遍历

### string基本概念

string（）空构造

string(const* s)

## 多线程

### 数据库的基本使用

多线程中函数的调用

```c++
#include<thread>//需要包含的头文件名
#include<iostream>
#include<string>
using namespace std;
void print_helloworld(string msg)
{
    cout<<msg<<endl;
}

int main()
{
    std::thread thread1(print_helloworld,"fuck you");
//主程序不会等子程序结束然后结束，调用jion函数可以检查子进程有没有结束
    thread1.join();
//调用detach主城不会等子程序运行结束，但是子程序会在后台运行   
    thread.detach()
   //使用一个bool值接受jionable的jionable的返回值
    bool isjion = thread1.joinable();
    //如果可以jion则调用jion函数
    if(isjion)
    {
        //因为jion函数jion函数只能调用一次所以要判断
        thread1.join();
    }
    return 0;
}
```

C++中的join函数用于等待子线程结束并返回子线程的执行结果。当调用join函数时，主线程会阻塞直到子线程执行完毕，然后才会继续执行。因此，可以将join函数视为声明子线程结束的标志。在子线程执行完毕后，可以通过join函数获取子线程的执行结果，或者进行其他相关的操作。

### 线程函数中的数据未定义错误

\1. 传递临时变量的问题：



```c++
#include <iostream>
#include <thread>
void foo(int& x) {
    x += 1;
}
int main() {
    std::thread t(foo, 1); // 传递临时变量
    t.join();
    return 0;
}
```



在这个例子中，我们定义了一个名为`foo`的函数，它接受一个整数引用作为参数，并将该引用加1。然后，我们创建了一个名为`t`的线程，将`foo`函数以及一个临时变量`1`作为参数传递给它。这样会导致在线程函数执行时，临时变量`1`被销毁，从而导致未定义行为。



解决方案是将变量复制到一个持久的对象中，然后将该对象传递给线程。例如，我们可以将`1`复制到一个`int`类型的变量中，然后将该变量的引用传递给线程。



```c++
#include <iostream>
#include <thread>
void foo(int& x) {
    x += 1;
}
int main() {
    int x = 1; // 将变量复制到一个持久的对象中
    std::thread t(foo, std::ref(x)); // 将变量的引用传递给线程
    t.join();
    return 0;
}
```



\2. 传递指针或引用指向局部变量的问题：



```c++
#include <iostream>
#include <thread>
void foo(int* ptr) {
    std::cout << *ptr << std::endl; // 访问已经被销毁的指针
}
int main() {
    int x = 1;
    std::thread t(foo, &x); // 传递指向局部变量的指针
    t.join();
    return 0;
}
```



在这个例子中，我们定义了一个名为`foo`的函数，它接受一个整型指针作为参数，并输出该指针所指向的整数值。然后，我们创建了一个名为`t`的线程，将`foo`函数以及指向局部变量`x`的指针作为参数传递给它。这样会导致在线程函数执行时，指向局部变量`x`的指针已经被销毁，从而导致未定义行为。



解决方案是将指针或引用指向堆上的变量，或使用`std::shared_ptr`等智能指针来管理对象的生命周期。例如，我们可以使用`new`运算符在堆上分配一个整数变量，并将指针指向该变量。



```c++
#include <iostream>
#include <thread>
void foo(int* ptr) {
    std::cout << *ptr << std::endl;
    delete ptr; // 在使用完指针后，需要手动释放内存
}
int main() {
    int* ptr = new int(1); // 在堆上分配一个整数变量
    std::thread t(foo, ptr); // 将指针传递给线程
    t.join();
    return 0;
}
```



\3. 传递指针或引用指向已释放的内存的问题：



```c++
#include <iostream>
#include <thread>
void foo(int& x) {
    std::cout << x << std::endl; // 访问已经被释放的内存
}
int main() {
    int* ptr = new int(1);
    std::thread t(foo, *ptr); // 传递已经释放的内存
    delete ptr;
    t.join();
    return 0;
}
```



在这个例子中，我们定义了一个名为`foo`的函数，它接受一个整数引用作为参数，并输出该引用的值。然后，我们创建了一个名为`t`的线程，将`foo`函数以及一个已经被释放的指针所指向的整数值作为参数传递给它解决方案是确保在线程函数执行期间，被传递的对象的生命周期是有效的。例如，在主线程中创建并初始化对象，然后将对象的引用传递给线程。



```c++
#include <iostream>
#include <thread>
void foo(int& x) {
    std::cout << x << std::endl;
}
int main() {
    int x = 1;
    std::thread t(foo, std::ref(x)); // 将变量的引用传递给线程
    t.join();
    return 0;
}
```



在这个例子中，我们创建了一个名为`x`的整数变量，并初始化为`1`。然后，我们创建了一个名为`t`的线程，将`foo`函数以及变量`x`的引用作为参数传递给它。这样可以确保在线程函数执行期间，变量`x`的生命周期是有效的。



\4. 类成员函数作为入口函数，类对象被提前释放



错误示例：

```c++
#include <iostream>
#include <thread>

class MyClass {
public:
    void func() {
        std::cout << "Thread " << std::this_thread::get_id() 
        << " started" << std::endl;
        // do some work
        std::cout << "Thread " << std::this_thread::get_id() 
        << " finished" << std::endl;
    }
};

int main() {
    MyClass obj;
    std::thread t(&MyClass::func, &obj);//
    // obj 被提前销毁了，会导致未定义的行为
    return 0;
}
```

上面的代码中，**在创建线程之后，obj 对象立即被销毁了，这会导致在线程执行时无法访问 obj 对象，可能会导致程序崩溃或者产生未定义的行为。**

为了避免这个问题，可以使用 std::shared_ptr 来管理类对象的生命周期，确保在线程执行期间对象不会被销毁。具体来说，可以在创建线程之前，将类对象的指针封装在一个 std::shared_ptr 对象中，并将其作为参数传递给线程。这样，在线程执行期间，即使类对象的所有者释放了其所有权，std::shared_ptr 仍然会保持对象的生命周期，直到线程结束。

以下是使用 std::shared_ptr 修复上面**错误**的示例：

```c++
#include <iostream>
#include <thread>
#include <memory>

class MyClass {
public:
    void func() {
        std::cout << "Thread " << std::this_thread::get_id() 
        << " started" << std::endl;
        // do some work
        std::cout << "Thread " << std::this_thread::get_id() 
        << " finished" << endl;
    }
};

int main() {
    shared_ptr<MyClass> obj = make_shared<MyClass>();
    std::thread t(&MyClass::func, obj);
    t.join();
    return 0;
}
```

上面的代码中，使用 make_shared 创建了一个 MyClass 类对象，并将其封装在一个 std::shared_ptr 对象中。然后，将 std::shared_ptr 对象作为参数传递给线程。这样，在线程执行期间，即使 obj 对象的所有者释放了其所有权，std::shared_ptr 仍然会保持对象的生命周期，直到线程结束。

**智能指针相当于代码中的模板**



5.入口函数为类的私有成员函数

```c++
#include <iostream>
#include <thread>

class MyClass {
private:
	friend void myThreadFunc(MyClass* obj);
	void privateFunc()
	{
		std::cout << "Thread " 
		<< std::this_thread::get_id() << " privateFunc" << std::endl;
	}
};

void myThreadFunc(MyClass* obj) 
{
	obj->privateFunc();
}

int main() {
	MyClass obj;
	std::thread thread_1(myThreadFunc, &obj);
	thread_1.join();
	return 0;
}
```

上面的代码中，将 `myThreadFunc` 定义为 `MyClass` 类的友元函数，并在函数中调用 `privateFunc` 函数。在创建线程时，需要将类对象的指针作为参数传递给线程。

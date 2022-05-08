# 数据结构作业之——一元多项式合并

## 题干：

* 给定两个一元多项式，实现两个一元多项式的相加算法。
* 提示：用一条单链表表示一个一元多项式，每个节点包含三个域：指数域、系数域和后继结点链。

## 文件结构：

1. `Linklist.h`

* 为单链表类
* 成员：数据（`val`）和指针
* 对应构造方法与访问、修改方法

2. `Polynomail.h`

* 为多项式类

* 成员：系数、自变量、指数

* 方法：

  ```cpp
  //有参、无参构造
  		Polynomial();
      Polynomial(int k, std::string s, int pow);
  //成员变量的`get`方法
  		int getK();
      std::string getS();
      int getPow();
  //判断两个单位是否可以合并
      bool canMerge(Polynomial* p);
  //两个同指数的单位合并
      bool mergeItem(Polynomial* p);
  //新建元素并插入链表
      bool buidNewItem(Polynomial* list, Polynomial* p);
  //输出表达式
  //eg：-x+2x-3x^{-4}+5x^{6}
  //输出为：-x+2x-3x{-4}+5x{6}
      std::string print();
  ```

3. `mergeHandle.h`

* 处理合并操作

```cpp
//创建新链表
Linklist* buidLinklist()
//用于没有相同幂的项创建新项（在指定位置后插入）
bool insertWithNewItem(Linklist* list, Polynomial* val)

//用于有相同幂的项创建新项，合并系数
bool insertWithOldItem(Linklist* list, Polynomial* val)

//寻找插入点
//如果有相同幂的项返回该项，如果没有按照降幂顺序返回其前的节点
Linklist* findInsertPosition(Linklist* list, Polynomial* val)

//遍历链表输出当前合并结果
void printAllItems(Linklist* list)
```

## 主要难点

### 输入表达式的处理

* 读入字符串后

  * 处理系数

  ```cpp
  //先处理符号
  bool flag = false;
  if (ps < len && s[ps] == '+')
    ps++;
  if (ps < len && s[ps] == '-') {
    flag = true;
    ps++;
  }
  //处理系数的整数部分
  if (ps < len && s[ps] <= '9' && s[ps] >= '0') {
    	while (ps < len && s[ps] <= '9' && s[ps] >= '0') {
        k *= 10;
        k += s[ps++] - '0';
      }
  } else
    k = 1;//如果没有系数位，系数就是1
  if (flag)//加上符号
    k = -k;
  ```

  * 处理字母、指数域

  ```cpp
  //读入字母
  ss += s[ps++];
  
  //由于指数带大括号，先判断大括号
  flag = false;
  if ((ps < len && s[ps] != '{') || ps == len) {
    pow = 1;
  } else {
    ps++;
    //处理符号
    if (ps < len && s[ps] == '-') {
      flag = true;
      ps++;
    }
    //获得整数域
    while (ps < len && s[ps] != '}') {
      pow *= 10;
      pow += s[ps++] - '0';
    }
    ps++;
    //加上符号
    if (flag)
      pow = -pow;
  } 
  ```

  * 与已有表达式合并

  ```cpp
  //创建Polynomial对象
  auto tval = new Polynomial(k, ss, pow);
  //寻找其在链表中按降幂排列的位置
  auto tplist = findInsertPosition(list, tval);
  //获得该位置的val
  auto tpval = (Polynomial*)tplist->getVal();
  //如果指数域相同，则进行合并，反之在其后新建节点
  if (tpval != nullptr && tpval->canMerge(tval)) {
    insertWithOldItem(tplist, tval);
  } else {
    insertWithNewItem(tplist, tval);
  }
  ```

  


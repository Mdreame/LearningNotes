## 基本数据类型
三种基本数据类型：
- 数字（Number）：整数、小数;
- 字符串（String）："hello"，包括空字符串。
- 布尔值（Boolean）：`true`、`false`

新增：
- 大整型：BigInt
- 标志：Symbol

对象：
- 狭义的对象
- 数组
- 函数

## 判断数据类型
三种方法：
- `typeof`运算符
- `Instanceof`运算符
- `Object.prototype.toString`方法

```js
typeof null;  //object
typeof undefined; //undefined
typeof []; //object
typeof {}; //boject
typeof function f(){}; //function
```

判断一个值不存在或者未定义时，用`typeof undefined`。
```js
if (val){
	...  //危险的写法
}

//推荐的写法
if (typeof val === "undefined") {
	...
}
```

实验：

![控制台测试typeof](https://picture.mdreame.life/typeof_diff_data.png)
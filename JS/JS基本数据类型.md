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



### 1.null、undefined
相同点：
- 在`if`语句中都会被转换为0；
- 使用`null == undefined`判断成立

区别：
- `null`表示空值，可以作为传参。
- `undefined`表示”未定义“，使用场景：
	```js
	//变量声明了，但未赋值
	var i;
	i //undefined
	
	//调用函数时，应该提供的参数缺少了，该参数为undefined
	function f(x){
		return x;
	}
	f()	//undefined
	
	//对象没有赋值的属性
	var obj = {};
	obj.a //undefined
	
	//函数没有返回值时，默认返回undefined
	function f(){}
	f() //undefined
	```

### 2.布尔值
逻辑取反和比较运算符会返回布尔值。
如果 JavaScript 预期某个位置应该是布尔值，会将该位置上现有的值自动转为布尔值。转换规则是除了下面六个值被转为`false`，其他值都视为`true`。
- `null`
- `undefined`
- `""`、`' '`
- `NaN`
- `0`
- `false`

注意，空数组和空对象对应的布尔值都是`true`。
> 原因可能因为其内容为空，但其引用的地址存在。

布尔值一般用于条件判断语句中判断真假。

### 3.数值
JS中数值可以说只有浮点类型，其存储格式为：
![JS数值存储形式](https://picture.mdreame.life/js_float_number.png)

## 如何判断数据类型
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

> null的类型是object，这是由于历史原因造成的。1995年的 JavaScript 语言第一版，只设计了五种数据类型（对象、整数、浮点数、字符串和布尔值），没考虑null，只把它当作object的一种特殊值。后来null独立出来，作为一种单独的数据类型，为了兼容以前的代码，typeof null返回object就没法改变了。


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
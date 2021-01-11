网格布局的实现主要由父容器（`container`）和子元素（`items`）的配合实现。

## 网格容器的设置

### 声明

给父元素的`display`值设置为`flex`，将使其变为网格容器。

```css
.container {
    display: flex;
}
```

### 模板行和列

````css
grid-template-columns: 50px 50px;
grid-template-rows: 50px 50px;
````

有几个属性值表示有几列（或几行），而每个值表示对应列的宽度（或高度）。每个元素占一个格子，超出行数的元素会自动换行排列。

**不同的单位**

```css
grid-template-columns: auto 50px 10% 2fr 1fr;
```

- `fr`：设置列或行占剩余空间的一个比例，

- `auto`：设置列宽或行高自动等于它的内容的宽度或高度，

- `%`：将列或行调整为它的容器宽度或高度的百分比，

### 间距

```css
grid-column-gap: 10px;
grid-row-gap: 5px;
```

指定行或列间的宽度。

简写形式：

```css
grid-gap: row column;
```

只有一个参数表示行列同宽。

### 对齐方式

```css
jsutify-items: stretch | start | center | end;
```

对网格容器使用`align-items`属性可以给网格中所有的网格项设置沿行轴对齐的方式。



```css
align-items: stretch | start | center | end;
```

对网格容器使用`align-items`属性可以给网格中所有的网格项设置沿列轴对齐的方式。



## 网格项的设置

### 网格项大小

用在每个网格项自身。

![网格](grid-column.png)

如上图模型所示：

```css
grid-column: 1/3;
grid-row: 1/3;
```

则表示网格项的位置坐标从左边第一条线开始到第三条线结束（不包括第三条线）。两个数的差值为占的行数或者列数。

### 对齐方向

在 CSS 网格中，每个网格项的内容分别位于被称为单元格（cell）的框内。`justify-self`属性可以设置其内容在**水平方向**的对齐方式。

```css
jsutify-self: stretch | start | center | end;
```

- `stretch`：内容填满整个单元格

- `start`：使内容在单元格左侧对齐

- `center`：使内容在单元格居中对齐

- `end`：使内容在单元格右侧对齐



```css
align-self: stretch | start | center | end;
```

`align-self`属性可以设置其内容在**垂直方向**的对齐方式。

## 组合使用（区域模板）

### 父容器

```css
.container {
    grid-template-areas:
  		"header header header"
  		"advert content content"
  		"footer footer footer";
}
```

每个单词代表一个网格单元格，每对引号代表一行。除了自定义标签，还可以使用句点（`.`）来表示一个空单元格

### 子元素

给特定的网格项添加下列样式，则可以将其放到指定区域。

```css
.item1 { grid-area: header;}
```

直接添加`grid-area`属性也可以指定网格项到特定位置：

```css
grid-area: 起始水平线 / 起始垂直线 / 末尾水平线 / 终止垂直线 ;
```

可以看成是，`grid-row`和`grid-column`的组合 ，如`.item5 {grid-area: 1/1/3/3;}`显示为：

![grid-area](grid-area.png)

前两个参数可以理解为起始坐标，后两个与前面参数的插值代表几行几列。

使用**媒体查询**来实现自适应布局：

```css
 @media (min-width: 400px){
    .container{
      grid-template-areas:
        "header header"
        "advert content"
        "footer footer";
    }
  }
```

当宽度大于400px的时候，header和footer分别占据头部和底部完整宽度。

![媒体查询结合grid](media-require.png)


## 内置函数

### repeat 函数创建重复

```css
grid-template-columns: repeat(2, 1fr 50px) 20px;
```

`repeat()`第一个参数为重复次数，第二个参数为每个网格项的样式。还可以与其他值一起使用。

### minmax()限制大小

内置函数`minmax`也可以可用于设置`grid-template-columns`和`grid-template-rows`的值。它的作用是在网格容器改变大小时限制网格项的大小。为此，你需要指定网格项允许的尺寸范围。例如：

```css
grid-template-columns: 100px minmax(50px, 200px);
```

在上面的代码中，`grid-template-columns`被设置为添加两列，第一列 100px 宽，第二列宽度最小值是 50px，最大值是 200px。

repeat和minmax函数可以一起使用，如：

```css
grid-template-columns: repeat(3, minmax(90px, 1fr));
```

重复方法带有一个名为自动填充（auto-fill）的功能。它的功能是根据容器的大小，尽可能多地放入指定大小的行或列。你可以通过结合`auto-fill`和`minmax`来更灵活地布局。

**auto-fill**

如`grid-template-columns`被设置为：

```css
repeat(auto-fill, minmax(60px, 1fr));
```

上面的代码效果：列的宽度会随容器大小改变。

## 网格嵌套

```css
  .item3 {
    background: PaleTurquoise;
    grid-area: content;
    display: grid;
    grid-template-columns: auto 1fr;
  }
```

将网格项设置为`display:flex`可以嵌套网格。
[toc]

## 弹性容器

给一个元素设置`display: flex;`属性会使其成为弹性容器（`flex-container`），其子元素都将成为弹性子元素（`flex-items`）。

弹性子元素默认是在同一行按照从左到右的顺序并排排列。弹性容器像块元素一样填满可用宽度，但是弹性子元素不一定填满其弹性容器的宽度。弹性子元素高度相等，该高度由它们的内容决定（意思是弹性容器的高度由最高的子元素决定，但每个弹性子元素都是等高的）。

### 排列顺序

```css
flex-direction: row|row-reverse|column|column-reverse|initial|inherit;
```

根据设定值决定子元素横向或者竖向进行顺序或者逆序排列。同时需根据弹性容器主轴的方向（ltr/rtl）来确定。

### 对齐

#### 水平方向的对齐

```css
justify-content: flex-start|flex-end|center|space-between|space-around|initial|inherit;
```

- `space-around`：空间等分后，将每个元素居中。

点击[这里](https://www.runoob.com/try/playit.php?f=playcss_justify-content&preval=space-between)查看演示。

#### 垂直方向的对齐

```css
align-items: stretch|center|flex-start|flex-end|baseline|initial|inherit;
```

- baseline: 基于基线对齐

### 换行

```css
flex-wrap: nowrap|wrap|wrap-reverse|initial|inherit;
```

- `wrap-reverse`：换行且反转排列。

## 弹性元素

### 伸缩

```css
flex-shrink: number|initial|inherit;
```

数值表示压缩的倍数。

```css
a{
    flex-shrink: 1;
}
b {
    flex-shrink: 3;
}
```

则a的宽度是b的3倍。

```css
flex-grow: number|initial|inherit;
```

与`flex-shrink`相反。

初始长度

```css
flex-basis: number|auto|initial|inherit;
```

组合使用：

```css
flex: flex-grow flex-shrink flex-basis;
```

```css
  #box-1 {
    flex: 2 2 150px;
  }

  #box-2 {
    flex: 1 1 150px;
  }
```

当box-1和box-2的父元素宽度超过300px时，box-1增长速率是box-2的两倍。

当box-1和box-2的父元素宽度小于300px时，box-1压缩速率是box-2的两倍。

### 排序

```css
order: number 
```

设置或检索弹性盒模型对象的子元素出现的順序。

### 自身对齐

设置子元素在父容器中垂直方向的对齐方式。

```css
align-self: auto|stretch|center|flex-start|flex-end|baseline|initial|inherit;
```

会抵消`align-items`的影响。
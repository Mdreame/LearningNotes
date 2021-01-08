知识点：

- 页面内部锚点链接不能有`target`属性

- 固定链接：用于暂时不确定跳转的情况。`<a href="#"></a>`

- `<main>`标签的使用

- 表单增加必填字段：`<input type="text" required>`

- 单选框是由name属性决定的：

  ```html
  <label for="indoor"><input id="indoor" type="radio" name="indoor-outdoor">indoor</label>
  <label for="outdoor"><input id="outdoor" type="radio" name="indoor-outdoor">outdoor</label>
  ```

- 给单选框或复选框设置默认选项：

  ```html
  <input id="indoor" type="radio" name="indoor-outdoor" checked>
  ```

- 内联样式结尾要加分号

  ```html
  <h2 style="color: red;">CatPhotoApp</h2>
  ```

- `font-family`字体间需要加逗号

  ```css
  font-family: Lobster, monospace;
  ```

- 属性选择器

  ```css
    [type='checkbox'] {
      margin: 10px 0 15px 0;
    }
  ```

- CSS样式优先级：`!important` > 内联 > ID  > Class > 属性选择器 > 元素选择器

- CSS变量

  ```css
  /*声明*/
  --penguin-skin: black;
  /*使用*/
  color: var(--penguin-skin);
  ```

  设置一个备用值来防止由于某些原因导致变量不生效的情况。

  ```css
  background: var(--penguin-skin, black);
  ```

  为了兼容性，需要将两种都写上：

  ```css
  p {
  	background: red;
  	background: var(--red-color);
  }
  ```

  就像`html`是`body`的容器一样，你也可以认为`:root`元素是你整个 HTML 文档的容器。

  在`:root`创建的变量，在整个网页里面都能生效。同时在其他位置重复声明，也会覆盖这个变量。

  ```css
  :root {
      --penguin-belly: white;
  }
  test {
      --penguin-belly: black;
  }
  ```

- 当元素的`position`被指定，如`fixed`或者`relative`时，CSS 偏移属性`right`、`left`、`top`和`bottom`可以用在动画规则里创建动作。

- 每个页面应该只有一个`h1`标签，用来说明页面主要内容。`h1`标签和其他的标题标签可以让搜索引擎获取页面的大纲。

- 音频：

  ```html
  <audio controls>
        <source src="https://s3.amazonaws.com/freecodecamp/screen-reader.mp3" type="audio/mpeg"></source>
      </audio>
  ```

  

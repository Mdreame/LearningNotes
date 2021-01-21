## 快速上手

Gatsby是一个可以快速构建网站和应用程序的框架，基于React。

### 安装

默认已配置好Node和Git环境。使用npm安装Gatsby-CLI：

```shell
npm install -g gatsby-cli
```

### 快速初始化网站

通过已有的[Gatsby网站模板](https://www.gatsbyjs.cn/starters/?v=2)可以快速初始化一个具有特定结构的网站。

```shell
gatsby new hello-world https://github.com/gatsbyjs/gatsby-starter-hello-world
```

### 启动预览

```shell
cd hello-world	#进入初始化的网站目录
gatsby develop	#启动开发环境
```

现在在浏览器中输入`http://localhost:8000/`就可以预览网站。

## 模块介绍

### 组件

网页元素的一个部分，可以将任何部分看成一个组件，如按钮，导航栏，甚至整个页面。

#### 页面

```js
import React from "react"
export default () => (
	<div style={{color: `teal`}}>
    	<h1>Im Index.js</h1>
		<p>Based On React.js</p>
    </div>
)
```

所有的页面文件都应该放在项目的`src/pages/`文件夹下，Gatsby默认将这里的组件渲染成页面。

#### 子组件

子组件用于将页面某个部分划分成更小的部分，以便再次使用。子组件的文件夹通常在`src/components/`下。

如定义一个标题组件：

1. 在`src/components/`文件夹下新建`header.js`;

   ```js
   import React from "react"
   export default () => (
   	<h1>Header in Homepage.</h1>
   )
   ```

   在`index.js`中引用：

   ```js
   import React from "react"
   import Header from "../components/header"
   
   export default () => (
   	<Header />
   )
   ```

2. 但是这样有一个问题，即标题中的内容是定死的，只能在`header.js`中修改。假如另一个页面`Contact.js`也需要引用这个标题组件，那就无法同时适配在两个页面。所以我们需要在各个页面分别根据需要定义标题内容，再写入`Header`组件并渲染到页面视图中。这就类似函数的传参，现在我们将组件`<Header>`当成函数，让其接受从各个页面传来的参数，也就是标题内容，然后显示出来。

   修改`Header.js` 如下：

   ```js
   import React from "react"
   export default props => (
   	<h1>{ props.headerText }</h1>
   )
   ```

   修改`index.js`：

   ```js
   import React from "react"
   export default () => (
   	<Header headerText="I'm Homepage."/>
       <Header anotherText="我可以复用了……" />
       <p>Nice props, cool React!</p>
   )
   ```

   **props就是一个全局对象，其中保存了自定义的属性。**

#### 链接

链接组件是Gatsby提供的子模块，使用方式非常简单。在`src/pages/`目录下创建`contact.js`页面：

```js
import { Link } from "gatsby"
export default () = (
	<div>
    	<Link to="/contact/">Contact Me</Link>
    	<Header headerText="Homepage" />
    </div>
)
```

`to`属性指定跳转路径，语法非常简单。

> 注意：
>
> - 在引入模块的时候，如果模块只暴露了一个默认属性或方法时，对命名不做限制。但是有多个属性或方法时，需要在引入的子模块加上大括号，且命名必须与引入的属性或方法的名称保持一致。
> - 渲染的内容包括组件和其他元素时，组件必须被父元素包含。只有组件则不需要。

### CSS

#### 全局CSS

在`src/styles/`目录下新建`global.css`：

```css
html {
    background-color: rgb(92, 224, 92);
}
```

在网站根目录下新建`gatsby-browser.js`：

```js
import "./src/styles/global.css"
```

`gatsby-browser.js`是一个可以被Gatsby识别的特殊文件，可以用于加载css文件。

#### 组件CSS

> 一个 **CSS 模块**是一个 CSS 文件，其中包含所有样式和 CSS3 动画名称 默认情况下只适用于本范围内。
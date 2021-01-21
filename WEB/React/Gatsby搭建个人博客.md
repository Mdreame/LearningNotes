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

## 组件

网页元素的一个部分，可以将任何部分看成一个组件，如按钮，导航栏，甚至整个页面。

### 页面

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

### 子组件

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

### 链接

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


## 使用CSS

### 全局CSS

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

### CSS模块

> 一个 **CSS 模块**是一个 CSS 文件，其中包含所有样式和 CSS3 动画名称 默认情况下只适用于本范围内。

新建两个文件：

```js
//container.js
import React from "react"
import containerStyles from "./container.module.css"

export default ({ children }) => (
  <div className={containerStyles.container}>{children}</div>
)
```

```css
//src/components/container.module.css
.container {
  margin: 3rem auto;
  max-width: 600px;
}
```

将`container.module.css`作为css模块引入`container`组件，然后在其他页面引用`container.js`模块。

### CSS-In-JS

以emotion为例：

#### 单独使用

```jsx
import { css, cx } from '@emotion/css'

const color = 'white'

render(
  <div
    className={css`
      padding: 32px;
      background-color: hotpink;
      font-size: 24px;
      border-radius: 4px;
      &:hover {
        color: ${color};
      }
    `}
  >
    Hover to change color.
  </div>
)
```

只需要`emotion/css`模块，可以使用css模板字符串。

#### 在React中使用

```jsx
import { css, jsx } from '@emotion/react'
const color = 'white'
render(
  <div
    css={css`
      padding: 32px;
      background-color: hotpink;
      font-size: 24px;
      border-radius: 4px;
      &:hover {
        color: ${color};
      }
    `}
  >
    Hover to change color.
  </div>
)
```

可以使用css变量。

#### React结合Styled

```jsx
import styled from '@emotion/styled'

const Button = styled.button`
  padding: 32px;
  background-color: hotpink;
  font-size: 24px;
  border-radius: 4px;
  color: black;
  font-weight: bold;
  &:hover {
    color: white;
  }
`
render(<Button>This my button component.</Button>)
```

直接定义成小组件的形式。

## 查询数据

`graphql`模块可以用来查询网站数据。

### 页面查询

```js
import React from "react"
import { graphql } from "gatsby"	//导入graphql模块
import Layout from "../components/layout"

export default ({ data }) => (	//将数据传入
  <Layout>
    <h1>About {data.site.siteMetadata.title}</h1>	//引用数据
    <p>
      We're the only site running on your computer dedicated to showing the best
      photos and videos of pandas eating lots of food.
    </p>
  </Layout>
)
//此处导出查询的内容
export const query = graphql`
  query {
    site {
      siteMetadata {
        title
      }
    }
  }
`
```

此处是将查到的数据对象直接返回给页面。

### 静态查询

`useStaticQuery`可以在组件内返回对象

```js
import React from "react"
import { css } from "@emotion/core"
import { useStaticQuery, Link, graphql } from "gatsby"

import { rhythm } from "../utils/typography"
export default ({ children }) => {
  const data = useStaticQuery(	//接受返回对象
    graphql`
      query {
        site {
          siteMetadata {
            title
          }
        }
      }
    `
  )
  return (
        <h3
          css={css`
            margin-bottom: ${rhythm(2)};
            display: inline-block;
            font-style: normal;
          `}
        >
          {data.site.siteMetadata.title}	//引用
        </h3>
  )
}
```

## 文件查询

Gatsby 网站中的数据可以来自任何地方：API、数据库、CMS、本地文件等等。`gatsby-source-system`插件可以查询文件。

安装：`npm install --save gatsby-source-filesystem`

然后添加到`gatsby-config.js`：

```js
plugins: [
    {
      resolve: `gatsby-source-filesystem`,
      options: {
        name: `src`,
        path: `${__dirname}/src/`,
      },
    },
]
```

重启项目后，打开` http://localhost:8000/___graphql`即可查询。

- 在查询框内输入`ctrl + Enter`可自动填写查询的所有文件。自动显示出id选项，可以增加其他选项再查询。
- 使用自动完成的快捷键`shift + Space`。这将在 `File` 节点上显示可查询的字段。

## 转换markdown文件数据

安装插件：

```shell
npm install --save gatsby-transformer-remark
```

添加到`gatsby-config.js`中：

```js
module.exports = {
  siteMetadata: {
    title: `Pandas Eating Lots`,
  },
  plugins: [
    {
      resolve: `gatsby-source-filesystem`,
      options: {
        name: `src`,
        path: `${__dirname}/src/`,
      },
    },
    `gatsby-transformer-remark`,
  ],
}
```
>>>>>>> 3fa1d74bf977667ad5240f37cc765b56a76de87f

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

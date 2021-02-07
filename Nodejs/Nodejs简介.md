## Node.js是什么

*Node.js* 是一个基于 `Chrome V8 引擎`的 JavaScript 运行环境。其开源与跨平台的特性使得它几乎可以用于构建任何项目。

## 安装

有多种方式安装：

- [官网下载](http://nodejs.cn/download/)安装包。
- `nvm`安装
- Linux系统`apt-get`安装

安装详解：[IBM-Nodejs](https://developer.ibm.com/zh/tutorials/learn-nodejs-installing-node-nvm-and-vscode/)

## 建议

建议在深入研究 Node.js 之前，对 JavaScript 的主要概念有所了解：

- 词汇结构
- 表达式
- 数据类型
- 变量
- 函数
- this
- 箭头函数
- 循环
- 作用域
- 数组
- 模板字面量
- 分号
- 严格模式
- ECMAScript 6、2016、2017



异步编程是 Node.js 的基本组成部分：

- 异步编程与回调
- 定时器
- Promise
- Async 与 Await
- 闭包
- 事件循环

## Nodejs与浏览器的区别

### 适用范围不同

Nodejs可以使用于浏览器以外的环境。

### 生态系统不同

Nodejs没有浏览器提供的`document`、`window`、以及其他所有对象。浏览器也无法使用Nodejs的API，如访问文件系统功能。

### 版本控制不同

Nodejs可以使用所有基于ES6-7-8-9规范的JavaScript，而浏览器升级慢，只能通过Babel将代码转换为与ES5兼容的代码。

### 标准不同

Node.js 使用 CommonJS 模块系统，而在浏览器中，则还正在实现 ES 模块标准。

在实践中，这意味着在 Node.js 中使用 `require()`，而在浏览器中则使用 `import`。

## Node.js 组成架构

![**Node.js 架构堆栈**](https://developer.ibm.com/developer/default/tutorials/learn-nodejs-tour-node/images/figure-1.png)

- [Node API](https://nodejs.org/dist/latest-v10.x/docs/api/)：JavaScript 实用程序（如文件和网络 I/O）以及其他许多实用程序（如加密和压缩）
- Node Core：一组 JavaScript 模块，用于实现 Node API。（显然，有些模块依赖于 libuv 和其他 C++ 代码，但这属于实现细节。）
  - JavaScript 引擎：Chrome 的 V8 引擎：一个快速的“JavaScript 到机器”代码编译程序，用于加载、优化和运行 JavaScript 代码
  - 事件循环：使用称为 libuv 的事件驱动型非阻塞 I/O 库来实施，使其实现轻量化和高效 （且可扩展）

## REPL

安装 Node 时，会自动建立 Read-Eval-Print-Loop (REPL) 环境。这并不是 Node 仿真器。实际上，它 就是 Node。

- 进入：命令行输入`node`

- 操作：`.help`

  ```shell
  > .help
  .break    Sometimes you get stuck, this gets you out
  .clear    Alias for .break
  .editor   Enter editor mode
  .exit     Exit the repl
  .help     Print this help message
  .load     Load JS from a file into the REPL session
  .save     Save all evaluated commands in this REPL session to a file
  >
  ```

  
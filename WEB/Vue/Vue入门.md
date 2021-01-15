## Vue是什么

## 安装使用

### 1.CDN引入

在html页面中添加下行代码即可引入Vue：

```html
<script src="https://unpkg.com/vue@next"></script>
```



## 核心概念

### 

### 声明式渲染

Vue.js核心是一个**通过模板语法来声明式渲染数据到DOM**的系统。

```html
<div id="counter">
    Counter: {{ count }}
</div>
```

```js
const Counter = {
    data() {
        return {
            count: 0
        }
    }
}
Vue.createApp(Counter).mount('#counter')
```

- `createApp()`：用于创建一个实例，其中的参数为根组件的配置，是渲染的起点
- `mount()`：用于将创建的实例挂载到DOM元素中，并**返回根组件实例**。

### 组件实例

通过`createApp()`创建新的应用实例，即根组件，然后可以在其中注册其他组件。

```js
const app = Vue.createApp({/* ... */})
app.component('searchBtn',SearchBtnComponent)
app.directive('focus', FocusDirective)
app.use(LocalePlugin)
//也支持链式调用
Vue.createApp({})
  .component('SearchInput', SearchInputComponent)
  .directive('focus', FocusDirective)
  .use(LocalePlugin)
```

每个组件将有自己的组件实例 `vm`。对于一些组件，如 `TodoItem`，在任何时候都可能有多个实例渲染。这个应用中的所有组件实例将共享同一个应用实例。

#### 组件选项

定义了实例在生命周期的不同阶段的可操作项，可以将实例的属性（property）暴露出去。

- `data`：一个函数，其返回一个对象。

  本身以 `$data` 的形式存储在组件实例中。该对象的任何顶级 property 也直接通过组件实例暴露出来。

  需要用的属性最好都添加，不确定的值用`null`或`undefined`占位。如果不添加或者是后续添加的值，不会被Vue响应追踪。

  避免使用`$`和`_`开头的前缀。

- `methods`：一个对象，包含向组件添加的方法。

  Vue 自动为 `methods` 绑定 `this`，以便于它始终指向组件实例。定义方法时，**避免使用箭头函数因为这会阻止 Vue 绑定恰当的 `this` 指向**。

  一般用于事件监听，主动访问多使用计算属性。

- `computed`：一个对象，包括一些负责复杂计算的函数。

  ```js
  computed: {
      //getter
  	moreFruits() {
  		return this.mythings.books.length >= 3 ? "是" : "没有"
  	}
      //setter
      set(newVal) {
          const names = newValue.split(' ')
        	this.firstName = names[0]
        	this.lastName = names[names.length - 1]
      }
  }
  ```

  **计算属性与方法的区别**：计算属性只在相关响应式依赖发生改变时它们才会重新求值，否则返回之前的结果。

- props`：

- `inject`：

- `setup`：

#### 组件实例的property

```js
const app = Vue.createApp({
    data() {
        return {
            count: 4
        }
    },
    methods: {
        add() {
            this.count++
        }
    }
})
```

组件实例的所有 property都可以在组件的模板中访问。也可以通过根组建实例vm访问。如上访问count可以使用`vm.$data.count`或者直接使用`vm.count`。访问`add()`函数只能使用`vm.add`。

Vue 还通过组件实例暴露了一些内置 property，如 `$attrs` 和 `$emit`。这些 property 都有一个 `$` 前缀，以避免与用户定义的 property 名冲突。

### 模板语法

模板中的内容为表达式，如`{{ exp }}`和`v-bind="exp"`。

1. 双大括号`{{ ... }}`

   ```html
   <span>Message: {{ msg }}</span>
   ```

   `{{ ... }}`中可以是值也可以是表达式

2. 输出html

   ```html
   <p v-html="rawHtml"></p>
   ```

   `<p>`内容将会被替换成为 property 值 `rawHtml`，而且会忽略其中的数据绑定。**慎用**

3. HTML标签属性

   ```html
   <button :disabled="show">鬼一样的按钮</button>
   ```

   如果`show`的值为`true`，则其不可点击。

4. JS表达式

   所有的数据绑定都可以使用数据表达式。**不可为语句或者条件结构**。

   ```js
   {{ number + 1 }} 
   {{ ok ? 'YES' : 'NO' }} 
   {{ message.split('').reverse().join('')}}
   ```

   ```html
   <div v-bind:id="'list-' + id"></div>
   ```

   

### 数据绑定

不需要重复渲染DOM

### 指令

以前缀`v-`开头的属性（attribute），指令的职责是，当表达式的值改变时，将其产生的连带影响，响应式地作用于 DOM。

- 参数：每个指令后可以跟一个参数，如`v-bind:url`。

- 动态参数：可以为动态属性或动态事件绑定

  ```html
  <a v-bind:[attributeName]="url"> ... </a>
  <a v-on:[eventName]="doSomething"> ... </a>
  ```

  注意参数表达式不可包括空格和引号，或者用计算属性代替。

- 修饰符：`.`指明的特殊后缀，用于指出一个指令应该以特殊方式绑定。例如，`.prevent` 修饰符告诉 `v-on` 指令对于触发的事件调用 `event.preventDefault()`：

  ```html
  <form v-on:submit.prevent="onSubmit">...</form>
  ```

常用指令

- `v-model`：实现表单输入和应用状态之间的双向绑定。
- `v-bind:url`或`:url`：
- `v-on:click`或`@click`：事件监听。
- `v-if`：
- `v-for`：

### 响应式


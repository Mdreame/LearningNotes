## npm

npm（node package manager）nodejs的包管理器，用于node插件管理（包括安装、卸载、管理依赖等）。

## nvm

node版本管理器

### windows版本

```shell
$ nvm list available	//列举可用版本
$ nvm install <version>
$ nvm uninstall <version>
$ nvm use <version>	//切换版本
$ nvm version
```

从特定版本导入到我们将要安装的新版本 Node：

```shell
nvm install v5.0.0 --reinstall-packages-from=4.2
```

参考：

- [nvm安装和使用](https://titangene.github.io/article/nvm.html)

- [我的博客](https://mdreame.gitee.io/2020/09/15/%E4%BD%BF%E7%94%A8nvm%E5%AE%89%E8%A3%85%E7%AE%A1%E7%90%86node%E5%92%8Cnpm/)

## nrm

nrm（NPM registry manager）是一个NPM源管理器。

### 安装

```shell
npm install -g nrm
```

### 查看源列表

```shell
$ nrm ls //

* npm -------- https://registry.npmjs.org/
  yarn ------- https://registry.yarnpkg.com/
  cnpm ------- http://r.cnpmjs.org/
  taobao ----- https://registry.npm.taobao.org/
  nj --------- https://registry.nodejitsu.com/
  npmMirror -- https://skimdb.npmjs.com/registry/
  edunpm ----- http://registry.enpmjs.org/
```

带`*`的是当前使用的源。

### 切换源

```shell
$ nrm use cnpm 	//
	Registry has been set to: http://r.cnpmjs.org/
```

### 测速

```shell
$ nrm test \nrm test <registry>

  npm ---- 5358ms
  yarn --- 3182ms
* cnpm --- 7146ms
  taobao - 744ms
  nj ----- Fetch Error
  npmMirror  2388ms
  edunpm - Fetch Error
```

显示error则不可用

### 常用操作

```shell
nrm add <registry> <url> //增加源
nrm del <registry>	//删除源

nrm -V/--version
nrm -h/--help
```

#### 






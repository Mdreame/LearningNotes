# git命令免重复输入密码

## Linux下的方法

1. 创建`.git-credentials`文件，进入并写入内容：

   ```shell
   cd ~
   touch .git-credentials
   vim .git-credentials
   https://{username}:{password}@github.com
   ```

   其中`github.com`可替换为仓库地址。

2. 执行：

   ```shell
   git config --global credential.helper store
   ```

   注意：`credential`结尾没有`s`。

3. 打开`~/.gitconfig`文件，会多出来一项：

   ```shell
   [credential]
   	helper = store
   ```

其实直接执行步骤2中的命令也可以，只是git时需要输入一次用户名和密码，之后也可以免密登录。

## Windows下的方法

### 方法一

此方法同上面，只是第一步创建`git-credentials`有点不同。

在`%HOME%`目录中，一般为`C:\users\Administrator`，也可以是你自己创建的系统用户名目录，反正都在`C:\users\`中。文件名为`.git-credentials`,由于在Window中不允许直接创建以"."开头的文件，所以需要借助git bash进行，打开git bash客户端，进行`%HOME%`目录，然后用`touch`创建文件 `.git-credentials`, 然后后面的操作同上面。

### 方法二

**1. 添加环境变量**

在windows中添加一个HOME环境变量，变量名:`HOME`,变量值：`%USERPROFILE%`。

**2. 创建git用户名和密码存储文件**

进入`%HOME%`目录，新建一个名为"_netrc"的文件，文件中内容格式如下：

```shell
machine {git account name}.github.com
login your-usernmae
password your-password
```

重新打开git bash即可，无需再输入用户名和密码。



## 给密码设定生效时长

```shell
git config credential.helper 'cache --timeout=3600'
```


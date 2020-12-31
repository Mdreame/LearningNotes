# Linux下安装常用软件

## 1.Linux下安装nodejs

1. 首先去[官网](https://nodejs.org/en/download/)或者[中文网](http://nodejs.cn/download/)下载node，解压后进入该目录，检查一下是否有node和npm文件。

   ```shell
   tar -xvf node-v14.15.1-linux-x64.tar.xz   
   ```

   

2. 将其重命名并放到自己喜欢的位置。

   ```shell
   mv node-v14.15.1-linux-x64 ~/Desktop/Coding/SoftWare/nodejs
   ```

   如我的位置：

   ![image-20201205112621416](image.png)

   

3. 建立软链接

```shell
ln -s ~/Desktop/Coding/SoftWare/nodejs/bin/npm /usr/local/bin/
ln -s ~/Desktop/Coding/SoftWare/nodejs/bin/node/usr/local/bin/
```

若提示`ln: 无法创建符号链接'/usr/local/bin/npm': 权限不够`，切换到`sudo`输入密码就好了。

```shell
sudo ln -s ~/Desktop/Coding/SoftWare/nodejs/bin/npm /usr/local/bin/
sudo ln -s ~/Desktop/Coding/SoftWare/nodejs/bin/node/usr/local/bin/
```



------

参考：

- [Linux下Nodejs安装（完整详细）](https://blog.csdn.net/dwjpeng2/article/details/82994321)
- [[nodejs的安装配置]](https://www.linuxprobe.com/nodejs-install-conf.html)



## 2.cnpm

1. 终端运行：

   ```shell
   $ npm install -g cnpm --registry=https://registry.npm.taobao.org
   ```

   安装成功后显示：

   ```shell
   npm WARN deprecated request@2.88.2: request has been deprecated, see https://github.com/request/request/issues/3142
   npm WARN deprecated har-validator@5.1.5: this library is no longer supported
   /home/mdreame/Desktop/Coding/SoftWare/nodejs/bin/cnpm -> /home/mdreame/Desktop/Coding/SoftWare/nodejs/lib/node_modules/cnpm/bin/cnpm
   + cnpm@6.1.1
   added 689 packages from 972 contributors in 31.618s
   ```

2. 建立软链接

   ```shell
   $ sudo ln -s /home/mdreame/Desktop/Coding/SoftWare/nodejs/bin/cnpm /usr/local/bin/cnpm
   ```

   其中安装的位置在前一步有提示。

   验证`cnpm -v`：

   ```shell
   cnpm@6.1.1 (/home/mdreame/Desktop/Coding/SoftWare/nodejs/lib/node_modules/cnpm/lib/parse_argv.js)
   npm@6.14.9 (/home/mdreame/Desktop/Coding/SoftWare/nodejs/lib/node_modules/cnpm/node_modules/npm/lib/npm.js)
   node@14.15.1 (/home/mdreame/Desktop/Coding/SoftWare/nodejs/bin/node)
   npminstall@3.28.0 (/home/mdreame/Desktop/Coding/SoftWare/nodejs/lib/node_modules/cnpm/node_modules/npminstall/lib/index.js)
   prefix=/home/mdreame/Desktop/Coding/SoftWare/nodejs 
   linux x64 5.4.70-amd64-desktop 
   registry=https://r.npm.taobao.org
   ```




## 3.nvm

首先去[官网下载](https://github.com/nvm-sh/nvm)。

```shell
tar -xzvf nvm-0.37.2.tar.gz
```

然后进入解压后的nvm文件夹：

```shell
cd nvm-0.37.2
```

运行`install.sh`：

```shell
./install.sh
```

重启终端即可使用。

## 4.Vue

1. 运行：

   ```shell
   cnpm install vue
   cnpm install -g vue-cli
   ```

   完成之后提示安装路径：

   ```shell
   All packages installed (233 packages installed from npm registry, used 5s(network 4s), speed 1.13MB/s, json 220(473.53kB), tarball 4.55MB)                      
   [vue-cli@2.9.6] link /home/mdreame/Desktop/Coding/SoftWare/nodejs/bin/vue@ -> /home/mdreame/Desktop/Coding/SoftWare/nodejs/lib/node_modules/vue-cli/bin/vue
   [vue-cli@2.9.6] link /home/mdreame/Desktop/Coding/SoftWare/nodejs/bin/vue-init@ -> /home/mdreame/Desktop/Coding/SoftWare/nodejs/lib/node_modules/vue-cli/bin/vue-init
   [vue-cli@2.9.6] link /home/mdreame/Desktop/Coding/SoftWare/nodejs/bin/vue-list@ -> /home/mdreame/Desktop/Coding/SoftWare/nodejs/lib/node_modules/vue-cli/bin/vue-list
   ```

2. 建立软链接

   ```shell
   sudo ln -s /home/mdreame/Desktop/Coding/SoftWare/nodejs/bin/vue /usr/local/bin/vue
   ```

   
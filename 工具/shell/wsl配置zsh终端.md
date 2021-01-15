## WSL下载和配置

1. win10下`win + Q`或者打开设置搜索“启用或关闭windows功能”选项；

   ![turn-on-wsl](https://picture.mdreame.life/turn-on-wsl.png)

2. 勾选“适用于Linux的Windos子系统”选项，保存重启电脑；

3. 再windos商店搜索"Linux"，选择一个Linux版本下载；

4. 安装完成后，启动会出现如下界面（我已配置完成），等待系统初始化后，设置用户名和密码就可以使用。

   ![wsl-ubuntu.png](https://picture.mdreame.life/wsl-ubuntu.png)

## Windows Terminal启用WSL

1. 在商店下载Windows Terminal，安装好后`win + Q`输入`wt`快捷键即可启动；

2. 点击标题栏下拉按钮，选择刚配置好的WSL环境；

   ![wt-choose-wsl](https://picture.mdreame.life/wt-choose-wsl.png)

## 更换镜像源

为了使用内置的安装下载更换，需要将源更换成清华或者淘宝镜像。

1. 先备份好默认的源文件；

   ```shell
   sudo mv /etc/apt/sources.list /etc/apt/sources.list.bak
   ```

2. 选择与自己WSL系统版本一致的[清华镜像](https://link.zhihu.com/?target=https%3A//mirrors.tuna.tsinghua.edu.cn/help/ubuntu/)，复制地址粘贴到`sources.list`文件；

   ```shell
   sudo vim sources.list
   ```

3. 更新仓库；

   ```shell
   sudo apt-get update && sudo apt-get upgrade
   ```

4. 中文乱码问题：

   1. 找到`/etc/enviroment`文件，在末尾添加下行：

      ```shell
      export LC_ALL="zh_CN.UTF-8"
      ```

   2. 执行：

      ```shell
      sudo locale-gen zh_CN.UTF-8
      ```

   3. 空格乱码，安装中文字体

      ```shell
      sudo apt-get install fonts-droid-fallback ttf-wqy-zenhei ttf-wqy-microhei fonts-arphic-ukai fonts-arphic-uming
      ```

## zsh下载和oh-my-zsh

见



参考：

- [Windows10 子系统(WSL)的配置和使用](https://zhuanlan.zhihu.com/p/90173113)

- [【WSL+Docker】新手Win10下的WSL Ubuntu18并使用Docker（两种方式）](https://zhuanlan.zhihu.com/p/61542198)
## 准备

- 查看当前shell

  ```shell
  echo $SHELL
  ```

- 查看系统自带哪些shell

  ```shell
  cat /etc/shells
  ```



## 安装zsh

- deepin/debian

  ```shell
  sudo apt-get install zsh
  ```

- 将`zsh`设置为默认shell

  ```shell
  chsh -s /bin/zsh
  ```

  可以通过`echo $SHELL`来查看是否操作成功。

## 安装oh-my-zsh

- 自动安装

  ```shell
  wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | sh
  ```

- 手动安装

  ```shell
  git clone git://github.com/robbyrussell/oh-my-zsh.git ~/.oh-my-zsh 
  cp ~/.oh-my-zsh/templates/zshrc.zsh-template ~/.zshrc
  ```

  完成之后执行`source ~/.zshrc`更新配置。

### 主题配置

查看已有主题

```shell
ls ~/.oh-my-zsh/themes
```

修改`~/.zshrc`文件中的`ZSH_THEME="agnoster"`，即可更换主题。

![agnoster主题](https://picture.mdreame.life/oh-my-zsh.png)

我喜欢的是`agnoster`主题,如上图。使用这个主题需要安装更纱字体，否则在命令行的图标显示不出小三角。

- 点击[下载更纱字体](https://github.com/be5invis/Sarasa-Gothic/releases/download/v0.16.5/sarasa-gothic-ttf-0.16.5.7z);
- 将字体解压放到系统字体文件夹，如`/usr/share/fonts`;
- 更换终端字体并重启就可以显示了。

### 常用命令

- 敲 zsh_stats 可以看到你的使用频率前 20 的命令是什么！ 

- take 看看 which take 就知道它有什么用了 

- clipcopy 和 clippaste，剪贴板和命令行的交互

## 插件

### autojump

[autojump](https://github.com/wting/autojump) 可以实现快捷跳转目录，但必须是曾经进入过的目录才能跳转。支持模糊匹配。

- 安装

  ```shell
  sudo apt-get install autojump
  ```

  安装好之后，打开`~/.zshrc`，在plugins一行中增加autojump，如`plugins=(git autojump)`，另外还需要添加一行：

  ```shell
  [[ -s ~/.autojump/etc/profile.d/autojump.sh ]] && . ~/.autojump/etc/profile.d/autojump.sh
  ```

  执行`source ~/.zshrc`更新配置。

- 常用操作

  - `j <directory>`：跳转到文件夹。如果曾经打开某个文件夹，则会直接补全中间路径。
  - `jc <subDirectory>`：跳转到子文件夹
  - `jo images `：打开文件管理器目录
  - `jco github-img `：打开子目录
  - `j --stat`：查看路径权重状态



参考：

- [这篇 iTerm2 + Oh My Zsh 教程手把手让你成为这条街最靓的仔](https://segmentfault.com/a/1190000022813972)
- [Powerlevel9k：zsh下最棒的Powerline主题](https://www.thisfaner.com/p/powerlevel9k-zsh/)
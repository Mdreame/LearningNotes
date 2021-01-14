[toc]

## 1.GitHub 镜像访问

这里提供两个最常用的镜像地址：

-  [https://github.com.cnpmjs.org/](https://github.com.cnpmjs.org/)
- [https://hub.fastgit.org/](https://hub.fastgit.org/)

也就是说上面的镜像就是一个克隆版的Github，你可以访问上面的镜像网站，网站的内容跟Github是完整同步的镜像，然后在这个网站里面进行下载克隆等操作。



## 2.GitHub文件加速

利用 Cloudflare Workers 对` github release` 、`archive` 以及项目文件进行加速，部署无需服务器且自带CDN。

- [https://gh.api.99988866.xyz](https://gh.api.99988866.xyz/)

- [GitHub 文件加速](https://ghproxy.com/)

以上网站为演示站点，如无法打开可以查看开源项目：[gh-proxy-GitHub 文件加速]([开源分享：gh-proxy--基于cloudflare workers的GitHub文件加速](https://link.zhihu.com/?target=https%3A//hunsh.net/archives/23/))自行部署。



## 3.Github 加速下载

只需要复制当前 GitHub 地址粘贴到输入框中就可以代理加速下载！

[GitHub 加速下载 - 在线工具](https://toolwa.com/github/)



## 4.谷歌浏览器GitHub加速插件(推荐)

[ 谷歌浏览器Github加速插件.crx 下载]([https://chrome.google.com/webstore/detail/github%E5%8A%A0%E9%80%9F/mfnkflidjnladnkldfonnaicljppahpg/related?hl=zh-CN](https://link.zhihu.com/?target=https%3A//chrome.google.com/webstore/detail/github%E5%8A%A0%E9%80%9F/mfnkflidjnladnkldfonnaicljppahpg/related%3Fhl%3Dzh-CN))

百度网盘: [https://pan.baidu.com/s/1qGiIUzqNlN1ZczTNFbPg0A](https://pan.baidu.com/s/1qGiIUzqNlN1ZczTNFbPg0A),提取码：stsv

如果可以直接访问谷歌商店，可以访问[GitHub 加速谷歌]([https://chrome.google.com/webstore/detail/github%E5%8A%A0%E9%80%9F/mfnkflidjnladnkldfonnaicljppahpg](https://link.zhihu.com/?target=https%3A//chrome.google.com/webstore/detail/github%E5%8A%A0%E9%80%9F/mfnkflidjnladnkldfonnaicljppahpg))商店安装。



## 5.通过Gitee中转fork仓库下载

网上有很多相关的教程，这里简要的说明下操作。

1. 访问gitee网站： <[码云 - 基于 Git 的代码托管和研发协作平台](https://link.zhihu.com/?target=https%3A//gitee.com/)> 并登录，在顶部选择“从GitHub/GitLab导入仓库”

2. 在导入页面中粘贴你的Github仓库地址，点击导入即可

3. 等待导入操作完成，然后在导入的仓库中下载浏览对应的该GitHub仓库代码，你也可以点击仓库顶部的“刷新”按钮进行Github代码仓库的同步。



## 6.通过修改HOSTS文件进行加速

通过IP查询获取，github的实时地址，添加到hosts文件。

1、修改[C:\Windows\System32\drivers\etc\hosts](C:\Windows\System32\drivers\etc\hosts)文件的权限，指定可写入：

右击->hosts->属性->安全->编辑->点击Users->在Users的权限“写入”后面打勾。

2、右击->hosts->打开方式->选定记事本（或者你喜欢的编辑器）->在末尾处添加以下内容：

```TXT
199.232.69.194 github.global.ssl.fastly.net
140.82.114.4 github.com
```
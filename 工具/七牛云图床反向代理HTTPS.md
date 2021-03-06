## 1.域名准备
首先需要有一个已经备案的域名，然后我们新建三个三级域名备用。
如我的域名是`mdreame.life`，则新建的域名为：
- photo.mdreame.life：映射的本地静态资源使用域名，也就是七牛镜像使用的镜像源域名，使用http即可。
- img.mdreame.life：七牛云存储空间绑定的自定义域名，使用http即可。
- picture.mdreame.life：映射的在浏览器中实际访问的静态资源域名，必须是https。

这一步需要将三个域名添加到解析。其中主机记录填写自己的域名的前缀，其他保持默认，而七牛云绑定的域名需要设置成CNAME，下面介绍。

![解析示例](https://picture.mdreame.life/qiniuyun2.png)

向photo.mdreame.life上传一张图片测试解析是否成功，我的服务器是腾讯云Linux主机，通过宝塔面板上传，其中nginx的路径配置为
```nginx
server 
{
	listen: 80;
    server_name photo.mdreame.life;
    index index.php index.html index.htm default.php default.htm default.html;
    root /www/wwwroot/photo.mdreame.life/img; #这里在网站根目录新建img文件夹存放图片，并设置为默认访问路径
}
```

然后访问`http://photo.mdreame.life/test.jpg`，可以正常显示说明解析成功。


## 2.七牛云空间申请
首先需要[注册七牛云帐号](https://www.qiniu.com/)，并且实名认证。
完成之后进入对象存储，选“空间管理-新建空间”，输入想要的空间名称，选择区域和公开访问。

![新建空间](https://picture.mdreame.life/qiniuyun1.png)

创建完成之后，进入空间，选择自定义域名：

![解析示例](https://picture.mdreame.life/qiniuyun3.png)

这一步的目的是使图片可以通过七牛云正常访问到。需要创建自己的域名，因为七牛云默认提供的域名只有30天的有效期。

成功后，七牛云会提供一个CNAME的值，复制该值，到域名解析页面添加该记录值。（[如何配置CNAME](https://developer.qiniu.com/fusion/kb/1322/how-to-configure-cname-domain-name)）。

![生成CNAME](https://picture.mdreame.life/qiniuyun4.png)

完成后返回空间，选择“文件管理-上传文件”，本地上传一张图片“test.jpg”，然后访问`http://img.mdreame.life/test.jpg`，如果域名解析正确的话应该可以正常显示。

## 3.七牛云镜像访问
这一步的目的是通过七牛云`img.mdreame.life`来访问自己服务器的`photo.mdreame.life`上的图片。如果上传图片到自己的服务器，七牛云访问过一次，那么图片资源会被存储到七牛云，之后自己服务器的图片删除了也没关系。

进入七牛云管理控制台，选择“CDN-域名管理-回源配置-修改配置”，按下图配置：

![回源配置](https://picture.mdreame.life/qiniuyun5.png)

向photo.mdreame.life上传一张测试图片`hi.jpg`，然后点击“源站测试”即可。若不成功可能路径有问题，请对照前面步骤仔细查看。

这一步完成即可通过`img.mdreame.life`来访问自己服务器上的资源了。

## 4.反向代理HTTPS
对于免费用户，七牛云每个月给予10G的流量，然而只限于http访问，https访问是需要额外收费的。为了实现https访问，需要自己准备一个域名，即`picture.mdreame.life`，并安装ssl证书。

### 申请证书
个人用户可以申请免费证书，我用的是腾讯云的[免费证书](https://console.cloud.tencent.com/ssl)，时效一年。
将申请的证书下载并解压上传到自己的服务器，记住路径。

### 配置nginx
由于不熟悉nginx的配置，导致访问是总是出现404,找了半天发现是location的问题，路径有优先顺序，见[Ngnix中location与proxy_pass配置规则总结](https://blog.csdn.net/oMaoYanEr/article/details/82557764)。

nginx配置如下：
```nginx
server
{
    listen 80;
	listen 443 ssl http2;
    server_name picture.mdreame.life;
    index index.php index.html index.htm default.php default.htm default.html;
    root /www/wwwroot/picture.mdreame.life;
 
    if ($server_port !~ 443){
        rewrite ^(/.*)$ https://$host$1 permanent;	#将http转为https
    }
    
    ssl_certificate    /www/server/panel/vhost/cert/picture.mdreame.life/fullchain.pem;	 #证书路径
    ssl_certificate_key    /www/server/panel/vhost/cert/picture.mdreame.life/privkey.pem;	#密钥路径
    ssl_protocols TLSv1.1 TLSv1.2 TLSv1.3;
    ssl_ciphers EECDH+CHACHA20:EECDH+CHACHA20-draft:EECDH+AES128:RSA+AES128:EECDH+AES256:RSA+AES256:EECDH+3DES:RSA+3DES:!MD5;
    ssl_prefer_server_ciphers on;
    ssl_session_cache shared:SSL:10m;
    ssl_session_timeout 10m;
    add_header Strict-Transport-Security "max-age=31536000";
    error_page 497  https://$host$request_uri;
	
    location / {
      proxy_pass http://img.mdreame.life/;	定位到七牛云
    }
```

弱国使用宝塔面板输入密钥和证书，则会自动添加到ssl配置中，否则，需要自己将路径分别修改为之前安装ssl的路径。

这样就实现在自己的服务器上传图片、管理证书，用七牛云做存储，并且可以通过https访问了。主要是不费钱。


## 5.批量上传图片
### ftp工具
上传图片到自己服务器。

### 图形化工具 Kodo Browser
Kodo Browser 是七牛对象存储提供的图形化管理工具，支持用户通过可视化页面进行上传、下载等操作。

[下载地址](https://developer.qiniu.com/kodo/tools/5972/kodo-browser)

### 命令行工具qshell
1. 推荐通过命令行方式上传，首先进入七牛云提供的[下载页面](https://developer.qiniu.com/kodo/tools/1302/qshell#2)，根据机型选择对应版本，例如我用的是deepin，选择Linux amd64。

2. 将软件安装到你想要的位置，完成之后，需要为qshell建立软链接，这样在任何位置都可以使用其命令了。

	终端输入：
	```shell
	sudo ln -s ~/Desktop/SoftWare/qshell /usr/local/bin/qshell
	```

	第一个地址是安装路径，第二个是用户环境变量的目录。
3. 在终端中输入`qshell`命令，出现列表即安装成功。

---

参考：
- [使用反向代理方式配置七牛镜像存储为自定义域名并使用HTTPS](https://www.ktanx.com/blog/p/5057)
- [七牛云图床和Markdown使用](https://www.cnblogs.com/ssgeek/p/10854839.html)
- [七牛云-CDN常见问题](https://blog.csdn.net/PEACEFUL000/article/details/77503770#commentBox)
- [七牛镜像存储使用手册](https://developer.qiniu.com/kodo/kb/1376/seven-cattle-image-storage-instruction-manuals)
## 安装
### win10
去[官网下载](https://www.mongodb.com/try/download/community)对应版本。

### Linux安装
#### 源安装

#### 解压包安装
在官方下载界面的下载按钮一侧有一个下载链接，先复制，再打开终端下载，如：
```shell
wget https://fastdl.mongodb.org/linux/mongodb-linux-x86_64-rhel70-4.4.2.tgz
```

安装配置过程中可能出现一系列意外情况导致mongodb无法启动，比如文件权限不对，或者之前安装过没有卸载干净，可以通过命令行提示一步一步排查。
```shell
journalctl -xe
```

可能出现的问题：
- [记一次死坑，mongodb无法启动报错 reason: errno:111 Connection refused](https://blog.csdn.net/sinat_38385185/article/details/82699948#commentBox)
- [添加了IP限制的mongod重启出错：Job for mongod.service failed because the control process exited with error code](https://www.crifan.com/mongodb_add_multiple_ip_restriction_restart_mongod_fail_job_for_mongod_service_failed/)


有一次在宝塔面板上安装过，但是没有卸载干净，后来看官网文档删除：
```shell
sudo yum erase $(rpm -qa | grep mongodb-org)
sudo rm -r /var/log/mongodb
sudo rm -r /var/lib/mongo
```

之后重新安装，按步骤可以连接。

---

参考：
- [官方文档](https://docs.mongodb.com/manual/tutorial/install-mongodb-on-red-hat/)
- [MongoDB 在windows服务器安装部署与远程访问配置](https://juejin.cn/post/6844903745684242446#heading-0)
- [在阿里云centos下部署mongodb教程](https://www.yisu.com/zixun/146447.html)
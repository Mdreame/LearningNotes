## SSH是什么

SSH（Secure Shell）是一种网络协议，与HTTP、FTP等类似。但SSH可以对信息进行加密，且支持各种身份验证机制。

实际场景中，主要用于保证远程登录和远程通信的安全，任何网络服务都可以用这个协议来加密。

### OpenSSH

目前，OpenSSH是SSH2最流行的的一种实现，并且开源。Linux 的所有发行版几乎都自带 OpenSSH。（阮一峰-[SSH历史](https://wangdoc.com/ssh/basic.html#%E5%8E%86%E5%8F%B2))

> SSH 的软件架构为C/S模式。OpenSSH 的实现中，客户端为 ssh；服务器为 sshd。（通常约定，大写的 SSH 表示协议，小写的 ssh 表示客户端软件。）

OpenSSH 还提供一些辅助工具软件（比如 ssh-keygen 、ssh-agent）和专门的客户端工具（比如 scp 和 sftp）。

## SSH原理



## SSH用途



如何使用
### 创建密钥对
ssh-keygen -t rsa -C 'git key for github' -f ~/.ssh/id_rsa
ras 加密方式
'git key for github' 注释
~/.ssh/id_rsa 保存路径
### 配置github公钥
填入.pub文件公钥
### 测试连接
本地 ssh -T git@github.com
Hi nian0122! You've successfully authenticated, but GitHub does not provide shell access.
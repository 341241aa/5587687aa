# GitHub
> 软件研发工程工具类网站，世界范围影响力较大的项目托管网站，大量私人/企业项目托管发布，拥有海量开源内容

## github网站访问
- Tiopic：分类查看
- trending：推送查看
- 搜索栏：按关键字查询内容
- 按标签查询：`sample`，`tutorial`
- 示例：`xxxx sample`

## 项目结构
**仓库**：工程存储单位，一般一个仓库存储一个独立项目，一个用户可以拥有若干仓库

- `CODE`：存储开源数据、源代码；用户下载开源项目，下载的就是code内全部内容
- `ISSUES`：问答板块，用于解决项目异常、提交bug
- `README.md`：工程自述文件，项目介绍、版本答疑，使用markdown语言编写
- 许可证：`GPL 3.0`、`Apache 2.0`、`MIT`，给使用者最小的限制，最大的权力（法务问题）

## git的配置，工程的上传下载
> 云端仓库  (托管在github中)
1. 设备认证，生成密钥串，粘贴到github账户，让设备受信任，后续可上传内容
2. 创建本地仓库，出现`(master)`标志，代表当前处于仓库目录；git仓库默认隐藏文件，创建命令：`git init`

### 关于(Master)分支概念
分支：资源存储单位。仓库包含分支，默认仓库都有主分支，默认所有数据向主分支存储；一个仓库可以创建多个分支。
多人协作开发，可对分支进行管理/合并，相关命令：创建分支，删除分支，分支选择等。

> 分支流程说明
> 仓库 → master主分支 → 工程基础框架
> 仓库 → transform
> 仓库 → branch
> 仓库 → branch
> 后续上传规则：分支名相同则合并，不同则在云端创建新分支，存储用户上传内容

```bash
ssh -T git@github.com #测试设备是否关联成功
git config --list #查看git本地配置文件
git config --global user.email "you email"
git config --global username "you name"
```
### 生成密钥文件，传输加密方式选择非对称 rsa 加密，（设备指纹）
```bash
ssh-keygen -t rsa -C "you email"   记住密钥的生成位置，找到密钥文件，复制密钥串
```
根据提供的位置，打开.pub密钥文件，复制其中密钥字符串，粘贴到指定位置
头像 (menu) --> Settings -> SSH and GPG key --> New SSH key --> 粘贴密钥 --> add SSH key
再次使用下面命令测试关联
```bash
ssh -T git@github.com
```
### 本地数据上传过程，以及版本更新
相互的依赖关系，本地方为新版，云端为旧版（发行版），版本更新使用本地新内容同步给云端
了解本地数据到云端同步 (增、删、改)

##### 掌握 git 命令，Git 全程分布式版本控制系统，可以让开发者在本地电脑通过命令远程访问修改仓库的数据和内容

* 上传可以以目录为单位，也可以是单个文件
* 使用 git remote 命令创建 ssh 地址别名

```bash
git remote add origin git@github.com:8341241aa/5587687aa.git
git remote remove origin #删除别名
```
![截图](https://i.imgs.ovh/2026/09/17/b39a2449a59fe1ee57709f42db6b588d.jpg)

### commit 提交
用户的每次提交，commit 系统进行代码的备份，进行交叉对比，有一个提交列表，存储这份备份，可以通过提交功能，回溯到任意时候删除或修改的位置

### 下载开源项目
所有以 git 仓库为单位的操作都与开发有关，只是打包下载源代码和资源文件而已
* 命令下载
```bash
git clone "工程https地址"
```


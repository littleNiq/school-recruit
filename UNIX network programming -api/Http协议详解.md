# 一、概念
协议是指计算机通信网络中两台计算机之间进行通信所必须共同遵守的规定或规则，超文本传输协议(HTTP)是一种通信协议，它允许将超文本标记语言(HTML)文档从Web服务器传送到客户端的浏览器。
[http://www.jianshu.com/p/59126c9d9bbf]

## ARQ
它包括停止等待ARQ协议和连续ARQ协议，错误侦测（Error Detection）、正面确认（Positive Acknowledgment）、逾时重传（Retransmission after Timeout）与负面确认继以重传（Negative Acknowledgment and Retransmission）等机制。

## GET和POST的区别：

        GET提交的数据会放在URL之后，以?分割URL和传输数据，参数之间以&相连，如EditPosts.aspx?name=test1&id=123456. POST方法是把提交的数据放在HTTP包的Body中。
        GET提交的数据大小有限制，最多只能有1024字节（因为浏览器对URL的长度有限制），而POST方法提交的数据没有限制。
        GET方式需要使用Request.QueryString来取得变量的值，而POST方式通过Request.Form来获取变量的值。
        GET方式提交数据，会带来安全问题，比如一个登录页面，通过GET方式提交数据时，用户名和密码将出现在URL上，如果页面可以被缓存或者其他人可以访问这台机器，就可以从历史记录获得该用户的账号和密码。

## 请求信息：
发出的请求信息格式如下：

        请求行，例如GET /images/logo.gif HTTP/1.1，表示从/images目录下请求logo.gif这个文件。
        （请求）头，例如Accept-Language: en
        空行
        可选的消息体　请求行和标题必须以<CR><LF>作为结尾（也就是，回车然后换行）。空行内必须只有<CR><LF>而无其他空格。在HTTP/1.1协议中，所有的请求头，除post外，都是可选的。
[http://www.cnblogs.com/yaozhongxiao/archive/2013/03/02/2940252.html]

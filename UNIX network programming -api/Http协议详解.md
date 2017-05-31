# 一、概念
协议是指计算机通信网络中两台计算机之间进行通信所必须共同遵守的规定或规则，超文本传输协议(HTTP)是一种通信协议，它允许将超文本标记语言(HTML)文档从Web服务器传送到客户端的浏览器。
[http://www.jianshu.com/p/59126c9d9bbf]

## ARQ
它包括停止等待ARQ协议和连续ARQ协议，错误侦测（Error Detection）、正面确认（Positive Acknowledgment）、逾时重传（Retransmission after Timeout）与负面确认继以重传（Negative Acknowledgment and Retransmission）等机制。

## GET和POST的区别：

        GET提交的数据会放在URL之后，以?分割URL和传输数据，参数之间以&相连，如EditPosts.aspx?name=test1&id=123456. 
        POST方法是把提交的数据放在HTTP包的Body中。
        GET提交的数据大小有限制，最多只能有1024字节（因为浏览器对URL的长度有限制），而POST方法提交的数据没有限制。
        GET方式需要使用Request.QueryString来取得变量的值，而POST方式通过Request.Form来获取变量的值。
        GET方式提交数据，会带来安全问题，比如一个登录页面，通过GET方式提交数据时，用户名和密码将出现在URL上，
        如果页面可以被缓存或者其他人可以访问这台机器，就可以从历史记录获得该用户的账号和密码。

## 请求信息：
发出的请求信息格式如下：

        请求行，例如GET /images/logo.gif HTTP/1.1，表示从/images目录下请求logo.gif这个文件。
        （请求）头，例如Accept-Language: en
        空行
        可选的消息体　请求行和标题必须以<CR><LF>作为结尾（也就是，回车然后换行）。空行内必须只有<CR><LF>而无其他空格。
        在HTTP/1.1协议中，所有的请求头，除post外，都是可选的。
        (在HTTP/1.1 协议中，所有的请求头，除Host外，都是可选的）
[http://www.cnblogs.com/yaozhongxiao/archive/2013/03/02/2940252.html]
## Session的实现方式：
1、使用Cookie来实现:

服务器给每个Session分配一个唯一的JSESSIONID，并通过Cookie发送给客户端。
当客户端发起新的请求的时候，将在Cookie头中携带这个JSESSIONID。这样服务器能够找到这个客户端对应的Session。

2、使用URL回写来实现
URL回写是指服务器在发送给浏览器页面的所有链接中都携带JSESSIONID的参数，这样客户端点击任何一个链接都会把JSESSIONID带会服务器。如果直接在浏览器输入服务端资源的url来请求该资源，那么Session是匹配不到的。
Tomcat对Session的实现，是一开始同时使用Cookie和URL回写机制，如果发现客户端支持Cookie，就继续使用Cookie，停止使用URL回写。如果发现Cookie被禁用，就一直使用URL回写。jsp开发处理到Session的时候，对页面中的链接记得使用response.encodeURL() 。

## URL详解

URL(Uniform Resource Locator) 地址用于描述一个网络上的资源， 基本格式如下  
schema://host[:port#]/path/.../[;url-params][?query-string][#anchor]   
　　scheme 指定低层使用的协议(例如：http, https, ftp)  
　　host HTTP服务器的IP地址或者域名  
　　port# HTTP服务器的默认端口是80，这种情况下端口号可以省略。如果使用了别的端口，必须指明，例如 http://www.cnblogs.com:8080/  
　　path 访问资源的路径  
　　url-params  
　　query-string 发送给http服务器的数据   
　　anchor- 锚   

URL 的一个例子：      

 http://www.mywebsite.com/sj/test;id=8079?name=sviergn&x=true#stuff  

Schema: http  
host: www.mywebsite.com  
path: /sj/test  
URL params: id=8079  
Query String: name=sviergn&x=true  
Anchor: stuff  

## Ssm框架整合
1.整合的思路
*  Dao层
使用mybatis框架。创建SqlMapConfig.xml。  
创建一个applicationContext-dao.xml  
1、配置数据源  
2、需要让spring容器管理SqlsessionFactory，单例存在。  
3、把mapper的代理对象放到spring容器中。使用扫描包的方式加载mapper的代理对象。  

*  Service层   
1、事务管理  
2、需要把service实现类对象放到spring容器中管理。  

*  3表现层  
1、配置注解驱动  
2、配置视图解析器  
3、需要扫描controller  

*  4Web.xml  
1、spring容器的配置  
2、Springmvc前端控制器的配置  
3、Post乱码过滤器  

### 框架整合  
需要把配置文件放到taotao-manager-web工程下。因为此工程为war工程，其他的工程只是一个jar包。

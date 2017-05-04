### POJO（Plain Old Java Objects）简单的Java对象，实际就是普通JavaBeans，是为了避免和EJB混淆所创造的简称。

使用POJO名称是为了避免和 EJB混淆起来, 而且简称比较直接. 其中有一些属性及其getter setter方法的类,没有业务逻辑，有时可以作为 VO(value -object)或 dto(Data Transform Object)来使用.当然,如果你有一个简单的运算属性也是可以的,但不允许有业务方法,也不能携带有connection之类的方法。
POJO是Plain Old Java Objects的缩写不错，但是它通指没有使用Entity Beans的普通java对象，可以把POJO作为支持业务逻辑的协助类。
POJO实质上可以理解为简单的实体类，顾名思义POJO类的作用是方便程序员使用数据库中的数据表，对于广大的程 序员，可以很方便的将POJO类当做对象来进行使用，当然也是可以方便的调用其get,set方法。POJO类也给我们在struts框架中的配置带来了 很大的方便。

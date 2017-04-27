
# (1).java堆溢出：

Java堆用于存储实例对象，只要不断创建对象，并且保证GC Roots到对象之间有引用的可达，避免垃圾收集器回收实例对象，

就会在对象数量达到堆最大容量时产生`OutOfMemoryError`异常。

想要方便快速地产生堆溢出，要使用如下java虚拟机参数：-Xms10m(最小堆内存为10MB)，-Xmx10m(最大堆内存为10MB，

最小堆内存和最大堆内存相同是为了避免堆动态扩展)，-XX:+HeapDumpOnOutOfMemoryError可以让java虚拟机在出现内存溢出时产生当前堆内存快照以便进行异常分析。

## 什么是GC Roots？
常说的GC(Garbage Collector) roots，特指的是垃圾收集器（Garbage Collector）的对象，GC会收集那些不是GC roots且没有被GC roots引用的对象。

### eg:
  public class HeapOOM{  
    static class OOMObject{  
  }  
  public static void main(String[] args){  
    List<OOMObject> list = new ArrayList<OOMObject>();  
    while(true){  
    list.add(new OOMObject());  
  }  
  }  
  }  

## 各个内存区域容量设置的参数
* -Xss2M：设置栈的容量为2M
* -Xms10M：设置堆的初始容量为10M
* -Xmx10M：设置对的最大容量为10M
* -XX:PermSize=10M：设置方法区的初始容量为10M
* -XX:MaxPermSize=10M：设置方法区的最大容量为10M
* -XX:MaxDirectMemorySize=10M：设置直接内存的最大容量为10M

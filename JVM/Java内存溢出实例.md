
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
运行一段时间就会发现产生OutOfMemoryError异常，并且产生了堆内存异常dump文件。

## 各个内存区域容量设置的参数
* -Xss2M：设置栈的容量为2M
* -Xms10M：设置堆的初始容量为10M
* -Xmx10M：设置堆的最大容量为10M
* -XX:PermSize=10M：设置方法区的初始容量为10M
* -XX:MaxPermSize=10M：设置方法区的最大容量为10M
* -XX:MaxDirectMemorySize=10M：设置直接内存的最大容量为10M

# (2).java虚拟机栈和本地方法栈溢出：

由于Sun的HotSpot虚拟机不区分java虚拟机栈和本地方法栈，因此对于HotSpot虚拟机来说-Xoss参数(设置本地方法栈大小)虽然存在，但是实际上是无效的，栈容量只能由-Xss参数设定。

由于Java虚拟机栈会出现StackOverflowError和OutOfMemoryError两种异常，所以分别使用两个例子演示这两种情况：

## a.java虚拟机栈深度溢出：

单线程的环境下，无论是由于栈帧太大，还是虚拟机栈容量太小，当内存无法再分配的时候，虚拟机总抛出StackOverflowError异常。使用-Xss128k将java虚拟机栈大小设置为128kb，例子代码如下：

### eg:  
public class JavaVMStackOF{  
	private int stackLength = 1;  
	public void stackLeak(){  
		statckLength++;  
		stackLeak();  
}  
public static void main(String[] args){  
	JavaVMStackOF oom = new JavaVMStackOF();  
oom.stackLeak();  
}  
}  
运行一段时间后，产生StackOverflowError异常。Java虚拟机栈溢出一般会产生在方法递归调用过多而java虚拟机栈内存不够的情况下。

## b.java虚拟机栈内存溢出：

多线程环境下，能够创建的线程最大内存=物理内存-最大堆内存-最大方法区内存，在java虚拟机栈内存一定的情况下，单个线程占用的内存越大，所能创建的线程数目越小，所以在多线程条件下很容易产生java虚拟机栈内存溢出的异常。

使用-Xss2m参数设置java虚拟机栈内存大小为2MB，例子代码如下：
### eg:  
public class JavaVMStackOOM{  
	private void dontStop(){  
	while(true){  
}  
}  
public void stackLeakByThread(){  
	while(true){  
		Thread t = new Thread(new Runnable(){  
	public void run(){  
	dontStop();  
}  
});  
t.start();  
}  
}   
public static void main(String[] args){  
	JavaVMStackOOM oom = new JavaVMStackOOM();  
	oom. stackLeakByThread();    
}  
}  
运行一段时间之后，java虚拟机栈就会因为内存太小无法创建线程而产生OutOfMemoryError。  
# (4).方法区溢出：
运行时常量池是方法区的一部分，他们都属于HotSpot虚拟机中的永久代内存区域。方法区用于存放Class的相关信息，Java的反射和动态代理可以动态产生Class，另外第三方的CGLIB可以直接操作字节码，也可以动态产生Class，实验通过CGLIB来演示，同样使用-XX:PermSize=10m和-XX:MaxPermSize=10m将永久代最大内存和最小内存设置为10MB大小，并且由于永久代最大内存和最小内存大小相同，因此无法扩展。

## (5).本机直接内存溢出：

Java虚拟机可以通过参数-XX:MaxDirectMemorySize设定本机直接内存可用大小，如果不指定，则默认与java堆内存大小相同。JDK中可以通过反射获取Unsafe类(Unsafe的getUnsafe()方法只有启动类加载器Bootstrap才能返回实例)直接操作本机直接内存。通过使用-XX:MaxDirectMemorySize=10M，限制最大可使用的本机直接内存大小为10MB，例子代码如下：

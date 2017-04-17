[原文链接1](：https://www.nowcoder.com/discuss/1835?type=&order=0&pos=4&page=1）
# 面经一：
**1.Arraylist 集合类：**
arrayList linkedlist hashmap vector hashtable hashset treemap, 不过前面三个比较常用，后面的不常.
**2.arraylist 和 linkedlist 的区别？** 
底层： arraylist 底层是数组， linkedlist 是双链表 
效率：根据 arraylist 底层数组的特性，查询效率比较高，而增删效率较低，但是也不尽然，如果是在最后一位进行增加或者是删除最后一位元素的话，那么增删效率也是很高的。 Linkedlist 根据底层是双联表的特性，增删效率比较高，但是查询效率比较低，但是头尾例外。 
Arraylist 的增删的实现方式（请参照源码说明）， linkedlist 的查询的实现方式（参照源码说明） 
LinkedList类是双向列表,列表中的每个节点都包含了对前一个和后一个元素的引用.
LinkedList的构造函数如下
1. public LinkedList():  ——生成空的链表
2. public LinkedList(Collection col):  复制构造函数
  我们可以使用LinkedList的indexOf()或者lastIndexOf()方法来查找元素（遇到第一个匹配的元素即停止搜索，同时返回该元素的索引。所以，当LinkedList中有两个同样的元素的时候，使用这两个方法只会返回第一个匹配的元素）。虽然LinkedList不像ArrayList一样支持随机搜索（random search），但是我们仍可以遍历整个线性表，查找需要的元素。
  java.util.LinkedList是双向链表的实现，因此有两个可以用来进行查找操作，分别是：
indexOf()表示从线性表的头部开始搜索，当找到第一个匹配的元素后就停止搜索并返回匹配的元素的索引
lastIndexOf()表示从线性表的尾部开始搜索，当找到第一个匹配的元素后就停止搜索并返回匹配的元素的索引。
它们的索引值都是以头部为起点开始计算的，所以对于LinkedList中同一个的元素，使用indexOf()和lastIndexOf()两个方法返回的值是一样的。如果LinkedList中有两个一样的元素，则使用lastIndexOf()和indexOf()返回的结果肯定是不同的。正如前面所说的，LinkedList并不支持随机搜索，要搜索一个元素需要遍历整个List，这意味这查找的时间复杂度（time complexity）是O(n)。
public class LinkedListSearch {
 
    public static void main(String args[]) {
 
       LinkedList<Integer> ints = new LinkedList<>();
        ints.add(1001);
        ints.add(1002);
        ints.add(1003);
        ints.add(1004);
        ints.add(1005);
        ints.add(1003);
        // let's search a duplicate element in linked list
        // for duplicate elements indexOf() and lastIndexOf() will
        // return different indexes.
        System.out.println("First index of 1003 is : " ints.indexOf(1003));
        System.out.println("Last index of 1003 is : " ints.lastIndexOf(1003));
        
 
        // let's search an element which is not appeared twice
        // for unique elements both indexOf() and lastIndexOf() will return
        // same position
        System.out.println("First index of 1002 is : " ints.indexOf(1002));
        System.out.println("Last index of 1002 is : " ints.lastIndexOf(1002));
 
    }
 
}
 
Output :
First index of 1003 is : 2
Last index of 1003 is : 5
First index of 1002 is : 1
Last index of 1002 is : 1
**3.hashmap 底层是怎么实现的？** 
数组加链表。HashMap底层就是一个数组，数组中的每一项又是一个链表。当新建一个HashMap的时候，就会初始化一个数组。Entry就是数组中的元素，每个Map.Entry就是一个key-value对，它持有一个指向下一个元素的引用，这就构成了链表。


**4.malloc和new的区别**


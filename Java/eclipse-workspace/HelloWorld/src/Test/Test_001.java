package Test;
import java.lang.*;

class ClassFirst{
	static int a=10;
	int b=20;
	static void function001() {
		System.out.println("你好");
	}
	static{
		System.out.println("这个是静态");
		System.out.println(a);
		//System.out.println(b);
	}
	{
		System.out.println("这个是动态");
		System.out.println(a);
		System.out.println(b);
	}
	public  ClassFirst() {
		System.out.println("构造方法");
	}
}
class ClassSecond extends ClassFirst{


}

public class Test_001 {
	final static int[] aa=new int[] {10,20};
	public static void ff(final int[] a) {
		a[0]=100;
	}
	public static void main(String arg[]) {
		System.out.println("Hello,World!");
		//new ClassFirst();
		System.out.println();
		
		ClassFirst.function001();
		System.out.println(aa[0]);
		ff(aa);
		Double bbb=new Double(Math.PI);
		System.out.println(bbb.toString());
		double aaa=Math.PI;
		System.out.println(aaa);
		System.out.println(aa[0]);
		System.out.println(Math.PI);
		System.out.println(Math.E);
		System.out.println(Math.random());
		
	}

}

interface First{
		int a=10;
	default void fun() {
		
	}
}

//thread类的使用==============多线程
package Test;
class Mythread1 extends Thread{
	@Override 
	public void run() {
		for(int i=0;i<10;i++) {
			if (i%2==0) {
				System.out.println(Thread.currentThread().getName()+":"+"i="+i);
			}
		}
	}
}
class Mythread2 extends Thread{
	@Override 
	public void run() {
		for(int i=0;i<10;i++) {
			if (i%2!=0) {
				System.out.println(Thread.currentThread().getName()+":"+"i="+i);
			}
		}
	}
}
public class Test_003 {

	public Test_003() {
		// TODO Auto-generated constructor stub
	}
	public static void main(String a[]) {
					
			Thread t1=	new Mythread1();
			t1.start();
			Thread t3=new Mythread2();
			t3.start();
			Thread t2=new Thread() {
				public void run () {
					for(int i=0;i<10;i++) {
						if (i%2==0) {
							System.out.println(Thread.currentThread().getName()+":"+i+"===============");
						}
					}
				}
			};
			t2.start();
			System.out.println("hello");
			Thread.currentThread().setName("MAIN:");
			for(int i=0;i<10;i++) {
				if (i%2==0) {
					System.out.println(Thread.currentThread().getName()+":"+i+"===============");
			}
		
			}
	}
			

}

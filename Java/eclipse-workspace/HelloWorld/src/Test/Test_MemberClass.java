package Test;

public class Test_MemberClass {
	public static void main(String args[]) {
		FFFF aa=new FFFF();
		FFFF.AAAAAA getF=aa.new AAAAAA();
		getF.function();
		Object A=new student();
		//A.function();
		System.out.println(A.getClass());
		System.out.println(aa.getClass());
	}
		
}

class FFFF{
	public void function() {
		
	}
	
	class AAAAAA{
		void function() {
			System.out.println("这是内部类");
			
		}
	}
	
}
class student extends FFFF{
	public void Get() {
		
	}
}
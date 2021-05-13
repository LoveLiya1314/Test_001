package Test;

public class enum01 {
	public static void main(String arg[]) {
		Light aaa=Light.Green;
	System.out.print(aaa.getClass().getName());
	}
	

}
enum Light {
	Red,Green
	//Red="10";Gren=10;Yello="hi";
}
import java.io.File;
//import java.io.FileInputStream;
import java.util.Scanner;

public class Hello{
    public static void main(String[] args) {
       // FileInputStream fps =new FileInputStream(s.txt);
        System.out.println("Hello,world");
        int a=10,b;
        Scanner sc =new Scanner(System.in);
        a=sc.nextInt();
        b = sc.nextInt();
        for (int i = 0; i < a; i++) {
            System.out.println(i+"====="+b);
            //System.out.println(b);
        }
      //  Scanner sc1 = new Scanner(System.in);
      //  File aaa =new File(a.txt);

    }
    
}
package pack2;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class UDPClient2 {
    private static final int PORT = 8000;
    private DatagramSocket dataSocket;
    private DatagramPacket dataPacket,dq;
    private byte sendDataByte[],tr[]=new byte[16];
    private String s;

    public UDPClient2() {
    	dq = new DatagramPacket(tr, tr.length); 
    	Init();
    }
    public void Init() {
        try {
            // 指定端口号，避免与其他应用程序发生冲突
            dataSocket = new DatagramSocket(0,InetAddress.getByName("127.0.0.1"));
            sendDataByte = new byte[128];
            FileInputStream in=new FileInputStream("D:/CODE/Java/测试/MyTest/src/Test/test1.java");//指定要发送的文件      
            int i=0;long size=new File("D:/CODE/Java/测试/MyTest/src/Test/test1.java").length();
            
            while(i!=-1)
            {       	            
            //s = "客户端向你发来数据测试";
            //sendDataByte = s.getBytes();
            i=in.read(sendDataByte, 0, sendDataByte.length);
            dataPacket = new DatagramPacket(sendDataByte, sendDataByte.length,
                    InetAddress.getByName("127.0.0.1"), PORT);
            
            System.out.println(dataPacket.getLength());
            dataSocket.send(dataPacket);size-=128;
             
            if(size<128){
            
        	   System.out.println("进入if");
            	byte[] b=new byte[(int) size];
            	dataPacket = new DatagramPacket(b,b.length,
                        InetAddress.getByName("127.0.0.1"), PORT); 
            	dataSocket.send(dataPacket);i=-1;break;          	       
            }
            
            
            //这里设计实现“回包”确认再继续传输机制
            while(true){
            	/*System.out.println("待接收方确认中......");
            	dataSocket.receive(dq);
            	//接收方确认收到
            	System.out.println(tr.toString());*/
            	//if(tr.toString().equals("Y"))
            	if(UDPServer2.ss==1)
            	{break;}
            }
               
            }//对应while
        if(i==-1){
        System.out.println("恭喜,文件传输完毕！！！");
        }
        } catch (SocketException se) {
            se.printStackTrace();
        } catch (IOException ie) {
            ie.printStackTrace();
        } 
    }

    public static void main(String args[]) {
        new UDPClient2();
    }
}
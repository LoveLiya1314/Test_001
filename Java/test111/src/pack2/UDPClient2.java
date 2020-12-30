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
            // ָ���˿ںţ�����������Ӧ�ó�������ͻ
            dataSocket = new DatagramSocket(0,InetAddress.getByName("127.0.0.1"));
            sendDataByte = new byte[128];
            FileInputStream in=new FileInputStream("D:/CODE/Java/����/MyTest/src/Test/test1.java");//ָ��Ҫ���͵��ļ�      
            int i=0;long size=new File("D:/CODE/Java/����/MyTest/src/Test/test1.java").length();
            
            while(i!=-1)
            {       	            
            //s = "�ͻ������㷢�����ݲ���";
            //sendDataByte = s.getBytes();
            i=in.read(sendDataByte, 0, sendDataByte.length);
            dataPacket = new DatagramPacket(sendDataByte, sendDataByte.length,
                    InetAddress.getByName("127.0.0.1"), PORT);
            
            System.out.println(dataPacket.getLength());
            dataSocket.send(dataPacket);size-=128;
             
            if(size<128){
            
        	   System.out.println("����if");
            	byte[] b=new byte[(int) size];
            	dataPacket = new DatagramPacket(b,b.length,
                        InetAddress.getByName("127.0.0.1"), PORT); 
            	dataSocket.send(dataPacket);i=-1;break;          	       
            }
            
            
            //�������ʵ�֡��ذ���ȷ���ټ����������
            while(true){
            	/*System.out.println("�����շ�ȷ����......");
            	dataSocket.receive(dq);
            	//���շ�ȷ���յ�
            	System.out.println(tr.toString());*/
            	//if(tr.toString().equals("Y"))
            	if(UDPServer2.ss==1)
            	{break;}
            }
               
            }//��Ӧwhile
        if(i==-1){
        System.out.println("��ϲ,�ļ�������ϣ�����");
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
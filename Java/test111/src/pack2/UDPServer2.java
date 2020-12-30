package pack2;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPServer2 {
    private static final int PORT = 8000;
	private static int ss=0;;
    private DatagramSocket dataSocket;
    private DatagramPacket dataPacket,dp;
    private byte receiveByte[],t[]=new byte[16];
    private String receiveStr,str="Y";
    private FileOutputStream out;
    
    
    public UDPServer2() {
        t=str.getBytes();
        Init();
    }
    public void Init() {
        try {
            dataSocket = new DatagramSocket(PORT,InetAddress.getByName("127.0.0.1"));
            //��Socket����һ�����ݱ�ʱ�������ݱ��Ĳ��ִ洢��receive[]�У�һֱ������ȫ�洢
            receiveByte = new byte[128];
            dataPacket = new DatagramPacket(receiveByte, receiveByte.length);   
            
            receiveStr = "";
            int i = 0,j=0;
            out=new FileOutputStream("D:/FTP�������ļ�/a.mp4");//�������ɵ��ļ������
            
            while (i == 0)// �����ݣ���ѭ��
            {
                dataSocket.receive(dataPacket);
                i = dataPacket.getLength();
                // ��������
                if (i > 0) {
                	
                    // ָ�����յ����ݵĳ���,��ʹ��������������ʾ,��ʼʱ�����׺�����һ��               
                    receiveStr = new String(receiveByte, 0, dataPacket.getLength());    
                    
                    out.write(receiveByte);
                     //����ȷ��  
                    /*dp = new DatagramPacket(t, t.length,
                            InetAddress.getByName("127.0.0.1"), 0);
                    System.out.println(t.toString());
                    dataSocket.send(dp);
                    System.out.println("�ѷ��ذ��÷��ͷ�ȷ��");*/
                    
                    //System.out.println(receiveStr);
                    ss=1;
                    i = 0;// ѭ������            
                }                
                      
                
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String args[]) {
        new UDPServer2();
    }
}
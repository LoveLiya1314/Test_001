package FTP_Test002_NOUSE;

import java.io.FileOutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPServer2 {
    private static final int PORT = 2112;
    public static int ss=0;;
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
            //当Socket接收一个数据报时，将数据报的部分存储在receive[]中，一直到包完全存储
            receiveByte = new byte[128];
            dataPacket = new DatagramPacket(receiveByte, receiveByte.length);

            receiveStr = "";
            int i = 0,j=0;
            out=new FileOutputStream("D:/CODE/Java/测试/MyTest/src/Test/test1.java");//创建生成的文件输出流

            while (i == 0)// 无数据，则循环
            {
                dataSocket.receive(dataPacket);
                i = dataPacket.getLength();
                // 接收数据
                if (i > 0) {

                    // 指定接收到数据的长度,可使接收数据正常显示,开始时很容易忽略这一点
                    receiveStr = new String(receiveByte, 0, dataPacket.getLength());

                    out.write(receiveByte);
                    //返回确认
                    dp = new DatagramPacket(t, t.length,
                            InetAddress.getByName("127.0.0.1"), 0);
                    System.out.println(t.toString());
                    dataSocket.send(dp);
                    System.out.println("已发回包让发送方确认");

                    //System.out.println(receiveStr);
                    ss=1;
                    i = 0;// 循环接收
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
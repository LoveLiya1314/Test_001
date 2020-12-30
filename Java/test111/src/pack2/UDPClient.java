package pack2;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class UDPClient {
    private static final int PORT = 8000;
    private DatagramSocket dataSocket;
    private DatagramPacket dataPacket;
    private byte sendDataByte[];
    private String s;

    public UDPClient() {
        Init();
    }

    public void Init() {
        try {
            // 指定端口号，避免与其他应用程序发生冲突

            dataSocket = new DatagramSocket(0,InetAddress.getByName("127.0.0.1"));
            sendDataByte = new byte[8192];
 
            
            
            s = "客户端向你发来数据测试";
            sendDataByte = s.getBytes();
            dataPacket = new DatagramPacket(sendDataByte, sendDataByte.length,
                    InetAddress.getByName("127.0.0.1"), PORT);
            
            dataSocket.send(dataPacket); System.out.println("已链接");
        } catch (SocketException se) {
            se.printStackTrace();
        } catch (IOException ie) {
            ie.printStackTrace();
        }
    }

    public static void main(String args[]) {
        new UDPClient();
    }
}
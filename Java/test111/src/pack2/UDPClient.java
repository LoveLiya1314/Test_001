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
            // ָ���˿ںţ�����������Ӧ�ó�������ͻ

            dataSocket = new DatagramSocket(0,InetAddress.getByName("127.0.0.1"));
            sendDataByte = new byte[8192];
 
            
            
            s = "�ͻ������㷢�����ݲ���";
            sendDataByte = s.getBytes();
            dataPacket = new DatagramPacket(sendDataByte, sendDataByte.length,
                    InetAddress.getByName("127.0.0.1"), PORT);
            
            dataSocket.send(dataPacket); System.out.println("������");
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
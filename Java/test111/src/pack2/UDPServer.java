package pack2;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class UDPServer {
    private static final int PORT = 8000;
    private DatagramSocket dataSocket;
    private DatagramPacket dataPacket;
    private byte receiveByte[];
    private String receiveStr;

    public UDPServer() {
        Init();
    }

    public void Init() {
        try {
            dataSocket = new DatagramSocket(PORT);
            //��Socket����һ�����ݱ�ʱ�������ݱ��Ĳ��ִ洢��receive[]�У�һֱ������ȫ�洢
            receiveByte = new byte[8192];
            dataPacket = new DatagramPacket(receiveByte, receiveByte.length);
            
            receiveStr = "";
            int i = 0;
            while (i == 0)// �����ݣ���ѭ��
            {
                dataSocket.receive(dataPacket);
                i = dataPacket.getLength();
                // ��������

                if (i > 0) {
                    // ָ�����յ����ݵĳ���,��ʹ��������������ʾ,��ʼʱ�����׺�����һ��

                    receiveStr = new String(receiveByte, 0, dataPacket.getLength());
                    System.out.println(receiveStr);
                    i = 0;// ѭ������

                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String args[]) {
        new UDPServer();
    }
}
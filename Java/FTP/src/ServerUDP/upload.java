package ServerUDP;

import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class upload {
    public void upload_001(String Host, int Port, String FilePath) {
        DatagramSocket Up=null;
        InputStream LOL=null;
        try
        {
            Up=new DatagramSocket(Port);                  //构造数据包套接字
            System.out.println("客户端在 "+Port+" 监听");
            LOL=new FileInputStream(new File(FilePath));
            byte[] b=new byte[LOL.available()];
            LOL.read(b);
            DatagramPacket dp=new DatagramPacket(b,0,b.length);
            dp.setPort(Port);
            dp.setAddress(InetAddress.getByName(Host));
            Up.send(dp);
            System.out.println("文件发送成功");
        } catch (SocketException e)
        {
            e.printStackTrace();
        } catch (IOException e)
        {
            e.printStackTrace();
        }
        finally
        {
            try
            {
                LOL.close();
                Up.close();
            } catch (IOException e)
            {
                e.printStackTrace();
            }

        }
    }

}

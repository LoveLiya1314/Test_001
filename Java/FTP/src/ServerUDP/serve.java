
package ServerUDP;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

public class serve
{
    public static void main(String[] args) throws SocketException, IOException
    {


        OutputStream os=null;
        DatagramSocket DataStruct=null;
        try
        {
            DataStruct=new DatagramSocket(23333);
            System.out.println("在23333端口监听...");
            byte[] b=new byte[1024];
            DatagramPacket DataGrape=new DatagramPacket(b,0,b.length);
            DataStruct.receive(DataGrape);
            byte[] data=DataGrape.getData();
            os=new FileOutputStream(new File("C:\\FTPTest\\ssss.txt"));
            os.write(data, 0, DataGrape.getLength());
            System.out.println("文件接收成功");
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
                os.close();
                DataStruct.close();
            } catch (IOException e)
            {
                e.printStackTrace();
            }


        }
    }
}


package FTP_Test002_NOUSE;

import ServerUDP.upload;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;
import java.net.SocketException;
import java.nio.charset.StandardCharsets;

public class Test {



    public static boolean UDPFile(String Host, int Port, String FilePath, String FileName) {
        System.out.println("发送端启动中...");
        //* 1 使用DatagramSocket 创建发送端
        DatagramSocket client = null;
        try {
            client = new DatagramSocket(Port);
        } catch (SocketException e) {
            e.printStackTrace();
            return false;
        }
        // * 2 准备容器 一定要转成字节数组
        String data = FileName;
        byte[] datas = FileName.getBytes(StandardCharsets.UTF_8);
        //* 3 封装DatagramPacket包裹
        DatagramPacket packet = new DatagramPacket(datas, datas.length,
                new InetSocketAddress(Host, Port));
        //* 4 发送包裹send(DatagramPacket p)
        try {
            client.send(packet);
            System.out.println("文件名发送完毕！");
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
        // * 5 释放资源 </p>
        client.close();
        upload aaa=new upload();
        aaa.upload_001(Host,Port,FilePath);
        return true;

    }
//=====================================================================================================================
//=====================================================================================================================
//=====================================================================================================================
       /* //* 1 使用DatagramSocket 创建发送端
        DatagramSocket client1 = null;
        try {
            client1 = new DatagramSocket(Port);
        } catch (SocketException e) {
            e.printStackTrace();
            return false;
        }
        // * 2 准备容器 一定要转成字节数组
        String data1 = FilePath;
        byte[] datas1 = fileToByteArray(data1);
        //* 3 封装DatagramPacket包裹
        DatagramPacket packet1 = new DatagramPacket(datas1, datas1.length,
                new InetSocketAddress(Host, Port));
        //* 4 发送包裹send(DatagramPacket p)
        try {
            client1.send(packet1);
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
        // * 5 释放资源 </p>
        client1.close();
        return true;
    }

    *//**
     * 读取文件，转成字节数组
     * @param args
     * @return
     *//*
    public static byte[] fileToByteArray(String path) {
        InputStream is = null;
        ByteArrayOutputStream baos = null;
        try {
            is = new FileInputStream(path);
            baos = new ByteArrayOutputStream();
            int len = -1;
            byte[] datas = new byte[1024 * 60];
            while ((len = is.read(datas)) != -1) {
                baos.write(datas, 0, len);
            }
            baos.flush();

        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return baos.toByteArray();
    }*/
    public static void main(String[] args) {
 /*       File s=new File("D:\\CODE\\vs_ConsoleApplication\\22222.txt");
        try {
            s.createNewFile();
        } catch (IOException e) {
            e.printStackTrace();
        }*/
        UDPFile("192.168.159.130",23333,"D:\\CODE\\vs_ConsoleApplication\\233.txt","22.txt");

    }
}

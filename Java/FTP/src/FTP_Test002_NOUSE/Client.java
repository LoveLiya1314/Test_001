package FTP_Test002_NOUSE;

import java.io.*;
import java.net.*;


public class Client {
    // 上传的文件路径
    private static String filePath;
    // 服务器地址和端口号
    private static String host;
    private static int port;
    private static String fileName;

    /**
     * 客户端文件上传
     *
     * @param fileName 文件名
     */
    public static boolean uploadFile(String host, int port, String filePath, String fileName) {
        DatagramSocket dsk = null;
        DatagramPacket dpk = null;
        DataInputStream fis = null;
        try {
            dsk = new DatagramSocket(port, InetAddress.getByName("192.168.159.130"));
            int bufferSize = 8192;
            byte[] buf = new byte[bufferSize];
            dpk = new DatagramPacket(buf, buf.length, new InetSocketAddress(InetAddress.getByName(host), port + 1));
            // 选择进行传输的文件
            File fi = new File(filePath + fileName);
            System.out.println("文件长度:" + (int) fi.length());
            fis = new DataInputStream(new FileInputStream(filePath + fileName));
            buf = fi.getName().getBytes();
            dpk.setData(buf, 0, fileName.length());
            dsk.send(dpk);
            String fileLen = Long.toString((long) fi.length());
            buf = fileLen.getBytes();
            System.out.println("buf文件长度" + new String(buf));
            dpk.setData(buf, 0, fileLen.length());
            dsk.send(dpk);
            while (true) {
                int read = 0;
                if (fis != null) {
                    read = fis.read(buf);
                }

                if (read == -1) {
                    break;
                }
                dpk.setData(buf, 0, read);
                dsk.send(dpk);
            }
            //给服务器发布一个终止信号
            dpk.setData(buf, 0, 0);
            dsk.send(dpk);
            System.out.println("文件传输完成");
            return true;
        } catch (Exception e) {
            System.out.println("服务器" + host + ":" + port + "失去连接");
            e.printStackTrace();
            return false;
        } finally {
            try {
                if (fis != null) {
                    fis.close();
                }
                if (dsk != null) {
                    dsk.close();
                }
                return false;
            } catch (IOException e) {
                e.printStackTrace();
                return false;
            }
        }
    }

    public static boolean Client(String Host, int Port, String FilePath, String FileName) {
        boolean result = false;
        Host.replace("/", "");
        host = "192.168.159.130";
        port =Port;
        fileName = FileName;
        filePath = FilePath;
        result = Client.uploadFile(host, port, filePath, fileName);
        return result;

    }



}

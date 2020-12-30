package ServerUDP;

import ServerUDP.upload;
/**
 * UDP
 *  <p>文件上传
 * 1 使用DatagramSocket 创建接收端
 * 2 准备容器 一定要转成字节数组
 * 3 封装DatagramPacket包裹
 * 4 阻塞式接收包裹receive(DatagramPacket p)
 * 5 分析数据 byte[] getData, getLength。
 * 6 释放资源 </p>
 * @author ad
 *
 */
public class UDPFileClient {
    public static boolean UDPFileClient(String Host, int Port, String FilePath, String FileName) {
        upload aaa=new upload();
        aaa.upload_001(Host,Port,FilePath);
        return true;
    }
}

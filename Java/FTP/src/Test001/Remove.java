package Test001;

import org.apache.commons.net.ftp.FTPClient;

import java.io.IOException;

public class Remove {
          /**
            * 删除文件夹下所有文件
            * @return
            * @throws IOException
            */
     public static boolean Remove(String Path,String pathname,FTPClient client) throws IOException {
         boolean flag=false;
             /*
              * 个方法的意思就是每次数据连接之前，ftp client告诉ftp server开通一个端口来传输数据。
              * ftp server可能每次开启不同的端口来传输数据，
              * 但是在linux上，由于安全限制，可能某些端口没有开启，所以就出现阻塞。
              * */
         client.changeWorkingDirectory(Path);                                //重新定位文件位置
         flag = client.deleteFile(pathname);
             //flag=client.deleteFile(new String(pathname.getBytes("utf-8"),"ios-8859-1"));
         return flag;

     }


}

/**
 * 看到一位大佬的一个关于删除文件的函数声明=========================暂时抄过来，已备不时之需
 * https://developer.aliyun.com/article/319859
 */

